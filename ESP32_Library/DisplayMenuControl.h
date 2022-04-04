//
// Created by iange on 04.04.2022.
//

#ifndef DISPLAYMENUCONTROL_H
#define DISPLAYMENUCONTROL_H

#include "TFTDisplayMenu.h"
#include "GyverButton.h"

#define NUMBER_OF_PAGES 5
#define START_PAGE 0

class DisplayMenuControl {
public:
    DisplayMenuControl();
    ~DisplayMenuControl();

    void execute();
    void nextPage();
    void updateMenuInformation(int movementX, int movementY, int cameraX, int cameraY, String movementDirection, int movementSpeed);
    void updateMenuSittings(bool soundSittings, bool vibroSittings);

    bool getSoundSettings();
    bool getVibroSettings();

private:
    TFTDisplayMenu displayMenu;
    int currentPage;

    int movementX;
    int movementY;
    int cameraX;
    int cameraY;
    String movementDirection;
    int movementSpeed;

    bool soundSittings;
    bool vibroSittings;

    GButton nextPageButton = GButton(12);
};


#endif //DISPLAYMENUCONTROL_H
