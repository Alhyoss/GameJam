#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <ctime>
#include <cstdlib>

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


     sf::RectangleShape lifejoueur;
     lifejoueur.setSize(sf::Vector2f(p->getVitality(), 10));
     sf::RectangleShape lifeennemi;
     lifeennemi.setSize(sf::Vector2f(e->getVitality(), 10));
     lifeennemi.setFillColor(sf::Color::Red);
     lifejoueur.setFillColor(sf::Color::Red);
     lifejoueur.setPosition(30, 800);
     lifeennemi.setPosition(540, 800);

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
        window.draw(lifeennemi);
        window.draw(lifejoueur);

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
