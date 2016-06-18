/*
    Nombre: Operaciones_Trazado_Deshacer.cpp
    Autor: Pablo Álvarez Martínez
    Fecha: 13/06/16
    Versión: 2.0
    Changelog:
        0.1 => Operate_First_Point() implementada
        0.2 => añadidas e implementadas las clases "T_Coords" y "T_PilaDatos"
        1.0 => Operate_Second_Point() implementada
        1.1 => Recuperar_Trazados() implementada para los casos de Operate_First_Point()
        1.2 => Depurado el trazado de la Bisectriz, implementación del header de "Calculos_Trazado"
        2.0 => Recuperar_Trazados() mejorada, incluidos los casos de Operate_Second_Point()
*/


#include "Operaciones_Trazado_Deshacer.h"


//==========================================================================================================//

bool Operate_First_Point(SDL_Renderer *render,T_PilaDatos Image_Buffer,const int &MAX_HEIGHT,const char * Path_s,SDL_Texture* Radio_o,SDL_Texture* Toolb_o,SDL_Rect* Src,SDL_Rect *Dst)
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
                        */Recuperar_Trazados(Image_Buffer,render,MAX_HEIGHT,Path_s,Radio_o,Toolb_o,Src,Dst);
                        undo_F = true;

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

//==========================================================================================================//

