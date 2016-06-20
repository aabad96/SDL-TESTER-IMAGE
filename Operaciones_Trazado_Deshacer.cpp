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

void Draw_Aspa (SDL_Renderer * render,T_Coords center){
    Sint32 coordx,coordy;
    Sint32 corxv,corxh,coryh,coryv;

    coordx=center.get_xPos();
    coordy=center.get_yPos();
    corxv=coordx-10;
    corxh=coordx+10;
    coryv=coordy-10;
    coryh=coordy+10;
    SDL_RenderDrawLine(render, corxv,coordy , corxh, coordy);
    SDL_RenderDrawLine(render, coordx, coryv, coordx, coryh);

}
//==========================================================================================================//

bool Operate_First_Point(std::vector<T_ToolbarButton> Botones,T_Calculo &Calcs_Traz,SDL_Renderer *render,T_PilaDatos &Image_Buffer,const int &MAX_HEIGHT,std::string Path_s,SDL_Texture* Radio_o,SDL_Texture* Toolb_o,SDL_Rect &Src,SDL_Rect &Dst)
{

    SDL_Event Ms_e;
    bool endPointOps = false;
    bool Aux_Bool = false;
    long double CalC1 = 0;
    int click_times_flag = 0;
    int codigo_comprobacion = 0;
    T_Coords Aux_Click_Coords;
    T_Coords Point_Center;
    T_Coords Point_Calculate;
    T_Dato Aux_Saver;
    T_Coords Point_Calculate_2;
    while (endPointOps == false){
        Aux_Bool = false;

        Aux_Click_Coords.set_xPos(0); //se resetea la x de la auxiliar
        Aux_Click_Coords.set_yPos(0);//se resetea la x de la auxiliar
                while (SDL_PollEvent(&Ms_e)){
            if (Ms_e.type == SDL_MOUSEBUTTONDOWN){
                if (Ms_e.button.button == SDL_BUTTON_LEFT){
                    Aux_Click_Coords.set_xPos(Ms_e.button.x);
                    Aux_Click_Coords.set_yPos(Ms_e.button.y);
                    codigo_comprobacion = Clik_Boton(Botones,Aux_Click_Coords);
                    if (codigo_comprobacion == 10){
                    switch(click_times_flag){
                    case 0: //primer punto y trazado de la vertical
                        std::cout << "Primer Punto del Agujero mentoniano" << std::endl;
                        Point_Center.set_xPos(Ms_e.button.x);
                        Point_Center.set_yPos(Ms_e.button.y);
                        Aux_Saver.set_Coords(Point_Center.get_xPos(),Point_Center.get_yPos());
                        Aux_Saver.set_Estado(first_Point_OP1);
                        Aux_Bool = Image_Buffer.Insertar_Dato(Aux_Saver);
                        if (Aux_Bool == true){
                            SDL_SetRenderDrawColor(render,202, 18, 202,255);
                            Draw_Aspa(render,Point_Center);
                            SDL_SetRenderDrawColor(render,0,255,0,255);
                            SDL_RenderDrawLine(render, Point_Center.get_xPos(),Point_Center.get_yPos(),Point_Center.get_xPos(),MAX_HEIGHT);
                            click_times_flag = click_times_flag+1;
                        }
                    break;
                    case 1: //segundo punto (primero de operacion)
                        std::cout << "Segundo Punto del Agujero mentoniano" << std::endl;
                        Point_Calculate.set_xPos(Point_Center.get_xPos());
                        Point_Calculate.set_yPos(Ms_e.button.y);
                        Aux_Saver.set_Coords(Point_Calculate.get_xPos(),Point_Calculate.get_yPos());
                        Aux_Saver.set_Estado(first_Point_OP2);
                        Aux_Bool = Image_Buffer.Insertar_Dato(Aux_Saver);
                        if (Aux_Bool == true){
                            SDL_SetRenderDrawColor(render,202, 18, 202,255);
                            Draw_Aspa(render,Point_Calculate);
                            click_times_flag++;
                        }
                    break;
                    case 2: //tercer punto (segundo de operación)
                        std::cout << "Tercer Punto del Agujero mentoniano" << std::endl;
                        Point_Calculate_2.set_xPos(Point_Center.get_xPos());
                        Point_Calculate_2.set_yPos(Ms_e.button.y);
                        SDL_SetRenderDrawColor(render,202, 18, 202,255);
                        Aux_Saver.set_Coords(Point_Calculate_2.get_xPos(),Point_Calculate_2.get_yPos());
                        Aux_Saver.set_Estado(first_Point_OP3);
                        Aux_Bool = Image_Buffer.Insertar_Dato(Aux_Saver);
                        if (Aux_Bool == true){
                         Draw_Aspa(render,Point_Calculate_2);
                         endPointOps = true;
                         click_times_flag++;
                        }
                    break;
                    }
                }else if (codigo_comprobacion == 3){
                   /*
                        Image_Buffer.Borrar_Dato();
                        */Recuperar_Trazados(Image_Buffer,Calcs_Traz,render,MAX_HEIGHT,Path_s,Radio_o,Toolb_o,Src,Dst);
                          click_times_flag--;
                   }
                }

	}

        SDL_RenderPresent(render);
    }
    }
    CalC1 = distancia(Point_Calculate,Point_Calculate_2);
    Calcs_Traz.Insertar_Calculo(CalC1);
    //renderTexture(tex_medidaca1(CalC1,render),render,posicion1x,posicion1y,nullptr);
    return endPointOps;
}

