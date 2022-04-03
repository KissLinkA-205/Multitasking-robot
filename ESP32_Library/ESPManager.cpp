//
// Created by iange on 03.04.2022.
//

#include "ESPManager.h"

ESPManager::ESPManager() {
    Serial.begin(115200);
    Serial.println("Start manager");
    pinMode(12, INPUT_PULLUP);
}

ESPManager::~ESPManager() {

}

void ESPManager::begin() {

}

void ESPManager::handle() {
    int movementX = controller.getXPositionFromMovement();
    int movementY = controller.getYPositionFromMovement();
    int cameraX = controller.getXPositionFromCameraMovement();
    int cameraY = controller.getYPositionFromCameraMovement();
    display.setValues(movementX, movementY, cameraX, cameraY);

    int buttonState = digitalRead(12);
    Serial.println(buttonState);
    if (buttonState == 0) {
        display.nextPage();
    }

    display.execute();
    delay(300);
}

