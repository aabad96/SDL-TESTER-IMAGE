//Programa principal SDL Dentist_Labs
// Grupo ONPI 17/06/16

#include <iostream>
#include <string>
#include <SDL.h>
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
#include "T_Calculos.h"
SDL_Rect *Src_R = NULL;
SDL_Rect *Dst_R = NULL;
const int WIDTH = 791;
const int HEIGHT = 512;
int main(int, char**){
	// Inicia SDL y crea la ventana de carga
	SDL_Event e;
	int menu_Opts;
	SDL_Rect *Src_R = NULL;
	SDL_Rect *Dst_R = NULL;

	T_Calculos Calculos_traz;
	long double cal_1 = 0.0;
	long double cal_2 = 0.0;
	std::string file_name = "";
	std::string file_path = "";
	const char *Load_File;
	T_Coords Click_Pos;
	T_PilaDatos Pila_Coords;
    std::vector<T_ToolbarButton> Toolbar_Buttons = vec_botones();
	std::string opcion_salir = "";
	SDL_Texture *Radiografia = NULL;
	SDL_Texture *Toolbar = NULL;
	//Abre el primer archivo
	file_path = Pedir_Archivo();
    file_name = ID_Paciente(file_path);
    Load_File = Path_Modificado(file_path);
    SDL_Window *win = init_ventana();
    // crea el "renderer" de la ventana
    SDL_Renderer *ren = Init_Render(win);
	Toolbar = textura_gtool(ren);
    Radiografia = Abrir_Archivo(Load_File,ren,Toolbar,Src_R,Dst_R);


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
                std::cout << "Tecla pulsada: " << SDL_GetKeyName(key)
                          << std::endl;
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
			if (e.type == SDL_MOUSEBUTTONDOWN){
                if  (e.button.button == SDL_BUTTON_LEFT){
                    Click_Pos.set_xPos(e.button.x);
                    Click_Pos.set_yPos(e.button.y);
                    menu_Opts = Clik_Boton(Toolbar_Buttons,Click_Pos);
                }
			}

		}
        switch(menu_Opts){
            case 0:
            //Abre el archivo
                file_path = Pedir_Archivo();
                file_name = ID_Paciente(file_path);
                Load_File = Path_Modificado(file_path);
                Radiografia = Abrir_Archivo(Load_File,ren,Toolbar,Src_R,Dst_R);
            break;
            case 1:
                Operate_First_Point(ren,Pila_Coords,HEIGHT,Load_File,Radiografia,Toolbar,Src_R,Dst_R);
            break;
            case 2:
                Operate_Second_Point(ren,Pila_Coords,HEIGHT,Load_File,Radiografia,Toolbar,Src_R,Dst_R);
            break;
            case 3:
                Recuperar_Trazados(Pila_Coords,ren,HEIGHT,Load_File,Radiografia,Toolbar,Src_R,Dst_R);
            break;
            case 4:
                //Deshacer_Todo
            break;
            case 5:
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
	std::cout << "Programa finalizado. Adiós!" << std::endl;
	SDL_Quit();

	return 0;
}

