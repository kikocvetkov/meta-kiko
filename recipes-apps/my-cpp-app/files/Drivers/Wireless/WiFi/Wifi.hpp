#pragma once

#include <string_view>
#include <optional>
#include <sdbus-c++/sdbus-c++.h>

namespace Drivers::Wireless::Wifi
{
    enum class WifiError
    {
        InterfaceNotFound,
        InvalidCredentials,
        AuthenticationFailed,
        SupplicantInternalError,
        Timeout
    };

    enum class WifiState
    {
        None,
        Disconnected,
        Authenticating,
        Connected,
        Failed
    };
    
    using WifiEventCallback = std::function<void(WifiState)>;

    class Wifi
    {
    public:
        Wifi();
        ~Wifi() = default;

        Wifi(const Wifi &) = delete;
        Wifi(Wifi &&) = delete;
        Wifi &operator=(const Wifi &) noexcept = delete;
        Wifi &operator=(Wifi &&) noexcept = delete;

        void RegisterWifiCallback(WifiEventCallback wifiCallback);
        std::optional<WifiError> ConnectToWifiAp(std::string_view ssid, std::string_view password);
        WifiState GetWifiState();

    private:
    void onPropertiesChanged(const std::string& interfaceName, 
                             const std::map<std::string, sdbus::Variant>& changedParameter, 
                             const std::vector<std::string>& invalidatedProps);

        std::unique_ptr<sdbus::IConnection> _connection;
        std::unique_ptr<sdbus::IProxy> _interfaceProxy;
        WifiEventCallback _wifiCallback;
        WifiState _wifiState;
    };
}
