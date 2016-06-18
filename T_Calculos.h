//
//  T_Calculos.h
//  insertar calculos
//
//  Created by Adrian on 18/6/16.
//  Copyright © 2016 Adrian. All rights reserved.
//
#ifndef T_Calculos_H
#define T_Calculos_H
#include <iostream>
#include <vector>

class T_Calculos
{
public:
    T_Calculos(void);
    void  Borrar_Calculo(void);
    bool Insertar_Calculo(const long double &Nw_Calculo);
    long double Buscar_Calculo(const int &Pos);
protected:
    
private:
    std::vector<long double> Calculos_realizados;
};
 // T_CALCULOS_H
