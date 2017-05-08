#ifndef _WORLD_HPP_
#define _WORLD_HPP_ 1

#include <SFML/Graphics.hpp>
#include "map.hpp"

class World
{
    public:
        World();
        World(int height, int width);
        ~World();

    private:
        Map* getcarte(int s);

    public:
        Map* world [4][4];

    private:
        int windowHeight = 0, windowWidth = 0;
};

#endif