bool Operate_Second_Point(SDL_Renderer *render,T_PilaDatos Image_Buffer,const int &MAX_HEIGHT,const char * Path_s,SDL_Texture* Radio_o,SDL_Texture* Toolb_o,SDL_Rect* Src,SDL_Rect *Dst){
    /*OBJETIVO: Realiza los trazados y operaciones del calculo del Cuerpo Mandibular
    //ENTRADA: Un puntero al Renderer asociado a la ventana (render) de tipo SDL_Renderer, y una Pila de coordenadas(Image_Buffer) de tipo T_PilaDatos
    //SALIDA: un booleano, que comprueba la realizacion correcta de los trazados en función de los datos de la Pila
    //PreCD: Las operaciones de Operate_First_Point() deben haber sido realizadas
    //PosCD: No se puede volver a realizar Operate_First_Point() o Operate_Second_Point() sin deshacer los trazos
    */
    SDL_Event Ms_e;
    bool endPointOps = false;
    bool undo_F = false;
    bool Aux_Bool = false;
    int click_times_flag = 0;
    T_Coords Aux_Click_Coords;
    T_Coords Point_R1;
    T_Coords Point_R2;
    T_Coords Point_R3;
    T_Coords Point_R4;
    T_Coords Point_Calculate;
    T_Coords Point_Calculate_2;
    Point P_Aux1;
    Point P_Aux2;
    Point P_AuxBis;
    Point P_AuxBis2;
    T_Recta Rct_1(Point_R1,Point_R2);
    T_Recta Rct_2(Point_R1,Point_R2);
    T_Dato Aux_Saver;
    while(!endPointOps){
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
                    case 0: //primer punto (primero recta1)
                        Point_R1.set_xPos(Ms_e.button.x);
                        Point_R1.set_yPos(Ms_e.button.y);
                        Aux_Saver.set_Coords(Point_R1.get_xPos(),Point_R1.get_yPos());
                        Aux_Saver.set_Estado(second_Point_OP1);
                        Aux_Bool = Image_Buffer.Insertar_Dato(Aux_Saver);

                        if (Aux_Bool == true){
                            SDL_SetRenderDrawColor(render,255,0,0,255);
                            SDL_RenderDrawPoint(render,Point_R1.get_xPos(),Point_R1.get_yPos());
                            P_Aux1 = Coords_ToPoint(Point_R1);
                        }
                    break;
                    case 1: //segundo punto (segundo recta1)
                        Point_R2.set_xPos(Ms_e.button.x);
                        Point_R2.set_yPos(Ms_e.button.y);
                        Aux_Saver.set_Coords(Point_R2.get_xPos(),Point_R2.get_yPos());
                        Aux_Saver.set_Estado(second_Point_OP2);
                        Aux_Bool = Image_Buffer.Insertar_Dato(Aux_Saver);
                        if (Aux_Bool == true){
                            SDL_SetRenderDrawColor(render,255,0,0,255);
                            SDL_RenderDrawPoint(render,Point_R2.get_xPos(),Point_R2.get_yPos());
                            SDL_RenderDrawLine(render,Point_R1.get_xPos(),Point_R1.get_yPos(),Point_R2.get_xPos(),Point_R2.get_yPos());
                            T_Recta RctAux_1(Point_R1,Point_R2);
                            Rct_1 = RctAux_1;
                        }
                    break;
                    case 2: //tercer punto (primero de la recta2)
                        Point_R3.set_xPos(Ms_e.button.x);
                        Point_R3.set_yPos(Ms_e.button.y);
                        Aux_Saver.set_Coords(Point_R3.get_xPos(),Point_R3.get_yPos());
                        Aux_Saver.set_Estado(second_Point_OP3);
                        Aux_Bool = Image_Buffer.Insertar_Dato(Aux_Saver);
                        if (Aux_Bool == true){
                         SDL_SetRenderDrawColor(render,255,0,0,255);
                         SDL_RenderDrawPoint(render,Point_R3.get_xPos(),Point_R3.get_yPos());
                        }
                        break;
                    case 3: //cuarto punto (segundo recta2)
                        Point_R4.set_xPos(Ms_e.button.x);
                        Point_R4.set_yPos(Ms_e.button.y);
                        Aux_Saver.set_Coords(Point_R4.get_xPos(),Point_R4.get_yPos());
                        Aux_Saver.set_Estado(second_Point_OP4);
                        Aux_Bool = Image_Buffer.Insertar_Dato(Aux_Saver);
                        if (Aux_Bool == true){
                            SDL_SetRenderDrawColor(render,255,0,0,255);
                            SDL_RenderDrawPoint(render,Point_R4.get_xPos(),Point_R4.get_yPos());
                            SDL_RenderDrawLine(render,Point_R3.get_xPos(),Point_R3.get_yPos(),Point_R4.get_xPos(),Point_R4.get_yPos());
                            //Realizamos el trazado de la bisectriz mediante los calculos adecuados
                            T_Recta RctAux_2(Point_R3,Point_R4);
                            Rct_2 = RctAux_2;
                            P_Aux2 = Coords_ToPoint(Point_R4);
                            P_AuxBis = intersecta(Rct_1,Rct_2);
                            P_AuxBis2 = bisector(P_Aux1,P_AuxBis,P_Aux2);
                            SDL_SetRenderDrawColor(render,0,255,0,255);
                            SDL_RenderDrawLine(render,Point_ToCoords(P_AuxBis).get_xPos(),Point_ToCoords(P_AuxBis).get_yPos(),Point_ToCoords(P_AuxBis2).get_xPos(),Point_ToCoords(P_AuxBis2).get_yPos());
                        }
                        break;
                    case 4: //Primer punto Calculo
                        Point_Calculate.set_xPos(Ms_e.button.x);
                        Point_Calculate.set_yPos(Ms_e.button.y);
                        Aux_Saver.set_Coords(Point_Calculate.get_xPos(),Point_Calculate.get_yPos());
                        Aux_Saver.set_Estado(second_Point_OP5);
                        Aux_Bool = Image_Buffer.Insertar_Dato(Aux_Saver);
                        if (Aux_Bool == true){ //comprueba que se inserta
                            SDL_SetRenderDrawColor(render,0,0,255,255);
                            SDL_RenderDrawPoint(render,Point_Calculate.get_xPos(),Point_Calculate.get_yPos());
                        }

                    break;
                    case 5: //Segundo punto Calculo
                        Point_Calculate_2.set_xPos(Ms_e.button.x);
                        Point_Calculate_2.set_yPos(Ms_e.button.y);
                        Aux_Saver.set_Coords(Point_Calculate_2.get_xPos(),Point_Calculate_2.get_yPos());
                        Aux_Saver.set_Estado(second_Point_OP6);
                        Aux_Bool = Image_Buffer.Insertar_Dato(Aux_Saver);
                        if (Aux_Bool == true){
                            SDL_SetRenderDrawColor(render,0,0,255,255);
                            SDL_RenderDrawPoint(render,Point_Calculate_2.get_xPos(),Point_Calculate_2.get_yPos());
                            endPointOps = true;
                        }
                    break;
                    }
                   //if codigo_comprobacion == 3
                    /*
                        Image_Buffer.Borrar_Dato();
                        */Recuperar_Trazados(Image_Buffer,render,MAX_HEIGHT,Path_s,Radio_o,Toolb_o,Src,Dst);
                        undo_F = true;

                   //
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
    return (Image_Buffer.Tam_Pila_Datos() == 8);
}

