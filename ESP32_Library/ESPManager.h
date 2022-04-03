//
// Created by iange on 03.04.2022.
//

#ifndef ESPMANAGER_H
#define ESPMANAGER_H

#include "ControlController.h"
#include "DisplayMenu.h"
#include "Arduino.h"

class ESPManager {
public:
    ESPManager();
    ~ESPManager();

    void begin();
    void handle();

private:
    ControlController controller;
    DisplayMenu display;
};


#endif //ESPMANAGER_H
