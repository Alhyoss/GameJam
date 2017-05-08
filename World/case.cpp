#include "case.hpp"
#include <iostream>

Case::Case(int style, int x, int y)
{
    setStyle(style);
    setPosition(sf::Vector2f((x*54) + 296, y*54));
    setSize(sf::Vector2f(54-2, 54-2));
    setOutlineColor(sf::Color::Black);
    setOutlineThickness(2);
}


Case::Case(int style, int x, int y, int height, int width) : Case(style, x, y)
{
    this->windowHeight = height;
    this->windowWidth = width;
}

void Case::setStyle(int style)
{
    sprite = new sf::Texture();
    if(!sprite->loadFromFile("Img/sprite.png"))
        std::cout << "ERROR" << std::endl;
    skel = new sf::Texture();
    if(!skel->loadFromFile("Img/skel.png"))
        std::cout << "ERROR" << std::endl;

    this->style = style;
    this->setTexture(NULL);
    if (style == 0)
        this->setFillColor(sf::Color::White);
    else if (style==1)
        this->setFillColor(sf::Color::Black);
    else if (style==2)
        this->setTexture(skel, true);
    else if (style==3)
        this->setTexture(sprite, true);
    else
        this->setFillColor(sf::Color::Blue);
}

Case::~Case()
{
    delete sprite;
    delete skel;
}
