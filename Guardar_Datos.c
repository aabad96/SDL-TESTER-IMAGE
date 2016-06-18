//
//  Guardar_Datos.cpp
//  Guardar proyecto
//
//  Created by Adrian on 8/6/16.
//  Copyright © 2016 Adrian. All rights reserved.
//
#include "Guardar_Datos.h"
#include <iostream>
#include <fstream>

void guardar (std::string &n_expediente,long double &cal1, long double &cal2) {
    std:: ofstream aux_file (n_expediente+".csv");
    if (aux_file.is_open())
    {
        aux_file << cal1;
        aux_file << cal2;
        aux_file.close();
    }
    else std::cout << "Unable to open file";//Error de fichero no abierto

}

