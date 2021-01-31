#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "animation.h"
#include "player.h"
#include<iostream>
#include<vector>
#include<cmath>
#include<sstream>

using namespace sf;
using namespace std;
int main()
{
    vector< pair <double,double>>bullet;
    vector<bool>bulletface;

    //Gameover initiation:





    //Gamewin initiation

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




        window.setFramerateLimit(120);


        window.clear(Color:: White);





        window.display();
    }

    return 0;
}
