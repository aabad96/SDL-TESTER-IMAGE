#ifndef T_CALCULOS_TRAZADO_H
#define T_CALCULOS_TRAZADO_H
#include <iostream>
#include <cmath>
#include <string>
#include "T_Recta.h"
struct Point {
    long double x;
    long double y;
};
T_Coords Point_ToCoords(const Point& p1);
Point Coords_ToPoint(T_Coords c1);
T_Recta bisectriz( const Point&, const Point&, const Point& );
Point intersecta( T_Recta r1,  T_Recta r2);
Point bisector( const Point&, const Point&, const Point& );
long double distancia(T_Coords p1, T_Coords p2);
double Pixels_To_mm(const double &Dist);

#endif
