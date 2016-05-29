#ifndef T_DATO_H
#define T_DATO_H
#include <SDL.h>
#include <SDL_image.h>
class T_Dato
{
    enum  Buffer_State {point1, point2, iniitimg};
    public:
        T_Dato(SDL_Texture D_Texture, Buffer_State D_State);
        void Get_Textura(SDL_Texture Nw_Textura);
        SDL_Texture Set_Textura();
        void Set_Estado(Buffer_State Nw_Estado);
        Buffer_State Get_Estado();


    protected:

    private:
        SDL_Texture Textura;
        Buffer_State Estado_Textura;
}

#endif // T_DATO_H
