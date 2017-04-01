#ifndef _ENNEMI_HPP_
#define _ENNEMI_HPP_ 1

#include "character.hpp"
#include "world.hpp"
#include "player.hpp"

class Enemy : public Character
{
    public:
        Enemy(World *world, Player *p);
        void move(int x, int y) {}
        void searchPath();

    private:
        Player *player;
};

class node
{
    node(int f, int h, int g, int x, int y)
    {
        fCost = f;
        hCost = h;
        gCost = g;
    }
    int x, Y;
    int fCost, hCost, gCost;
};

#endif
