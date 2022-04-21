//
// Created by Anzhalika Dziarkach on 05.04.2022.
//

#ifndef WIFI_CONTROLLER_H
#define WIFI_CONTROLLER_H

#include <WiFi.h>
#include <SPI.h>
#include "Arduino.h"
#include "pch.h"

const char *ROBOT_SSID = "Multitasking_robot";
const char *ROBOT_PASSWORD = "robot123";
//const uint16_t ROBOT_PORT = 65432;
//const char *ROBOT_IP = "192.168.1.23";

class WifiController {
public:
    WifiController();
    ~WifiController();

    void begin();

private:
    WiFiClient client;
};


#endif //WIFI_CONTROLLER_H
