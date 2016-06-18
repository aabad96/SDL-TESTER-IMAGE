//
//  main.cpp
//  Vector botones
//
//  Created by Adrian on 14/6/16.
//  Copyright © 2016 Adrian. All rights reserved.
//
#include "Comp_boton.h"

//comprobacion de botones 10 no a clicado en ningun boton, 0-6 como aparecen en los botones de la TollbarButton comentario

std::vector <T_ToolbarButton> vec_botones(){ // b0=  Abrir fichero, b1 = agujero Mentoniano, b2= cuerpo Mandibular,b3= deshacer, b4= deshacerTodo, b5= guardar dato, b6= Calculos.


    std::vector <T_ToolbarButton> button(7);// Creamos un vector donde almacenaremos los botones del Toolbar


    T_Coords cordenadas; //variable auxiliar para las coordenadas

    cordenadas.set_xPos(0);         //Introducimos las coordenadas una a una
    cordenadas.set_yPos(0);
        button[0].set_LeftPoint(cordenadas);

    cordenadas.set_xPos(108);
    cordenadas.set_yPos(76);
        button[0].set_RightPoint(cordenadas);
    button[0].set_ButtonType(OPEN_I);

    cordenadas.set_xPos(110);
    cordenadas.set_yPos(0);
        button[1].set_LeftPoint(cordenadas);

    cordenadas.set_xPos(216);
    cordenadas.set_yPos(76);
        button[1].set_RightPoint(cordenadas);
        button[1].set_ButtonType(F_POINT);


    cordenadas.set_xPos(218);
    cordenadas.set_yPos(0);
        button[2].set_LeftPoint(cordenadas);

    cordenadas.set_xPos(324);
    cordenadas.set_yPos(76);
        button[2].set_RightPoint(cordenadas);
        button[2].set_ButtonType(S_POINT);

    cordenadas.set_xPos(326);
    cordenadas.set_yPos(0);
        button[3].set_LeftPoint(cordenadas);

    cordenadas.set_xPos(432);
    cordenadas.set_yPos(76);
        button[3].set_RightPoint(cordenadas);
        button[3].set_ButtonType(UNDO);

    cordenadas.set_xPos(434);
    cordenadas.set_yPos(0);
        button[4].set_LeftPoint(cordenadas);

    cordenadas.set_xPos(540);
    cordenadas.set_yPos(76);
        button[4].set_RightPoint(cordenadas);
        button[4].set_ButtonType(SAVE);


    cordenadas.set_xPos(542);
    cordenadas.set_yPos(0);
        button[5].set_LeftPoint(cordenadas);

    cordenadas.set_xPos(648);
    cordenadas.set_yPos(76);
        button[5].set_RightPoint(cordenadas);
        button[5].set_ButtonType(CLOSE);

    cordenadas.set_xPos(650);
    cordenadas.set_yPos(0);
        button[6].set_LeftPoint(cordenadas);

    cordenadas.set_xPos(791);
    cordenadas.set_yPos(76);
        button[6].set_RightPoint(cordenadas);
        button[6].set_ButtonType(S_CALCS);

    return button;


}
int Clik_Boton(std::vector <T_ToolbarButton> &botones, T_Coords Coordenadas_comp)// comprobacion de las cordenadas return int 0-6 botones 10 no a clicado en ningun boton
{
    T_ToolbarButton aux1;
    bool boton=false;
    int n_boton=0;
    Sint32 aux_xI=0,aux_yI=0,aux_xF=0,aux_yF=0,coor_x=0,coor_y=0;//coor x , y son las cordenadas que ha clicada
    T_Coords  new_corde;
    new_corde= Coordenadas_comp;
    coor_x=new_corde.get_xPos();
    coor_y= new_corde.get_yPos();
    std::vector<T_ToolbarButton> vec_botones;
    vec_botones= botones;
    int i=0;

    do{
        aux1=vec_botones[i];
        aux_xI=aux1.get_LeftPoint().get_xPos();
        aux_yI=aux1.get_LeftPoint().get_yPos();
        aux_xF=aux1.get_RightPoint().get_xPos();
        aux_yF=aux1.get_RightPoint().get_yPos();

        if ((coor_x>=aux_xI) && (coor_y>=aux_yI)) {
            if ((coor_x<=aux_xF) && (coor_y<=aux_yF)){
                boton =true;
                n_boton=i;
            }else {boton =false;}

        }else {boton=false;}
        i++;
    }while ((i<7) && (boton==false));

    if (boton==true) {
        return n_boton;

    }else {
        n_boton=10;// Referencia ningun boton clickado
        return n_boton;
    }
}



