#include "player.hpp"

#include <iostream>
#include <ctime>
#include <cstdlib>




Player::Player(World *world) : Character(100, world)
{
    setMapX(0);
    setMapY(0);
    setX(7);
    setY(7);
    world->world[getMapX()][getMapY()]->map[getX()][getY()]->setStyle(3);
    deffence=15;
    atk = 22;
}

void Player::move(int x, int y)
{
    int style = world->world[getMapX()][getMapY()]->map[getX()+x][getY()+y]->style;

    if(style == 1 || style == 2)
        return;
    if(getX() == 0)
        world->world[getMapX()][getMapY()]->map[getX()][getY()]->setStyle(6);
    else if(getX() == 13)
        world->world[getMapX()][getMapY()]->map[getX()][getY()]->setStyle(4);
    else if(getY() == 0)
        world->world[getMapX()][getMapY()]->map[getX()][getY()]->setStyle(7);
    else if(getY() == 13)
        world->world[getMapX()][getMapY()]->map[getX()][getY()]->setStyle(5);
    else
        world->world[getMapX()][getMapY()]->map[getX()][getY()]->setStyle(0);
    if(style == 0)
    {
        setX(getX()+x);
        setY(getY()+y);
        world->world[getMapX()][getMapY()]->map[getX()][getY()]->setStyle(3);
    }
    else if(style == 4)
    {
        setMapY(getMapY()+1);
        setX(0);
        world->world[getMapX()][getMapY()]->map[getX()][getY()]->setStyle(3);
    }
    else if(style == 5)
    {
        setMapX(getMapX()+1);
        setY(0);
        world->world[getMapX()][getMapY()]->map[getX()][getY()]->setStyle(3);
    }
    else if(style == 6)
    {
        setMapY(getMapY()-1);
        setX(13);
        world->world[getMapX()][getMapY()]->map[getX()][getY()]->setStyle(3);
    }
    else if(style == 7)
    {
        setMapX(getMapX()-1);
        setY(13);
        world->world[getMapX()][getMapY()]->map[getX()][getY()]->setStyle(3);
    }
}
