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
    this -> renderTarget = renderTarget;
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
    bulletDelay = 0.1f;
    bulletDelayCount = 0.0f;
    shotSpeed = 0.0f;
    shotSpeedBase = 500.0f;
    range = 100.0f;
    fitWidth = originalWidth/6;
    fitHeight = originalHeight/8;
    displayBase = 1.5f;
    displayWidth = fitWidth * displayBase;
    displayHeight = fitHeight * displayBase;
    sourceRect = {renderPosX, renderPosY, fitWidth, fitHeight};
    desRect = {posX, posY, displayWidth, displayHeight};
    bullet = new Bullet(0, 0, this -> renderTarget, -1, range);
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
        posX = posX >= (800  - fitWidth) ? (800  - fitWidth) : (posX + speed*delta);
        renderPosY = 2 * fitHeight;
    }
    if (keyState[SDL_SCANCODE_A]) {
        posX = posX <= 0 ? 0 : (posX - speed*delta);
        renderPosY = 1 * fitHeight;
    }if (keyState[SDL_SCANCODE_S]) {
        posY = posY >= (800 - fitHeight) ? (800 - fitHeight) : (posY + speed*delta);
        renderPosY = 0 * fitHeight;
    }
    if (keyState[SDL_SCANCODE_W]) {
        posY = posY <= 0 ? 0 : (posY - speed*delta);
        renderPosY = 3 * fitHeight;
    }
    
    int temp_direction = -1;
    
    if (keyState[SDL_SCANCODE_RIGHT]) {
        temp_direction = 2;
    }
    else if (keyState[SDL_SCANCODE_LEFT]) {
        temp_direction = 0;
    }
    else if (keyState[SDL_SCANCODE_UP]) {
        temp_direction = 1;
    }
    else if (keyState[SDL_SCANCODE_DOWN]) {
        temp_direction = 3;
    }
    
    if (temp_direction != -1 && bulletDelayCount >= bulletDelay) {
        bulletDelayCount = 0;
        BulletProperty temp_bulletPropery = {posX + (displayWidth - bullet -> GetFitWidth())/2, posY + (displayHeight - bullet -> GetFitHeight())/2, temp_direction};
        bulletArray.push_back(temp_bulletPropery);
    } else {
        bulletDelayCount += delta;
    }
    
    desRect = {posX, posY, displayWidth, displayHeight};
    sourceRect = {renderPosX, renderPosY, fitWidth, fitHeight};
    shotSpeed = delta * shotSpeedBase;
    UpdateBullet();
    return true;
}

bool Character::UpdateBullet() {
    for (int i = 0; i < bulletArray.size(); i ++) {
        bullet -> Update(shotSpeed, bulletArray[i].direction, &bulletArray[i].posX, &bulletArray[i].posY);
        bool result = bullet -> Draw(renderTarget);
        if(!result) {
            bulletArray.erase(bulletArray.begin() + i);
        }
    }
    return true;
}

bool Character::Draw(SDL_Renderer *renderTarget) {
    bool res = SDL_RenderCopy(renderTarget, characterTexture, &sourceRect, &desRect);
    return res;
}
