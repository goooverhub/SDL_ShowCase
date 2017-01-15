//
//  Texts.hpp
//  SDL_REAL
//
//  Created by ShiLin on 1/14/17.
//  Copyright © 2017 lin. All rights reserved.
//

#ifndef Texts_hpp
#define Texts_hpp

#include <iostream>
#include <stdio.h>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2_ttf/SDL_ttf.h>

#endif /* Texts_hpp */


class Texts {
    
    SDL_Surface *textSurface;
    SDL_Texture *textTexture;
    TTF_Font *font;
    int fontSize;
    SDL_Color   textColor;
    SDL_Rect descRect;
    
    int textureWidth;
    int textureHeight;
    
public:
    Texts(SDL_Renderer *renderTarget, std::string text);
    ~Texts();
    bool Update(std::string text);
    bool Draw(SDL_Renderer *renderTarget);
};
