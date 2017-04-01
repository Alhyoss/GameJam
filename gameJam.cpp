#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

void handleEvents(sf::RenderWindow *window);

int main()
{
    sf::RenderWindow *window = new sf::RenderWindow(sf::VideoMode(700, 700), "GameJam",
                            sf::Style::Titlebar | sf::Style::Close);

    while(window->isOpen())
    {
        handleEvents(window);

        window->clear(sf::Color::Black);
        window->display();
    }
    return 0;
}

void handleEvents(sf::RenderWindow *window)
{

    sf::Event event;
    while(window->pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
            window->close();
    }
}
