#ifndef COMP_BOTON_H
#define COMP_BOTON_H
#include <iostream>
#include <vector>
#include "T_ToolbarButton.h"
#include "T_Coords.h"
#include "T_Dato.h"
std::vector <T_ToolbarButton> vec_botones(void);
int Clik_Boton(std::vector <T_ToolbarButton> &botones, T_Coords Coordenadas_comp);


#endif
