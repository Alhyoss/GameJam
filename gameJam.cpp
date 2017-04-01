#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>

#include "world.hpp"
#include "player.hpp"
#include "enemy.hpp"
using namespace std;

void handleEvents(sf::RenderWindow &window, Player *player);

int main()
{
    sf::RenderWindow window(sf::VideoMode(700, 850), "GameJam",
                            sf::Style::Titlebar | sf::Style::Close);

    World* world = new World();
    Player *p = new Player(world);
    Enemy *e = new Enemy(world, p);
    sf::Font font;
    if (!font.loadFromFile("arial.ttf"))
	   {
    // error...
	   }
     std::vector<sf::RectangleShape*> lifejoueur;
     for (int i = 0; i < p->getVitality(); i++) {
       sf::RectangleShape *r =new sf::RectangleShape(sf::Vector2f(10,10));
       r->setPosition((i+1)*20, 700);
       r->setFillColor(sf::Color::Red);
       lifejoueur.push_back(r);
     }
    while(window.isOpen())
    {
        handleEvents(window, p);

        window.clear(sf::Color::Black);
        sf::Text joueur;
        string J;
        J = "Joueur";
        joueur.setString(J);
        joueur.setFont(font);
        joueur.setCharacterSize(24);
        joueur.setColor(sf::Color::White);
        joueur.setPosition(40, 750);
        sf::Text enemie;
        string E;
        E = "Ennemi";
        enemie.setString(E);
        enemie.setFont(font);
        enemie.setCharacterSize(24);
        enemie.setColor(sf::Color::White);
        enemie.setPosition(550, 750);

        for(int i=0; i < 14; i++)
        {
            for(int j=0; j<14; j++)
                window.draw(*(world->world[p->getMapX()][p->getMapY()]->map[i][j]));
        }
        window.draw(joueur);
        window.draw(enemie);
        for(sf::RectangleShape* r : lifejoueur)
          window.draw(*r);
        window.display();

    }
    return 0;
}

void handleEvents(sf::RenderWindow &window, Player *player)
{
    sf::Event event;
    while(window.pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
            window.close();
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            if(player->getX() != 0)
                player->move(-1, 0);
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            if(player->getX() != 13)
                player->move(1, 0);
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            if(player->getY() != 0)
                player->move(0, -1);
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            if(player->getY() != 13)
                player->move(0, 1);
        }
    }
}
