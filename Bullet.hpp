//
//  Bullet.hpp
//  SDL_REAL
//
//  Created by ShiLin on 1/14/17.
//  Copyright © 2017 lin. All rights reserved.
//

#ifndef Bullet_hpp
#define Bullet_hpp

#include <stdio.h>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include "Config.hpp"

#endif /* Bullet_hpp */

class Bullet {
    
    SDL_Surface *bulletSurface;
    SDL_Texture *bulletTexture;
    
    int posX;
    int posY;
    
    int fitWidth;
    int fitHeight;
    
    int originWidth;
    int originHeight;
    
    int direction;
    int speed;
    int range;
    
    bool dead;
    
    SDL_Rect sourceRect;
    SDL_Rect desRect;
    
public:
    Bullet(int posX, int posY, SDL_Renderer *renderTarget, int direction, int range);
    ~Bullet();
    
    bool Update(float shotSpeed, int direction, int *posX, int *posY);

    bool Draw(SDL_Renderer *renderTarget);
    
    int GetFitWidth();
    int GetFitHeight();
    
};

struct BulletProperty {
    int posX;
    int posY;
    int direction;
};
