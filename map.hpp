#ifndef _MAP_HPP_
#define _MAP_HPP_ 1

#include "case.hpp"

class Map
{
    public:
      Case* map [14][14];
      Map(int **carte);
      ~Map();
};

#endif
