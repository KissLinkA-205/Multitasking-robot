//
// Created by iange on 04.04.2022.
//

#include "TFTDisplayMenu.h"

TFTDisplayMenu::TFTDisplayMenu() {
    tft.init();
    tft.setRotation(1);
    Serial.println("TFTDisplayMenu loaded");
    clearDisplay();
}

TFTDisplayMenu::~TFTDisplayMenu() {

}

void TFTDisplayMenu::clearDisplay() {
    tft.fillScreen(TFT_BLACK);
    tft.setCursor(0, 0, 2);
    tft.setTextColor(TFT_WHITE, TFT_BLACK);
}

void TFTDisplayMenu::showStartPage() {
    tft.println("          START\n");
    tft.println("Connection to the robot");
    tft.println("...");
}

void TFTDisplayMenu::showInfoPage() {
    tft.println("       INFORMATION\n");
}

void TFTDisplayMenu::showMovementPage() {
    tft.println("         MOVEMENT\n");
    tft.println("x: ");
    tft.println("y: ");
    tft.println("==========================");
    tft.println("direction: ");
    tft.println("speed: ");
}

void TFTDisplayMenu::showMovementPageInformation(int x, int y, String direction, int speed) {
    tft.setCursor(20, 32, 2);
    tft.print(x);
    tft.print("     ");

    tft.setCursor(20, 48, 2);
    tft.print(y);
    tft.print("     ");

    tft.setCursor(64, 80, 2);
    tft.print(direction);
    tft.print("     ");

    tft.setCursor(50, 96, 2);
    tft.print("     ");

    tft.setCursor(50, 96, 2);
    tft.print(speed);
    tft.print(" %");
}

void TFTDisplayMenu::showCameraMovementPage() {
    tft.println("   CAMERA MOVEMENT\n");
    tft.println("x: ");
    tft.print("y: ");
}

void TFTDisplayMenu::showCameraMovementPageInformation(int x, int y) {
    tft.setCursor(20, 32, 2);
    tft.print(x);
    tft.print("     ");

    tft.setCursor(20, 48, 2);
    tft.print(y);
    tft.print("     ");
}

void TFTDisplayMenu::showVideoPage() {
    tft.println("          VIDEO\n");
}

void TFTDisplayMenu::showSettingsPage() {
    tft.println("         SETTINGS\n");

    tft.println("sound: ");
    tft.println("vibro: ");
}

void TFTDisplayMenu::showSettingsPageInformation(bool sound, bool vibro) {
    tft.setCursor(42, 32, 2);
    if (sound) {
        tft.println("on ");
    } else {
        tft.println("off");
    }

    tft.setCursor(42, 48, 2);
    if (vibro) {
        tft.println("on ");
    } else {
        tft.println("off");
    }
}