//
//  Funciones_Imagen.cpp
//
//
//  Created by Alejandro Abad Martínez on 15/6/16.
//  Copyright © 2016 Alejandro Abad Martínez. All rights reserved.
//


#include "Funciones_Imagen.h"


//Screen dimension constants
const int SCREEN_WIDTH = 791;
const int SCREEN_HEIGHT = 512;
/*
 Source_crect.x = 0;
 Source_rect.y = 0;
 Source_rect.w = 3166;
 Source_rect.h = 1534;
 Destin_rect.x = 0;
 Destin_rect.y = 77;
 Destin_rect.w = 791;
 Destin_rect.h = 435;
 */





SDL_Window* init_ventana(){

    //iniciamos flag
    SDL_Window* success = NULL;

    //inicializamos SDL
    if( SDL_Init( SDL_INIT_VIDEO ) != 0 ){
        printf( "SDL no pudo inicializarse! SDL_Error: %s\n", SDL_GetError() );

    }
    else
    {
        //Creamos ventana
        success = SDL_CreateWindow( "Programa ONPI", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );

    }
    return success;
}
SDL_Renderer *Init_Render(SDL_Window *window){
    SDL_Renderer *Aux_rend = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (Aux_rend == nullptr){
        SDL_DestroyWindow(window); // SDL_DestroyWindow(win);
        std::cerr << "Error 2: No se pudo crear la textura. Cerrando... " << SDL_GetError() << std::endl;
        SDL_Quit();
        return NULL;
    }else{
        return Aux_rend;
    }
}
//imagen que se va a pasar
SDL_Surface* loadMedia_gtool(void)
{
    //imagen que se va a pasar
    SDL_Surface* gtool ;

    //cargamos imagenes
    gtool = IMG_Load("toolbar");
    return gtool;
}

//imagen que se va a pasar
SDL_Surface* loadMedia_gradiografia(const char *range)
{
    //imagen que se va a pasar
    SDL_Surface* gradiografia;

    //cargamos imagenes

    gradiografia = IMG_Load(range);

    if (gradiografia==NULL) {
        std::cout<<"sere fea"<<std::endl;
    }
    return gradiografia;
}

SDL_Texture* textura_gradiografia(SDL_Renderer* render, const char *range){
    //surface de la ventana
    SDL_Surface* media_gradiografia;


    SDL_Texture* t_gradiografia=NULL;

    media_gradiografia=loadMedia_gradiografia(range);


    if (media_gradiografia==NULL) {
        std::cout<< "Error no se pudo cargar la imagen1"<<std::endl;
    }else t_gradiografia= SDL_CreateTextureFromSurface(render, media_gradiografia);

    SDL_FreeSurface(media_gradiografia);
    return t_gradiografia;

}SDL_Texture* textura_gtool(SDL_Renderer* render){
    SDL_Surface* media_gtool=NULL;
     SDL_Texture* t_gtool=NULL;
    media_gtool=loadMedia_gtool();

    if (media_gtool==NULL){
        std::cout<< "Error no se pudo cargar la imagen2"<<std::endl;
    }
    t_gtool= SDL_CreateTextureFromSurface(render, media_gtool);
    SDL_FreeSurface(media_gtool);
    return t_gtool;
}


void cargar_texturas(SDL_Renderer *render,const char *Path,SDL_Texture* text_gradiografia, SDL_Texture* text_gtool, SDL_Rect * srcrect,  SDL_Rect * dstrect)
{
    SDL_Texture* t_gradiografia=NULL;
    SDL_Texture* t_gtool=NULL;
    t_gtool=textura_gtool(render);
    t_gradiografia=textura_gradiografia(render, Path);

    SDL_RenderClear(render);
    SDL_RenderCopy(render,t_gtool , NULL, NULL);
    SDL_RenderCopy(render, t_gradiografia, srcrect, dstrect);
    SDL_RenderPresent(render);


}
