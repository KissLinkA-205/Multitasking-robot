//
// Created by Anzhalika Dziarkach on 03.04.2022.
//

#ifndef ESP_MANAGER_H
#define ESP_MANAGER_H

#include "ControlController.h"
#include "DisplayMenuController.h"
#include "WifiController.h"
#include "Arduino.h"

class ESPManager {
public:
    ESPManager();
    ~ESPManager();

    void begin();
    void handle();

private:
    ControlController controlController;
    DisplayMenuController displayMenuController;
    WifiController wifiController;
};


#endif //ESP_MANAGER_H
