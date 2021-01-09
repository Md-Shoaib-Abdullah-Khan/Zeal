#ifndef ANIMATION_H
#define ANIMATION_H
#include <SFML/Graphics.hpp>
#include<iostream>
using namespace sf;


class Animation
{
    public:
        Animation(sf::Texture* texture,sf::Vector2u imagecount, float switchtime);
        void update(int row, float deltatime,bool faceright);

    public:
        sf::IntRect uvRect;

    private:
        Vector2u imagecount;
        Vector2u currentimage;

        float totaltime;
        float switchtime;
};

#endif // ANIMATION_H
