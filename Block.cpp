//
//  Block.cpp
//  SDL_REAL
//
//  Created by ShiLin on 1/15/17.
//  Copyright © 2017 lin. All rights reserved.
//

#include "Block.hpp"

Block::Block(SDL_Renderer *renderTarget, int blockWidth, int blockHeight, int posX, int posY, Uint8 r, Uint8 g, Uint8 b){
    this -> renderTarget = renderTarget;
    this -> posX = posX;
    this -> posY = posY;
    this -> blockWidth = blockWidth;
    this -> blockHeight = blockHeight;
    this -> r = r;
    this -> g = g;
    this -> b = b;
}

Block::~Block() {
}

bool Block::Update() {
    desRect = {this -> posX, this -> posY, this -> blockWidth, this -> blockHeight};
    return Draw();
}

bool Block::Draw() {
    SDL_SetRenderDrawColor(renderTarget, r, g, b, 255);
    SDL_RenderFillRect(renderTarget, &desRect);
    return true;
}
