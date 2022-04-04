//
// Created by iange on 04.04.2022.
//

#include "DisplayMenuControl.h"

DisplayMenuControl::DisplayMenuControl() {
    currentPage = START_PAGE;
    currentSettingsPosition = 0;

    Serial.println("DisplayMenuControl loaded");
    displayMenu.showStartPage();


    nextPageButton.setDebounce(50);
    nextSittingButton.setDebounce(50);
    previousSittingButton.setDebounce(50);
    changeSittingButton.setDebounce(50);
}

DisplayMenuControl::~DisplayMenuControl() {

}

void DisplayMenuControl::execute() {
    nextPageButton.tick();
    if (nextPageButton.isPress()) {
        nextPage();
    }

    nextSittingButton.tick();
    if (nextSittingButton.isPress()) {
        nextSittingsPosition();
    }

    previousSittingButton.tick();
    if (previousSittingButton.isPress()) {
        previousSittingsPosition();
    }

    changeSittingButton.tick();
    if (changeSittingButton.isPress() && currentPage == 4) {
        changeSittings();
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
            displayMenu.showSettingsPageInformation(soundSittings, vibroSittings, currentSettingsPosition);
            break;
    }
}

void DisplayMenuControl::nextPage() {
    currentSettingsPosition = 0;
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
            displayMenu.showSettingsPageInformation(soundSittings, vibroSittings, currentSettingsPosition);
            break;
    }
}

void DisplayMenuControl::nextSittingsPosition() {
    if (currentSettingsPosition < NUMBER_OF_SETTINGS - 1) {
        currentSettingsPosition++;
    }
    if (currentPage == 4) {
        displayMenu.showSettingsPageInformation(soundSittings, vibroSittings, currentSettingsPosition);
    }
}

void DisplayMenuControl::previousSittingsPosition() {
    if (currentSettingsPosition > 0) {
        currentSettingsPosition--;
    }
    if (currentPage == 4) {
        displayMenu.clearDisplay();
        displayMenu.showSettingsPage();
        displayMenu.showSettingsPageInformation(soundSittings, vibroSittings, currentSettingsPosition);
    }
}

void DisplayMenuControl::changeSittings() {
    if (currentSettingsPosition == 0) {
        soundSittings = !soundSittings;
    } else if (currentSettingsPosition == 1) {
        vibroSittings = !vibroSittings;
    }
    displayMenu.clearDisplay();
    displayMenu.showSettingsPage();
    displayMenu.showSettingsPageInformation(soundSittings, vibroSittings, currentSettingsPosition);
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