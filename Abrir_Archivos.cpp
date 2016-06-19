#include "Abrir_Archivos.h"
std::string Pedir_Archivo(void){
    std::string aux_string;
    char Option;
    bool end_Path = false;
    while(!end_Path){
        std::cout << "Inserte el path del archivo que quiera cargar por pantalla: " << std::endl;
        std::cin >> aux_string;
        while(!std::cin){
            aux_string = "";
            std::cin >> aux_string;
        }
        std::cout << "Path del archivo insertado: " << '\n' << aux_string << std::endl;
        std::cout << "¿Esta seguro de que es el path correcto? (S/N)" << std::endl;
        std::cin >> Option;
        while(!std::cin){
            std::cin >> Option;
            std::cout << "Error 4: inserción errónea de la opción, vuelva a insertarla" << std::endl;
        }
        if (Option == 'S'){
                end_Path = true;
        } else {
            end_Path = false;
        }
    }
    return aux_string;
}
std::string ID_Paciente(std::string path_name){
    size_t aux_pos;
    std::string aux_path = "";
    std::string aux_Id = "";
    aux_pos = path_name.find_last_of('/');
    aux_path = path_name.substr(aux_pos+1);
    std::cout << "El nombre del archivo seleccionado es: " << path_name << std::endl;
    aux_pos = aux_path.find(".");
    aux_Id = aux_path.substr(0,aux_pos);
    std::cout << "ID del paciente de la radiografia: " << aux_Id << std::endl;
    return aux_Id;

}
const char * Path_Modificado(std::string Path_name){
    const char *file_name = Path_name.c_str();
    std::cout << "Path del archivo : " << file_name << std::endl;
    return file_name;
}
SDL_Texture *Abrir_Archivo(std::string Path_name,SDL_Renderer *Render,SDL_Texture *Toolbar,SDL_Rect &Source_Rect,SDL_Rect &Dest_Rect){
    SDL_RenderClear(Render);

    SDL_Texture *Radiografia = textura_gradiografia(Render,Path_name);
    std::cout << "Path Pasado: "<< Path_name << std::endl;
    cargar_texturas(Render,Path_name,Radiografia,Toolbar,Source_Rect,Dest_Rect);
    SDL_RenderPresent(Render);
    return Radiografia;
}
