#ifndef T_RECTA_H
#define T_RECTA_H
#include"T_Coords.h"

class T_Recta
{
    public:
        T_Recta(T_Coords p1, T_Coords p2);
        double get_Aval(void);
        double get_Bval(void);
        double get_Cval(void);
        void set_Aval(T_Coords Nw_A1,T_Coords Nw_A2);
        void set_Bval(T_Coords Nw_B1,T_Coords Nw_B2);
        void set_Cval(T_Coords Nw_C1, T_Coords Nw_C2);


    protected:

    private:
        double a_value;
        double b_value;
        double c_value;
};

#endif // T_RECTA_H
