#ifndef _WORLD_HPP_
#define _WORLD_HPP_ 1

#include <SFML/Graphics.hpp>
#include "map.hpp"

class World
{
    public:
        World(int height, int width);
        ~World();

    private:
        Map* getcarte(int s);

    public:
        Map* world [4][4];

    private:
        int windowHeight, windowWidth;
};

#endif
