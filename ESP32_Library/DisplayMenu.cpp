#include "DisplayMenu.h"

DisplayMenu::DisplayMenu() {
    menuPosition = 1;

    tft.init();
    tft.setRotation(1);
    Serial.println("DisplayMenu loaded");
    clearDisplay();
    showStartPage();
}

DisplayMenu::~DisplayMenu() {

}

int DisplayMenu::getCurrentPage() {
    return menuPosition;
}

void DisplayMenu::nextPage() {
    menuPosition++;
    if (menuPosition >= NUMBER_OF_PAGES) {
        menuPosition = START_PAGE;
    }
}

void DisplayMenu::setValues(int movementX, int movementY, int cameraX, int cameraY) {
    this->movementX = movementX;
    this->movementY = movementY;
    this->cameraX = cameraX;
    this->cameraY = cameraY;
}

void DisplayMenu::execute() {
    clearDisplay();
    switch (menuPosition) {
        case 0:
            showInfoPage();
            break;
        case 1:
            showMovementPage(0, 0, 's', 0);
            break;
        case 2:
            showCameraMovementPage(0, 0, 's');
            break;
        case 3:
            showVideoPage();
            break;
        case 4:
            showSettingsPage();
            break;
    }
}

void DisplayMenu::clearDisplay() {
    tft.fillScreen(TFT_BLACK);
    tft.setCursor(0, 0, 2);
    tft.setTextColor(TFT_WHITE, TFT_BLACK);
    //tft.setTextSize(1);
}

void DisplayMenu::showStartPage() {
    tft.println("          START\n");
    tft.println("Connection to the robot");
    tft.println("...");
}

void DisplayMenu::showInfoPage() {
    tft.println("       INFORMATION\n");
}

void DisplayMenu::showMovementPage(int x, int y, char directionMovement, int speedMovement) {
    tft.println("         MOVEMENT\n");
    tft.print("x: ");
    tft.println(movementX);
    tft.print("y: ");
    tft.println(movementY);
    tft.println("==========================");
    tft.print("direction: ");
    tft.println(directionMovement);
    tft.print("speed: ");
    tft.print(speedMovement);
    tft.println(" %");
}

void DisplayMenu::showCameraMovementPage(int x, int y, char directionMovement) {
    tft.println("   CAMERA MOVEMENT\n");
    tft.print("x: ");
    tft.println(x);
    tft.print("y: ");
    tft.println(y);
    tft.println("==========================");
    tft.print("direction: ");
    tft.println(directionMovement);
}

void DisplayMenu::showVideoPage() {
    tft.println("          VIDEO\n");
}

void DisplayMenu::showSettingsPage() {
    tft.println("         SETTINGS\n");
    tft.print("sound: ");
    tft.println("on");
    tft.print("vibro: ");
    tft.println("on");
}