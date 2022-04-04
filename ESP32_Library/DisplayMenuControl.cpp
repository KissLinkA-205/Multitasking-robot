//
// Created by iange on 04.04.2022.
//

#include "DisplayMenuControl.h"

DisplayMenuControl::DisplayMenuControl() {
    currentPage = START_PAGE;

    Serial.println("DisplayMenuControl loaded");
    displayMenu.showStartPage();


    nextPageButton.setDebounce(50);
}

DisplayMenuControl::~DisplayMenuControl() {

}

void DisplayMenuControl::execute() {
    nextPageButton.tick();
    if (nextPageButton.isPress()) {
        nextPage();
    }

    switch (currentPage) {
        case 0:

            break;
        case 1:

            displayMenu.showMovementPageInformation(movementX, movementY, movementDirection, movementSpeed);
            break;
        case 2:

            displayMenu.showCameraMovementPageInformation(cameraX, cameraY);
            break;
        case 3:

            break;
        case 4:
            displayMenu.showSettingsPageInformation(soundSittings, vibroSittings);
            break;
    }
}

void DisplayMenuControl::nextPage() {
    currentPage++;
    if (currentPage >= NUMBER_OF_PAGES) {
        currentPage = START_PAGE;
    }

    displayMenu.clearDisplay();
    switch (currentPage) {
        case 0:
            displayMenu.showInfoPage();
            break;
        case 1:
            displayMenu.showMovementPage();
            displayMenu.showMovementPageInformation(movementX, movementY, movementDirection, movementSpeed);
            break;
        case 2:
            displayMenu.showCameraMovementPage();
            displayMenu.showCameraMovementPageInformation(cameraX, cameraY);
            break;
        case 3:
            displayMenu.showVideoPage();
            break;
        case 4:
            displayMenu.showSettingsPage();
            displayMenu.showSettingsPageInformation(soundSittings, vibroSittings);
            break;
    }
}

bool DisplayMenuControl::getSoundSettings() {
    return soundSittings;
}

bool DisplayMenuControl::getVibroSettings() {
    return vibroSittings;
}

void DisplayMenuControl::updateMenuInformation(int movementX, int movementY, int cameraX, int cameraY,
                                               String movementDirection, int movementSpeed) {
    this->movementX = movementX;
    this->movementY = movementY;
    this->cameraX = cameraX;
    this->cameraY = cameraY;
    this->movementDirection = movementDirection;
    this->movementSpeed = movementSpeed;
}