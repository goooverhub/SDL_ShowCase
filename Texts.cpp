//
//  Texts.cpp
//  SDL_REAL
//
//  Created by ShiLin on 1/14/17.
//  Copyright © 2017 lin. All rights reserved.
//

#include "Texts.hpp"

Texts::Texts(SDL_Renderer *renderTarget, std::string text){
    this -> renderTarget = renderTarget;
    textColor = {255, 0, 0};
    fontSize = 12;
    font = TTF_OpenFont("Hack-Bold.ttf", fontSize);
    textSurface = TTF_RenderText_Solid(font, text.c_str(), textColor);
    textTexture = SDL_CreateTextureFromSurface(renderTarget, textSurface);
    SDL_FreeSurface(textSurface);
    SDL_QueryTexture(textTexture, 0, 0, &textureWidth, &textureHeight);
    content = "n/a";
    updateBase = 0.5;
}

Texts::~Texts(){
    
}

bool Texts::Update(std::string text, float delta) {
    
    if (updateCounter >= updateBase) {
        updateCounter = 0;
        content = text;
    } else {
        updateCounter += delta;
    }

    textSurface = TTF_RenderText_Solid(font, content.c_str(), textColor);
    if (textTexture != NULL) {
        SDL_DestroyTexture(textTexture);
        textTexture = nullptr;
    }
    textTexture = SDL_CreateTextureFromSurface(this -> renderTarget, textSurface);
    SDL_FreeSurface(textSurface);
    SDL_QueryTexture(textTexture, 0, 0, &textureWidth, &textureHeight);
    this -> Draw();

    return true;
}

bool Texts::Draw() {
    descRect = {Config::mainWindowWidth - textureWidth, Config::mainWindowHeight - textureHeight, textureWidth, textureHeight};
    SDL_RenderCopy(this -> renderTarget, textTexture, NULL, &descRect);
    return true;
}
