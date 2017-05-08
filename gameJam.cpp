#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <ctime>
#include <cstdlib>

#include "World/world.hpp"
#include "Character/player.hpp"
#include "Character/enemy.hpp"
#include "Menu/mainmenu.hpp"
#include <unistd.h>

using namespace std;

void handleEvents(sf::RenderWindow &window, Player *player, int aqui, Enemy *enemy,
                  MainMenu *menu, unsigned *gameState);

void initGame(World **world, Player **p, Enemy **e, int *aqui, int height, int width);

int main()
{
    sf::RenderWindow window(sf::VideoMode(), "GameJam",
                            sf::Style::Titlebar | sf::Style::Close | sf::Style::Fullscreen);

    MainMenu *menu = new MainMenu(window);
    unsigned gameState = menu->showMenu();

    sf::VideoMode mode = sf::VideoMode::getDesktopMode();

    if(gameState == PLAY)
    {
        menu->setGame(true);
        gameState = RESUME;
    }
    else if(gameState == EXIT)
        return EXIT_SUCCESS;

    World* world = NULL;
    int aqui = 1;
    Player *p = NULL;
    Enemy *e = NULL;

    initGame(&world, &p, &e, &aqui, mode.height, mode.width);

    int height= mode.height;
    int width= mode.width;

    sf::Font font;
    font.loadFromFile("Img/arial.ttf");

    sf::Text joueur;
    string J;
    J = "Joueur";
    joueur.setString(J);
    joueur.setFont(font);
    joueur.setCharacterSize(24);
    joueur.setColor(sf::Color::White);
    joueur.setPosition(40, 70);
    sf::Text enemie;
    string E;
    E = "Ennemi";
    enemie.setString(E);
    enemie.setFont(font);
    enemie.setCharacterSize(24);
    enemie.setColor(sf::Color::White);
    enemie.setPosition(width-250, 70);
    sf::RectangleShape lifejoueur;
    lifejoueur.setSize(sf::Vector2f(p->getVitality(), 10));
    sf::RectangleShape lifeennemi;
    lifeennemi.setSize(sf::Vector2f(e->getVitality(), 10));
    lifeennemi.setFillColor(sf::Color::Red);
    lifejoueur.setFillColor(sf::Color::Red);
    lifejoueur.setPosition(30, 110);
    lifeennemi.setPosition(width - 260, 110);

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

        handleEvents(window, p, aqui, e, menu, &gameState);
        if(gameState == PLAY)
        {
            menu->setGame(true);
            initGame(&world, &p, &e, &aqui, mode.height, mode.width);
            gameState = RESUME;
        }

        lifejoueur.setSize(sf::Vector2f(p->getVitality(), 10));
        lifeennemi.setSize(sf::Vector2f(e->getVitality(), 10));
        if(aqui == 0)
        {
            if(e->getMapX() != p->getMapX() || e->getMapY() != p->getMapY())
                e->tour =0;
            else if(e->alive)
            {
                usleep(100000);
                if((abs(p->getX() - e->getX()) + abs(p->getY() - e->getY())) != 1)
                {
                    e->searchPath();
                    e->move();
                }
                else
                    e->attack(p);
            }
        }
        window.clear(sf::Color::Black);

        if(aqui == 0)
            enemie.setColor(sf::Color::Yellow);
        else
            joueur.setColor(sf::Color::Yellow);
        for(int i=0; i < 14; i++)
        {
            for(int j=0; j<14; j++)
                window.draw(*(world->world[p->getMapX()][p->getMapY()]->map[i][j]));
        }

        if(e->alive == false || p->alive == false)
        {
            menu->setGame(false);
            gameState = menu->showMenu();
            if(gameState == PLAY)
            {
                menu->setGame(true);
                initGame(&world, &p, &e, &aqui, mode.height, mode.width);
                gameState = RESUME;
                continue;
            }
        }

        if (e->alive==true)
            window.draw(enemie);
        window.draw(joueur);
        window.draw(lifeennemi);
        window.draw(lifejoueur);

        window.display();


    }
    delete menu;
    delete world;
    delete p;
    delete e;

    return 0;
}

void handleEvents(sf::RenderWindow &window, Player *player, int aqui, Enemy *enemy,
                  MainMenu *menu, unsigned *gameState)
{
    sf::Event event;
    while(window.pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
            window.close();
        else if(event.type == sf::Event::KeyPressed)
        {
            if(event.key.code == sf::Keyboard::Escape)
                *gameState = menu->showMenu();
        }
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

void initGame(World **world, Player **p, Enemy **e, int *aqui, int height, int width)
{
    if(*world != NULL)
        delete *world;
    if(*p != NULL)
        delete *p;
    if(*e != NULL)
        delete *e;
    *world = new World(height, width);
    *p = new Player(*world);
    *e = new Enemy(*world, *p);
    *aqui = 1;
}
