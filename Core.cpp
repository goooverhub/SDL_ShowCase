//
//  Core.cpp
//  SDL_REAL
//
//  Created by ShiLin on 12/31/16.
//  Copyright © 2016 lin. All rights reserved.
//

#include <iostream>
#include <SDL2/SDL.h>
#include "Core.hpp"

SCore::SCore(int windowWidth, int windowHeight) {
    this -> windowWidth = windowWidth;
    this -> windowHeight = windowHeight;
    bool success = true;
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "Error in sdl_init: " << SDL_GetError() << std::endl;
        success = false;
    } else {
        mainWindow = SDL_CreateWindow("SDL_REAL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight, SDL_WINDOW_SHOWN);
        
        if (mainWindow == NULL) {
            std::cout << "Error in sdl_createwindow" << SDL_GetError() << std::endl;
            success = false;
        }
        
    }
    
    renderTarget = SDL_CreateRenderer(mainWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    
    character = new Character(renderTarget);
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
    
    background = SDL_LoadBMP("background.bmp");
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
        std::cout << "Ddelta " << delta << std::endl;

        int st = 0;
        
        SDL_RenderClear(renderTarget);
        
        character -> Update(keyState, delta);
        
        SDL_RenderCopy(renderTarget, bgTexture, NULL, NULL);
        st = character -> Draw(renderTarget);
        
        
        SDL_RenderPresent(renderTarget);

    }
}

int SCore::GetWindowWidth() {
    return windowWidth;
}

int SCore::GetWindowHeight() {
    return windowHeight;
}

