//
//  Core.cpp
//  SDL_REAL
//
//  Created by ShiLin on 12/31/16.
//  Copyright © 2016 lin. All rights reserved.
//

#include <iostream>
#include <stdint.h>
#include "Core.hpp"

SCore::SCore(int windowWidth, int windowHeight) {
    this -> windowWidth = windowWidth;
    this -> windowHeight = windowHeight;
    bool success = true;
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "Error in sdl_init: " << SDL_GetError() << std::endl;
        success = false;
    } else {
        TTF_Init();
        IMG_Init(IMG_INIT_PNG);
        
        mainWindow = SDL_CreateWindow("SDL_REAL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight, SDL_WINDOW_SHOWN);
        
        if (mainWindow == NULL) {
            std::cout << "Error in sdl_createwindow" << SDL_GetError() << std::endl;
            success = false;
        }
        
    }
    
    renderTarget = SDL_CreateRenderer(mainWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    
    character = new Character(renderTarget);
    text = new Texts(renderTarget, "HELLO FRIENDS");
    
}

SCore::~SCore() {
    SDL_FreeSurface(windowSurface);
    windowSurface = nullptr;
    
    SDL_DestroyWindow(mainWindow);
    mainWindow = nullptr;
}


void SCore::StartMainLoop() {
    int currentTime = 0;
    int prevTime = 0;
    float delta = 0.0f;
    const Uint8 *keyState;
    SDL_Surface* background;
    
    background = IMG_Load("full.png");
    bgTexture = SDL_CreateTextureFromSurface(renderTarget, background);
    SDL_FreeSurface(background);
    
    while (!quit) {
        while(SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
            
        }
        keyState = SDL_GetKeyboardState(NULL);
        prevTime = currentTime;
        currentTime = SDL_GetTicks();
        
        delta = (currentTime - prevTime) / 1000.0f;

        int st = 0;
        
        SDL_SetRenderDrawColor(renderTarget, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(renderTarget);
        
        SDL_RenderCopy(renderTarget, bgTexture, NULL, NULL);
        character -> Update(keyState, delta);
        st = character -> Draw(renderTarget);
        text -> Update("fps: " + std::to_string((int)(1/delta)), delta);
        
        SDL_RenderPresent(renderTarget);

    }
}

int SCore::GetWindowWidth() {
    return windowWidth;
}

int SCore::GetWindowHeight() {
    return windowHeight;
}

