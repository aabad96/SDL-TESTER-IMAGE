//
//  Texto.h
//  texto_donde queramos
//
//  Created by Adrian on 18/6/16.
//  Copyright © 2016 Adrian. All rights reserved.
//

#ifndef FUNCIONES_TEXTO_H
#define FUNCIONES_TEXTO_H

#include <string>
#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include "cleanup.h"
#include <sstream>
SDL_Texture* tex_medidaca1(long double ca1,SDL_Renderer *ren);
SDL_Texture* tex_medidaca2(long double ca2, SDL_Renderer *ren);
std::string ToString(double cal);
SDL_Texture* renderText(const std::string &message, const std::string &fontFile, SDL_Color color,
                        int fontSize, SDL_Renderer *renderer);
void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, SDL_Rect *clip);
void Load_renderTexture(SDL_Texture *tex,SDL_Renderer *ren,SDL_Rect *DstR,SDL_Rect *clip_r);

const int posicion1x=734;//Posicion x del primer calculo
const int posicion1y=15;// posiccion y del primer calculo
const int posicion2x=734;// posicion x del segundo calculo
const int posicion2y=46;// posicion y del segundo calculo

#endif /* Texto_h */
