#ifndef T_DATO_H
#define T_DATO_H
#include<SDL.h>
#include"T_Coords.h"
#include<SDL_image.h>
enum Buffer_State {first_Point_OP1,first_Point_OP2,first_Point_OP3,
second_Point_OP1,second_Point_OP2,second_Point_OP3,second_Point_OP4,second_Point_OP5,second_Point_OP6,second_Point_End,
Init_Image};
/*
    first_Point_O P1: Punto del Agujero Mentoniano, que genera una recta una vez trazado
    first_Point_OP2: Primer punto de calculo del Grosor_1
    first_Point_OP3: Segundo punto de calculo del Grosor_1
    second_Point_OP1: Primer punto de la primera recta tangente del Cuerpo Mandibular
    second_Point_OP2: Segundo punto de la primera recta tangente del Cuerpo Mandibular
    second_Point_OP3: Primer punto de la segunda recta tangente del Cuerpo Mandibular
    second_Point_OP4: Segundo punto de la segunda recta tangente del Cuerpo Mandibular, traza la bisectriz automática
    second_Point_OP5: Primer punto de calculo del Grosor_2, en la bisectriz
    second_Point_OP6: Segundo punto de calculo del Grosor_2
    second_Point_End: Flag que activa el finalizado del segundo trazado, habilita el guardado en un fichero
    Init_Image: Imagen inicial, para activar el flag del botón Deshacer_Todo
*/
class T_Dato
{
    public:
        T_Dato();
        void set_Coords(Sint32 nw_x,Sint32 nw_y);
        T_Coords get_Coords(void);
        void set_Estado(Buffer_State Nw_Estado);
        Buffer_State get_Estado(void);

    protected:

    private:
        T_Coords Coordenadas_Trazado; //almacena los datos de las coordenadas de trazado del renderer
        Buffer_State Estado_Render;
};

#endif // T_DATO_H
