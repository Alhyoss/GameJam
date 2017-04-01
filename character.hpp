#ifndef _CHARACTER_HPP_
#define _CHARACTER_HPP_ 1

#include "world.hpp"

class Character
{
    public:
        Character(int vitality, World *world, int deffence);
        virtual void move(int x, int y) =0;

        int getVitality();
        void setVitality(int v);
        int getX() { return x; }
        int getY() { return y;}
        void setX(int x) { this->x = x; }
        void setY(int y) { this->y = y; }
        int getMapX() { return mapX; }
        int getMapY() { return mapY;}
        void setMapX(int x) { this->mapX = x; }
        void setMapY(int y) { this->mapY = y; }

    protected:
        int vitality;
        int x, y;
        int mapX, mapY;
        World *world;
        int deffence;
};

#endif
