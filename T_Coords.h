#ifndef T_COORDS_H
#define T_COORDS_H
#include <SDL.h>

class T_Coords
{
    public:
        T_Coords();

        void set_xPos(Sint32 Nw_val);
        void set_yPos(Sint32 Nw_val);
        Sint32 get_xPos(void);
        Sint32 get_yPos(void);

    protected:

    private:
        Sint32 x;
        Sint32 y;
};

#endif // T_COORDS_H
