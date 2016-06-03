#include "T_Coords.h"

T_Coords::T_Coords()
{
    x = 0;
    y = 0;
    //ctor
}
void T_Coords :: set_xPos(Sint32 Nw_val)
{
    x = Nw_val;
}
void T_Coords :: set_yPos(Sint32 Nw_val)
{
    y = Nw_val;
}
Sint32 T_Coords :: get_xPos(void)
{
    return x;
}
Sint32 T_Coords :: get_yPos(void)
{
    return y;
}
