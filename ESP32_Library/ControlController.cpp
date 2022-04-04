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

String ControlController::getDirectionMovement(int x, int y) {
    String result = STOP_MOVEMENT;

    if (y > BASE_AXIS_VALUE + AXIS_INFELICITY) {
        result = FORWARD_MOVEMENT;
    } else if (y < BASE_AXIS_VALUE - AXIS_INFELICITY) {
        result = BACK_MOVEMENT;
    } else if (x > BASE_AXIS_VALUE + AXIS_INFELICITY) {
        result = RIGHT_MOVEMENT;
    } else if (x < BASE_AXIS_VALUE - AXIS_INFELICITY) {
        result = LEFT_MOVEMENT;
    }

    return result;
}

int ControlController::getSpeed(int x, int y) {
    String directionMovement = getDirectionMovement(x, y);
    int result = 0;
    if (directionMovement == BACK_MOVEMENT) {
        result = (MIN - y) * 100 / MIN;
    } else if (directionMovement == FORWARD_MOVEMENT) {
        result = (y - BASE_AXIS_VALUE - AXIS_INFELICITY) * 100 /
                 (MAX - BASE_AXIS_VALUE - AXIS_INFELICITY);
    } else if (directionMovement == LEFT_MOVEMENT) {
        result = (MIN - x) * 100 / MIN;
    } else if (directionMovement == RIGHT_MOVEMENT) {
        result = (x - BASE_AXIS_VALUE - AXIS_INFELICITY) * 100 /
                 (MAX - BASE_AXIS_VALUE - AXIS_INFELICITY);
    }
    return result;
}