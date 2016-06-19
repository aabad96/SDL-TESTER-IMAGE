
//
//  Multiventana.h
//  PRUEBA MULTIVENTANA
//
//  Created by Alejandro Abad Martínez on 15/6/16.
//  Copyright © 2016 Alejandro Abad Martínez. All rights reserved.
//

#ifndef FUNCIONES_IMAGEN_H
#define FUNCIONES_IMAGEN_H
#include <iostream>
#include <fstream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>

//inicializa SDL
SDL_Window* init_ventana();

SDL_Surface* loadMedia_gtool();

SDL_Surface* loadMedia_gradiografia(std::string range);

SDL_Renderer *Init_Render(SDL_Window *window);

SDL_Texture* textura_gtool(SDL_Renderer* render);

void cargar_texturas(SDL_Renderer *render,std::string Path,SDL_Texture* text_gradiografia, SDL_Texture* text_gtool, SDL_Rect &srcrect,  SDL_Rect &dstrect);

SDL_Texture* textura_gradiografia(SDL_Renderer* render, std::string range);
#endif /* Multiventana_h */
