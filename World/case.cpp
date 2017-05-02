#include "case.hpp"
#include <iostream>

Case::Case(int style, int x, int y)
{
    //int a;
    //int b;
    //a= heig14;
    setStyle(style);
    setPosition(sf::Vector2f((x*50) + 296, y*50));
    setSize(sf::Vector2f(54-2, 54-2));
    setOutlineColor(sf::Color::Black);
    setOutlineThickness(2);
}

void Case::setStyle(int style)
{
    sf::Texture *imageSource = new sf::Texture();
    if(!imageSource->loadFromFile("Img/sprite.png"))
        std::cout << "ERROR" << std::endl;
    sf::Texture *skel = new sf::Texture();
    if(!skel->loadFromFile("Img/skel.png"))
        std::cout << "ERROR" << std::endl;
    //sf::Texture *marb = new sf::Texture();
    //if(!marb->loadFromFile("Img/marb.png"))
    //    std::cout << "ERROR" << std::endl;

    this->style = style;
    this->setTexture(NULL);
    if (style == 0)
        this->setFillColor(sf::Color::White);
    else if (style==1)
        this->setFillColor(sf::Color::Black);
    else if (style==2)
        this->setTexture(skel, true);
    else if (style==3)
        this->setTexture(imageSource, true);
    else
        this->setFillColor(sf::Color::Blue);
}
