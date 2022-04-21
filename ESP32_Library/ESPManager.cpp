//
// Created by Anzhalika Dziarkach on 03.04.2022.
//

#include "ESPManager.h"

ESPManager::ESPManager() {
    Serial.begin(115200);
    Serial.println("Start ESPManager");
}

ESPManager::~ESPManager() {

}

void ESPManager::begin() {
    controlController.turnOnSound();
    delay(500);
    controlController.turnOffSound();

    wifiController.begin();
    displayMenuController.showPage();
}

void ESPManager::handle() {
    int movementX = controlController.getXPositionFromMovementJoystick();
    int movementY = controlController.getYPositionFromMovementJoystick();
    bool movementZ = controlController.isMovementButtonPressed();

    int cameraX = controlController.getXPositionFromCameraJoystick();
    int cameraY = controlController.getYPositionFromCameraJoystick();
    bool cameraZ = controlController.isCameraButtonPressed();

    String direction = controlController.getDirectionMovement(movementX, movementY);
    int speed = controlController.getSpeed(movementX, movementY);

    displayMenuController.updateMenuInformation(movementX, movementY, movementZ, cameraX, cameraY, cameraZ, direction, speed);
    displayMenuController.execute();
}

