#ifndef OPERACIONES_TRAZADO_DESHACER_H
#define OPERACIONES_TRAZADO_DESHACER_H

#include <SDL.h>
#include "T_Coords.h"
#include "T_PilaDatos.h"
#include "Calculos_Trazado.h"
#include "Funciones_Imagen.h"
bool Operate_First_Point(SDL_Renderer *render,T_PilaDatos Image_Buffer,const int &MAX_HEIGHT,const char * Path_s,SDL_Texture* Radio_o,SDL_Texture* Toolb_o,SDL_Rect* Src,SDL_Rect *Dst);
bool Operate_Second_Point(SDL_Renderer *render,T_PilaDatos Image_Buffer,const int &MAX_HEIGHT,const char * Path_s,SDL_Texture* Radio_o,SDL_Texture* Toolb_o,SDL_Rect* Src,SDL_Rect *Dst);
bool Recuperar_Trazados(T_PilaDatos Img_Buffer, SDL_Renderer *Renderer,const int &MAX_HEIGHT,const char * Path,SDL_Texture* Radio,SDL_Texture* Toolb,SDL_Rect* Src,SDL_Rect *Dst);

#endif // OPERACIONES_TRAZADO_DESHACER_H
