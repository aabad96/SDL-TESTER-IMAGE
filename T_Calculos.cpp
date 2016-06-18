#include "T_Calculos.h"

T_Calculos::T_Calculos()
{
    //ctor
}

void T_Calculos:: Borrar_Calculo(void){ //Borra el dato de calculo insertado en la ultima posición del vector

    long int tamaño=0,aux_tamaño=0;
    std::vector<long double> aux_vector;
    tamaño=Calculos_realizados.size();
    aux_tamaño=tamaño-2;
    if (tamaño>0) {
        for (int i=0; i<aux_tamaño; i++) {
            aux_vector[i]=Calculos_realizados[i];
        }
        Calculos_realizados=aux_vector;
    }
}
bool T_Calculos:: Insertar_Calculo(const long double &Nw_Calculo){ // Inserta un calculo realizado, de tipo long double
    long int aux_calculos=0,aux2_calculos=0;
    bool comprobacion=false;
    
    aux_calculos=Calculos_realizados.size();
    Calculos_realizados[aux_calculos]=Nw_Calculo;
    aux2_calculos=aux_calculos+1;
    
    if (Calculos_realizados.size()==aux2_calculos) {
        comprobacion=true;
    }else comprobacion=false;

        return comprobacion;
}
long double T_Calculos::  Buscar_Calculo(const int &Pos){ // Busca el calculo guardado segun la posición
    
    return Calculos_realizados[Pos];
}
