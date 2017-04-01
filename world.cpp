#include "world.hpp"

World::World()
{
    int worldpat [4][4] = {{0,1,0,0},
                           {2,3,0,0},
                           {0,0,0,0},
                           {0,0,0,0}};
    for (int i=0; i < 4; i++)
    {
        for (int j=0; j<4; j++)
            world [i][j] = getcarte(worldpat[i][j]);
    }
}

Map* World::getcarte(int s)
{
    if (s==0)
    {
        int **carte = new int*[14];
        for(int i=0; i<14; i++)
            carte[i] = new int[14];
        int c[14][14] = {{1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                         {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
                         {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
                         {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
                         {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
                         {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
                         {1,0,0,0,0,0,0,0,0,0,0,0,0,5},
                         {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
                         {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
                         {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
                         {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
                         {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
                         {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
                         {1,1,1,1,1,1,4,1,1,1,1,1,1,1}};
        for(int i=0; i<14; i++)
        {
            for(int j=0; j<14; j++)
                carte[i][j] = c[i][j];
        }
        return new Map(carte);
    }
    else if (s==1)
    {
        int **carte = new int*[14];
        for(int i=0; i<14; i++)
            carte[i] = new int[14];
        int c[14][14] = {{1,1,1,1,1,1,6,1,1,1,1,1,1,1},
                         {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
                         {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
                         {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
                         {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
                         {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
                         {1,0,0,0,0,0,0,0,0,0,0,0,0,5},
                         {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
                         {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
                         {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
                         {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
                         {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
                         {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
                         {1,1,1,1,1,1,1,1,1,1,1,1,1,1}};
        for(int i=0; i<14; i++)
        {
            for(int j=0; j<14; j++)
                carte[i][j] = c[i][j];
        }
        return new Map(carte);
    }
    else if (s==2)
    {
        int **carte = new int*[14];
        for(int i=0; i<14; i++)
            carte[i] = new int[14];
        int c[14][14] = {{1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                         {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
                         {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
                         {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
                         {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
                         {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
                         {7,0,0,0,0,0,0,0,0,0,0,0,0,1},
                         {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
                         {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
                         {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
                         {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
                         {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
                         {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
                         {1,1,1,1,1,1,4,1,1,1,1,1,1,1}};
        for(int i=0; i<14; i++)
        {
            for(int j=0; j<14; j++)
                carte[i][j] = c[i][j];
        }
        return new Map(carte);
    }
    else
    {
        int **carte = new int*[14];
        for(int i=0; i<14; i++)
            carte[i] = new int[14];
        int c[14][14] = {{1,1,1,1,1,1,6,1,1,1,1,1,1,1},
                         {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
                         {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
                         {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
                         {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
                         {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
                         {7,0,0,0,0,0,0,0,0,0,0,0,0,1},
                         {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
                         {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
                         {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
                         {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
                         {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
                         {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
                         {1,1,1,1,1,1,1,1,1,1,1,1,1,1}};
        for(int i=0; i<14; i++)
        {
            for(int j=0; j<14; j++)
                carte[i][j] = c[i][j];
        }
        return new Map(carte);
    }
}