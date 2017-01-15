//
//  Texts.cpp
//  SDL_REAL
//
//  Created by ShiLin on 1/14/17.
//  Copyright © 2017 lin. All rights reserved.
//

#include "Texts.hpp"

Texts::Texts(SDL_Renderer *renderTarget, std::string text){
    textColor = {0, 0, 0};
    fontSize = 20;
    font = TTF_OpenFont("Hack-Bold.ttf", fontSize);
    textSurface = TTF_RenderText_Solid(font, text.c_str(), textColor);
    textTexture = SDL_CreateTextureFromSurface(renderTarget, textSurface);
    SDL_FreeSurface(textSurface);
    SDL_QueryTexture(textTexture, 0, 0, &textureWidth, &textureHeight);
}

Texts::~Texts(){
    
}

bool Texts::Update(std::string text) {
    return true;
}

bool Texts::Draw(SDL_Renderer *renderTarget) {
    descRect = {800 - textureWidth, 800 - textureHeight, textureWidth, textureHeight};
    SDL_RenderCopy(renderTarget, textTexture, NULL, &descRect);
    return true;
}
