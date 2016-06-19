#include "T_PilaDatos.h"
using namespace std;

T_PilaDatos::T_PilaDatos()
{
    vector<T_Dato> Pila_Datos;
    Pila_Carga = Pila_Datos;
    //ctor
}

bool T_PilaDatos :: Pila_Vacia(void)
{
    return (Pila_Carga.size() == 0);
}

bool T_PilaDatos :: Insertar_Dato(T_Dato Nw_Dato)
/*OBJETIVO:
//ENTRADA:
//SALIDA: un booleano, que comrpueba que el mismo estado del dato insertado (Nw_Dato) es igual al ultimo elemento insertado)
//PreCD: El dato insertado debe tener un estado asociado almacenado válido
*/
{
    int Tam_Pila = Pila_Carga.size();
    vector<T_Dato> Aux_Pila;
    if (Tam_Pila == 0){
        Pila_Carga.push_back(Nw_Dato);
    } else{
        Aux_Pila.push_back(Nw_Dato);
        for (int i = 0; i < Tam_Pila; i++){
            Aux_Pila.push_back(Pila_Carga[i]);
        }
        Pila_Carga = Aux_Pila;
    }
    return(Nw_Dato.get_Estado() == Pila_Carga[0].get_Estado());
}

T_Dato T_PilaDatos :: Buscar_Dato( int Pos_Pila)
{
    return Pila_Carga[Pos_Pila];
}

T_Dato T_PilaDatos :: Primer_Dato(void)
{
    return Pila_Carga[0];
}

T_Dato T_PilaDatos :: Ultimo_Dato(void)
{
    return Pila_Carga[Pila_Carga.size()-1];
}

T_Dato T_PilaDatos :: Siguiente(int Pos_Pila){
    if ((Pos_Pila <= 0)||(Pila_Carga.size() == 0)){
        cout << "Error 1: no se puede devolver el dato" << endl;
        return Pila_Carga[0];
    }
    else if (Pos_Pila  >= (Pila_Carga.size())){
        cout << "Error 2: Siguiente() dato no encontrado" << endl;
        return Pila_Carga[0];
    } else {
    return Pila_Carga[Pos_Pila+1];
    }
}

T_Dato T_PilaDatos :: Anterior(int Pos_Pila)
{
  if (Pos_Pila <= 0){
    cout << "Error 3: dato no encontrado" << endl;
    return Pila_Carga[0];
  } else {
    return Pila_Carga[Pos_Pila-1];
  }
}

int T_PilaDatos ::  Buscar_Estado(Buffer_State Estado_Img)
{
    int Bus_Pila = Pila_Carga.size() - 1;
    while (Pila_Carga[Bus_Pila].get_Estado() != Estado_Img){
        Bus_Pila--;
    }
    return Bus_Pila;
}

void T_PilaDatos :: Modificar_Dato(Buffer_State Nw_Estado, Sint32 Nw_x ,Sint32 Nw_y, int Pos_Pila)
{
    Pila_Carga[Pos_Pila].set_Estado(Nw_Estado);
    Pila_Carga[Pos_Pila].set_Coords(Nw_x,Nw_y);
}

int T_PilaDatos :: Cantidad_Estado(Buffer_State Estado_Img, int Pos_Pila)
{
    int Bus_Pila = Pila_Carga.size();
    return Bus_Pila;
}
bool T_PilaDatos :: Borrar_Dato(void){
    int Bus_Pila = Pila_Carga.size();
    if (Bus_Pila == 0){
        return false;
    } else {
        Pila_Carga.erase(Pila_Carga.begin());
        return true;
    }
}
int T_PilaDatos :: Tam_Pila_Datos(void){

    return Pila_Carga.size();
}
bool T_PilaDatos :: Vaciar_Pila(void){
    Pila_Carga.clear();
    return (Pila_Carga.size() == 0);
}
