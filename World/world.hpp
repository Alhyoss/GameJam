#ifndef _WORLD_HPP_
#define _WORLD_HPP_ 1

#include <SFML/Graphics.hpp>
#include "map.hpp"

class World
{
    public:
      
      Map* world [4][4];
      World();
      Map* getcarte(int s);
      ~World();
};

#endif
