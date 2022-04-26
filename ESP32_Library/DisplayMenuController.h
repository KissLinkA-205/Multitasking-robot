//
// Created by Anzhalika Dziarkach on 04.04.2022.
//

#ifndef DISPLAYMENUCONTROL_H
#define DISPLAYMENUCONTROL_H

#include <EEPROM.h>
#include "TFTDisplayMenu.h"
#include "GyverButton.h"
#include "pch.h"
#include "ControlController.h"

#define EEPROM_SIZE 3
#define SOUND_EEPROM_POSITION 0
#define VIBRO_EEPROM_POSITION 1
#define INVERSION_EEPROM_POSITION 2

#define NUMBER_OF_PAGES 5
#define INFO_PAGE_POSITION 0
#define MOVEMENT_PAGE_POSITION 1
#define CAMERA_PAGE_POSITION 2
#define VIDEO_PAGE_POSITION 3
#define SETTINGS_PAGE_POSITION 4

#define NUMBER_OF_SETTINGS 4
#define SOUND_SETTING_POSITION 0
#define VIBRO_SETTING_POSITION 1
#define CONTROL_INVERSION_POSITION 2
#define START_TEST_POSITION 3

#define BUTTON_DEBOUNCE 50

class DisplayMenuController {
public:
    DisplayMenuController();
    ~DisplayMenuController();

    void execute();

    void nextPage();
    void showPage();
    void showConnection();

    void nextSettingPosition();
    void previousSettingPosition();

    void changeSetting();
    void updateMenuInformation(int movementX, int movementY, bool movementZ, int cameraX, int cameraY,
                               bool cameraZ, String movementDirection, int movementSpeed, String cameraHorizontalDirection,
                               String cameraVerticalDirection);

    bool getSoundSetting();
    bool getVibroSetting();
    bool getControlInversionSetting();

private:
    TFTDisplayMenu displayMenu;
    int currentPage;
    int currentSettingPosition;

    int movementX;
    int movementY;
    bool movementButton;
    int cameraX;
    int cameraY;
    bool cameraButton;

    String movementDirection;
    int movementSpeed;

    String cameraHorizontalDirection;
    String cameraVerticalDirection;

    bool soundSetting;
    bool vibroSetting;
    bool controlInversionSetting;

    GButton nextPageButton = GButton(NEXT_PAGE_BUTTON);
    GButton nextSettingButton = GButton(NEXT_SETTING_BUTTON);
    GButton changeSettingButton = GButton(CHANGE_SETTING_BUTTON);
    GButton previousSettingButton = GButton(PREVIOUS_SETTING_BUTTON);
};


#endif //DISPLAYMENUCONTROL_H
