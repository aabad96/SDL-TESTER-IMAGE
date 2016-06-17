//
//  Multiventana.h
//  PRUEBA MULTIVENTANA
//
//  Created by Alejandro Abad Martínez on 15/6/16.
//  Copyright © 2016 Alejandro Abad Martínez. All rights reserved.
//

#ifndef Multiventana_h
#define Multiventana_h

//inicializa SDL
SDL_Window* init_ventana();

SDL_Surface* loadMedia_gtool();

SDL_Surface* loadMedia_glina(const char *range);

SDL_Texture* textura_gtool(SDL_Renderer* render);

void cargar_texturas( SDL_Texture* text_glina, SDL_Texture* text_gtool, SDL_Rect * srcrect,  SDL_Rect * dstrect);

SDL_Texture* textura_glina(SDL_Renderer* render, const char *range);



#endif /* Multiventana_h */
