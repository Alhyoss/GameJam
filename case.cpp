#include "case.hpp"
#include <iostream>

Case::Case(int style, int x, int y)
{
    setStyle(style);
    setPosition(sf::Vector2f(x*50, y*50));
    setSize(sf::Vector2f(50-2, 50-2));
    setOutlineColor(sf::Color::Black);
    setOutlineThickness(2);
}

void Case::setStyle(int style)
{
  sf::Texture *imageSource = new sf::Texture();
  if(!imageSource->loadFromFile("sprite.png"))
     {
      std::cout << "ERROR" << std::endl;
      }

    this->style = style;
    this->setTexture(NULL);
    if (style == 0)
        this->setFillColor(sf::Color::White);
    else if (style==1)
        this->setFillColor(sf::Color::Black);
    else if (style==2)
        this->setFillColor(sf::Color::Red);
    else if (style==3)
        this->setTexture(imageSource, true);
    else
        this->setFillColor(sf::Color::Blue);
}
