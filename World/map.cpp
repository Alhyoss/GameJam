#include "map.hpp"
#include <iostream>

Map::Map(int **carte, int height, int width)
{
    for (int i=0; i < 14; i++)
    {
        for (int j=0; j<14; j++)
            map[i][j] = new Case(carte[i][j], i, j, height, width);
    }
}

Map::~Map()
{
    for (int i=0; i < 14; i++)
    {
        for (int j=0; j<14; j++)
            delete map[i][j];
    }
}
