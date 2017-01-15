//
//  Core.hpp
//  SDL_REAL
//
//  Created by ShiLin on 12/31/16.
//  Copyright © 2016 lin. All rights reserved.
//

#ifndef Core_hpp
#define Core_hpp

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include "Character.hpp"
#include "Texts.hpp"

class SCore {
    
    int windowWidth;
    int windowHeight;
    
    bool quit = false;
    
    SDL_Event event;
    
    SDL_Renderer *renderTarget;
    
    SDL_Texture *texture;
    SDL_Texture *bgTexture;
    
    SDL_Rect srcRect;
    SDL_Rect desRect;
    
    SDL_Window *mainWindow;
    SDL_Surface *windowSurface;
    
    Character *character;
    Texts *text;
    
public:
    
    SCore(int windowWidth, int windowHeight);
    
    ~SCore();
    
    void StartMainLoop();
    
    int GetWindowWidth();
    
    int GetWindowHeight();
    
};

#endif /* Core_hpp */
