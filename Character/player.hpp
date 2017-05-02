#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_ 1

#include "character.hpp"
#include "../World/world.hpp"

class Player : public Character
{
    public:
        Player(World *world);
        void move(int x, int y);
};

#endif
