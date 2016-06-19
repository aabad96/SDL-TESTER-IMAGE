#ifndef T_PILADATOS_H
#define T_PILADATOS_H
#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include <iostream>
#include "T_Dato.h"
using namespace std;

class T_PilaDatos
{
    public:
        T_PilaDatos(void);
        bool Pila_Vacia(void);
        bool Insertar_Dato(T_Dato Nw_Dato);
        T_Dato Buscar_Dato(int Pos_Pila);
        T_Dato Primer_Dato(void);
        T_Dato Ultimo_Dato(void);
        T_Dato Siguiente(int Pos_Pila);
        T_Dato Anterior (int Pos_Pila);
        int Buscar_Estado(Buffer_State Estado_Img);
        void Modificar_Dato(Buffer_State Nw_Estado, Sint32 Nw_x,Sint32 Nw_y, int Pos_Pila);
        int Cantidad_Estado(Buffer_State Estado_Img, int Pos_Pila);
        bool Borrar_Dato(void);
        bool Vaciar_Pila(void);
        int Tam_Pila_Datos(void);
    protected:

    private:
        vector<T_Dato> Pila_Carga;

};

#endif // T_PILADATOS_H
