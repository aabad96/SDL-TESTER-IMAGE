#include <SDL.h>
#include "T_Coords.h"
#include "T_PilaDatos.h"
#include "Operaciones_Trazado_Deshacer.h"
bool Operate_First_Point(SDL_Renderer *render,T_PilaDatos Image_Buffer,const int &MAX_HEIGHT)
{
    SDL_Event Ms_e;
    bool endPointOps = false;
    bool undo_F = false;
    bool Aux_Bool = false;
    int click_times_flag = 0;
    T_Coords Aux_Click_Coords;
    T_Coords Point_Center;
    T_Coords Point_Calculate;
    T_Dato Aux_Saver;
    T_Coords Point_Calculate_2;
    while (!endPointOps){
        Aux_Bool = false;
        undo_F = false;
        Aux_Click_Coords.set_xPos(0); //se resetea la x de la auxiliar
        Aux_Click_Coords.set_yPos(0); //se resetea la x de la auxiliar
        while (SDL_PollEvent(&Ms_e)){
            if (Ms_e.type == SDL_MOUSEBUTTONDOWN){
                if (Ms_e.button.button == SDL_BUTTON_LEFT){
                    Aux_Click_Coords.set_xPos(Ms_e.button.x);
                    Aux_Click_Coords.set_yPos(Ms_e.button.y);
                    // Comprobar(Aux_Click_Coords)
                    //If codigo_comprobacion == 10
                    switch(click_times_flag){
                    case 0: //primer punto y trazado de la vertical
                        Point_Center.set_xPos(Ms_e.button.x);
                        Point_Center.set_yPos(Ms_e.button.y);
                        Aux_Saver.set_Coords(Point_Center.get_xPos(),Point_Center.get_yPos());
                        Aux_Saver.set_Estado(first_Point_OP1);
                        Aux_Bool = Image_Buffer.Insertar_Dato(Aux_Saver);

                        if (Aux_Bool == true){
                            SDL_SetRenderDrawColor(render,255,0,0,255);
                            SDL_RenderDrawPoint(render,Point_Center.get_xPos(),Point_Center.get_yPos());
                            SDL_SetRenderDrawColor(render,0,255,0,255);
                            SDL_RenderDrawLine(render, Point_Center.get_xPos(),Point_Center.get_yPos(),Point_Center.get_xPos(),MAX_HEIGHT);
                        }
                    break;
                    case 1: //segundo punto (primero de operacion)
                        Point_Calculate.set_xPos(Ms_e.button.x);
                        Point_Calculate.set_yPos(Ms_e.button.y);
                        Aux_Saver.set_Coords(Point_Calculate.get_xPos(),Point_Calculate.get_yPos());
                        Aux_Saver.set_Estado(first_Point_OP2);
                        Aux_Bool = Image_Buffer.Insertar_Dato(Aux_Saver);
                        if (Aux_Bool == true){
                            SDL_SetRenderDrawColor(render,0,0,255,255);
                            SDL_RenderDrawPoint(render,Point_Calculate.get_xPos(),Point_Calculate.get_yPos());
                        }
                    break;
                    case 2: //tercer punto (segundo de operación)
                        Point_Calculate_2.set_xPos(Ms_e.button.x);
                        Point_Calculate_2.set_yPos(Ms_e.button.y);
                        SDL_SetRenderDrawColor(render,0,0,255,255);
                        Aux_Saver.set_Coords(Point_Calculate_2.get_xPos(),Point_Calculate_2.get_yPos());
                        Aux_Saver.set_Estado(first_Point_OP3);
                        Aux_Bool = Image_Buffer.Insertar_Dato(Aux_Saver);
                        if (Aux_Bool == true){
                         SDL_RenderDrawPoint(render,Point_Calculate_2.get_xPos(),Point_Calculate_2.get_yPos());
                         endPointOps = true;
                        }
                        break;
                    }
                   //if codigo_comprobacion == 3
                   /*
                        Image_Buffer.Borrar_Dato();
                        Recuperar_Trazados(Image_Buffer,render,MAX_HEIGHT);
                        undo_F = true;

                   */
                   //if codigo_comprobacion == 4
                   /*
                        Image_Buffer.Vaciar_Pila();
                        click_times_flag = 0;
                   */
                }

	}
        if (undo_F == false){
            click_times_flag++;
        } else {
            click_times_flag--;
        }
        SDL_RenderPresent(render);
    }
    }
    return (Image_Buffer.Tam_Pila_Datos() == 3);
}
bool Recuperar_Trazados(T_PilaDatos Img_Buffer, SDL_Renderer *Renderer,const int &MAX_HEIGHT){
    int Pos_Finder = Img_Buffer.Tam_Pila_Datos();
    bool proof = true;
    int i = Pos_Finder-1;
    SDL_RenderClear(Renderer);
    //Operacion Cargar_Toolbar_y_Imagen();
    while ((i  >= 0) && (proof = true)) {
        if (Img_Buffer.Buscar_Dato(i).get_Estado() == first_Point_OP1){
            SDL_SetRenderDrawColor(Renderer,255,0,0,255);
            SDL_RenderDrawPoint(Renderer,Img_Buffer.Buscar_Dato(i).get_Coords().get_xPos(),Img_Buffer.Buscar_Dato(i).get_Coords().get_yPos());
            SDL_SetRenderDrawColor(Renderer,0,255,0,255);
            SDL_RenderDrawLine(Renderer,Img_Buffer.Buscar_Dato(i).get_Coords().get_xPos(),Img_Buffer.Buscar_Dato(i).get_Coords().get_yPos(),Img_Buffer.Buscar_Dato(i).get_Coords().get_xPos(),MAX_HEIGHT);
        } else if(Img_Buffer.Buscar_Dato(i).get_Estado() == first_Point_OP2){
            SDL_SetRenderDrawColor(Renderer,255,0,255,255);
            SDL_RenderDrawPoint(Renderer,Img_Buffer.Buscar_Dato(i).get_Coords().get_xPos(),Img_Buffer.Buscar_Dato(i).get_Coords().get_yPos());
        } else if(Img_Buffer.Buscar_Dato(i).get_Estado() == first_Point_OP3){
            SDL_RenderDrawPoint(Renderer,Img_Buffer.Buscar_Dato(i).get_Coords().get_xPos(),Img_Buffer.Buscar_Dato(i).get_Coords().get_yPos());
            proof = true;
        }else{
            proof = false;
        }
    }
    return proof;
}


