#include "T_Recta.h"

T_Recta::T_Recta(T_Coords p1, T_Coords p2)
{
    a_value = (double) p2.get_xPos() - (double) p1.get_xPos();
    b_value = (double) p2.get_yPos() - (double) p1.get_yPos();
    c_value = (double) p1.get_yPos() * (double)((double)p2.get_xPos() - (double)p1.get_xPos()) - (double)p1.get_xPos() * ((double)p2.get_yPos() - (double)p1.get_yPos());
}
double T_Recta :: get_Aval(void){
    return a_value;
}
double T_Recta :: get_Bval(void){
    return b_value;
}
double T_Recta :: get_Cval(void){
    return c_value;
}
void T_Recta :: set_Aval(T_Coords Nw_A1,T_Coords Nw_A2){
    a_value = (double) Nw_A2.get_xPos() - (double) Nw_A1.get_xPos();
}
void T_Recta :: set_Bval(T_Coords Nw_B1,T_Coords Nw_B2){
    b_value = (double) Nw_B2.get_yPos() - (double) Nw_B1.get_yPos();
}
void T_Recta :: set_Cval(T_Coords Nw_C1, T_Coords Nw_C2){
    c_value = (double) Nw_C1.get_yPos() * ((double)Nw_C2.get_xPos() - (double)Nw_C1.get_xPos()) - (double)Nw_C1.get_xPos() * ((double)Nw_C2.get_yPos() - (double)Nw_C1.get_yPos());
}


