#ifndef T_CALCULO_H
#define T_CALCULO_H
#include <iostream>
#include <vector>

class T_Calculo
{
    public:
        T_Calculo(void);
        void  Borrar_Calculo(void);
        bool Insertar_Calculo(const long double &Nw_Calculo);
        long double Buscar_Calculo(const int &Pos);
        void Vaciar_Calculos(void);
    protected:

    private:
        std::vector<long double> Calculos_realizados;
};

#endif // T_CALCULOS_H
