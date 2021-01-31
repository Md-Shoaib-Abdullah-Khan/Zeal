#include "player.h"
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "animation.h"
#include<iostream>

using namespace sf;

Player::Player(sf::Texture* texture,sf::Vector2u imagecount, float switchtime, float speed):
    Animation (texture, imagecount,switchtime)
{
    this-> speed=speed;
    int row=0;
    faceright=true;

    body.setSize(Vector2f(200.0f,150.0f));
    body.setPosition(250.0f,250.0f);
    body.setTexture(texture);


}

void Player::update(float deltatime)
{int row;
    Vector2f movement(0.0f,0.0f);
    if(Keyboard::isKeyPressed(Keyboard::A))
    {
        movement.x-=speed*deltatime;
    }
    if(Keyboard::isKeyPressed(Keyboard::D))
    {
        movement.x+=speed*deltatime;
    }
    if(movement.x==0.0f)
    {
         row=0;
    }
    else
    {
        row=1;
        if(movement.x>0.0f)faceright=true;
        else faceright=false;
    }
    std::cout<<movement.x<<std::endl;
    Animation.update(row,deltatime,faceright);
    body.setTextureRect(Animation.uvRect);
    body.move(movement);
}

void Player:: draw(RenderWindow& window)
{
    window.draw(body);
}
