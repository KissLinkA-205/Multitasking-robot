//
// Created by iange on 03.04.2022.
//

#include "ControlController.h"

ControlController::ControlController() {
    Serial.println("Start ControlController");

    pinMode(LED_PIN, OUTPUT);
    pinMode(motorchiki, OUTPUT);
    pinMode(soundPin, OUTPUT);
    pinMode(MOVEMENT_X, INPUT);
    pinMode(MOVEMENT_Y, INPUT);
    pinMode(CAMERA_X, INPUT);
    pinMode(CAMERA_Y, INPUT);
}

ControlController::~ControlController() {

}

int ControlController::getXPositionFromMovement() {
    return analogRead(MOVEMENT_X);
}

int ControlController::getYPositionFromMovement() {
    return analogRead(MOVEMENT_Y);
}

int ControlController::getXPositionFromCameraMovement() {
    return analogRead(CAMERA_X);
}

int ControlController::getYPositionFromCameraMovement() {
    return analogRead(CAMERA_Y);
}

void ControlController::turnOnLED() {
    digitalWrite(LED_PIN, HIGH);
}

void ControlController::turnOffLED() {
    digitalWrite(LED_PIN, LOW);
}