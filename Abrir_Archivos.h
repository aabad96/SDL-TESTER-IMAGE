#ifndef ABRIR_ARCHIVOS_H
#define ABRIR_ARCHIVOS_H
#include <iostream>
#include <string>
#include "Funciones_Imagen.h"

std::string Pedir_Archivo(void);
std::string ID_Paciente(std::string path_name);
const char * Path_Modificado(std::string Path_name);
SDL_Texture *Abrir_Archivo(std::string Path_name,SDL_Renderer *Render,SDL_Texture *Toolbar,SDL_Rect &Source_Rect,SDL_Rect &Dest_Rect);

#endif
