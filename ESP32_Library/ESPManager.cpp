//
// Created by iange on 03.04.2022.
//

#include "ESPManager.h"

ESPManager::ESPManager() {
    Serial.begin(115200);
    Serial.println("Start manager");
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
    String direction = controller.getDirectionMovement(movementX, movementY);
    int speed = controller.getSpeed(movementX, movementY);

    menuControl.updateMenuInformation(movementX, movementY, cameraX, cameraY, direction, speed);
    menuControl.execute();
}

