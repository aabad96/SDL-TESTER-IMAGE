#include "Calculos_Trazado.h"
using namespace std;



Point Coords_ToPoint(T_Coords c1){
    Point Aux_point;
    Aux_point.x = (long double)c1.get_xPos();
    Aux_point.y = (long double)c1.get_yPos();
    return Aux_point;
}



T_Coords Point_ToCoords(const Point& p1){
    T_Coords Aux_coords;
    Aux_coords.set_xPos((Sint32)p1.x);
    Aux_coords.set_yPos((Sint32)p1.y);
    return Aux_coords;
}



long double distancia(T_Coords p1, T_Coords p2 ) {
    long double xx = (long double)p2.get_xPos() - (long double)p1.get_xPos();
    long double yy = (long double)p2.get_yPos() - (long double)p1.get_yPos();
    return sqrt( xx*xx + yy*yy );
}

// calcula el punto de intersección de dos rectas
Point intersecta( T_Recta r1,  T_Recta r2 ) {
    double xx = (r2.get_Bval() * r1.get_Cval() - r1.get_Bval() * r2.get_Cval()) / (r2.get_Aval() * r1.get_Bval() - r1.get_Aval() * r2.get_Bval());
    double yy = (r2.get_Aval() * r1.get_Cval() - r1.get_Aval() * r2.get_Cval()) / (r1.get_Aval() * r2.get_Bval() - r2.get_Aval() * r1.get_Bval());
    return Point {xx, yy};
}

// devuelve el punto sobre el segmento entre P1 y P3 que, al unirlo a P2, define la bisectriz
Point bisector( const Point& p1, const Point& p2, const Point& p3 ) {
    T_Coords Aux_p1;
    T_Coords Aux_p2;
    T_Coords Aux_p3;
    Aux_p1.set_xPos(p1.x);
    Aux_p1.set_yPos(p1.y);
    Aux_p2.set_xPos(p2.x);
    Aux_p2.set_yPos(p2.y);
    Aux_p3.set_xPos(p3.x);
    Aux_p3.set_yPos(p3.y);
    long double d12 = distancia(Aux_p1, Aux_p2);
    long double d23 = distancia(Aux_p2, Aux_p3);
    long double fraccion = d12 / (d12 + d23);
    long double xx = p1.x + fraccion * (p3.x - p1.x);
    long double yy = p1.y + fraccion * (p3.y - p1.y);
    return Point {xx, yy};
}
