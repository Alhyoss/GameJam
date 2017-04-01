#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <ctime>
#include <cstdlib>

#include "world.hpp"
#include "player.hpp"
#include "enemy.hpp"
using namespace std;

void handleEvents(sf::RenderWindow &window, Player *player, int aqui, Enemy *enemy);

int main()
{
    sf::RenderWindow window(sf::VideoMode(700, 850), "GameJam",
                            sf::Style::Titlebar | sf::Style::Close);

    World* world = new World();
    int aqui = 1;
    Player *p = new Player(world);
    Enemy *e = new Enemy(world, p);
    sf::Font font;
    font.loadFromFile("arial.ttf");

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
      if(p->tour<=0 && e->alive)
      {
        if(aqui==1)
            e->tour=2;
        aqui = 0;
      }
      if (e->tour<=0 && p->alive)
      {
        if(aqui==0)
            p->tour=2;
        aqui = 1;
      }

        handleEvents(window, p, aqui, e);
        lifejoueur.setSize(sf::Vector2f(p->getVitality(), 10));
        lifeennemi.setSize(sf::Vector2f(e->getVitality(), 10));
        if(aqui == 0)
        {
            if(e->getMapX() != p->getMapX() || e->getMapY() != p->getMapY())
                e->tour =0;
            else if(e->alive)
            {
                if((abs(p->getX() - e->getX()) + abs(p->getY() - e->getY())) != 1)
                {
                    e->searchPath();
                    e->move();
                }
                else
                {
                    e->attack(p);
                }
            }
        }
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

        if (e->alive==false)
        {

        }

        window.draw(joueur);
        if (e->alive==true)
        {
          window.draw(enemie);
        }
        window.draw(lifeennemi);
        window.draw(lifejoueur);

        window.display();

    }
    delete world;
    delete p;
    delete e;

    return 0;
}

void handleEvents(sf::RenderWindow &window, Player *player, int aqui, Enemy *enemy)
{
    sf::Event event;
    while(window.pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
            window.close();
        if (aqui==1 && player->alive)
        {

              if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
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
              if ((abs(player->getX() - enemy->getX()) + abs(player->getY() - enemy->getY())) == 1)
              {
                  if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::A)
                    player->attack(enemy);
              }
          }
      }
}
