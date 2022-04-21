//
// Created by Anzhalika Dziarkach on 05.04.2022.
//

#include "WifiController.h"

WifiController::WifiController() {
    pinMode(LED_PIN, OUTPUT);

    Serial.println("WifiController loaded");
}

WifiController::~WifiController() {

}

void WifiController::begin() {
    WiFi.begin(ROBOT_SSID, ROBOT_PASSWORD);
    while (WiFi.status() != WL_CONNECTED) {
        Serial.println("Connection to the robot ...");
        digitalWrite(LED_PIN, LOW);
        delay(500);
        digitalWrite(LED_PIN, HIGH);
        delay(500);
    }

    Serial.println("Connected to the robot successfully");
    digitalWrite(LED_PIN, HIGH);
}