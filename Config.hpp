//
//  Config.hpp
//  SDL_REAL
//
//  Created by ShiLin on 1/1/17.
//  Copyright © 2017 lin. All rights reserved.
//

#ifndef Config_hpp
#define Config_hpp

#include <stdio.h>

#endif /* Config_hpp */

class Config {
    
    static int mainWindowWidth;
    
    static int mainWindowHeight;
    
public:
    
    Config();
    
    Config(int customWindowWidth, int customWindowHeight);
    
    ~Config();
    
    int GetMainWindowWidth();
    
    int GetMainWindowHeight();
    
};
