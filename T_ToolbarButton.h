#ifndef T_TOOLBARBUTTON_H
#define T_TOOLBARBUTTON_H
#include "T_Coords.h"
#include <string>
enum Button_Type{UNDO, OPEN_I, F_POINT, S_POINT, SAVE,CLOSE , S_CALCS,DEFAULT_B}; /* UNDO: Deshacer
                                                                            OPEN_I: Abrir Fichero
                                                                            F_POINT: Agujero Mentoniano
                                                                            S_POINT: Cuerpo Mandibular
                                                                            SAVE: Guardar datos
                                                                            CLOSE: Cerrar el programa
                                                                            S_CALCS: Calculos realizados
                                                                            DEFAULT_B: valor por defecto, al inicializar
                                                                            */
class T_ToolbarButton
{
    public:
        T_ToolbarButton();
        void set_LeftPoint(T_Coords Nw_Coord);
        void set_RightPoint(T_Coords Nw_Coord);
        void set_ButtonType(Button_Type Nw_Type);
        T_Coords get_LeftPoint(void);
        T_Coords get_RightPoint(void);
        Button_Type get_ButtonType(void);

    protected:

    private:
        Button_Type Btn_Class;
        T_Coords Left_Corner_Point; //Punto Inicial del rectangulo (arriba a la izquierda)
        T_Coords Right_Corner_Point; //Punto Final del rectangulo (abajo a la derecha)
};

#endif // T_TOOLBARBUTTON_H
