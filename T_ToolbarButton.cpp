#include "T_ToolbarButton.h"
#include "T_Coords.h"
T_ToolbarButton::T_ToolbarButton()
{
    Btn_Class = DEFAULT_B;
    Left_Corner_Point = T_Coords();
    Right_Corner_Point = T_Coords();
}
void T_ToolbarButton :: set_LeftPoint(T_Coords Nw_Coord)
{
    Left_Corner_Point = Nw_Coord;
}
void T_ToolbarButton :: set_RightPoint(T_Coords Nw_Coord)
{
    Right_Corner_Point = Nw_Coord;
}
void T_ToolbarButton :: set_ButtonType(Button_Type Nw_Type)
{
    Btn_Class = Nw_Type;
}
T_Coords T_ToolbarButton :: get_LeftPoint(void)
{
    return Left_Corner_Point;
}
T_Coords T_ToolbarButton :: get_RightPoint(void)
{
    return Right_Corner_Point;
}
Button_Type T_ToolbarButton ::  get_ButtonType(void)
{
    return Btn_Class;
}

