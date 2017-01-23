//
//  Block.hpp
//  SDL_REAL
//
//  Created by ShiLin on 1/15/17.
//  Copyright © 2017 lin. All rights reserved.
//

#ifndef Block_hpp
#define Block_hpp

#include <stdio.h>
#include <SDL2/SDL.h>

class Block {
    
    SDL_Renderer *renderTarget;
    
    SDL_Rect sourceRect;
    SDL_Rect desRect;
    
    Uint8 r;
    Uint8 g;
    Uint8 b;
    
    int posX;
    int posY;
    
    int blockWidth;
    int blockHeight;
    
public:
    
    Block(SDL_Renderer *renderTarget, int blockWidth, int blockHeight, int posX, int posY, Uint8 r, Uint8 g, Uint8 b);
    ~Block();
    
    bool Update();
    bool Draw();
    
};

#endif /* Block_hpp */
