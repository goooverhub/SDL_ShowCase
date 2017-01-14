//
//  Character.cpp
//  SDL_REAL
//
//  Created by ShiLin on 1/13/17.
//  Copyright © 2017 lin. All rights reserved.
//
#include <iostream>
#include "Character.hpp"
#include "Core.hpp"

Character::Character(SDL_Renderer *renderTarget) {
    SDL_Surface *temp = SDL_LoadBMP("character.bmp");
    int res = SDL_SetColorKey(temp, SDL_TRUE, SDL_MapRGB(temp->format, 255, 0, 255));
    if (res < 0) {
        std::cout << res << SDL_GetError() << std::endl;
    }
    characterTexture = SDL_CreateTextureFromSurface(renderTarget, temp);
    SDL_FreeSurface(temp);
    SDL_QueryTexture(characterTexture, NULL, NULL, &originalWidth, &originalHeight);
    posX = 0;
    posY = 0;
    renderPosX = 0;
    renderPosY = 0;
    speed = 200.0f;
    fitWidth = originalWidth/6;
    fitHeight = originalHeight/8;
    sourceRect = {renderPosX, renderPosY, fitWidth, fitHeight};
    desRect = {posX, posY, fitWidth, fitHeight};
    
    frameCounter = 0;
}

Character::~Character() {
}

bool Character::Update(const Uint8 *keyState, float delta) {
    
    if (frameCounter >= 0.16666f) {
        frameCounter = 0;
        renderPosX += fitWidth;
        if (renderPosX > originalWidth - fitWidth)
        {
            renderPosX = 0;
        }
    } else {
        frameCounter += delta;
    }
    
    if (keyState[SDL_SCANCODE_D]) {
//        std::cout << "D" << speed*delta << std::endl;
        posX = posX >= (800  - fitWidth) ? (800  - fitWidth) : (posX + speed*delta);
        renderPosY = 2 * fitHeight;
    }
    
    else if (keyState[SDL_SCANCODE_A]) {
        
        posX = posX <= 0 ? 0 : (posX - speed*delta);
        renderPosY = 1 * fitHeight;
    }
    
    else if (keyState[SDL_SCANCODE_S]) {
        posY = posY >= (800 - fitHeight) ? (800 - fitHeight) : (posY + speed*delta);
        renderPosY = 0 * fitHeight;
    }
    
    else if (keyState[SDL_SCANCODE_W]) {
        posY = posY <= 0 ? 0 : (posY - speed*delta);
        renderPosY = 3 * fitHeight;
    }
    
    else {
        
    }
    
    desRect = {posX, posY, fitWidth, fitHeight};
    sourceRect = {renderPosX, renderPosY, fitWidth, fitHeight};
    return true;
}

bool Character::Draw(SDL_Renderer *renderTarget) {
    bool res = SDL_RenderCopy(renderTarget, characterTexture, &sourceRect, &desRect);
    return res;
}
