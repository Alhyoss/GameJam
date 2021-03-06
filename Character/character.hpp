#ifndef _CHARACTER_HPP_
#define _CHARACTER_HPP_ 1

#include "../World/world.hpp"

class Character
{
    public:
        Character(int vitality, World *world);
        void attack(Character* car);
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
        int tour;
        bool alive;


    protected:
        int vitality;
        int x, y;
        int mapX, mapY;
        World *world;
        int deffence, atk;


};

#endif
