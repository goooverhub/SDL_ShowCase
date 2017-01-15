//
//  Character.hpp
//  SDL_REAL
//
//  Created by ShiLin on 1/13/17.
//  Copyright © 2017 lin. All rights reserved.
//

#ifndef Character_hpp
#define Character_hpp

#include <stdio.h>
#include <SDL2/SDL.h>
#include "Bullet.hpp"
#include <vector>

class Character {
    
    SDL_Texture *characterTexture;
    SDL_Rect sourceRect;
    SDL_Rect desRect;
    SDL_Renderer *renderTarget;
    
    int originalWidth;
    int originalHeight;
    
    int fitWidth;
    int fitHeight;
    
    int posX;
    int posY;
    
    int renderPosX;
    int renderPosY;
    
    float speed;
    float range;
    float bulletDelay;
    
    float frameCounter;
    
    std::vector<Bullet *> bulletArray;
    
public:
    Character(SDL_Renderer *renderTarget);
    ~Character();
    bool Update(const Uint8 *keyState, float delta);
    bool UpdateBullet();
    bool Draw(SDL_Renderer *renderTarget);
};

#endif /* Character_hpp */


