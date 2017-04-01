#ifndef _ENNEMI_HPP_
#define _ENNEMI_HPP_ 1

#include "character.hpp"
#include "world.hpp"
#include "player.hpp"

class Enemy : public Character
{
    public:
        Enemy(World *world, Player *player);
        void move(int x, int y) {}
        void serchPath();
};

#endif
