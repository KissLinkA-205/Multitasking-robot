//
// Created by iange on 04.04.2022.
//

#ifndef DISPLAYMENUCONTROL_H
#define DISPLAYMENUCONTROL_H

#include "TFTDisplayMenu.h"
#include "GyverButton.h"

#define NUMBER_OF_PAGES 5
#define START_PAGE 0

#define NUMBER_OF_SETTINGS 2

class DisplayMenuControl {
public:
    DisplayMenuControl();
    ~DisplayMenuControl();

    void execute();
    void nextPage();
    void nextSittingsPosition();
    void previousSittingsPosition();
    void changeSittings();
    void updateMenuInformation(int movementX, int movementY, int cameraX, int cameraY, String movementDirection, int movementSpeed);

    bool getSoundSettings();
    bool getVibroSettings();

private:
    TFTDisplayMenu displayMenu;
    int currentPage;
    int currentSettingsPosition;

    int movementX;
    int movementY;
    int cameraX;
    int cameraY;
    String movementDirection;
    int movementSpeed;

    bool soundSittings;
    bool vibroSittings;

    GButton nextPageButton = GButton(12);
    GButton nextSittingButton = GButton(14);
    GButton previousSittingButton = GButton(27);
    GButton changeSittingButton = GButton(13);
};


#endif //DISPLAYMENUCONTROL_H
