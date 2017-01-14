//
//  Config.cpp
//  SDL_REAL
//
//  Created by ShiLin on 1/1/17.
//  Copyright © 2017 lin. All rights reserved.
//

#include "Config.hpp"

int Config::mainWindowWidth = 640;

int Config::mainWindowHeight = 320;

Config::Config() {
    mainWindowWidth = 640;
    mainWindowHeight = 320;
}

Config::Config(int customWindowWidth, int customWindowHeight) {
    mainWindowHeight = customWindowHeight;
    mainWindowWidth = customWindowWidth;
}

Config::~Config() {

}

int Config::GetMainWindowWidth() {
    return mainWindowWidth;
}

int Config::GetMainWindowHeight() {
    return mainWindowHeight;
}