//==========================================================================================================//

bool Operate_Second_Point(std::vector<T_ToolbarButton> Botones,T_Calculo &Calcs_Traz,SDL_Renderer *render,T_PilaDatos &Image_Buffer,const int &MAX_HEIGHT,std::string Path_s,SDL_Texture* Radio_o,SDL_Texture* Toolb_o,SDL_Rect &Src,SDL_Rect &Dst){
    /*OBJETIVO: Realiza los trazados y operaciones del calculo del Cuerpo Mandibular
    //ENTRADA: Un puntero al Renderer asociado a la ventana (render) de tipo SDL_Renderer, y una Pila de coordenadas(Image_Buffer) de tipo T_PilaDatos
    //SALIDA: un booleano, que comprueba la realizacion correcta de los trazados en función de los datos de la Pila
    //PreCD: Las operaciones de Operate_First_Point() deben haber sido realizadas
    //PosCD: No se puede volver a realizar Operate_First_Point() o Operate_Second_Point() sin deshacer los trazos
    */

    SDL_Event Ms_e;
    bool endPointOps = false;
    bool Aux_Bool = false;
    long double CalC2 = 0;
    int click_times_flag = 0;
    T_Coords Aux_Click_Coords;
    T_Coords Point_R1;
    T_Coords Point_R2;
    T_Coords Point_R3;
    T_Coords Point_R4;
    T_Coords Point_Calculate;
    T_Coords Point_Calculate_2;
    int codigo_comprobacion;
    Point P_Aux1;
    Point P_Aux2;
    Point P_Aux3;
    Point P_Aux4;
    Point P_Aux5;
    double Pendiente;
    Point P_AuxBis;
    Point P_AuxBis2;
    T_Recta Rct_1(Point_R1,Point_R2);
    T_Recta Rct_2(Point_R1,Point_R2);
    T_Dato Aux_Saver;
    while(!endPointOps){
        Aux_Bool = false;
        Aux_Click_Coords.set_xPos(0); //se resetea la x de la auxiliar
        Aux_Click_Coords.set_yPos(0); //se resetea la x de la auxiliar
        while (SDL_PollEvent(&Ms_e)){
            if (Ms_e.type == SDL_MOUSEBUTTONDOWN){
                if (Ms_e.button.button == SDL_BUTTON_LEFT){
                    Aux_Click_Coords.set_xPos(Ms_e.button.x);
                    Aux_Click_Coords.set_yPos(Ms_e.button.y);
                    codigo_comprobacion = Clik_Boton(Botones,Aux_Click_Coords);
                    if (codigo_comprobacion == 10){
                    switch(click_times_flag){
                    case 0: //primer punto (primero recta1)
                        std::cout << "Primer Punto del Cuerpo Mandibular" << std::endl;
                        Point_R1.set_xPos(Ms_e.button.x);
                        Point_R1.set_yPos(Ms_e.button.y);
                        Aux_Saver.set_Coords(Point_R1.get_xPos(),Point_R1.get_yPos());
                        Aux_Saver.set_Estado(second_Point_OP1);
                        Aux_Bool = Image_Buffer.Insertar_Dato(Aux_Saver);

                        if (Aux_Bool == true){
                            SDL_SetRenderDrawColor(render,202, 18, 202,255);
                            Draw_Aspa(render,Point_R1);
                            P_Aux1 = Coords_ToPoint(Point_R1);
                            click_times_flag++;
                        }
                    break;
                    case 1: //segundo punto (segundo recta1)
                        std::cout << "Segundo Punto del Cuerpo Mandibular" << std::endl;
                        Point_R2.set_xPos(Ms_e.button.x);
                        Point_R2.set_yPos(Ms_e.button.y);
                        Aux_Saver.set_Coords(Point_R2.get_xPos(),Point_R2.get_yPos());
                        Aux_Saver.set_Estado(second_Point_OP2);
                        Aux_Bool = Image_Buffer.Insertar_Dato(Aux_Saver);
                        if (Aux_Bool == true){
                            SDL_SetRenderDrawColor(render,202, 18, 202,255);
                            Draw_Aspa(render,Point_R2);
                            SDL_SetRenderDrawColor(render,34, 236, 226,255);
                            SDL_RenderDrawLine(render,Point_R1.get_xPos(),Point_R1.get_yPos(),Point_R2.get_xPos(),Point_R2.get_yPos());
                            T_Recta RctAux_1(Point_R1,Point_R2);
                            Rct_1 = RctAux_1;
                            click_times_flag++;
                        }
                    break;
                    case 2: //tercer punto (primero de la recta2)
                        std::cout << "Tercero Punto del Cuerpo Mandibular" << std::endl;
                        Point_R3.set_xPos(Ms_e.button.x);
                        Point_R3.set_yPos(Ms_e.button.y);
                        Aux_Saver.set_Coords(Point_R3.get_xPos(),Point_R3.get_yPos());
                        Aux_Saver.set_Estado(second_Point_OP3);
                        Aux_Bool = Image_Buffer.Insertar_Dato(Aux_Saver);
                        if (Aux_Bool == true){
                         SDL_SetRenderDrawColor(render,202, 18, 202,255);
                         Draw_Aspa(render,Point_R3);
                         click_times_flag++;
                        }
                        break;
                    case 3: //cuarto punto (segundo recta2)
                        std::cout << "Cuarto Punto del Cuerpo Mandibular" << std::endl;
                        Point_R4.set_xPos(Ms_e.button.x);
                        Point_R4.set_yPos(Ms_e.button.y);
                        Aux_Saver.set_Coords(Point_R4.get_xPos(),Point_R4.get_yPos());
                        Aux_Saver.set_Estado(second_Point_OP4);
                        Aux_Bool = Image_Buffer.Insertar_Dato(Aux_Saver);
                        if (Aux_Bool == true){
                            SDL_SetRenderDrawColor(render,202, 18, 202,255);
                            Draw_Aspa(render,Point_R4);
                            SDL_SetRenderDrawColor(render,34, 236, 226,255);
                            SDL_RenderDrawLine(render,Point_R3.get_xPos(),Point_R3.get_yPos(),Point_R4.get_xPos(),Point_R4.get_yPos());
                            //Realizamos el trazado de la bisectriz mediante los calculos adecuados
                            T_Recta RctAux_2(Point_R3,Point_R4);
                            Rct_2 = RctAux_2;
                            //
                            P_AuxBis = intersecta(Rct_1,RctAux_2);
                            //Comprueba los calculos para realizar el bisector
                            if (Point_R3.get_xPos() > Point_R4.get_xPos()){ //si el mayor es el punto 3
                                P_Aux2 = Coords_ToPoint(Point_R3);
                                P_Aux5 = Coords_ToPoint(Point_R4);
                            } else if (Point_R3.get_xPos() < Point_R4.get_xPos()){ //si el mayor es el punto 4
                                P_Aux2 = Coords_ToPoint(Point_R4);
                                P_Aux5 = Coords_ToPoint(Point_R3);
                            }
                            if(Point_R1.get_xPos() < Point_R2.get_xPos()){ //si el mayor es el punto 2
                                P_Aux3 = Coords_ToPoint(Point_R2);
                            } else if (Point_R1.get_xPos() > Point_R2.get_xPos()){ //si el mayor es el punto 1
                                P_Aux3 = Coords_ToPoint(Point_R1);
                            }
                            if (P_Aux3.x > P_Aux2.x){  //si el punto mayor de Recta1 esta mas alejado que el mayor de Recta2
                                P_Aux4.x = P_Aux2.x + 2*(P_Aux3.x - P_Aux2.x);
                                std::cout << "Distancia entre P4 y P3: "<< P_Aux4.x << std::endl;
                                Pendiente = ((P_Aux2.y - P_Aux5.y)/(P_Aux2.x - P_Aux5.x));
                                P_Aux4.y = (Pendiente* (P_Aux4.x - P_Aux2.x))+ P_Aux2.y;
                                std::cout << "Punto y prolongado: " << P_Aux4.y << std::endl;
                                SDL_SetRenderDrawColor(render,202, 18, 202,255);
                                Draw_Aspa(render,Point_ToCoords(P_Aux4)); //dibuja el nuevo punto convertido
                                SDL_SetRenderDrawColor(render,34, 236, 226,255);
                                SDL_RenderDrawLine(render,P_Aux2.x,P_Aux2.y,P_Aux4.x,P_Aux4.y);
                            } else { //El mayor de Recta2 es mayor que el de la Recta1
                                P_Aux4 = P_Aux2;
                            }
                            SDL_SetRenderDrawColor(render,34, 236, 226,255);
                            SDL_RenderDrawLine(render,Point_R2.get_xPos(),Point_R2.get_yPos(),P_AuxBis.x,P_AuxBis.y); //la recta prolongada desde el mayor de Recta1
                            SDL_RenderDrawLine(render,P_Aux2.x,P_Aux2.y,P_AuxBis.x,P_AuxBis.y); //la recta prolongada desde el mayor de Recta2
                            P_AuxBis2 = bisector(P_Aux1,P_AuxBis,P_Aux4); //calcula el punto del bisector
                            SDL_SetRenderDrawColor(render,0,255,0,255);
                            SDL_RenderDrawLine(render,P_AuxBis.x,P_AuxBis.y,P_AuxBis2.x,P_AuxBis2.y); //dibuja la bisectriz
                            std::cout << "Posicion x intersecta: "<< P_AuxBis.x << std::endl;
                            std::cout << "Posicion y intersecta: "<< P_AuxBis.y << std::endl;
                            std::cout << "Posicion x bisectriz: " << P_AuxBis2.x << std::endl;
                            std::cout << "Posicion y bisectriz: " << P_AuxBis2.y << std::endl;
                            click_times_flag++;
                        }
                        break;
                    case 4: //Primer punto Calculo
                        std::cout << "Quinto Punto del Cuerpo Mandibular" << std::endl;
                        Point_Calculate.set_xPos(Ms_e.button.x);
                        Point_Calculate.set_yPos(Ms_e.button.y);
                        Aux_Saver.set_Coords(Point_Calculate.get_xPos(),Point_Calculate.get_yPos());
                        Aux_Saver.set_Estado(second_Point_OP5);
                        Aux_Bool = Image_Buffer.Insertar_Dato(Aux_Saver);
                        if (Aux_Bool == true){ //comprueba que se inserta
                            SDL_SetRenderDrawColor(render,202, 18, 202,255);
                            Draw_Aspa(render,Point_Calculate);
                            click_times_flag++;
                        }

                    break;
                    case 5: //Segundo punto Calculo
                        std::cout << "Sexto Punto del Cuerpo Mandibular" << std::endl;
                        Point_Calculate_2.set_xPos(Ms_e.button.x);
                        Point_Calculate_2.set_yPos(Ms_e.button.y);
                        Aux_Saver.set_Coords(Point_Calculate_2.get_xPos(),Point_Calculate_2.get_yPos());
                        Aux_Saver.set_Estado(second_Point_OP6);
                        Aux_Bool = Image_Buffer.Insertar_Dato(Aux_Saver);
                        if (Aux_Bool == true){
                            SDL_SetRenderDrawColor(render,202, 18, 202,255);
                            Draw_Aspa(render,Point_Calculate_2);
                            endPointOps = true;
                            click_times_flag++;
                        }
                    break;
                    }

                   } else if (codigo_comprobacion == 3){
                        Recuperar_Trazados(Image_Buffer,Calcs_Traz,render,MAX_HEIGHT,Path_s,Radio_o,Toolb_o,Src,Dst);
                        click_times_flag--;
                   }

                }

    }

        SDL_RenderPresent(render);
    }
    }
    CalC2 = distancia(Point_Calculate,Point_Calculate_2);
    Calcs_Traz.Insertar_Calculo(CalC2);
    //renderTexture(tex_medidaca2(CalC2,render),render,posicion2x,posicion2y,nullptr);
    return endPointOps;
}
//=====================================================================================================//
void Trazados_Bisectriz_Intersecta(T_PilaDatos &Img_Buffer,SDL_Renderer* Render){
//OBJETIVO: Comprueba las posiciones de los puntos de las rectas en función del eje X, y realiza los trazados ajustados a estos
//ENTRADA: Un puntero Render, de tipo SDL Renderer y un Img_Buffer, de tipo T_PilaDatos donde se encuentran almacenados los valores
//PosCD: El Img_Buffer no debe haber sido modificado
    T_Coords R1;
    T_Coords R2;
    T_Coords R3;
    T_Coords R4;
    Point Aux_1;
    Point Aux_2;
    Point Aux_3;
    Point Aux_4;
    Point Aux_5;
    Point Aux_Bis;
    Point Aux_Bis2;
    double Pendiente;
    int aux_Finder = 0; //Buscador de la posición de los datos de Img_Buffer
    //Encontramos los datos insertados en la Pila
    aux_Finder = Img_Buffer.Buscar_Estado(second_Point_OP1);
    R1 = Img_Buffer.Buscar_Dato(aux_Finder).get_Coords();
    aux_Finder = Img_Buffer.Buscar_Estado(second_Point_OP2);
    R2 = Img_Buffer.Buscar_Dato(aux_Finder).get_Coords();
    aux_Finder = Img_Buffer.Buscar_Estado(second_Point_OP3);
    R3 = Img_Buffer.Buscar_Dato(aux_Finder).get_Coords();
    aux_Finder = Img_Buffer.Buscar_Estado(second_Point_OP4);
    R4 = Img_Buffer.Buscar_Dato(aux_Finder).get_Coords();
    T_Recta RctAux_1(R1,R2);
    T_Recta RctAux_2(R3,R4);
    Aux_Bis = intersecta(RctAux_1,RctAux_2);
        if (R3.get_xPos() > R4.get_xPos()){ //si el mayor es el punto 3
            Aux_1 = Coords_ToPoint(R3);
            Aux_2 = Coords_ToPoint(R4);
        } else if (R3.get_xPos() < R4.get_xPos()){ //si el mayor es el punto 4
            Aux_1 = Coords_ToPoint(R4);
            Aux_2 = Coords_ToPoint(R3);
        }
        if(R1.get_xPos() < R2.get_xPos()){ //si el mayor es el punto 2
            Aux_5 = Coords_ToPoint(R1);
            Aux_3 = Coords_ToPoint(R2);
        } else if (R1.get_xPos() > R2.get_xPos()){ //si el mayor es el punto 1
            Aux_3 = Coords_ToPoint(R1);
            Aux_5 = Coords_ToPoint(R2);
        }
        if (Aux_3.x > Aux_1.x){  //si el punto mayor de Recta1 esta mas alejado que el mayor de Recta2
            Aux_4.x = Aux_1.x + 2*(Aux_3.x - Aux_1.x);
            Pendiente = ((Aux_1.y - Aux_2.y)/(Aux_1.x - Aux_2.x));
            Aux_4.y = (Pendiente* (Aux_4.x - Aux_1.x))+ Aux_1.y;
            SDL_SetRenderDrawColor(Render,202, 18, 202,255);
            Draw_Aspa(Render,Point_ToCoords(Aux_4)); //dibuja el nuevo punto convertido
            SDL_SetRenderDrawColor(Render,34, 236, 226,255);
            SDL_RenderDrawLine(Render,Aux_1.x,Aux_1.y,Aux_4.x,Aux_4.y);
        } else { //El mayor de Recta2 es mayor que el de la Recta1
            Aux_4 = Aux_1;
        }
        SDL_SetRenderDrawColor(Render,34, 236, 226,255);
        SDL_RenderDrawLine(Render,Aux_3.x,Aux_3.y,Aux_Bis.x,Aux_Bis.y); //la recta prolongada desde el mayor de Recta1
        SDL_RenderDrawLine(Render,Aux_1.x,Aux_1.y,Aux_Bis.x,Aux_Bis.y); //la recta prolongada desde el mayor de Recta2
        Aux_Bis2 = bisector(Aux_5,Aux_Bis,Aux_4); //calcula el punto del bisector
        SDL_SetRenderDrawColor(Render,0,255,0,255);
        SDL_RenderDrawLine(Render,Aux_Bis.x,Aux_Bis.y,Aux_Bis2.x,Aux_Bis2.y); //dibuja la bisectriz
}
//==========================================================================================================//
bool Deshacer_Todos_Trazados(const int &flag_Undo,T_PilaDatos &Img_Buffer,T_Calculo &Calcs_Traz,SDL_Renderer *Renderer,std::string Path,SDL_Texture* Radio,SDL_Texture* Toolb,SDL_Rect &Src,SDL_Rect &Dst,const int &MAX_HEIGHT){
/* OBJETIVO: Vacia el SDL_Renderer de la ventana y borra todos los puntos y calculos realizados hasta el momento
// ENTRADA: La Pila con las coordenadas trazadas(Img_Buffer) de tipo T_PilaDatos, el puntero al renderer de la ventana(Renderer).
// SALIDA: Un booleano que compruebe que se ha vaciado todo
// PreCD: Debe haberse hecho al menos un trazado completo
// PosCD: se pueden realizar de nuevo ambos calculos
*/
     //limpia el renderer
    bool vaciado = false;
    if (flag_Undo == 0){
        std::cout << "Borrando los trazados del Agujero Mentoniano..." << std::endl;
        Calcs_Traz.Borrar_Calculo();
        Img_Buffer.Vaciar_Pila();
        Calcs_Traz.Vaciar_Calculos();
        SDL_RenderClear(Renderer);
        cargar_texturas(Renderer,Path,Radio,Toolb,Src,Dst);
        SDL_RenderPresent(Renderer);
        vaciado = (Img_Buffer.Tam_Pila_Datos() == 0);

    } else if(flag_Undo == 1){ //error
        std::cout << "Borrando los trazados del Cuerpo Mandibular y Agujero Mentoniano..." << std::endl;
        Img_Buffer.Vaciar_Pila();
        Calcs_Traz.Vaciar_Calculos();
        SDL_RenderClear(Renderer);
        cargar_texturas(Renderer,Path,Radio,Toolb,Src,Dst);
        SDL_RenderPresent(Renderer);
        vaciado = (Img_Buffer.Tam_Pila_Datos() == 0);
    }

    return vaciado;

}
//==========================================================================================================//

