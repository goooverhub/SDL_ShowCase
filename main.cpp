//
//  main.cpp
//  SDL_REAL
//
//  Created by ShiLin on 12/31/16.
//  Copyright © 2016 lin. All rights reserved.
//

#include <iostream>
#include "Core.hpp"
#include "Config.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    
    Config *config = new Config(800,800);
    
    SCore *Core = new SCore(config -> GetMainWindowWidth(), config -> GetMainWindowHeight());
    
    Core->StartMainLoop();
    
    SDL_Quit();
    return 0;
}
