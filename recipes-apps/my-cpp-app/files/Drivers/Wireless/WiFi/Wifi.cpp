#include "Wifi.hpp"

namespace Drivers::Wireless::Wifi
{
  constexpr std::string_view serviceName_ = "fi.w1.wpa_supplicant1";
  constexpr std::string_view interfaceName = "fi.w1.wpa_supplicant1.Interface";
  constexpr std::string_view wlan0PathStr = "/fi/w1/wpa_supplicant1/Interfaces/0";

  Wifi::Wifi(WifiEventCallback WifiCallback) : _WifiCallback{WifiCallback},
                                               _wifiState{WifiState::None}
  {
    _connection = sdbus::createSystemBusConnection();
    _interfaceProxy = sdbus::createProxy(*_connection, serviceName_.data(), wlan0PathStr.data());

    _interfaceProxy->uponSignal("PropertiesChanged")
        .onInterface("org.freedesktop.DBus.Properties")
        .call([this](const std::string &interface,
                     const std::map<std::string, sdbus::Variant> &changed,
                     const std::vector<std::string> &invalidated)
              { this->onPropertiesChanged(interface, changed, invalidated); });

    _connection->enterEventLoopAsync();
  }

  std::optional<WifiError> Wifi::ConnectToWifiAp(std::string_view ssid, std::string_view password)
  {
    std::vector<uint8_t> ssidBytes(ssid.begin(), ssid.end());

    std::map<std::string, sdbus::Variant> config;
    config["ssid"] = sdbus::Variant(ssidBytes);
    config["psk"] = sdbus::Variant(std::string(password));
    config["key_mgmt"] = sdbus::Variant("WPA-PSK");

    try
    {
      sdbus::ObjectPath networkPath;

      _interfaceProxy->callMethod("AddNetwork")
          .onInterface(interfaceName.data())
          .withArguments(config)
          .storeResultsTo(networkPath);

      _interfaceProxy->callMethod("SelectNetwork")
          .onInterface(interfaceName.data())
          .withArguments(networkPath);

      return std::nullopt;
    }
    catch (const sdbus::Error &e)
    {
      if (e.getName() == "org.freedesktop.DBus.Error.ServiceUnknown")
      {
        printf("Wifi: Internal Error\n");
        return WifiError::SupplicantInternalError;
      }
      else if (e.getName() == "fi.w1.wpa_supplicant1.InvalidArgs")
      {
        printf("Wifi: Invalid Credentials\n");
        return WifiError::InvalidCredentials;
      }
      else if (e.getName() == "fi.w1.wpa_supplicant1.InterfaceUnknown")
      {
        printf("Wifi: Interface not founf");
        return WifiError::InterfaceNotFound;
      }
      else
      {
        printf("Wifi: Unknown Error: %s\n", e.getName().data());
        return WifiError::SupplicantInternalError;
      }
    }
  }

  void Wifi::onPropertiesChanged(const std::string &interfaceName,
                                 const std::map<std::string, sdbus::Variant> &changedParameter,
                                 const std::vector<std::string> &invalidatedProps)
  {
    auto it = changedParameter.find("State");
    if (it != changedParameter.end() && _WifiCallback)
    {
      std::string state = it->second;

      if (state == "completed")
      {
        printf("Wifi: State Connected\n");
        _wifiState = WifiState::Connected;
      }

      else if (state == "disconnected")
      {
        printf("Wifi: State DisConnected\n");
        _wifiState = WifiState::Disconnected;
      }

      else if (state == "associating")
      {
        printf("Wifi: State Associating\n");
        _wifiState = WifiState::Authenticating;
      }

      _WifiCallback(_wifiState);
    }
  }

  WifiState Wifi::GetWifiState()
  {
    return _wifiState;
  }
}
