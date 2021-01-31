#include "animation.h"
#include <SFML/Graphics.hpp>
#include<iostream>
using namespace sf;
Animation::Animation(Texture* texture,Vector2u imagecount, float switchtime)
{
    this-> imagecount= imagecount;
    this-> switchtime = switchtime;

    totaltime =0.0f;
    currentimage.x=0;
    uvRect.width= texture->getSize().x/float(imagecount.x);
    uvRect.height= texture->getSize().y/float(imagecount.y);
}

void Animation::update( int row,float deltatime,bool faceright)
{
    totaltime+=deltatime;

    if(totaltime>=switchtime)
    {
        totaltime-=switchtime;
        currentimage.x++;

        if(currentimage.x>=imagecount.x)
    {
        currentimage.x=0;
    }

    }



}
