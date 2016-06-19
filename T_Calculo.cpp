#include "T_Calculo.h"

T_Calculo::T_Calculo()
{
    //ctor
}

void T_Calculo:: Borrar_Calculo(void){ //Borra el dato de calculo insertado en la ultima posición del vector

    long int tam=0;
    long int aux_tam=0;
    std::vector<long double> aux_vector;
    tam=Calculos_realizados.size();
    aux_tam=tam-1;
    if (tam>0) {
        for (int i=0; i<aux_tam; i++) {
            aux_vector[i]=Calculos_realizados[i];
            std::cout << "Peto??" << std::endl;
        }
        Calculos_realizados=aux_vector;
    }
}
bool T_Calculo:: Insertar_Calculo(const long double &Nw_Calculo){ // Inserta un calculo realizado, de tipo long double
    long int aux_calculos=0;
    bool comprobacion=false;


    Calculos_realizados.push_back(Nw_Calculo);
    aux_calculos=Calculos_realizados.size()-1;
    if (Calculos_realizados[aux_calculos]== Nw_Calculo) {
        comprobacion=true;
    }else {comprobacion=false;
    }

    return comprobacion;
}
long double T_Calculo::  Buscar_Calculo(const int &Pos){ // Busca el calculo guardado segun la posición

    return Calculos_realizados[Pos];
}
void T_Calculo :: Vaciar_Calculos(void){
    Calculos_realizados.clear();
}
