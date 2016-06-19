//
//  Funciones_Texto.cpp
//  texto_donde queramos
//
//  Created by Adrian on 14/6/16.
//  Copyright � 2016 Adrian. All rights reserved.
//
#include "Funciones_Texto.h"


void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, SDL_Rect *clip){
    SDL_Rect dst;
    dst.x = x;
    dst.y = y;
    if (clip != nullptr){
        dst.w = clip->w;
        dst.h = clip->h;
    }
    else {
        SDL_QueryTexture(tex, NULL, NULL, &dst.w, &dst.h);
    }
    Load_renderTexture(tex, ren, &dst, clip);
}
void Load_renderTexture(SDL_Texture *tex,SDL_Renderer *ren,SDL_Rect * DstR,SDL_Rect *clip_r){
    SDL_RenderCopy(ren,tex,DstR,clip_r);
}
std::string ToString(double cal) //devuelve un string a partir de un double
{
    std:: string out;
    std:: ostringstream ss;
    ss << cal;
    out = ss.str();
    return out;
}
SDL_Texture* tex_medidaca1(long double ca1,SDL_Renderer *ren){

    long double aux_cal1=ca1;
    std:: string calculo1;
    calculo1=ToString(aux_cal1);

    SDL_Color color={255,255,255,255};
    SDL_Texture *imagen;
    imagen = renderText(calculo1,"amble-bold.ttf",color,20,ren); //devuelve un puntero como textura, descargar fuente en el proyecto y enviarla en la carpeta //
    return imagen;
}
SDL_Texture* tex_medidaca2(long double ca2,SDL_Renderer *ren){

    long double aux_cal2=ca2;
    std:: string calculo2, calculoT;
    calculo2=ToString(aux_cal2);

    SDL_Color color={255,255,255,255};
    SDL_Texture *picture;
    picture = renderText(calculo2,"/04-SDL_image/amble-bold.ttf",color,20,ren); //devuelve un puntero como textura, descargar fuente en el proyecto y enviarla en la carpeta //
    return picture;
}
SDL_Texture* renderText(const std::string &message, const std::string &fontFile, SDL_Color color,
                        int fontSize, SDL_Renderer *renderer)
{
    //Open the font
    TTF_Font *font = TTF_OpenFont("amble-bold.ttf", fontSize);
    if (font == nullptr){
        std::cout<<"Error TTF_OpenFont"<<std::endl;
        return nullptr;
    }
    //We need to first render to a surface as that's what TTF_RenderText returns, then
    //load that surface into a texture
    SDL_Surface *surf = TTF_RenderText_Blended(font, message.c_str(), color);
    if (surf == nullptr){
        TTF_CloseFont(font);
        std::cout<<"Error TTF_RenderText"<<std::endl;
        return nullptr;
    }
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surf);
    if (texture == nullptr){
        std::cout<<"Error CreateTexture"<<std::endl;
    }
    //Clean up the surface and font
    SDL_FreeSurface(surf);
    TTF_CloseFont(font);
    return texture;
}
