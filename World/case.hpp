#ifndef _CASE_HPP_
#define _CASE_HPP_ 1

#include <SFML/Graphics.hpp>

class Case : public sf::RectangleShape
{
    public:
      int style;
      Case(int style, int x, int y);
      Case(int style, int x, int y, int height, int width);
      void setStyle(int style);
      ~Case();

    private:
      int windowHeight, windowWidth;
      sf::Texture *sprite, *skel;
};

#endif
