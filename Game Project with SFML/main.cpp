#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "animation.h"
#include "player.h"
#include<iostream>
using namespace sf;
int main()
{
    RenderWindow window(sf::VideoMode(1500, 900), "SFML works!");
    RectangleShape body2(Vector2f(150.0f,150.0f));
    RectangleShape body1(Vector2f(150.0f,150.0f));
    RectangleShape body0(Vector2f(150.0f,150.0f));
    RectangleShape body3(Vector2f(150.0f,150.0f));
    RectangleShape body(Vector2f(150.0f,150.0f));

    Texture playertexture3[10],playertexture1[10],playertexture2[10],playertexture4[10],ex,ex1;

    Sprite sprite,sprite1;
    ex.loadFromFile("an/bk.png");
    ex1.loadFromFile("an/bk1.png");
    sprite.setTexture(ex);
    sprite1.setTexture(ex1);

    playertexture4[0].loadFromFile("1/Jump__000.png");
    playertexture4[1].loadFromFile("1/Jump__001.png");
    playertexture4[2].loadFromFile("1/Jump__002.png");
    playertexture4[3].loadFromFile("1/Jump__003.png");
    playertexture4[4].loadFromFile("1/Jump__004.png");
    playertexture4[5].loadFromFile("1/Jump__005.png");
    playertexture4[6].loadFromFile("1/Jump__006.png");
    playertexture4[7].loadFromFile("1/Jump__007.png");
    playertexture4[8].loadFromFile("1/Jump__008.png");
    playertexture4[9].loadFromFile("1/Jump__009.png");

    playertexture3[0].loadFromFile("1/Run__000.png");
    playertexture3[1].loadFromFile("1/Run__001.png");
    playertexture3[2].loadFromFile("1/Run__002.png");
    playertexture3[3].loadFromFile("1/Run__003.png");
    playertexture3[4].loadFromFile("1/Run__004.png");
    playertexture3[5].loadFromFile("1/Run__005.png");
    playertexture3[6].loadFromFile("1/Run__006.png");
    playertexture3[7].loadFromFile("1/Run__007.png");
    playertexture3[8].loadFromFile("1/Run__008.png");
    playertexture3[9].loadFromFile("1/Run__009.png");

    playertexture2[0].loadFromFile("1/Runb__000.png");
    playertexture2[1].loadFromFile("1/Runb__001.png");
    playertexture2[2].loadFromFile("1/Runb__002.png");
    playertexture2[3].loadFromFile("1/Runb__003.png");
    playertexture2[4].loadFromFile("1/Runb__004.png");
    playertexture2[5].loadFromFile("1/Runb__005.png");
    playertexture2[6].loadFromFile("1/Runb__006.png");
    playertexture2[7].loadFromFile("1/Runb__007.png");
    playertexture2[8].loadFromFile("1/Runb__008.png");
    playertexture2[9].loadFromFile("1/Runb__009.png");

    playertexture1[0].loadFromFile("1/Idle__000.png");
    playertexture1[1].loadFromFile("1/Idle__001.png");
    playertexture1[2].loadFromFile("1/Idle__002.png");
    playertexture1[3].loadFromFile("1/Idle__003.png");
    playertexture1[4].loadFromFile("1/Idle__004.png");
    playertexture1[5].loadFromFile("1/Idle__005.png");
    playertexture1[6].loadFromFile("1/Idle__006.png");
    playertexture1[7].loadFromFile("1/Idle__007.png");
    playertexture1[8].loadFromFile("1/Idle__008.png");
    playertexture1[9].loadFromFile("1/Idle__009.png");


    int i=0,pos=0,jump=0;
    double time=0,y=660.0,jumptimer=0.0;
    Vector2f movement(500.0f,0.0f);
    float deltatime=0.0f;
    Clock clock;

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
        ex.setRepeated(true);
        ex1.setRepeated(true);
        body.setPosition(300.0f,300.0f);
        sprite.setPosition(0.0f,100.0f);
        sprite1.setPosition(0.0f,0.0f);
       // sprite.setSize(Vector2f(200.0f,150.0f));

        float speed=100.0;
        pos=0;
    if(Keyboard::isKeyPressed(Keyboard::A))
    {
        movement.x-=speed*deltatime;
        pos=1;
    }
    if(Keyboard::isKeyPressed(Keyboard::D))
    {
        movement.x+=speed*deltatime;
        pos=2;
    }
    if(Keyboard::isKeyPressed(Keyboard::Space))
    {
        jump=1;
        jumptimer=1.0;

    }


       if(pos==2)
       {body2.setTexture(&playertexture3[i]);
       //body2.setPosition((movement.x),250.0f);
       }
       else if(pos==1)
       {body1.setTexture(&playertexture2[i]);
       //body1.setPosition((movement.x),250.0f);
       }
       else if(pos==0)
       {body0.setTexture(&playertexture1[i]);
        //body0.setPosition((movement.x),250.0f);
       }
       else if(pos==3)
       {body3.setTexture(&playertexture4[i]);
       // body3.setPosition((movement.x),250.0f);
       }
        if(i==9){i=0;}
        time+=deltatime;
        if(time>0.1)
        {i++;
        time=0.0;


         sprite.setTextureRect(IntRect(movement.x,0,1500+movement.x,1000));
         sprite1.setTextureRect(IntRect(movement.x,0,1500+movement.x,1000));

         if(movement.x>=1000){movement.x=0.0f;}
        else if(movement.x)

        if(jump)
        {jumptimer-=.1;
            if(jumptimer>=0.5){y-=30;}
            else{y+=30;}
            if(jumptimer<=0.0)
                {
                    y=660.0;
                    jump=0;
            }
        }


         body0.setPosition(700.0f,y);
      body1.setPosition(700.0f,y);
       body2.setPosition(700.0f,y);
        body3.setPosition(700.0f,y);


        std::cout<<movement.x<<" "<<deltatime<<std::endl;
        }


        window.clear(Color:: White);
    window.draw(sprite1);
        window.draw(sprite);

        if(pos==0)window.draw(body0);
        else if(pos==1)window.draw(body1);
        else if(pos==2)window.draw(body2);
        window.display();
    }

    return 0;
}
