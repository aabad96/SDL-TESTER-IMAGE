#include "T_Dato.h"
T_Dato::T_Dato(SDL_Texture* D_Texture, Buffer_State D_State)
{
    Textura = D_Texture;
    Estado_Textura = D_State;
    //ctor
}

T_Dato::~T_Dato()
{
    //dtor
}
void T_Dato :: Set_Textura(SDL_Texture* Nw_Textura)
{
   Textura = Nw_Textura;
}
SDL_Texture* T_Dato :: Get_Textura (void)
{
    return Textura;
}
void T_Dato :: Set_Estado (Buffer_State Nw_Estado)
{
    Estado_Textura = Nw_Estado;
}
Buffer_State T_Dato :: Get_Estado(void)
{
    return Estado_Textura;
}
