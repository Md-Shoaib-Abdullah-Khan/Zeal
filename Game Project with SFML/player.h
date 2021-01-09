#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "animation.h"
#include<iostream>
using namespace sf;


class Player
{
    public:
        Player(sf::Texture* texture,sf::Vector2u imagecount, float switchtime, float speed);

        void update(float deltatime);
        void draw(RenderWindow& window);

    protected:

    private:
        RectangleShape body;
        Animation Animation;
        float speed;
        bool faceright;
};

#endif // PLAYER_H
