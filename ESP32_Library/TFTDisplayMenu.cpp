//
// Created by Anzhalika Dziarkach on 04.04.2022.
//

#include "TFTDisplayMenu.h"

TFTDisplayMenu::TFTDisplayMenu() {
    tft.init();
    tft.setRotation(1);
    clearDisplay();

    Serial.println("TFTDisplayMenu loaded");
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
    tft.println("            ...");
}

void TFTDisplayMenu::showInfoPage() {
    tft.println("       INFORMATION\n");
}

void TFTDisplayMenu::showMovementPage() {
    tft.println("         MOVEMENT");
    tft.println("x: ");
    tft.println("y: ");
    tft.println("z: ");
    tft.println("==========================");
    tft.println("direction: ");
    tft.println("speed: ");
}

void TFTDisplayMenu::showMovementPageInformation(int x, int y, bool z, String direction, int speed) {
    tft.setCursor(20, 16, 2);
    tft.print(x);
    tft.print("     ");

    tft.setCursor(20, 32, 2);
    tft.print(y);
    tft.print("     ");

    tft.setCursor(20, 48, 2);
    tft.print(z);
    tft.print("     ");

    tft.setCursor(64, 80, 2);
    tft.print(direction);
    tft.print("     ");

    tft.setCursor(50, 96, 2);
    tft.print("       ");

    tft.setCursor(50, 96, 2);
    tft.print(speed);
    tft.print(" %");
}

void TFTDisplayMenu::showCameraMovementPage() {
    tft.println("   CAMERA MOVEMENT\n");
    tft.println("x: ");
    tft.println("y: ");
    tft.println("z: ");
}

void TFTDisplayMenu::showCameraMovementPageInformation(int x, int y, bool z) {
    tft.setCursor(20, 32, 2);
    tft.print(x);
    tft.print("     ");

    tft.setCursor(20, 48, 2);
    tft.print(y);
    tft.print("     ");

    tft.setCursor(20, 64, 2);
    tft.print(z);
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

void TFTDisplayMenu::showSettingsPageInformation(bool isSound, bool isVibro, int settingsPosition) {
    tft.setCursor(42, 32, 2);

    switch (settingsPosition) {
        case 0:
            tft.setTextColor(TFT_WHITE, 0x5AEB);
            if (isSound) {
                tft.println("on ");
            } else {
                tft.println("off");
            }

            tft.setTextColor(TFT_WHITE, TFT_BLACK);
            tft.setCursor(42, 48, 2);
            if (isVibro) {
                tft.println("on ");
            } else {
                tft.println("off");
            }

            break;

        case 1:
            tft.setTextColor(TFT_WHITE, TFT_BLACK);
            if (isSound) {
                tft.println("on ");
            } else {
                tft.println("off");
            }

            tft.setTextColor(TFT_WHITE, 0x5AEB);
            tft.setCursor(42, 48, 2);
            if (isVibro) {
                tft.println("on ");
            } else {
                tft.println("off");
            }

            break;
        default:
            tft.setTextColor(TFT_WHITE, TFT_BLACK);
            if (isSound) {
                tft.println("on ");
            } else {
                tft.println("off");
            }

            tft.setCursor(42, 48, 2);
            if (isVibro) {
                tft.println("on ");
            } else {
                tft.println("off");
            }
            break;
    }
}