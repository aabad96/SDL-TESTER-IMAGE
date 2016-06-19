#ifndef OPERACIONES_TRAZADO_DESHACER_H
#define OPERACIONES_TRAZADO_DESHACER_H

#include <SDL.h>
#include "T_Coords.h"
#include "T_PilaDatos.h"
#include "T_Calculo.h"
#include "Comp_boton.h"
#include "Calculos_Trazado.h"
#include "Funciones_Imagen.h"
#include "Funciones_Texto.h"

void Draw_Aspa (SDL_Renderer * render,T_Coords center);
bool Operate_First_Point(std::vector<T_ToolbarButton> Botones,T_Calculo &Calcs_Traz,SDL_Renderer *render,T_PilaDatos &Image_Buffer,const int &MAX_HEIGHT,std::string Path_s,SDL_Texture* Radio_o,SDL_Texture* Toolb_o,SDL_Rect &Src,SDL_Rect &Dst);
bool Operate_Second_Point(std::vector<T_ToolbarButton> Botones,T_Calculo &Calcs_Traz,SDL_Renderer *render,T_PilaDatos &Image_Buffer,const int &MAX_HEIGHT,std::string Path_s,SDL_Texture* Radio_o,SDL_Texture* Toolb_o,SDL_Rect &Src,SDL_Rect &Dst);
bool Deshacer_Todos_Trazados(const int &flag_Undo,T_PilaDatos &Img_Buffer,T_Calculo &Calcs_Traz,SDL_Renderer *Renderer,std::string Path,SDL_Texture* Radio,SDL_Texture* Toolb,SDL_Rect &Src,SDL_Rect &Dst,const int &MAX_HEIGHT);
bool Recuperar_Trazados(T_PilaDatos &Img_Buffer,T_Calculo &Calcs_Traz, SDL_Renderer *Renderer,const int &MAX_HEIGHT,std::string Path,SDL_Texture* Radio,SDL_Texture* Toolb,SDL_Rect &Src,SDL_Rect &Dst);

#endif // OPERACIONES_TRAZADO_DESHACER_H
