#ifndef OPERACIONES_TRAZADO_DESHACER_H
#define OPERACIONES_TRAZADO_DESHACER_H
#include <SDL.h>
#include "T_Coords.h"
#include "T_PilaDatos.h"
bool Operate_First_Point(SDL_Renderer *render,T_PilaDatos Image_Buffer,const int &MAX_HEIGHT);
bool Recuperar_Trazados(T_PilaDatos Img_Buffer, SDL_Renderer *Renderer,const int &MAX_HEIGHT);

#endif // OPERACIONES_TRAZADO_DESHACER_H
