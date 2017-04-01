#ifndef _ENNEMI_HPP_
#define _ENNEMI_HPP_ 1

#include "character.hpp"
#include "world.hpp"

class Enemy : public Character
{
    public:
        Enemy(World *world);
        void move(int x, int y) {}
};

#endif
