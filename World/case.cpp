#include "case.hpp"
#include <iostream>

Case::Case(int style, int x, int y, int height, int width)
{
    this->windowHeight = height;
    this->windowWidth = width;
    int a, b;
    b = windowHeight/14;
    a = (windowWidth - windowHeight)/2;

    setStyle(style);
    setPosition(sf::Vector2f((x*b) + a, y*b));
    setSize(sf::Vector2f(b-2, b-2));
    setOutlineColor(sf::Color::Black);
    setOutlineThickness(2);
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
