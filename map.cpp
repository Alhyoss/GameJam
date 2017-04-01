#include "map.hpp"
#include <iostream>

Map::Map(int **carte)
{
    for (int i=0; i < 14; i++)
    {
        for (int j=0; j<14; j++)
            map [i][j] = new Case (carte[i][j], i, j);
    }
}
