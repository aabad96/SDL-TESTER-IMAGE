//Programa principal SDL Dentist_Labs
// Grupo ONPI 17/06/16

#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include "Funciones_Texto.h"
#include "cleanup.h"
#include "Abrir_Archivos.h"
#include "T_Coords.h"
#include "Calculos_Trazado.h"
#include "Comp_boton.h"
#include "Operaciones_Trazado_Deshacer.h"
#include "T_PilaDatos.h"
#include "Funciones_Imagen.h"
#include "Guardar_Datos.h"
#include "T_ToolbarButton.h"
#include "T_Calculo.h"
const int WIDTH = 791;
const int HEIGHT = 512;
int main(int, char**){
	// Inicia SDL y crea la ventana de carga
	SDL_Event e;
	int menu_Opts;
	SDL_Rect Src_R;
	SDL_Rect Dst_R;
    Src_R.x = 0;
    Src_R.y = 0;
    Src_R.w = 3166;
    Src_R.h = 1534;
    Dst_R.x = 0;
    Dst_R.y = 77;
    Dst_R.w = 791;
    Dst_R.h = 435;

    T_Calculo Calculos_Archivo;
	long double cal_1 = 0.0;
	long double cal_2 = 0.0;
	bool Agj_Mentoniano = false;
	bool Crp_Mandibular = false;
	std::string file_name = "";
	std::string file_path = "";
	T_Coords Click_Pos;
	T_PilaDatos Pila_Coords;
    std::vector<T_ToolbarButton> Toolbar_Buttons = vec_botones();
	std::string opcion_salir = "";
	SDL_Texture *Radiografia = NULL;
	SDL_Texture *Toolbar = NULL;
	//Abre el primer archivo
	file_path = Pedir_Archivo();
    file_name = ID_Paciente(file_path);
    SDL_Window *win = init_ventana();
    // crea el "renderer" de la ventana
    SDL_Renderer *ren = Init_Render(win);
	Toolbar = textura_gtool(ren);

    Radiografia = Abrir_Archivo(file_path,ren,Toolbar,Src_R,Dst_R);

	//For tracking if we want to quit
	bool quit = false;
	while (!quit){
        menu_Opts = 8;
		//Read any events that occurred
		while (SDL_PollEvent(&e)){
			//If user closes the window
			if (e.type == SDL_QUIT){
				quit = true;
			}
			//If user presses any key
			if (e.type == SDL_KEYDOWN) {
                SDL_Keycode key = e.key.keysym.sym;

                if (key == SDLK_ESCAPE){
                    std::cout << "¿Seguro que quiere salir del programa? (S/N)" << std::endl;
                    std::cin >> opcion_salir;
                    if(!std::cin){
                        std::cout << "error 1: incorrecta inserción de la opcion del programa. Cerrando..." << std::endl;
                        quit = true;
                    } else if ((opcion_salir == "S") ||(opcion_salir == "Si") || (opcion_salir == "yes")){
                        quit = true;
                    } else {
                        quit = false;
                    }
                }
			}
			//If user clicks the mouse
			else if (e.type == SDL_MOUSEBUTTONDOWN){

                if  (e.button.button == SDL_BUTTON_LEFT){
                    Click_Pos.set_xPos(e.button.x);
                    Click_Pos.set_yPos(e.button.y);
                    menu_Opts = Clik_Boton(Toolbar_Buttons,Click_Pos);
                }
			}

		}
        switch(menu_Opts){
            case 0: //Boton Abrir
                std::cout << "Abriendo un nuevo archivo, siga las instrucciones por consola de comandos..." << std::endl;
                file_path = Pedir_Archivo();
                file_name = ID_Paciente(file_path);
                Deshacer_Todos_Trazados(1,Pila_Coords,Calculos_Archivo,ren,file_path,Radiografia,Toolbar,Src_R,Dst_R,HEIGHT); //Vacia todo
                Agj_Mentoniano = false;
                Crp_Mandibular = false;
                Radiografia = Abrir_Archivo(file_path,ren,Toolbar,Src_R,Dst_R);
            break;
            case 1: //Boton Agujero Mentoniano
                std::cout << "Primera operacion: Calculo del Agujero Mentoniano" << std::endl;
                if (Agj_Mentoniano == true){
                    std::cout << "Error : No se puede realizar el trazado ya que esta realizado."
                    << '\n' << "Borre los puntos con la operación Deshacer Todo" << std::endl;
                } else {
                    Agj_Mentoniano = Operate_First_Point(Toolbar_Buttons,Calculos_Archivo,ren,Pila_Coords,HEIGHT,file_path,Radiografia,Toolbar,Src_R,Dst_R);
                    cal_1 = Calculos_Archivo.Buscar_Calculo(0);
                    std::cout << '\n' << "Resultado Agujero Mentoniano: " << cal_1 << " mm" << std::endl;
                    Agj_Mentoniano = true;
                }
            break;
            case 2: //Boton Cuerpo Mandibular
                std::cout << "Segunda operacion: Calculo del Cuerpo Mandibular" << std::endl;
                if (Crp_Mandibular == true){
                    std::cout << "Error :No se puede realizar el trazado ya que esta realizado."
                    << '\n' << "Borre los puntos con la operación Deshacer Todo" << std::endl;
                } else if ((Agj_Mentoniano == true) &&(Crp_Mandibular == false)) {
                    Operate_Second_Point(Toolbar_Buttons,Calculos_Archivo,ren,Pila_Coords,HEIGHT,file_path,Radiografia,Toolbar,Src_R,Dst_R);
                    cal_2 = Calculos_Archivo.Buscar_Calculo(1);
                    std::cout << '\n' << "Resultado Cuerpo Mandibular: " << cal_2 << " mm" << std::endl;
                    Crp_Mandibular = true;
                }
            break;
            case 3: //Boton Deshacer Puntos
                std::cout << "No se puede realizar el deshacer por puntos,solo permitido" <<
                 '\n'<< "durante la ejecucion de Agujero Mentoniano o Cuerpo Mandibular" << std::endl;
            break;
            case 4: //Boton Deshacer Todo
                if((Agj_Mentoniano == true) &&(Crp_Mandibular == false)){
                    Deshacer_Todos_Trazados(0,Pila_Coords,Calculos_Archivo,ren,file_path,Radiografia,Toolbar,Src_R,Dst_R,HEIGHT);
                    Agj_Mentoniano = false;
                } else if ((Crp_Mandibular == true)&&(Agj_Mentoniano == true)){
                    Deshacer_Todos_Trazados(1,Pila_Coords,Calculos_Archivo,ren,file_path,Radiografia,Toolbar,Src_R,Dst_R,HEIGHT);
                    Agj_Mentoniano = false;
                    Crp_Mandibular = false;
                }
            break;
            case 5://Boton Guardar
                std::cout << "Sexta operacion: Guardado de datos en un archivo .csv" << std::endl;
                guardar(file_name,cal_1,cal_2);
            break;
            case 9:
                std::cout << "Error 3: click fuera de la pantalla, por favor vuelva a la ventana" <<'\n'
                << "del programa." << std::endl;
            break;
        }

	}
    //Take a quick break after all that hard work
    SDL_Delay(1000);
    // limpia y termina
    cleanup(ren, win); // SDL_DestroyTexture(tex); SDL_DestroyRenderer(ren); SDL_DestroyWindow(win);
	std::cout << "Programa finalizado. Bye!" << std::endl;
	SDL_Quit();

	return 0;
}

