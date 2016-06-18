#ifndef COLOR_SETTINGS_H
#define COLOR_SETTINGS_H
#include<SDL.h>
#include<vector>
class Color_Settings
{
    public:
        Color_Settings();
        virtual ~Color_Settings();

    protected:

    private:
        vector<SDL_Color> Colors;
};

#endif // COLOR_SETTINGS_H
