//
//  main.cpp
//  Guardar proyecto
//
//  Created by Adrian on 8/6/16.
//  Copyright © 2016 Adrian. All rights reserved.
//
#include "Guardar_Datos.h"



void guardar (std::string &n_expediente,long double &cal1, long double &cal2) {
    std:: ofstream aux_file (n_expediente+".csv");
    if (aux_file.is_open())
    {
        std::cout << "Guardando los datos en el archivo con nombre: <" << n_expediente << ">" << std::endl;
        aux_file << cal1;
        aux_file << cal2;
        aux_file.close();
    }
    else std::cout << "Error : Imposible abrir el fichero";//Error de fichero no abierto

}