//==========================================================================================================//

bool Recuperar_Trazados(T_PilaDatos Img_Buffer, SDL_Renderer *Renderer,const int &MAX_HEIGHT,const char * Path,SDL_Texture* Radio,SDL_Texture* Toolb,SDL_Rect* Src,SDL_Rect *Dst){
    /*OBJETIVO: Vacía el SDL_Renderer de la ventana y traza de nuevo los puntos seleccionados hasta el momento, excepto el ultimo trazado.
    //ENTRADA: La Pila con las coordenadas trazadas(Img_Buffer) de tipo T_PilaDatos, el puntero al renderer de la ventana(Renderer), y la constante de altura de la ventana(MAX_HEIGHT)
    //SALIDA: un booleano (first_Op) que comprueba si se puede realizar correctamente la operación de Deshacer
    //PreCD: El puntero del Renderer debe estar asociado a la ventana principal
    */
    bool proof = false;
    bool first_Op = true;
    SDL_RenderClear(Renderer); //limpia el renderer
    cargar_texturas(Renderer,Path,Radio,Toolb,Src,Dst);
    if (Img_Buffer.Borrar_Dato() == true){ //comprueba que borra la ultima operación correctamente
        Point P_Aux1;   //
        Point P_Aux2;   //Variables auxiliares para el trazado en los
        Point P_AuxBis; // casos
        Point P_AuxBis2;//
        T_Recta Rct_1(Point_ToCoords(P_Aux1),Point_ToCoords(P_Aux2));
        T_Recta Rct_2(Point_ToCoords(P_Aux1),Point_ToCoords(P_Aux2));
        int Pos_Finder = Img_Buffer.Tam_Pila_Datos();
        int i = Pos_Finder-1;
        while ((i  >= 0) && (proof = true)) {
            switch(Img_Buffer.Buscar_Dato(i).get_Estado()){
                case first_Point_OP1: //caso 1: Primer punto, agujero mentoniano y trazado de la vertical
                    SDL_SetRenderDrawColor(Renderer,255,0,0,255);
                    SDL_RenderDrawPoint(
                                        Renderer,
                                        Img_Buffer.Buscar_Dato(i).get_Coords().get_xPos(),
                                        Img_Buffer.Buscar_Dato(i).get_Coords().get_yPos());
                    SDL_SetRenderDrawColor(Renderer,0,255,0,255);
                    SDL_RenderDrawLine(
                                       Renderer,
                                       Img_Buffer.Buscar_Dato(i).get_Coords().get_xPos(),
                                       Img_Buffer.Buscar_Dato(i).get_Coords().get_yPos(),
                                       Img_Buffer.Buscar_Dato(i).get_Coords().get_xPos(),
                                       MAX_HEIGHT);
                break;
                case first_Point_OP2: //caso 2: Primer punto del grosor 1
                    SDL_SetRenderDrawColor(Renderer,255,0,255,255);
                    SDL_RenderDrawPoint(Renderer,Img_Buffer.Buscar_Dato(i).get_Coords().get_xPos(),Img_Buffer.Buscar_Dato(i).get_Coords().get_yPos());
                break;
                case first_Point_OP3: //caso 3: Segundo punto del grosor 1
                    SDL_RenderDrawPoint(Renderer,Img_Buffer.Buscar_Dato(i).get_Coords().get_xPos(),Img_Buffer.Buscar_Dato(i).get_Coords().get_yPos());
                break;
                case second_Point_OP1: //caso 4: Primer punto de la primera recta (tangente1)
                  SDL_SetRenderDrawColor(Renderer,255,0,0,255);
                  SDL_RenderDrawPoint(Renderer,Img_Buffer.Buscar_Dato(i).get_Coords().get_xPos(),Img_Buffer.Buscar_Dato(i).get_Coords().get_yPos());
                break;
                case second_Point_OP2: //caso 5: Segundo punto de la primera recta (tangente1)
                    SDL_RenderDrawLine(Renderer,Img_Buffer.Buscar_Dato(i).get_Coords().get_xPos(),Img_Buffer.Buscar_Dato(i).get_Coords().get_yPos(),Img_Buffer.Buscar_Dato(i+1).get_Coords().get_xPos(),Img_Buffer.Buscar_Dato(i+1).get_Coords().get_yPos());
                    Rct_1.set_Aval(Img_Buffer.Buscar_Dato(i+1).get_Coords(),Img_Buffer.Buscar_Dato(i).get_Coords()); //
                    Rct_1.set_Bval(Img_Buffer.Buscar_Dato(i+1).get_Coords(),Img_Buffer.Buscar_Dato(i).get_Coords()); //Configura los valores de la primera recta
                    Rct_1.set_Cval(Img_Buffer.Buscar_Dato(i+1).get_Coords(),Img_Buffer.Buscar_Dato(i).get_Coords()); //
                break;
                case second_Point_OP3: //casp 6: Primer punto de la segunda recta (tangente2)
                  SDL_RenderDrawPoint(Renderer,Img_Buffer.Buscar_Dato(i).get_Coords().get_xPos(),Img_Buffer.Buscar_Dato(i).get_Coords().get_yPos());
                break;
                case second_Point_OP4: //caso 7: Segundo punto de la segunda recta (tangente2) y bisectriz
                    SDL_SetRenderDrawColor(Renderer,255,0,0,255);
                    SDL_RenderDrawPoint(Renderer,Img_Buffer.Buscar_Dato(i).get_Coords().get_xPos(),Img_Buffer.Buscar_Dato(i).get_Coords().get_yPos());
                    SDL_RenderDrawLine(Renderer,Img_Buffer.Buscar_Dato(i).get_Coords().get_xPos(),Img_Buffer.Buscar_Dato(i).get_Coords().get_yPos(),Img_Buffer.Buscar_Dato(i+1).get_Coords().get_xPos(),Img_Buffer.Buscar_Dato(i+1).get_Coords().get_yPos());
                    Rct_2.set_Aval(Img_Buffer.Buscar_Dato(i+1).get_Coords(),Img_Buffer.Buscar_Dato(i).get_Coords()); //
                    Rct_2.set_Bval(Img_Buffer.Buscar_Dato(i+1).get_Coords(),Img_Buffer.Buscar_Dato(i).get_Coords()); //Configura los valores de la segunda recta
                    Rct_2.set_Cval(Img_Buffer.Buscar_Dato(i+1).get_Coords(),Img_Buffer.Buscar_Dato(i).get_Coords()); //
                    P_Aux2 = Coords_ToPoint(Img_Buffer.Buscar_Dato(i).get_Coords());
                    P_AuxBis = intersecta(Rct_1,Rct_2);
                    P_AuxBis2 = bisector(P_Aux1,P_AuxBis,P_Aux2);
                    SDL_SetRenderDrawColor(Renderer,0,255,0,255);
                break;
                case second_Point_OP5: //caso 8: Primer punto del calculo del grosor 2
                   SDL_SetRenderDrawColor(Renderer,0,0,255,255);
                   SDL_RenderDrawPoint(Renderer,Img_Buffer.Buscar_Dato(i).get_Coords().get_xPos(),Img_Buffer.Buscar_Dato(i).get_Coords().get_yPos());
                break;
                case second_Point_OP6: //caso 9: Segundo punto del calculo del grosor 2
                    SDL_SetRenderDrawColor(Renderer,0,0,255,255);
                    SDL_RenderDrawPoint(Renderer,Img_Buffer.Buscar_Dato(i).get_Coords().get_xPos(),Img_Buffer.Buscar_Dato(i).get_Coords().get_yPos());
                break;
                case second_Point_End: //caso de error 10: no se ha borrado el flag de finalizado del trazado
                    proof = false;
                    first_Op = false;
                break;
                case Init_Image: //caso de error 11: la pila se encuentra vacía con el flag por defecto Init Image
                    first_Op = false; //flag de error de deshacer trazados
                    proof = true; //salimos del bucle
                break;
            }
            i--;//iteramos sobre el buffer
            SDL_RenderPresent(Renderer);
        }
    }
    return first_Op;
}