bool Recuperar_Trazados(T_PilaDatos &Img_Buffer,T_Calculo &Calcs_Traz, SDL_Renderer *Renderer,const int &MAX_HEIGHT,std::string Path,SDL_Texture* Radio,SDL_Texture* Toolb,SDL_Rect &Src,SDL_Rect &Dst){
    /*OBJETIVO: Vacía el SDL_Renderer de la ventana y traza de nuevo los puntos seleccionados hasta el momento, excepto el ultimo trazado.
    //ENTRADA: La Pila con las coordenadas trazadas(Img_Buffer) de tipo T_PilaDatos, el puntero al renderer de la ventana(Renderer), y la constante de altura de la ventana(MAX_HEIGHT)
    //SALIDA: un booleano (first_Op) que comprueba si se puede realizar correctamente la operación de Deshacer
    //PreCD: El puntero del Renderer debe estar asociado a la ventana principal
    //PosCD: Si se han realizado los calculos, debe devolverlos a traves de Calcs_Traz
    */
    bool proof = false;
    bool first_Op = true;
    long double cal_1 = 0;
    long double cal_2 = 0;
    Calcs_Traz.Vaciar_Calculos();
    SDL_RenderClear(Renderer); //limpia el renderer
    cargar_texturas(Renderer,Path,Radio,Toolb,Src,Dst);
    if (Img_Buffer.Borrar_Dato() == true){ //comprueba que borra la ultima operación correctamente
        Point P_Aux1;   //
        Point P_Aux2;   //Variables auxiliares para el trazado en los
        T_Recta Rct_1(Point_ToCoords(P_Aux1),Point_ToCoords(P_Aux2));
        T_Recta Rct_2(Point_ToCoords(P_Aux1),Point_ToCoords(P_Aux2));
        int Pos_Finder = Img_Buffer.Tam_Pila_Datos();
        int i = Pos_Finder-1;
        while ((i  >= 0) && (proof = true)) {
            switch(Img_Buffer.Buscar_Dato(i).get_Estado()){
                case first_Point_OP1: //caso 1: Primer punto, agujero mentoniano y trazado de la vertical
                    SDL_SetRenderDrawColor(Renderer,202, 18, 202,255);
                    Draw_Aspa(Renderer,Img_Buffer.Buscar_Dato(i).get_Coords());
                    SDL_SetRenderDrawColor(Renderer,0,255,0,255);
                    SDL_RenderDrawLine(
                                       Renderer,
                                       Img_Buffer.Buscar_Dato(i).get_Coords().get_xPos(),
                                       Img_Buffer.Buscar_Dato(i).get_Coords().get_yPos(),
                                       Img_Buffer.Buscar_Dato(i).get_Coords().get_xPos(),
                                       MAX_HEIGHT);
                break;
                case first_Point_OP2: //caso 2: Primer punto del grosor 1
                    SDL_SetRenderDrawColor(Renderer,202, 18, 202,255);
                    Draw_Aspa(Renderer,Img_Buffer.Buscar_Dato(i).get_Coords());
                break;
                case first_Point_OP3: //caso 3: Segundo punto del grosor 1
                    SDL_SetRenderDrawColor(Renderer,202, 18, 202,255);
                    Draw_Aspa(Renderer,Img_Buffer.Buscar_Dato(i).get_Coords());
                    cal_1 = distancia(Img_Buffer.Buscar_Dato(i).get_Coords(),Img_Buffer.Buscar_Dato(i+1).get_Coords()); //recalcula el calculo 1
                    Calcs_Traz.Insertar_Calculo(cal_1); //insertar calculo 1
                break;
                case second_Point_OP1: //caso 4: Primer punto de la primera recta (tangente1)
                    SDL_SetRenderDrawColor(Renderer,202, 18, 202,255);
                    Draw_Aspa(Renderer,Img_Buffer.Buscar_Dato(i).get_Coords());
                break;
                case second_Point_OP2: //caso 5: Segundo punto de la primera recta (tangente1)
                    SDL_SetRenderDrawColor(Renderer,202, 18, 202,255);
                    Draw_Aspa(Renderer,Img_Buffer.Buscar_Dato(i).get_Coords());
                    SDL_SetRenderDrawColor(Renderer,34, 236, 226,255);
                    SDL_RenderDrawLine(Renderer,Img_Buffer.Buscar_Dato(i).get_Coords().get_xPos(),Img_Buffer.Buscar_Dato(i).get_Coords().get_yPos(),Img_Buffer.Buscar_Dato(i+1).get_Coords().get_xPos(),Img_Buffer.Buscar_Dato(i+1).get_Coords().get_yPos());
                    Rct_1.set_Aval(Img_Buffer.Buscar_Dato(i+1).get_Coords(),Img_Buffer.Buscar_Dato(i).get_Coords()); //
                    Rct_1.set_Bval(Img_Buffer.Buscar_Dato(i+1).get_Coords(),Img_Buffer.Buscar_Dato(i).get_Coords()); //Configura los valores de la primera recta
                    Rct_1.set_Cval(Img_Buffer.Buscar_Dato(i+1).get_Coords(),Img_Buffer.Buscar_Dato(i).get_Coords()); //
                break;
                case second_Point_OP3: //casp 6: Primer punto de la segunda recta (tangente2)
                    SDL_SetRenderDrawColor(Renderer,202, 18, 202,255);
                    Draw_Aspa(Renderer,Img_Buffer.Buscar_Dato(i).get_Coords());
                break;
                case second_Point_OP4: //caso 7: Segundo punto de la segunda recta (tangente2) y bisectriz
                    SDL_SetRenderDrawColor(Renderer,202, 18, 202,255);
                    Draw_Aspa(Renderer,Img_Buffer.Buscar_Dato(i).get_Coords());
                    Trazados_Bisectriz_Intersecta(Img_Buffer,Renderer);
                break;
                case second_Point_OP5: //caso 8: Primer punto del calculo del grosor 2
                    SDL_SetRenderDrawColor(Renderer,202, 18, 202,255);
                    Draw_Aspa(Renderer,Img_Buffer.Buscar_Dato(i).get_Coords());
                break;
                case second_Point_OP6: //caso 9: Segundo punto del calculo del grosor 2
                    SDL_SetRenderDrawColor(Renderer,202, 18, 202,255);
                    Draw_Aspa(Renderer,Img_Buffer.Buscar_Dato(i).get_Coords());
                    cal_2 = distancia(Img_Buffer.Buscar_Dato(i).get_Coords(),Img_Buffer.Buscar_Dato(i+1).get_Coords()); //recalcula el calculo 2
                    Calcs_Traz.Insertar_Calculo(cal_2); //inserta el calculo 2
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
