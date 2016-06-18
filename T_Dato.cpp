#include "T_Dato.h"

T_Dato :: T_Dato()
{

    Estado_Render = Init_Image;
    //ctor
}

void T_Dato ::  set_Coords(Sint32 nw_x,Sint32 nw_y)
{
    Coordenadas_Trazado.set_xPos(nw_x);
    Coordenadas_Trazado.set_yPos(nw_y);
}

T_Coords T_Dato :: get_Coords(void)
{
    return Coordenadas_Trazado;
}

void T_Dato :: set_Estado(Buffer_State Nw_Estado)
{
    Estado_Render = Nw_Estado;
}

Buffer_State T_Dato ::  get_Estado(void)
{
    return Estado_Render;
}

