#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "animation.h"
#include "player.h"
#include<iostream>
#include<vector>
#include<cmath>

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




    //Health & Shield:
    int health=5, shield=5;

    //health point initiation:
    RectangleShape healthbody(Vector2f(50.0f,50.0f));
    Texture healthtexture;
    healthtexture.loadFromFile("others/health&shield/health.png");
    double healthontimer=3.0,healthofftimer=3.0,healthx=200.0,healthy=600.0;
    bool healthon=false;

    //shield point initiation:
    RectangleShape shieldbody(Vector2f(50.0f,50.0f));
    Texture shieldtexture;
    shieldtexture.loadFromFile("others/health&shield/shield.png");
    double shieldontimer=3.0,shieldofftimer=3.0,shieldx=200.0,shieldy=600.0;
    bool shieldon=false;

    //health bar initiation:
    RectangleShape healthbarbody(Vector2f(200.0f,50.0f));
    Texture healthbar[6];
    healthbar[0].loadFromFile("others/health&shield/health_bar000.png");
    healthbar[1].loadFromFile("others/health&shield/health_bar001.png");
    healthbar[2].loadFromFile("others/health&shield/health_bar002.png");
    healthbar[3].loadFromFile("others/health&shield/health_bar003.png");
    healthbar[4].loadFromFile("others/health&shield/health_bar004.png");
    healthbar[5].loadFromFile("others/health&shield/health_bar005.png");

    //shield bar initiation:
    RectangleShape shieldbarbody(Vector2f(200.0f,50.0f));
    Texture shieldbar[6];
    shieldbar[0].loadFromFile("others/health&shield/shield_bar000.png");
    shieldbar[1].loadFromFile("others/health&shield/shield_bar001.png");
    shieldbar[2].loadFromFile("others/health&shield/shield_bar002.png");
    shieldbar[3].loadFromFile("others/health&shield/shield_bar003.png");
    shieldbar[4].loadFromFile("others/health&shield/shield_bar004.png");
    shieldbar[5].loadFromFile("others/health&shield/shield_bar005.png");

    //Coin count initiation:
    int count1=0,count2=0,count3=0,count4=0;

    RectangleShape coincountbody(Vector2f(40.0f,40.0f));
    Texture coincounttexture[10];

    coincounttexture[0].loadFromFile("others/numbers/0.png");
    coincounttexture[1].loadFromFile("others/numbers/1.png");
    coincounttexture[2].loadFromFile("others/numbers/2.png");
    coincounttexture[3].loadFromFile("others/numbers/3.png");
    coincounttexture[4].loadFromFile("others/numbers/4.png");
    coincounttexture[5].loadFromFile("others/numbers/5.png");
    coincounttexture[6].loadFromFile("others/numbers/6.png");
    coincounttexture[7].loadFromFile("others/numbers/7.png");
    coincounttexture[8].loadFromFile("others/numbers/8.png");
    coincounttexture[9].loadFromFile("others/numbers/9.png");

    //Coin initiation:
    RectangleShape coinbody(Vector2f(80.0f,80.0f));
    Texture cointexture[10];

    cointexture[0].loadFromFile("others/coin/Coin_000.png");
    cointexture[1].loadFromFile("others/coin/Coin_001.png");
    cointexture[2].loadFromFile("others/coin/Coin_002.png");
    cointexture[3].loadFromFile("others/coin/Coin_003.png");
    cointexture[4].loadFromFile("others/coin/Coin_004.png");
    cointexture[5].loadFromFile("others/coin/Coin_005.png");
    cointexture[6].loadFromFile("others/coin/Coin_006.png");
    cointexture[7].loadFromFile("others/coin/Coin_007.png");
    cointexture[8].loadFromFile("others/coin/Coin_008.png");
    cointexture[9].loadFromFile("others/coin/Coin_009.png");

    vector<pair<double,bool>>cointimer;
    vector<pair<double,double>>coin;

    cointimer.push_back(make_pair(2.0,false));
    coin.push_back(make_pair(1500.0,700.0));
    cointimer.push_back(make_pair(10.0,false));
    coin.push_back(make_pair(1500.0,700.0));
    cointimer.push_back(make_pair(8.2,false));
    coin.push_back(make_pair(1500.0,500.0));
    cointimer.push_back(make_pair(5.0,false));
    coin.push_back(make_pair(1500.0,700.0));
    cointimer.push_back(make_pair(24.3,false));
    coin.push_back(make_pair(1500.0,500.0));
    cointimer.push_back(make_pair(20.3,false));
    coin.push_back(make_pair(1500.0,500.0));
    cointimer.push_back(make_pair(28.3,false));
    coin.push_back(make_pair(1500.0,500.0));
    cointimer.push_back(make_pair(33.2,false));
    coin.push_back(make_pair(1500.0,500.0));
    cointimer.push_back(make_pair(42.7,false));
    coin.push_back(make_pair(1500.0,500.0));
    cointimer.push_back(make_pair(46.7,false));
    coin.push_back(make_pair(1500.0,500.0));
    cointimer.push_back(make_pair(44.6,false));
    coin.push_back(make_pair(1500.0,300.0));
    cointimer.push_back(make_pair(44.8,false));
    coin.push_back(make_pair(1500.0,300.0));
    cointimer.push_back(make_pair(41.5,false));
    coin.push_back(make_pair(1500.0,700.0));
    cointimer.push_back(make_pair(43.5,false));
    coin.push_back(make_pair(1500.0,700.0));
    cointimer.push_back(make_pair(45.5,false));
    coin.push_back(make_pair(1500.0,700.0));
    cointimer.push_back(make_pair(47.5,false));
    coin.push_back(make_pair(1500.0,700.0));
    cointimer.push_back(make_pair(62.2,false));
    coin.push_back(make_pair(1500.0,400.0));
    cointimer.push_back(make_pair(64.2,false));
    coin.push_back(make_pair(1500.0,200.0));
    cointimer.push_back(make_pair(66.2,false));
    coin.push_back(make_pair(1500.0,400.0));
    cointimer.push_back(make_pair(68.2,false));
    coin.push_back(make_pair(1500.0,600.0));
    cointimer.push_back(make_pair(70.2,false));
    coin.push_back(make_pair(1500.0,400.0));
    cointimer.push_back(make_pair(72.2,false));
    coin.push_back(make_pair(1500.0,200.0));
    cointimer.push_back(make_pair(73.2,false));
    coin.push_back(make_pair(1500.0,200.0));
    cointimer.push_back(make_pair(74.2,false));
    coin.push_back(make_pair(1500.0,200.0));
    cointimer.push_back(make_pair(75.2,false));
    coin.push_back(make_pair(1500.0,200.0));
    cointimer.push_back(make_pair(72.2,false));
    coin.push_back(make_pair(1500.0,600.0));
    cointimer.push_back(make_pair(73.2,false));
    coin.push_back(make_pair(1500.0,600.0));
    cointimer.push_back(make_pair(74.2,false));
    coin.push_back(make_pair(1500.0,600.0));
    cointimer.push_back(make_pair(75.2,false));
    coin.push_back(make_pair(1500.0,600.0));
    cointimer.push_back(make_pair(77.2,false));
    coin.push_back(make_pair(1500.0,400.0));
    cointimer.push_back(make_pair(79.2,false));
    coin.push_back(make_pair(1500.0,200.0));
    cointimer.push_back(make_pair(81.2,false));
    coin.push_back(make_pair(1500.0,400.0));
    cointimer.push_back(make_pair(83.2,false));
    coin.push_back(make_pair(1500.0,600.0));
    cointimer.push_back(make_pair(85.2,false));
    coin.push_back(make_pair(1500.0,400.0));



    //Obstackle initiation:

    Texture obstacletexture[10];

    //Log:
    obstacletexture[0].loadFromFile("obstacle/log.png");
    RectangleShape obstaclebody(Vector2f(150.0f,150.0f));
    vector<pair<double,bool>>obstaclelogtimer;
    vector<pair<double,double>>obstaclelog;


    obstaclelogtimer.push_back(make_pair(4.8,false));
    obstaclelog.push_back(make_pair(1500.0,720.0));
   // obstaclelogtimer.push_back(make_pair(5.0,false));
    //obstaclelog.push_back(make_pair(1500.0,720.0));

    //stair:
    RectangleShape obstaclebodystair(Vector2f(150.0f,50.0f));
    obstacletexture[1].loadFromFile("obstacle/stair.png");
    vector<pair<double,bool>>obstaclestairtimer;
    vector<pair<double,double>>obstaclestair;

    obstaclestairtimer.push_back(make_pair(8.0,false));
    obstaclestair.push_back(make_pair(1500.0,600.0));
    obstaclestairtimer.push_back(make_pair(24.0,false));
    obstaclestair.push_back(make_pair(1500.0,600.0));
    obstaclestairtimer.push_back(make_pair(33.0,false));
    obstaclestair.push_back(make_pair(1500.0,600.0));
    obstaclestairtimer.push_back(make_pair(42.5,false));
    obstaclestair.push_back(make_pair(1500.0,600.0));
    obstaclestairtimer.push_back(make_pair(44.5,false));
    obstaclestair.push_back(make_pair(1500.0,400.0));
    obstaclestairtimer.push_back(make_pair(46.5,false));
    obstaclestair.push_back(make_pair(1500.0,600.0));
    obstaclestairtimer.push_back(make_pair(54.0,false));
    obstaclestair.push_back(make_pair(1500.0,500.0));
    obstaclestairtimer.push_back(make_pair(62.0,false));
    obstaclestair.push_back(make_pair(1500.0,500.0));
    obstaclestairtimer.push_back(make_pair(64.0,false));
    obstaclestair.push_back(make_pair(1500.0,300.0));
    obstaclestairtimer.push_back(make_pair(66.0,false));
    obstaclestair.push_back(make_pair(1500.0,500.0));
    obstaclestairtimer.push_back(make_pair(68.0,false));
    obstaclestair.push_back(make_pair(1500.0,700.0));
    obstaclestairtimer.push_back(make_pair(70.0,false));
    obstaclestair.push_back(make_pair(1500.0,500.0));
    obstaclestairtimer.push_back(make_pair(72.0,false));
    obstaclestair.push_back(make_pair(1500.0,300.0));
    obstaclestairtimer.push_back(make_pair(72.5,false));
    obstaclestair.push_back(make_pair(1500.0,300.0));
    obstaclestairtimer.push_back(make_pair(73.0,false));
    obstaclestair.push_back(make_pair(1500.0,300.0));
    obstaclestairtimer.push_back(make_pair(73.5,false));
    obstaclestair.push_back(make_pair(1500.0,300.0));
    obstaclestairtimer.push_back(make_pair(74.0,false));
    obstaclestair.push_back(make_pair(1500.0,300.0));
    obstaclestairtimer.push_back(make_pair(74.5,false));
    obstaclestair.push_back(make_pair(1500.0,300.0));
    obstaclestairtimer.push_back(make_pair(75.0,false));
    obstaclestair.push_back(make_pair(1500.0,300.0));
    obstaclestairtimer.push_back(make_pair(72.0,false));
    obstaclestair.push_back(make_pair(1500.0,700.0));
    obstaclestairtimer.push_back(make_pair(72.5,false));
    obstaclestair.push_back(make_pair(1500.0,700.0));
    obstaclestairtimer.push_back(make_pair(73.0,false));
    obstaclestair.push_back(make_pair(1500.0,700.0));
    obstaclestairtimer.push_back(make_pair(73.5,false));
    obstaclestair.push_back(make_pair(1500.0,700.0));
    obstaclestairtimer.push_back(make_pair(74.0,false));
    obstaclestair.push_back(make_pair(1500.0,700.0));
    obstaclestairtimer.push_back(make_pair(74.5,false));
    obstaclestair.push_back(make_pair(1500.0,700.0));
    obstaclestairtimer.push_back(make_pair(75.0,false));
    obstaclestair.push_back(make_pair(1500.0,700.0));
    obstaclestairtimer.push_back(make_pair(77.0,false));
    obstaclestair.push_back(make_pair(1500.0,500.0));
    obstaclestairtimer.push_back(make_pair(79.0,false));
    obstaclestair.push_back(make_pair(1500.0,300.0));
    obstaclestairtimer.push_back(make_pair(81.0,false));
    obstaclestair.push_back(make_pair(1500.0,500.0));
    obstaclestairtimer.push_back(make_pair(83.0,false));
    obstaclestair.push_back(make_pair(1500.0,700.0));
    obstaclestairtimer.push_back(make_pair(85.0,false));
    obstaclestair.push_back(make_pair(1500.0,500.0));




    //Slide:
    obstacletexture[2].loadFromFile("obstacle/slide.png");
    RectangleShape obstacleslidebody(Vector2f(500.0f,500.0f));
    vector<pair<double,bool>>obstacleslidetimer;
    vector<pair<double,double>>obstacleslide;

    obstacleslidetimer.push_back(make_pair(15,false));
    obstacleslide.push_back(make_pair(1500.0,350.0));

    //rock:
    RectangleShape obstaclerockbody(Vector2f(200.0f,200.0f));
    obstacletexture[3].loadFromFile("obstacle/rock.png");
    vector<pair<double,bool>>obstaclerocktimer;
    vector<pair<double,double>>obstaclerock;

    obstaclerocktimer.push_back(make_pair(52.0,false));
    obstaclerock.push_back(make_pair(1500.0,700.0));
    obstaclerocktimer.push_back(make_pair(56.0,false));
    obstaclerock.push_back(make_pair(1500.0,700.0));
    obstaclerocktimer.push_back(make_pair(60.0,false));
    obstaclerock.push_back(make_pair(1500.0,700.0));
    obstaclerocktimer.push_back(make_pair(87.0,false));
    obstaclerock.push_back(make_pair(1500.0,700.0));

    //river:
    RectangleShape obstacleriverbody(Vector2f(250.0f,250.0f));
    obstacletexture[4].loadFromFile("obstacle/river.png");
    vector<pair<double,bool>>obstaclerivertimer;
    vector<pair<double,double>>obstacleriver;

    obstaclerivertimer.push_back(make_pair(20.0,false));
    obstacleriver.push_back(make_pair(1500.0,660.0));
    obstaclerivertimer.push_back(make_pair(61.0,false));
    obstacleriver.push_back(make_pair(1500.0,660.0));
    obstaclerivertimer.push_back(make_pair(62.0,false));
    obstacleriver.push_back(make_pair(1500.0,660.0));
    obstaclerivertimer.push_back(make_pair(63.0,false));
    obstacleriver.push_back(make_pair(1500.0,660.0));
    obstaclerivertimer.push_back(make_pair(64.0,false));
    obstacleriver.push_back(make_pair(1500.0,660.0));
    obstaclerivertimer.push_back(make_pair(65.0,false));
    obstacleriver.push_back(make_pair(1500.0,660.0));
    obstaclerivertimer.push_back(make_pair(66.0,false));
    obstacleriver.push_back(make_pair(1500.0,660.0));
    obstaclerivertimer.push_back(make_pair(67.0,false));
    obstacleriver.push_back(make_pair(1500.0,660.0));
    obstaclerivertimer.push_back(make_pair(68.0,false));
    obstacleriver.push_back(make_pair(1500.0,660.0));
    obstaclerivertimer.push_back(make_pair(69.0,false));
    obstacleriver.push_back(make_pair(1500.0,660.0));
    obstaclerivertimer.push_back(make_pair(70.0,false));
    obstacleriver.push_back(make_pair(1500.0,660.0));
    obstaclerivertimer.push_back(make_pair(71.0,false));
    obstacleriver.push_back(make_pair(1500.0,660.0));
    obstaclerivertimer.push_back(make_pair(72.0,false));
    obstacleriver.push_back(make_pair(1500.0,660.0));
    obstaclerivertimer.push_back(make_pair(73.0,false));
    obstacleriver.push_back(make_pair(1500.0,660.0));
    obstaclerivertimer.push_back(make_pair(74.0,false));
    obstacleriver.push_back(make_pair(1500.0,660.0));
    obstaclerivertimer.push_back(make_pair(75.0,false));
    obstacleriver.push_back(make_pair(1500.0,660.0));
    obstaclerivertimer.push_back(make_pair(76.0,false));
    obstacleriver.push_back(make_pair(1500.0,660.0));
    obstaclerivertimer.push_back(make_pair(77.0,false));
    obstacleriver.push_back(make_pair(1500.0,660.0));
    obstaclerivertimer.push_back(make_pair(78.0,false));
    obstacleriver.push_back(make_pair(1500.0,660.0));
    obstaclerivertimer.push_back(make_pair(79.0,false));
    obstacleriver.push_back(make_pair(1500.0,660.0));
    obstaclerivertimer.push_back(make_pair(80.0,false));
    obstacleriver.push_back(make_pair(1500.0,660.0));
    obstaclerivertimer.push_back(make_pair(81.0,false));
    obstacleriver.push_back(make_pair(1500.0,660.0));
    obstaclerivertimer.push_back(make_pair(82.0,false));
    obstacleriver.push_back(make_pair(1500.0,660.0));
    obstaclerivertimer.push_back(make_pair(83.0,false));
    obstacleriver.push_back(make_pair(1500.0,660.0));
    obstaclerivertimer.push_back(make_pair(84.0,false));
    obstacleriver.push_back(make_pair(1500.0,660.0));
    obstaclerivertimer.push_back(make_pair(85.0,false));
    obstacleriver.push_back(make_pair(1500.0,660.0));
    obstaclerivertimer.push_back(make_pair(86.0,false));
    obstacleriver.push_back(make_pair(1500.0,660.0));


    //hole:
    RectangleShape obstacleholebody(Vector2f(250.0f,250.0f));
    obstacletexture[5].loadFromFile("obstacle/hole.png");
    vector<pair<double,bool>>obstacleholetimer;
    vector<pair<double,double>>obstaclehole;

    obstacleholetimer.push_back(make_pair(28.0,false));
    obstaclehole.push_back(make_pair(1500.0,810.0));
    obstacleholetimer.push_back(make_pair(32.0,false));
    obstaclehole.push_back(make_pair(1500.0,660.0));
    obstacleholetimer.push_back(make_pair(33.0,false));
    obstaclehole.push_back(make_pair(1500.0,660.0));
    obstacleholetimer.push_back(make_pair(40.0,false));
    obstaclehole.push_back(make_pair(1500.0,660.0));
    obstacleholetimer.push_back(make_pair(42.0,false));
    obstaclehole.push_back(make_pair(1500.0,660.0));
    obstacleholetimer.push_back(make_pair(44.0,false));
    obstaclehole.push_back(make_pair(1500.0,660.0));
    obstacleholetimer.push_back(make_pair(46.0,false));
    obstaclehole.push_back(make_pair(1500.0,660.0));
    obstacleholetimer.push_back(make_pair(48.0,false));
    obstaclehole.push_back(make_pair(1500.0,660.0));





    //Enemy initiation:
    vector< pair <double,double>>enemy;
    vector<pair<double,bool>>enemyon;

    enemy.push_back(make_pair(1500.0,680.0));
    enemyon.push_back(make_pair(101.0,false));
    enemy.push_back(make_pair(1500.0,680.0));
    enemyon.push_back(make_pair(102.0,false));
    enemy.push_back(make_pair(1500.0,680.0));
    enemyon.push_back(make_pair(105.0,false));
    enemy.push_back(make_pair(1500.0,680.0));
    enemyon.push_back(make_pair(105.0,false));
    enemy.push_back(make_pair(1500.0,680.0));
    enemyon.push_back(make_pair(105.5,false));
    enemy.push_back(make_pair(1500.0,680.0));
    enemyon.push_back(make_pair(105.7,false));
    enemy.push_back(make_pair(1500.0,680.0));
     enemyon.push_back(make_pair(107.6,false));
    enemy.push_back(make_pair(1500.0,680.0));
    enemyon.push_back(make_pair(108.0,false));
    enemy.push_back(make_pair(1500.0,680.0));
    enemyon.push_back(make_pair(110.0,false));
    enemy.push_back(make_pair(1500.0,680.0));
    enemyon.push_back(make_pair(112.0,false));
    enemy.push_back(make_pair(1500.0,680.0));
    enemyon.push_back(make_pair(117.0,false));
   enemy.push_back(make_pair(1500.0,680.0));
    enemyon.push_back(make_pair(119.6,false));
    enemy.push_back(make_pair(1500.0,680.0));
    enemyon.push_back(make_pair(121.0,false));
    enemy.push_back(make_pair(1500.0,680.0));
    enemyon.push_back(make_pair(122.0,false));
    enemy.push_back(make_pair(1500.0,680.0));
    enemyon.push_back(make_pair(125.0,false));
    enemy.push_back(make_pair(1500.0,680.0));
    enemyon.push_back(make_pair(135.0,false));
    enemy.push_back(make_pair(1500.0,680.0));
    enemyon.push_back(make_pair(135.5,false));
    enemy.push_back(make_pair(1500.0,680.0));
    enemyon.push_back(make_pair(137.0,false));
    enemy.push_back(make_pair(1500.0,680.0));
     enemyon.push_back(make_pair(163.0,false));
    enemy.push_back(make_pair(1500.0,680.0));
    enemyon.push_back(make_pair(175.0,false));
    enemy.push_back(make_pair(1500.0,680.0));
    enemyon.push_back(make_pair(176.2,false));
    enemy.push_back(make_pair(1500.0,680.0));
   enemyon.push_back(make_pair(178.0,false));
    enemy.push_back(make_pair(1500.0,680.0));
    enemyon.push_back(make_pair(182.7,false));
    enemy.push_back(make_pair(1500.0,680.0));
    enemyon.push_back(make_pair(187.0,false));
    enemy.push_back(make_pair(1500.0,680.0));
    enemyon.push_back(make_pair(189.0,false));
    enemy.push_back(make_pair(1500.0,680.0));
    enemyon.push_back(make_pair(191.0,false));
    enemy.push_back(make_pair(1500.0,680.0));
    enemyon.push_back(make_pair(192.0,false));
    enemy.push_back(make_pair(1500.0,680.0));
    enemyon.push_back(make_pair(194.0,false));
    enemy.push_back(make_pair(1500.0,680.0));
    enemyon.push_back(make_pair(199.0,false));

   //Enemy 1 initiation:
    vector< pair <double,double>>enemy1;
    vector<pair<double,bool>>enemy1on;
    RectangleShape enemy1body(Vector2f(200.0f,200.0f));
    Texture enemy1texture[10];

    enemy1texture[0].loadFromFile("enemy1/0.png");
    enemy1texture[1].loadFromFile("enemy1/1.png");
    enemy1texture[2].loadFromFile("enemy1/2.png");
    enemy1texture[3].loadFromFile("enemy1/3.png");
    enemy1texture[4].loadFromFile("enemy1/4.png");
    enemy1texture[5].loadFromFile("enemy1/5.png");
    enemy1texture[6].loadFromFile("enemy1/6.png");
    enemy1texture[7].loadFromFile("enemy1/7.png");
    enemy1texture[8].loadFromFile("enemy1/8.png");
    enemy1texture[9].loadFromFile("enemy1/9.png");


    enemy1.push_back(make_pair(1500.0,100.0));
    enemy1on.push_back(make_pair(108.0,false));
    enemy1.push_back(make_pair(1500.0,100.0));
    enemy1on.push_back(make_pair(115.0,false));
    enemy1.push_back(make_pair(1500.0,100.0));
    enemy1on.push_back(make_pair(120.0,false));
    enemy1.push_back(make_pair(1500.0,100.0));
    enemy1on.push_back(make_pair(130.0,false));
    enemy1.push_back(make_pair(1500.0,100.0));
    enemy1on.push_back(make_pair(131.0,false));
    enemy1.push_back(make_pair(1500.0,100.0));
    enemy1on.push_back(make_pair(133.0,false));
    enemy1.push_back(make_pair(1500.0,100.0));
    enemy1on.push_back(make_pair(161.0,false));
    enemy1.push_back(make_pair(1500.0,100.0));
    enemy1on.push_back(make_pair(162.0,false));
    enemy1.push_back(make_pair(1500.0,100.0));
    enemy1on.push_back(make_pair(162.0,false));
    enemy1.push_back(make_pair(1500.0,100.0));
    enemy1on.push_back(make_pair(173.0,false));
    enemy1.push_back(make_pair(1500.0,100.0));
    enemy1on.push_back(make_pair(185.0,false));
    enemy1.push_back(make_pair(1500.0,100.0));
    enemy1on.push_back(make_pair(195.0,false));
     enemy1.push_back(make_pair(1500.0,100.0));
    enemy1on.push_back(make_pair(200.0,false));

    //Venom initiation:
    vector< pair <double,double>>enemy1venom;
    double enemy1venomtimer=1.0;
    RectangleShape enemy1venombody(Vector2f(50.0f,50.0f));
    Texture enemy1venomtexture;
    enemy1venomtexture.loadFromFile("enemy1/venom/1.png");

    //Enemy 2 initiation:
    vector< pair <double,double>>enemy2;
    vector<pair<double,bool>>enemy2on;
    RectangleShape enemy2body(Vector2f(150.0f,150.0f));
    Texture enemy2texture[10];

    enemy2texture[0].loadFromFile("enemy2/0.png");
    enemy2texture[1].loadFromFile("enemy2/1.png");
    enemy2texture[2].loadFromFile("enemy2/2.png");
    enemy2texture[3].loadFromFile("enemy2/3.png");
    enemy2texture[4].loadFromFile("enemy2/4.png");
    enemy2texture[5].loadFromFile("enemy2/5.png");
    enemy2texture[6].loadFromFile("enemy2/6.png");
    enemy2texture[7].loadFromFile("enemy2/7.png");
    enemy2texture[8].loadFromFile("enemy2/8.png");
    enemy2texture[9].loadFromFile("enemy2/9.png");


    enemy2.push_back(make_pair(1500.0,680.0));
    enemy2on.push_back(make_pair(107.2,false));
    enemy2.push_back(make_pair(1500.0,680.0));
    enemy2on.push_back(make_pair(107.5,false));
    enemy2.push_back(make_pair(1500.0,680.0));
    enemy2on.push_back(make_pair(107.8,false));
    enemy2.push_back(make_pair(1500.0,680.0));
    enemy2on.push_back(make_pair(108.7,false));
    enemy2.push_back(make_pair(1500.0,680.0));
    enemy2on.push_back(make_pair(108.9,false));
    enemy2.push_back(make_pair(1500.0,680.0));
    enemy2on.push_back(make_pair(113.0,false));
    enemy2.push_back(make_pair(1500.0,680.0));
    enemy2on.push_back(make_pair(115.0,false));
    enemy2.push_back(make_pair(1500.0,680.0));
    enemy2on.push_back(make_pair(116.5,false));
    enemy2.push_back(make_pair(1500.0,680.0));
    enemy2on.push_back(make_pair(118.5,false));
    enemy2.push_back(make_pair(1500.0,680.0));
    enemy2on.push_back(make_pair(123.0,false));
    enemy2.push_back(make_pair(1500.0,680.0));
    enemy2on.push_back(make_pair(124.0,false));
    enemy2.push_back(make_pair(1500.0,680.0));
    enemy2on.push_back(make_pair(154.0,false));
     enemy2.push_back(make_pair(1500.0,680.0));
    enemy2on.push_back(make_pair(155.0,false));
    enemy2.push_back(make_pair(1500.0,680.0));
    enemy2on.push_back(make_pair(158.0,false));
    enemy2.push_back(make_pair(1500.0,680.0));
    enemy2on.push_back(make_pair(159.0,false));
     enemy2.push_back(make_pair(1500.0,680.0));
    enemy2on.push_back(make_pair(160.0,false));
    enemy2.push_back(make_pair(1500.0,680.0));
    enemy2on.push_back(make_pair(164.0,false));
    enemy2.push_back(make_pair(1500.0,680.0));
    enemy2on.push_back(make_pair(180.0,false));
    enemy2.push_back(make_pair(1500.0,680.0));
    enemy2on.push_back(make_pair(184.0,false));
    enemy2.push_back(make_pair(1500.0,680.0));
    enemy2on.push_back(make_pair(185.0,false));
    enemy2.push_back(make_pair(1500.0,680.0));
    enemy2on.push_back(make_pair(188.0,false));
    enemy2.push_back(make_pair(1500.0,680.0));
    enemy2on.push_back(make_pair(196.0,false));
    enemy2.push_back(make_pair(1500.0,680.0));
    enemy2on.push_back(make_pair(197.0,false));


    //Enemy 4 initiation:
    vector< pair <double,double>>enemy4;
    vector<pair<double,bool>>enemy4on;
    RectangleShape enemy4body(Vector2f(150.0f,150.0f));
    Texture enemy4texture[10];

    enemy4.push_back(make_pair(1500.0,680.0));
    enemy4on.push_back(make_pair(117.5,false));
    enemy4.push_back(make_pair(1500.0,680.0));
    enemy4on.push_back(make_pair(120.0,false));
    enemy4.push_back(make_pair(1500.0,680.0));
    enemy4on.push_back(make_pair(126.5,false));
    enemy4.push_back(make_pair(1500.0,680.0));
    enemy4on.push_back(make_pair(127.5,false));
    enemy4.push_back(make_pair(1500.0,680.0));
    enemy4on.push_back(make_pair(134.0,false));
    enemy4.push_back(make_pair(1500.0,680.0));
    enemy4on.push_back(make_pair(150.0,false));
    enemy4.push_back(make_pair(1500.0,680.0));
    enemy4on.push_back(make_pair(151.0,false));
    enemy4.push_back(make_pair(1500.0,680.0));
    enemy4on.push_back(make_pair(152.0,false));
    enemy4.push_back(make_pair(1500.0,680.0));
    enemy4on.push_back(make_pair(165.5,false));
    enemy4.push_back(make_pair(1500.0,680.0));
    enemy4on.push_back(make_pair(186.5,false));
    enemy4.push_back(make_pair(1500.0,680.0));
    enemy4on.push_back(make_pair(192.5,false));
    enemy4.push_back(make_pair(1500.0,680.0));
    enemy4on.push_back(make_pair(193.5,false));
    enemy4.push_back(make_pair(1500.0,680.0));
    enemy4on.push_back(make_pair(198.0,false));
    enemy4.push_back(make_pair(1500.0,680.0));
    enemy4on.push_back(make_pair(1.0,false));

    //Venom 1 initiation:
    vector< pair <double,double>>enemy4venom;
    double enemy4venomtimer=1.0;
    RectangleShape enemy4venombody(Vector2f(50.0f,50.0f));
    Texture enemy4venomtexture;
    enemy4venomtexture.loadFromFile("enemy1/venom/1.png");

    enemy4texture[0].loadFromFile("enemy4/0.png");
    enemy4texture[1].loadFromFile("enemy4/1.png");
    enemy4texture[2].loadFromFile("enemy4/2.png");
    enemy4texture[3].loadFromFile("enemy4/3.png");
    enemy4texture[4].loadFromFile("enemy4/4.png");
    enemy4texture[5].loadFromFile("enemy4/5.png");
    enemy4texture[6].loadFromFile("enemy4/6.png");
    enemy4texture[7].loadFromFile("enemy4/7.png");
    enemy4texture[8].loadFromFile("enemy4/8.png");
    enemy4texture[9].loadFromFile("enemy4/9.png");


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
                if(obstaclelog[j].first>=600&&obstaclelog[j].first<=800&&obstaclelog[j].second-100<=y&&obstaclelogtimer[j].second)
                {

                if(faceright&&(ceil(obstaclelog[j].first)==800||ceil(obstaclelog[j].first)==799||ceil(obstaclelog[j].first)==798))
                {

                    steprightonx=false;
                }
                if(faceright==false&&(ceil(obstaclelog[j].first)==600||(ceil(obstaclelog[j].first)==601)||(ceil(obstaclelog[j].first)==602)))
                {

                    stepleftonx=false;
                }
                    stepony=false;
                std::cout<<ceil(obstaclelog[j].first)<<endl;
                }




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
                if(ceil(obstacleslide[j].first)==450&&slide==0&&faceright)
                {

                    steprightonx=false;
                }
                if((ceil(obstacleslide[j].first)==300||ceil(obstacleslide[j].first)==301)&&slide==0&&faceright==false)
                {
                    stepleftonx=false;
                }


            }
        }

        //rock:
        if(!obstaclerock.empty())
        {
            for(int j=0;j<obstaclerock.size();j++)
            {
                if(obstaclerock[j].first>=550&&obstaclerock[j].first<=750&&obstaclerock[j].second-150<=y&&obstaclerocktimer[j].second)
                {

                if(faceright&&(ceil(obstaclerock[j].first)==750))
                {

                    steprightonx=false;
                }
                if(faceright==false&&(ceil(obstaclerock[j].first)==551||(ceil(obstaclerock[j].first)==552)))
                {

                    stepleftonx=false;
                }
                    stepony=false;

                }



            }
        }

        //Coin check:
        if(!coin.empty())
        {
            for(int j=0;j<coin.size();j++)
            {
                if((ceil(coin[j].first)==700)&&(coin[j].second>=y-100.0&&coin[j].second<=y+100.0)&&cointimer[j].second)
                {
                    coin.erase(coin.begin()+j);
                    cointimer.erase(cointimer.begin()+j);;
                    count4++;
                    if(count4>9)
                    {
                        count3++;
                        count4=0;
                    }
                    if(count3>9)
                    {
                        count2++;
                        count3=0;
                    }
                    if(count2>9)
                    {
                        count1++;
                        count2=0;
                    }
                }
            }
        }
         //enemy check:
        if(!enemy.empty())
        {
            for(int j=0;j<enemy.size();j++)
            {
                if((ceil(enemy[j].first)==700||ceil(enemy[j].first)==701||ceil(enemy[j].first)==702)&&(enemy[j].second>=y-100.0&&enemy[j].second<=y+100.0)&&enemyon[j].second)
                {
                    collisionbody.setPosition(enemy[j].first,enemy[j].second);
                collisionbool=true;
                collisiontime=.5;
                    enemy.erase(enemy.begin()+j);
                    enemyon.erase(enemyon.begin()+j);;

                    if(shield>0)
                    {
                        shield--;
                    }
                    else if(health>0)
                    {
                        health--;
                    }
                    else{gameover=true;}

                }
            }
        }

        //enemy 2 check:
        if(!enemy2.empty())
        {
            for(int j=0;j<enemy2.size();j++)
            {
                if((ceil(enemy2[j].first)==700||ceil(enemy2[j].first)==701||ceil(enemy2[j].first)==702)&&(enemy2[j].second>=y-300.0&&enemy2[j].second<=y+100.0)&&enemy2on[j].second)
                {
                    collisionbody.setPosition(enemy2[j].first,enemy2[j].second);
                collisionbool=true;
                collisiontime=.5;
                    enemy2.erase(enemy2.begin()+j);
                    enemy2on.erase(enemy2on.begin()+j);;

                    if(shield>0)
                    {
                        shield--;
                    }
                    else if(health>0)
                    {
                        health--;
                    }
                    else{gameover=true;}

                }
            }
        }
        //enemy 4 check:
        if(!enemy4.empty())
        {
            for(int j=0;j<enemy4.size();j++)
            {
                if((ceil(enemy4[j].first)==700||ceil(enemy4[j].first)==701||ceil(enemy4[j].first)==702)&&(enemy4[j].second>=y-300.0&&enemy4[j].second<=y+100.0)&&enemy4on[j].second)
                {
                    collisionbody.setPosition(enemy4[j].first,enemy4[j].second);
                collisionbool=true;
                collisiontime=.5;
                    enemy4.erase(enemy4.begin()+j);
                    enemy4on.erase(enemy4on.begin()+j);;

                    if(shield>0)
                    {
                        shield--;
                    }
                    else if(health>0)
                    {
                        health--;
                    }
                    else{gameover=true;}

                }
            }
        }

        //Collision check:

        collisionbody.setTexture(&collision);

        for(int j=0;j<bullet.size();j++)
        {
            for(int k=0;k<enemy.size();k++)
            {
                if((bullet[j].first>=enemy[k].first-10&&bullet[j].first<=enemy[k].first+10)&&(bullet[j].second>=650.0&&bullet[j].second<=730.0)&&enemyon[k].second)
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
            for(int k=0;k<enemy2.size();k++)
            {
                if((bullet[j].first>=enemy2[k].first-10&&bullet[j].first<=enemy2[k].first+10)&&(bullet[j].second>=650.0&&bullet[j].second<=730.0)&&enemy2on[k].second)
                   {
                collisionbody.setPosition(bullet[j].first,bullet[j].second);
                collisionbool=true;
                collisiontime=.5;
                      enemy2.erase(enemy2.begin()+k);
                enemy2on.erase(enemy2on.begin()+k);
                    bullet.erase(bullet.begin()+j);
                bulletface.erase(bulletface.begin()+j);

                   }
            }

            for(int k=0;k<enemy4.size();k++)
            {
                if((bullet[j].first>=enemy4[k].first-10&&bullet[j].first<=enemy4[k].first+10)&&(bullet[j].second>=650.0&&bullet[j].second<=730.0)&&enemy4on[k].second)
                   {
                collisionbody.setPosition(bullet[j].first,bullet[j].second);
                collisionbool=true;
                collisiontime=.5;
                      enemy4.erase(enemy4.begin()+k);
                enemy4on.erase(enemy4on.begin()+k);
                    bullet.erase(bullet.begin()+j);
                bulletface.erase(bulletface.begin()+j);

                   }
            }
        }

        //health check:
        if(healthx>=700&&healthx<=750.0&&y>=healthy-50&&y<=healthy+100&&healthon)
        {
            healthontimer=0.0;
            if(health<5){health++;}
            healthon=false;
        }

        //shield check:
        if(shieldx>=700&&shieldx<=800.0&&y>=shieldy-50&&y<=shieldy+100&&shieldon)
        {
            shieldon=false;
            shieldontimer=0.0;

            if(shield<5){shield++;}
        }
        //cout<<shield<<" "<<health<<endl;




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


        //std::cout<<time<<" "<<stepcount<<std::endl;



        //Obstacle update:

        //Log:
        if(!obstaclelog.empty())
        {
            for(int j=0;j<obstaclelog.size();j++)
            {
                if(stepcount>=obstaclelogtimer[j].first&&stepcount<=obstaclelogtimer[j].first+10.0)
                    {
                        obstaclelogtimer[j].second=true;
                        obstaclebody.setTexture(&obstacletexture[0]);

                }
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
        //rock:
        if(!obstaclerock.empty())
        {
            for(int j=0;j<obstaclerock.size();j++)
            {
                if(stepcount>=obstaclerocktimer[j].first&&stepcount<=obstaclerocktimer[j].first+10.0)
                    {
                        obstaclerocktimer[j].second=true;
                        obstaclerockbody.setTexture(&obstacletexture[3]);

                }
                else{obstaclerocktimer[j].second=false;}
                if(obstaclerocktimer[j].second)
                {

                    if(Keyboard::isKeyPressed(Keyboard::D)&&steprightonx)
                    {
                        obstaclerock[j].first-=deltatime*speed;

                    }
                    if(Keyboard::isKeyPressed(Keyboard::A)&&stepleftonx)
                    {
                        obstaclerock[j].first+=deltatime*speed;

                    }
                }

            }
        }
        //river:
        if(!obstacleriver.empty())
        {
            for(int j=0;j<obstacleriver.size();j++)
            {
                if(stepcount>=obstaclerivertimer[j].first&&stepcount<=obstaclerivertimer[j].first+10.0)
                    {
                        obstaclerivertimer[j].second=true;
                        obstacleriverbody.setTexture(&obstacletexture[4]);

                }
                else{obstaclerivertimer[j].second=false;}
                if(obstaclerivertimer[j].second)
                {

                    if(Keyboard::isKeyPressed(Keyboard::D)&&steprightonx)
                    {
                        obstacleriver[j].first-=deltatime*speed;

                    }
                    if(Keyboard::isKeyPressed(Keyboard::A)&&stepleftonx)
                    {
                        obstacleriver[j].first+=deltatime*speed;

                    }
                }

            }
        }

        //hole:
        if(!obstaclehole.empty())
        {
            for(int j=0;j<obstaclehole.size();j++)
            {
                if(stepcount>=obstacleholetimer[j].first&&stepcount<=obstacleholetimer[j].first+10.0)
                    {
                        obstacleholetimer[j].second=true;
                        obstacleholebody.setTexture(&obstacletexture[5]);

                }
                else{obstacleholetimer[j].second=false;}
                if(obstacleholetimer[j].second)
                {

                    if(Keyboard::isKeyPressed(Keyboard::D)&&steprightonx)
                    {
                        obstaclehole[j].first-=deltatime*speed;

                    }
                    if(Keyboard::isKeyPressed(Keyboard::A)&&stepleftonx)
                    {
                        obstaclehole[j].first+=deltatime*speed;

                    }
                }

            }
        }

        //health bar update:

        healthbarbody.setTexture(&healthbar[health]);
        healthbarbody.setPosition(10.0,10.0);

        //shield bar update:

        shieldbarbody.setTexture(&shieldbar[shield]);
        shieldbarbody.setPosition(10.0,70.0);


        //health update:
        if(stepcount>=0.0&&stepcount<=1000.0)
        {

            if(healthontimer>0.0)
            {
                healthontimer-=deltatime;
                healthon=true;
            }
            else if(healthofftimer>0.0)
            {
                healthon=false;
                healthofftimer-=deltatime;
                healthx=50.0+rand()%1450;
                healthy=500.0+rand()%200;
            }
            else
            {
                healthontimer=3.0;
                healthofftimer=3.0;
            }
            healthbody.setTexture(&healthtexture);
            healthbody.setPosition(healthx,healthy);


        }
        if(Keyboard::isKeyPressed(Keyboard::D)&&steprightonx)
                    {
                        healthx-=deltatime*speed;

                    }
                    if(Keyboard::isKeyPressed(Keyboard::A)&&stepleftonx)
                    {
                        healthx+=deltatime*speed;

                    }

        //Shield update:
        if(stepcount>=0.0&&stepcount<=1500.0)
        {

            if(shieldontimer>0.0)
            {
                shieldontimer-=deltatime;
                shieldon=true;
                shieldbody.setPosition(shieldx,shieldy);
            }
            else if(shieldofftimer>0.0)
            {
                shieldon=false;
                shieldofftimer-=deltatime;
                shieldx=50.0+rand()%1450;
                shieldy=500.0+rand()%200;
            }
            else
            {
                shieldontimer=5.0;
                shieldofftimer=5.0;
            }
            shieldbody.setTexture(&shieldtexture);




        }

            if(Keyboard::isKeyPressed(Keyboard::D)&&steprightonx)
                    {
                        shieldx-=deltatime*speed;

                    }
        if(Keyboard::isKeyPressed(Keyboard::A)&&stepleftonx)
                    {
                        shieldx+=deltatime*speed;

                    }


        //coin update:
        if(!coin.empty())
        {
            for(int j=0;j<coin.size();j++)
            {
                if(stepcount>=cointimer[j].first&&stepcount<=cointimer[j].first+10.0)
                    {
                        cointimer[j].second=true;
                        coinbody.setTexture(&cointexture[i]);

                }
                else{cointimer[j].second=false;}
                if(cointimer[j].second)
                {

                    if(Keyboard::isKeyPressed(Keyboard::D)&&steprightonx)
                    {
                        coin[j].first-=deltatime*speed;

                    }
                    if(Keyboard::isKeyPressed(Keyboard::A)&&stepleftonx)
                    {
                        coin[j].first+=deltatime*speed;

                    }
                }

            }
        }

        //enemy 1 venom update:

        enemy1venomtimer-=deltatime;
        enemy1venombody.setTexture(&enemy1venomtexture);

        if(!enemy1.empty()&&enemy1venomtimer<=0)
        {
            for(int j=0;j<enemy1.size();j++)
            {
                if(enemy1on[j].second)
                {
                    enemy1venom.push_back(make_pair(enemy1[j].first+20,enemy1[j].second+40));
                }

            }
            enemy1venomtimer=1.0;
        }

        //enemy 4 venom update:

        enemy4venomtimer-=deltatime;
        enemy4venombody.setTexture(&enemy4venomtexture);

        if(!enemy4.empty()&&enemy4venomtimer<=0)
        {
            for(int j=0;j<enemy4.size();j++)
            {
                if(enemy4on[j].second)
                {
                    enemy4venom.push_back(make_pair(enemy4[j].first+20,enemy4[j].second+40));
                }

            }
            enemy4venomtimer=1.0;
        }

        window.setFramerateLimit(120);


        window.clear(Color:: White);
    window.draw(sprite1);
        window.draw(sprite);
        if(!bullet.empty())
        {
            for(int j=0;j<bullet.size();j++)
            {
                if(bulletface[j])bullet[j].first+=deltatime*(speed+50);
                else bullet[j].first-=deltatime*speed;
                if(bulletface[j])
                    {
                        if(Keyboard::isKeyPressed(Keyboard::D)){bullet[j].first+=deltatime;}
                        else if(Keyboard::isKeyPressed(Keyboard::A)){bullet[j].first+=deltatime*speed;}
                }
                else
                {
                    if(Keyboard::isKeyPressed(Keyboard::D)){bullet[j].first-=deltatime*speed;}
                        else if(Keyboard::isKeyPressed(Keyboard::A)){bullet[j].first-=deltatime;}

                }
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

        //Venom:
        if(!enemy1venom.empty())
        {
            for(int j=0;j<enemy1venom.size();j++)
            {
                if(Keyboard::isKeyPressed(Keyboard::D)&&steprightonx)
                    {
                        enemy1venom[j].first-=deltatime*speed;

                    }
                    if(Keyboard::isKeyPressed(Keyboard::A)&&stepleftonx)
                    {
                        enemy1venom[j].first+=deltatime*speed;

                    }
                    enemy1venom[j].second+=deltatime*speed;

                enemy1venombody.setPosition(enemy1venom[j].first,enemy1venom[j].second);
                window.draw(enemy1venombody);

            }
        }

        //Enemy 4 Venom:
        if(!enemy4venom.empty())
        {
            for(int j=0;j<enemy4venom.size();j++)
            {
                if(Keyboard::isKeyPressed(Keyboard::D)){enemy4venom[j].first-=deltatime*speed;}
                        else if(Keyboard::isKeyPressed(Keyboard::A)){enemy4venom[j].first-=deltatime;}
                    enemy4venom[j].first-=deltatime*(speed+100);

                enemy4venombody.setTexture(&enemy4venomtexture);
                enemy4venombody.setPosition(enemy4venom[j].first,enemy4venom[j].second);
                window.draw(enemy4venombody);

            }
        }
        if(!enemy.empty())
        {
            if(i!=9)body6.setTexture(&playertexture8[i]);
            for(int j=0;j<enemy.size();j++)
            {
                if(stepcount>=enemyon[j].first){enemyon[j].second=true;}

                if(enemyon[j].second)
                {

                    enemy[j].first-=deltatime*(speed);
                    if(Keyboard::isKeyPressed(Keyboard::A)){enemy[j].first+=deltatime;}
                    if(Keyboard::isKeyPressed(Keyboard::D)){enemy[j].first-=deltatime*speed;}
                }
                if(enemy[j].first<=0.0)
                {
                enemy.erase(enemy.begin());
                enemyon.erase(enemyon.begin());

                }

                if(enemyon[j].second)
                    {
                        body6.setPosition(Vector2f(enemy[j].first,enemy[j].second));
                        window.draw(body6);
                    }
            }
        }

        if(!enemy1.empty())
        {
            enemy1body.setTexture(&enemy1texture[i]);
            for(int j=0;j<enemy1.size();j++)
            {
                if(stepcount>=enemy1on[j].first){enemy1on[j].second=true;}

                if(enemy1on[j].second)
                {

                    enemy1[j].first-=deltatime*(speed);
                    if(Keyboard::isKeyPressed(Keyboard::A)){enemy1[j].first+=deltatime;}
                    if(Keyboard::isKeyPressed(Keyboard::D)){enemy1[j].first-=deltatime*speed;}
                }
                if(enemy1[j].first<=0.0)
                {
                enemy1.erase(enemy1.begin());
                enemy1on.erase(enemy1on.begin());

                }

                if(enemy1on[j].second)
                    {
                        enemy1body.setPosition(Vector2f(enemy1[j].first,enemy1[j].second));
                        window.draw(enemy1body);
                    }
            }
        }

        //Enemy 2:

        if(!enemy2.empty())
        {
            enemy2body.setTexture(&enemy2texture[i]);
            for(int j=0;j<enemy2.size();j++)
            {
                if(stepcount>=enemy2on[j].first){enemy2on[j].second=true;}

                if(enemy2on[j].second)
                {

                    enemy2[j].first-=deltatime*(speed);
                    if(Keyboard::isKeyPressed(Keyboard::A)){enemy2[j].first+=deltatime;}
                    if(Keyboard::isKeyPressed(Keyboard::D)){enemy2[j].first-=deltatime*speed;}
                }
                if(enemy2[j].first<=0.0)
                {
                enemy2.erase(enemy2.begin());
                enemy2on.erase(enemy2on.begin());

                }

                if(enemy2on[j].second)
                    {
                        enemy2body.setPosition(Vector2f(enemy2[j].first,enemy2[j].second));
                        window.draw(enemy2body);
                    }
            }
        }

        //Enemy 4:

        if(!enemy4.empty())
        {
            enemy4body.setTexture(&enemy4texture[i]);
            for(int j=0;j<enemy4.size();j++)
            {
                if(stepcount>=enemy4on[j].first){enemy4on[j].second=true;}

                if(enemy4on[j].second)
                {

                    enemy4[j].first-=deltatime*(speed);
                    if(Keyboard::isKeyPressed(Keyboard::A)){enemy4[j].first+=deltatime;}
                    if(Keyboard::isKeyPressed(Keyboard::D)){enemy4[j].first-=deltatime*speed;}
                }
                if(enemy4[j].first<=0.0)
                {
                enemy4.erase(enemy4.begin());
                enemy4on.erase(enemy4on.begin());

                }

                if(enemy4on[j].second)
                    {
                        enemy4body.setPosition(Vector2f(enemy4[j].first,enemy4[j].second));
                        window.draw(enemy4body);
                    }
            }
        }

        //Obstacle draw:

        //Log:

        if(!obstaclelog.empty())
        {
            for(int j=0;j<obstaclelog.size();j++)
            {

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


        //river:
         if(!obstacleriver.empty())
        {
            for(int j=0;j<obstacleriver.size();j++)
            {

                if(obstaclerivertimer[j].second)
                {   obstacleriverbody.setPosition(obstacleriver[j].first,obstacleriver[j].second);
                    window.draw(obstacleriverbody);
                }

            }
        }
        //hole:
         if(!obstaclehole.empty())
        {
            for(int j=0;j<obstaclehole.size();j++)
            {

                if(obstacleholetimer[j].second)
                {   obstacleholebody.setPosition(obstaclehole[j].first,obstaclehole[j].second);
                    window.draw(obstacleholebody);
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
        //Rock:

        if(!obstaclerock.empty())
        {
            for(int j=0;j<obstaclerock.size();j++)
            {

                if(obstaclerocktimer[j].second)
                {   obstaclerockbody.setPosition(obstaclerock[j].first,obstaclerock[j].second);
                    window.draw(obstaclerockbody);
                }

            }
        }

        if(pos==0&&jump==0)window.draw(body0);
        else if(pos==1&&jump==0&&slide==0)window.draw(body1);
        else if(pos==2&&jump==0&&slide==0)window.draw(body2);
        else if(pos==3&&jump!=0&&slide==0)window.draw(body3);
        else if(pos==4&&jump==0&&slide!=0)window.draw(body5);

        if(collisionbool)
        {   collisiontime-=deltatime;
            window.draw(collisionbody);
            if(collisiontime<=0.0)collisionbool=false;
        }


        window.draw(healthbarbody);
        window.draw(shieldbarbody);

        //coin:
         if(!coin.empty())
        {
            for(int j=0;j<coin.size();j++)
            {

                if(cointimer[j].second)
                {   coinbody.setPosition(coin[j].first,coin[j].second);
                    window.draw(coinbody);
                }

            }
        }

        //coin count:

        coincountbody.setTexture(&coincounttexture[count1]);
        coincountbody.setPosition(600.0,10.0);
        window.draw(coincountbody);

        coincountbody.setTexture(&coincounttexture[count2]);
        coincountbody.setPosition(650.0,10.0);
        window.draw(coincountbody);

        coincountbody.setTexture(&coincounttexture[count3]);
        coincountbody.setPosition(700.0,10.0);
        window.draw(coincountbody);

        coincountbody.setTexture(&coincounttexture[count4]);
        coincountbody.setPosition(750.0,10.0);
        window.draw(coincountbody);

        //Health:

        if(healthon)
        {
            window.draw(healthbody);
        }
        //Shield:

        if(shieldon)
        {
            window.draw(shieldbody);
        }



        window.display();
    }

    return 0;
}
