#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "animation.h"
#include "player.h"
#include<iostream>
using namespace sf;
int main()
{
    RenderWindow window(sf::VideoMode(1500, 900), "SFML works!");
    //RectangleShape bk(Vector2f(1000.0f,1000.0f));

    Texture playertexture,background;
   // background.loadFromFile("an/bk.png");
    //bk.setTexture(&background);
    playertexture.loadFromFile("an/2.jpg");

    float deltatime=0.0f;
    Clock clock;

    Player Player(&playertexture,Vector2u(4.7,2),0.4f,100.0f);
    while (window.isOpen())
    {
        deltatime=clock.restart().asSeconds();
        Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case Event::Closed:
                {window.close();
                break;
                }
            case Event::KeyPressed:
                if(event.key.code==Keyboard::Escape)
                {window.close();
                break;
                }

            }
        }
        Player.update(deltatime);


        window.clear(Color:: White);
        Player.draw(window);
        window.display();
    }

    return 0;
}
