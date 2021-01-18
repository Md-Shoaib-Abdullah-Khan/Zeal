#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "animation.h"
#include "player.h"
#include<iostream>
#include<vector>
using namespace sf;
using namespace std;
int main()
{
    vector< pair <double,double>>bullet;
    vector<bool>bulletface;

    //Gameover initiation:
    bool gameover=false;

    //Obstacle check bool:
    bool steprightonx=true;
    bool stepleftonx=true;
    bool stepony=true;

    //Obstackle initiation:

    Texture obstacletexture[10];

    //Log:
    obstacletexture[0].loadFromFile("obstacle/log.png");
    RectangleShape obstaclebody(Vector2f(150.0f,150.0f));
    vector<pair<double,bool>>obstaclelogtimer;
    vector<pair<double,double>>obstaclelog;


    obstaclelogtimer.push_back(make_pair(1.0,false));
    obstaclelog.push_back(make_pair(1500.0,720.0));
    obstaclelogtimer.push_back(make_pair(5.0,false));
    obstaclelog.push_back(make_pair(1500.0,720.0));

    //stair:
    RectangleShape obstaclebodystair(Vector2f(150.0f,50.0f));
    obstacletexture[1].loadFromFile("obstacle/stair.png");
    vector<pair<double,bool>>obstaclestairtimer;
    vector<pair<double,double>>obstaclestair;

    obstaclestairtimer.push_back(make_pair(2.0,false));
    obstaclestair.push_back(make_pair(1500.0,600.0));
    obstaclestairtimer.push_back(make_pair(5.0,false));
    obstaclestair.push_back(make_pair(1500.0,600.0));

    //Slide:
    obstacletexture[2].loadFromFile("obstacle/slide.png");
    RectangleShape obstacleslidebody(Vector2f(500.0f,500.0f));
    vector<pair<double,bool>>obstacleslidetimer;
    vector<pair<double,double>>obstacleslide;

    obstacleslidetimer.push_back(make_pair(10,false));
    obstacleslide.push_back(make_pair(1500.0,350.0));




    //Enemy initiation:
    vector< pair <double,double>>enemy;
    vector<bool>enemyon;

    enemy.push_back(make_pair(1500.0,3.0));
    enemyon.push_back(false);
    enemy.push_back(make_pair(1500.0,4.5));
    enemyon.push_back(false);
    enemy.push_back(make_pair(1500.0,4.6));
    enemyon.push_back(false);
    enemy.push_back(make_pair(1500.0,5.0));
    enemyon.push_back(false);
    enemy.push_back(make_pair(1500.0,5.5));
    enemyon.push_back(false);
    enemy.push_back(make_pair(1500.0,5.7));
    enemyon.push_back(false);
    enemy.push_back(make_pair(1500.0,6.5));
    enemyon.push_back(false);
    enemy.push_back(make_pair(1500.0,6.9));
    enemyon.push_back(false);

    RenderWindow window(sf::VideoMode(1500, 900), "SFML works!");
    RectangleShape body6(Vector2f(150.0f,150.0f));
    RectangleShape body5(Vector2f(130.0f,130.0f));
    RectangleShape body2(Vector2f(150.0f,150.0f));
    RectangleShape body1(Vector2f(150.0f,150.0f));
    RectangleShape body0(Vector2f(150.0f,150.0f));
    RectangleShape body3(Vector2f(150.0f,150.0f));
    RectangleShape body(Vector2f(150.0f,150.0f));
     RectangleShape collisionbody(Vector2f(150.0f,150.0f));

    Texture predator,playertexture3[10],playertexture1[10],playertexture2[10],playertexture4[10],playertexture5[10],playertexture6[10],playertexture7[10],playertexture8[9],ex,ex1,bullet1,bullet2,collision;

    collision.loadFromFile("collision.png");

    Sprite sprite,sprite1;
    RectangleShape bulletsprite1(Vector2f(50.0f,50.0f));
    RectangleShape bulletsprite2(Vector2f(50.0f,50.0f));
    bullet1.loadFromFile("bullet/1.png");
    bullet2.loadFromFile("bullet/2.png");
    ex.loadFromFile("an/bk.png");
    ex1.loadFromFile("an/bk1.png");
    sprite.setTexture(ex);
    sprite1.setTexture(ex1);

    //Enemy texture:
    playertexture8[0].loadFromFile("enemy/WALK_000.png");
    playertexture8[1].loadFromFile("enemy/WALK_001.png");
    playertexture8[2].loadFromFile("enemy/WALK_002.png");
    playertexture8[3].loadFromFile("enemy/WALK_003.png");
    playertexture8[4].loadFromFile("enemy/WALK_004.png");
    playertexture8[5].loadFromFile("enemy/WALK_005.png");
    playertexture8[6].loadFromFile("enemy/WALK_006.png");
    playertexture8[7].loadFromFile("enemy/WALK_007.png");
    playertexture8[8].loadFromFile("enemy/WALK_008.png");


    playertexture7[0].loadFromFile("1/Slideb__000.png");
    playertexture7[1].loadFromFile("1/Slideb__001.png");
    playertexture7[2].loadFromFile("1/Slideb__002.png");
    playertexture7[3].loadFromFile("1/Slideb__003.png");
    playertexture7[4].loadFromFile("1/Slideb__004.png");
    playertexture7[5].loadFromFile("1/Slideb__005.png");
    playertexture7[6].loadFromFile("1/Slideb__006.png");
    playertexture7[7].loadFromFile("1/Slideb__007.png");
    playertexture7[8].loadFromFile("1/Slideb__008.png");
    playertexture7[9].loadFromFile("1/Slideb__009.png");

    playertexture6[0].loadFromFile("1/Slide__000.png");
    playertexture6[1].loadFromFile("1/Slide__001.png");
    playertexture6[2].loadFromFile("1/Slide__002.png");
    playertexture6[3].loadFromFile("1/Slide__003.png");
    playertexture6[4].loadFromFile("1/Slide__004.png");
    playertexture6[5].loadFromFile("1/Slide__005.png");
    playertexture6[6].loadFromFile("1/Slide__006.png");
    playertexture6[7].loadFromFile("1/Slide__007.png");
    playertexture6[8].loadFromFile("1/Slide__008.png");
    playertexture6[9].loadFromFile("1/Slide__009.png");

    playertexture5[0].loadFromFile("1/Jumpb__000.png");
    playertexture5[1].loadFromFile("1/Jumpb__001.png");
    playertexture5[2].loadFromFile("1/Jumpb__002.png");
    playertexture5[3].loadFromFile("1/Jumpb__003.png");
    playertexture5[4].loadFromFile("1/Jumpb__004.png");
    playertexture5[5].loadFromFile("1/Jumpb__005.png");
    playertexture5[6].loadFromFile("1/Jumpb__006.png");
    playertexture5[7].loadFromFile("1/Jumpb__007.png");
    playertexture5[8].loadFromFile("1/Jumpb__008.png");
    playertexture5[9].loadFromFile("1/Jumpb__009.png");

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


    int i=0,pos=0,jump=0,slide=0;
    double time=0,y=660.0,jumptimer=0.0,slidetimer=0.0,stepcount=0.0,collisiontime=0.0;
    bool faceright=true,collisionbool=false;
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
            if(event.type == Event::MouseButtonPressed && event.key.code == Mouse::Left)
            {
            if(faceright)
            {
                bullet.push_back(make_pair(800.0,y+50));
                bulletface.push_back(true);
            }
            else
            {
                bullet.push_back(make_pair(680.0,y+50));
                bulletface.push_back(false);
            }
            }
        }

        //Background:


        ex.setRepeated(true);
        ex1.setRepeated(true);


        body.setPosition(300.0f,300.0f);
        sprite.setPosition(0.0f,100.0f);
        sprite1.setPosition(0.0f,0.0f);

        float speed=200.0;
        pos=0;
    if(Keyboard::isKeyPressed(Keyboard::A)&&stepleftonx)
    {
        movement.x-=speed*deltatime;
        pos=1;
        faceright=false;
        stepcount-=deltatime;
    }
    if(Keyboard::isKeyPressed(Keyboard::D)&&steprightonx)
    {
        movement.x+=speed*deltatime;
        pos=2;
        faceright=true;
        stepcount+=deltatime;
    }
    if(Keyboard::isKeyPressed(Keyboard::Space)||jump!=0)
    {
        if(jump==0){jump=1;
        jumptimer=5.0;}
        pos=3;
    }
    if(Keyboard::isKeyPressed(Keyboard::S)||slide!=0)
    {
        if(slide==0){slide=1;
        slidetimer=1.0;}
        pos=4;
    }


       if(pos==2)
       {body2.setTexture(&playertexture3[i]);
       }
       else if(pos==1)
       {body1.setTexture(&playertexture2[i]);
       }
       else if(pos==0)
       {body0.setTexture(&playertexture1[i]);
       }
       else if(pos==3)
       {if(faceright)body3.setTexture(&playertexture4[i]);
       else body3.setTexture(&playertexture5[i]);
       }
       else if(pos==4)
       {if(faceright)body5.setTexture(&playertexture6[i]);
       else body5.setTexture(&playertexture7[i]);
       }

       //Obstacle check:
       steprightonx=true;
       stepleftonx=true;
        stepony=true;
       if(!obstaclelog.empty())
        {
            for(int j=0;j<obstaclelog.size();j++)
            {
                if(obstaclelog[j].first>=600&&obstaclelog[j].first<=800&&obstaclelog[j].second-100<=y)
                {
                    if(steprightonx==false){obstaclelog[j].first=600.0;}
                    if(stepleftonx==false){obstaclelog[j].first=800.0;}
                if(faceright&&obstaclelog[j].second-100<=y-10)
                {

                    steprightonx=false;
                }
                else if(faceright==false&&obstaclelog[j].second-100<=y-10)
                {

                    stepleftonx=false;
                }
                    stepony=false;
                }
                std::cout<<obstaclelog[j].first<<" "<<obstaclelog[j].second<<endl;


            }
        }

        //Stair:

        if(!obstaclestair.empty())
        {
            for(int j=0;j<obstaclestair.size();j++)
            {
                if(obstaclestair[j].first>=600&&obstaclestair[j].first<=800&&obstaclestair[j].second-150<=y&&obstaclestair[j].second-100>=y)
                {

                    stepony=false;
                }


            }
        }

        //slide:
        if(!obstacleslide.empty())
        {
            for(int j=0;j<obstacleslide.size();j++)
            {
                if(obstacleslide[j].first>=650&&obstacleslide[j].first<=750&&slide==0&&faceright)
                {

                    steprightonx=false;
                }
                if(obstacleslide[j].first>=750&&obstacleslide[j].first<=850&&slide==0&&faceright==false)
                {

                    stepleftonx=false;
                }


            }
        }



        if(i>=9){i=0;}
        time+=deltatime;
        if(time>0.1)
        {i++;
        time=0.0;
        }

         sprite.setTextureRect(IntRect(movement.x,0,1500+movement.x,1000));
         sprite1.setTextureRect(IntRect(movement.x,0,1500+movement.x,1000));

         bulletsprite1.setTexture(&bullet1);
         bulletsprite2.setTexture(&bullet2);

         if(movement.x>=1000){movement.x=0.0f;}
        else if(movement.x)

        if(jump)
        {jumptimer-=deltatime*3;
            if(jumptimer>=2.5){y-=deltatime*(speed+100);}
            else{if(stepony)y+=deltatime*(speed+100);}
            if(jumptimer<=0.0)
                {

                    jump=0;
                    jumptimer=0.0;
            }
        }
        if(y<660.0&&stepony&&jump==0){y+=deltatime*(speed+100);}
        if(y>660.0){y=660.0;}
        if(slide)
        {slidetimer-=deltatime;

            if(slidetimer<=0.0)
                {
                    y=660.0;
                    slide=0;
                    slidetimer=0.0;
            }
        }


        body0.setPosition(700.0f,y);
        body1.setPosition(700.0f,y);
        body2.setPosition(700.0f,y);
        body3.setPosition(700.0f,y);
        body5.setPosition(700.0f,y+50);


        std::cout<<time<<" "<<stepcount<<std::endl;

        collisionbody.setTexture(&collision);

        for(int j=0;j<bullet.size();j++)
        {
            for(int k=0;k<enemy.size();k++)
            {
                if((bullet[j].first>=enemy[k].first-10&&bullet[j].first<=enemy[k].first+10)&&(bullet[j].second>=650.0&&bullet[j].second<=730.0)&&enemyon[k])
                   {
                collisionbody.setPosition(bullet[j].first,bullet[j].second);
                collisionbool=true;
                collisiontime=.5;
                      enemy.erase(enemy.begin()+k);
                enemyon.erase(enemyon.begin()+k);
                    bullet.erase(bullet.begin()+j);
                bulletface.erase(bulletface.begin()+j);

                   }
            }
        }

        //Obstacle update:

        //Log:
        if(!obstaclelog.empty())
        {
            for(int j=0;j<obstaclelog.size();j++)
            {
                if(stepcount>=obstaclelogtimer[j].first&&stepcount<=obstaclelogtimer[j].first+10.0){obstaclelogtimer[j].second=true;}
                else{obstaclelogtimer[j].second=false;}
                if(obstaclelogtimer[j].second)
                {

                    if(Keyboard::isKeyPressed(Keyboard::D)&&steprightonx)
                    {
                        obstaclelog[j].first-=deltatime*speed;

                    }
                    if(Keyboard::isKeyPressed(Keyboard::A)&&stepleftonx)
                    {
                        obstaclelog[j].first+=deltatime*speed;

                    }
                }

            }
        }

        //Stair:

        if(!obstaclestair.empty())
        {
            for(int j=0;j<obstaclestair.size();j++)
            {
                if(stepcount>=obstaclestairtimer[j].first&&stepcount<=obstaclestairtimer[j].first+10.0){obstaclestairtimer[j].second=true;}
                else{obstaclestairtimer[j].second=false;}
                if(obstaclestairtimer[j].second)
                {

                    if(Keyboard::isKeyPressed(Keyboard::D)&&steprightonx)
                    {
                        obstaclestair[j].first-=deltatime*speed;

                    }
                    if(Keyboard::isKeyPressed(Keyboard::A)&&stepleftonx)
                    {
                        obstaclestair[j].first+=deltatime*speed;

                    }
                }

            }
        }

        //Slide:
        if(!obstacleslide.empty())
        {
            for(int j=0;j<obstacleslide.size();j++)
            {
                if(stepcount>=obstacleslidetimer[j].first&&stepcount<=obstacleslidetimer[j].first+10.0){obstacleslidetimer[j].second=true;}
                else{obstacleslidetimer[j].second=false;}
                if(obstacleslidetimer[j].second)
                {

                    if(Keyboard::isKeyPressed(Keyboard::D)&&steprightonx)
                    {
                        obstacleslide[j].first-=deltatime*speed;

                    }
                    if(Keyboard::isKeyPressed(Keyboard::A)&&stepleftonx)
                    {
                        obstacleslide[j].first+=deltatime*speed;

                    }
                }

            }
        }




        window.clear(Color:: White);
    window.draw(sprite1);
        window.draw(sprite);
        if(!bullet.empty())
        {
            for(int j=0;j<bullet.size();j++)
            {
                if(bulletface[j])bullet[j].first+=2;
                else bullet[j].first-=2;
                if(bullet[j].first>=1500.0&&bullet[j].first>=0.0){continue;}

                if(bulletface[j])
                    {
                        bulletsprite1.setPosition(Vector2f(bullet[j].first,bullet[j].second));
                        window.draw(bulletsprite1);
                    }
                else
                {
                        bulletsprite2.setPosition(Vector2f(bullet[j].first,bullet[j].second));
                        window.draw(bulletsprite2);
                }

            }
        }
        if(!enemy.empty())
        {
            if(i!=9)body6.setTexture(&playertexture8[i]);
            for(int j=0;j<enemy.size();j++)
            {
                if(stepcount>=enemy[j].second){enemyon[j]=true;}

                if(enemyon[j])
                {
                    enemy[j].first-=deltatime*(speed);
                    if(pos==1){enemy[j].first+=.1;}
                    if(pos==2){enemy[j].first-=.5;}
                }
                if(enemy[j].first<=0.0)
                {
                enemy.erase(enemy.begin());
                enemyon.erase(enemyon.begin());

                }

                if(enemyon[j])
                    {
                        body6.setPosition(Vector2f(enemy[j].first,680.0));
                        window.draw(body6);
                    }
            }
        }
        if(collisionbool)
        {   collisiontime-=deltatime;
            window.draw(collisionbody);
            if(collisiontime<=0.0)collisionbool=false;
        }

        if(pos==0&&jump==0)window.draw(body0);
        else if(pos==1&&jump==0&&slide==0)window.draw(body1);
        else if(pos==2&&jump==0&&slide==0)window.draw(body2);
        else if(pos==3&&jump!=0&&slide==0)window.draw(body3);
        else if(pos==4&&jump==0&&slide!=0)window.draw(body5);

        //Obstacle draw:

        //Log:

        if(!obstaclelog.empty())
        {
            for(int j=0;j<obstaclelog.size();j++)
            {   obstaclebody.setTexture(&obstacletexture[0]);

                if(obstaclelogtimer[j].second)
                {   obstaclebody.setPosition(obstaclelog[j].first,obstaclelog[j].second);
                    window.draw(obstaclebody);
                }

            }
        }
        //Stair:
        if(!obstaclestair.empty())
        {
            for(int j=0;j<obstaclestair.size();j++)
            {   obstaclebodystair.setTexture(&obstacletexture[1]);

                if(obstaclestairtimer[j].second)
                {   obstaclebodystair.setPosition(obstaclestair[j].first,obstaclestair[j].second);
                    window.draw(obstaclebodystair);
                }

            }
        }

        //Slide:
        if(!obstacleslide.empty())
        {
            for(int j=0;j<obstacleslide.size();j++)
            {   obstacleslidebody.setTexture(&obstacletexture[2]);

                if(obstacleslidetimer[j].second)
                {   obstacleslidebody.setPosition(obstacleslide[j].first,obstacleslide[j].second);
                    window.draw(obstacleslidebody);
                }

            }
        }
        window.display();
    }

    return 0;
}
