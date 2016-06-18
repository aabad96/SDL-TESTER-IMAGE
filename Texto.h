//
//  Texto.h
//  texto_donde queramos
//
//  Created by Adrian on 18/6/16.
//  Copyright © 2016 Adrian. All rights reserved.
//

#ifndef Texto_h
#define Texto_h
SDL_Texture* tex_medidaca1(long double ca1,SDL_Renderer *ren);
SDL_Texture* tex_medidaca2(long double ca2, SDL_Renderer *ren);
SDL_Texture* renderText(const std::string &message, const std::string &fontFile, SDL_Color color,
                        int fontSize, SDL_Renderer *renderer);
void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, SDL_Rect dst, SDL_Rect *clip = nullptr){
    SDL_RenderCopy(ren, tex, clip, &dst);
}

const int posicion1x=734;//Posicion x del primer calculo
const int posicion1y=15;// posiccion y del primer calculo
const int posicion2x=734;// posicion x del segundo calculo
const int posicion2y=46;// posicion y del segundo calculo

#endif /* Texto_h */
