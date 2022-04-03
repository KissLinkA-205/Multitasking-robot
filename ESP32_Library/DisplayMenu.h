#ifndef DISPLAYMENU_H
#define DISPLAYMENU_H

#include <SPI.h>
#include <TFT_eSPI.h>
#include "Arduino.h"

#define NUMBER_OF_PAGES 5
#define START_PAGE 0

class DisplayMenu {
public:
    DisplayMenu();
    ~DisplayMenu();

    void nextPage();
    void execute();
    int getCurrentPage();

    void clearDisplay();
    void showStartPage();
    void showInfoPage();
    void showMovementPage(int x, int y, char directionMovement, int speedMovement);
    void showCameraMovementPage(int x, int y, char directionMovement);
    void showVideoPage();
    void showSettingsPage();

    void setValues(int movementX, int movementY, int cameraX, int cameraY);

private:
    int menuPosition;
    TFT_eSPI tft = TFT_eSPI();

    int movementX;
    int movementY;
    int cameraX;
    int cameraY;
};

#endif //DISPLAYMENU_H