#ifndef T_CALCULOS_H
#define T_CALCULOS_H


class T_Calculos
{
    public:
        T_Calculos(void);
        void  Borrar_Calculo(void);
        bool Insertar_Calculo(long double Nw_Calculo);
        long double Buscar_Calculo(int Pos);
    protected:

    private:
        std::vector<long double> Calculos_realizados;
};

#endif // T_CALCULOS_H
