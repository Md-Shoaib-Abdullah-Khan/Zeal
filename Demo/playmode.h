#ifndef PLAYMODE_H
#define PLAYMODE_H


class Playmode
{
    private:
        //Gameover initiation:
         bool gameover=false;
        Texture gameovertexture;
        RectangleShape gameoverbody(Vector2f(1950.0f,1100.0f));

        //Gamewin initiation
        bool gamewin=false;
        RectangleShape gamewinbody(Vector2f(1950.0f,1100.0f));
        Texture gamewintexture;

        //Text initiation:
    Font font;

    Text text;
     //Obstacle check bool:
    bool steprightonx=true;
    bool stepleftonx=true;
    bool stepony=true;




    //Health & Shield:
    int health=5, shield=5;

    //health point initiation:
    RectangleShape healthbody(Vector2f(50.0f,50.0f));
    Texture healthtexture;

    double healthontimer=3.0,healthofftimer=3.0,healthx=200.0,healthy=600.0;
    bool healthon=false;

    //shield point initiation:
    RectangleShape shieldbody(Vector2f(50.0f,50.0f));
    Texture shieldtexture;

    double shieldontimer=3.0,shieldofftimer=3.0,shieldx=200.0,shieldy=600.0;
    bool shieldon=false;

    //health bar initiation:
    RectangleShape healthbarbody(Vector2f(300.0f,50.0f));
    Texture healthbar[6];


    //shield bar initiation:
    RectangleShape shieldbarbody(Vector2f(300.0f,50.0f));
    Texture shieldbar[6];


    //Coin count initiation:
    int count1=0,count2=0,count3=0,count4=0;

    RectangleShape coincountbody(Vector2f(40.0f,40.0f));
    Texture coincounttexture[10];



    //Coin initiation:
    RectangleShape coinbody(Vector2f(80.0f,80.0f));
    Texture cointexture[10];



    vector<pair<double,bool>>cointimer;
    vector<pair<double,double>>coin;

    cointimer.push_back(make_pair(0.0,false));
    coin.push_back(make_pair(900.0,10.0));
    cointimer.push_back(make_pair(2.0,false));
    coin.push_back(make_pair(2000.0,850.0));
    cointimer.push_back(make_pair(5.0,false));
    coin.push_back(make_pair(2000.0,850.0));
    cointimer.push_back(make_pair(10.0,false));
    coin.push_back(make_pair(2000.0,850.0));
    cointimer.push_back(make_pair(8.2,false));
    coin.push_back(make_pair(2000.0,650.0));
    cointimer.push_back(make_pair(16.0,false));
    coin.push_back(make_pair(2000.0,850.0));
    cointimer.push_back(make_pair(24.3,false));
    coin.push_back(make_pair(2000.0,650.0));
    cointimer.push_back(make_pair(20.3,false));
    coin.push_back(make_pair(2000.0,650.0));
    cointimer.push_back(make_pair(28.3,false));
    coin.push_back(make_pair(2000.0,650.0));
    cointimer.push_back(make_pair(33.2,false));
    coin.push_back(make_pair(2000.0,650.0));
    cointimer.push_back(make_pair(42.7,false));
    coin.push_back(make_pair(2000.0,650.0));
    cointimer.push_back(make_pair(46.7,false));
    coin.push_back(make_pair(2000.0,650.0));
    cointimer.push_back(make_pair(44.6,false));
    coin.push_back(make_pair(2000.0,450.0));
    cointimer.push_back(make_pair(44.8,false));
    coin.push_back(make_pair(2000.0,450.0));
    cointimer.push_back(make_pair(41.5,false));
    coin.push_back(make_pair(2000.0,850.0));
    cointimer.push_back(make_pair(43.5,false));
    coin.push_back(make_pair(2000.0,850.0));
    cointimer.push_back(make_pair(45.5,false));
    coin.push_back(make_pair(2000.0,850.0));
    cointimer.push_back(make_pair(54.2,false));
    coin.push_back(make_pair(2000.0,600.0));
    cointimer.push_back(make_pair(47.5,false));
    coin.push_back(make_pair(2000.0,850.0));
    cointimer.push_back(make_pair(62.2,false));
    coin.push_back(make_pair(2000.0,550.0));
    cointimer.push_back(make_pair(64.2,false));
    coin.push_back(make_pair(2000,350.0));
    cointimer.push_back(make_pair(66.2,false));
    coin.push_back(make_pair(2000,550.0));
    cointimer.push_back(make_pair(68.2,false));
    coin.push_back(make_pair(2000,750.0));
    cointimer.push_back(make_pair(70.2,false));
    coin.push_back(make_pair(2000,550.0));
    cointimer.push_back(make_pair(72.2,false));
    coin.push_back(make_pair(2000,350.0));
    cointimer.push_back(make_pair(73.2,false));
    coin.push_back(make_pair(2000,350.0));
    cointimer.push_back(make_pair(74.2,false));
    coin.push_back(make_pair(2000,350.0));
    cointimer.push_back(make_pair(75.2,false));
    coin.push_back(make_pair(2000,350.0));
    cointimer.push_back(make_pair(72.2,false));
    coin.push_back(make_pair(2000,750.0));
    cointimer.push_back(make_pair(73.2,false));
    coin.push_back(make_pair(2000,750.0));
    cointimer.push_back(make_pair(74.2,false));
    coin.push_back(make_pair(2000,750.0));
    cointimer.push_back(make_pair(75.2,false));
    coin.push_back(make_pair(2000,750.0));
    cointimer.push_back(make_pair(77.2,false));
    coin.push_back(make_pair(2000,550.0));
    cointimer.push_back(make_pair(79.2,false));
    coin.push_back(make_pair(2000.0,350.0));
    cointimer.push_back(make_pair(81.2,false));
    coin.push_back(make_pair(2000.0,550.0));
    cointimer.push_back(make_pair(83.2,false));
    coin.push_back(make_pair(2000.0,750.0));
    cointimer.push_back(make_pair(85.2,false));
    coin.push_back(make_pair(2000.0,550.0));
    cointimer.push_back(make_pair(90.2,false));
    coin.push_back(make_pair(2000.0,850.0));
    cointimer.push_back(make_pair(93.0,false));
    coin.push_back(make_pair(2000.0,850.0));
    cointimer.push_back(make_pair(95.2,false));
    coin.push_back(make_pair(2000.0,850.0));
    cointimer.push_back(make_pair(110.2,false));
    coin.push_back(make_pair(2000.0,850.0));
    cointimer.push_back(make_pair(142.2,false));
    coin.push_back(make_pair(2000.0,650.0));
    cointimer.push_back(make_pair(141.2,false));
    coin.push_back(make_pair(2000.0,450.0));
    cointimer.push_back(make_pair(140.2,false));
    coin.push_back(make_pair(2000.0,650.0));
    cointimer.push_back(make_pair(145.0,false));
    coin.push_back(make_pair(2000.0,650.0));
    cointimer.push_back(make_pair(150.2,false));
    coin.push_back(make_pair(2000.0,850.0));
    cointimer.push_back(make_pair(165.2,false));
    coin.push_back(make_pair(2000.0,650.0));
    cointimer.push_back(make_pair(170.0,false));
    coin.push_back(make_pair(2000.0,650.0));
    cointimer.push_back(make_pair(172.0,false));
    coin.push_back(make_pair(2000.0,850.0));
    cointimer.push_back(make_pair(174.0,false));
    coin.push_back(make_pair(2000.0,650.0));
    cointimer.push_back(make_pair(176.0,false));
    coin.push_back(make_pair(2000.0,850.0));
    cointimer.push_back(make_pair(178.0,false));
    coin.push_back(make_pair(2000.0,650.0));
    cointimer.push_back(make_pair(180.0,false));
    coin.push_back(make_pair(2000.0,850.0));
    cointimer.push_back(make_pair(182.0,false));
    coin.push_back(make_pair(2000.0,650.0));
    cointimer.push_back(make_pair(184.0,false));
    coin.push_back(make_pair(2000.0,850.0));
    cointimer.push_back(make_pair(186.0,false));
    coin.push_back(make_pair(2000.0,650.0));
    cointimer.push_back(make_pair(200.0,false));
    coin.push_back(make_pair(2000.0,850.0));
    cointimer.push_back(make_pair(200.0,false));
    coin.push_back(make_pair(2000.0,650.0));



    //Obstackle initiation:

    Texture obstacletexture[10];

    //Log:
    obstacletexture[0].loadFromFile("obstacle/log.png");
    RectangleShape obstaclebody(Vector2f(150.0f,150.0f));
    vector<pair<double,bool>>obstaclelogtimer;
    vector<pair<double,double>>obstaclelog;


    obstaclelogtimer.push_back(make_pair(4.8,false));
    obstaclelog.push_back(make_pair(2000,870.0));
    obstaclelogtimer.push_back(make_pair(90.0,false));
    obstaclelog.push_back(make_pair(2000.0,870.0));
    obstaclelogtimer.push_back(make_pair(95.0,false));
    obstaclelog.push_back(make_pair(2000.0,870.0));
    obstaclelogtimer.push_back(make_pair(110.0,false));
    obstaclelog.push_back(make_pair(2000.0,870.0));

    //stair:
    RectangleShape obstaclebodystair(Vector2f(150.0f,50.0f));

    vector<pair<double,bool>>obstaclestairtimer;
    vector<pair<double,double>>obstaclestair;

    obstaclestairtimer.push_back(make_pair(8.0,false));
    obstaclestair.push_back(make_pair(2000.0,750.0));
    obstaclestairtimer.push_back(make_pair(24.0,false));
    obstaclestair.push_back(make_pair(2000.0,750.0));
    obstaclestairtimer.push_back(make_pair(33.0,false));
    obstaclestair.push_back(make_pair(2000.0,750.0));
    obstaclestairtimer.push_back(make_pair(42.5,false));
    obstaclestair.push_back(make_pair(2000.0,750.0));
    obstaclestairtimer.push_back(make_pair(44.5,false));
    obstaclestair.push_back(make_pair(2000.0,550.0));
    obstaclestairtimer.push_back(make_pair(46.5,false));
    obstaclestair.push_back(make_pair(2000.0,750.0));
    obstaclestairtimer.push_back(make_pair(54.0,false));
    obstaclestair.push_back(make_pair(2000.0,650.0));
    obstaclestairtimer.push_back(make_pair(62.0,false));
    obstaclestair.push_back(make_pair(2000.0,650.0));
    obstaclestairtimer.push_back(make_pair(64.0,false));
    obstaclestair.push_back(make_pair(2000.0,450.0));
    obstaclestairtimer.push_back(make_pair(66.0,false));
    obstaclestair.push_back(make_pair(2000.0,650.0));
    obstaclestairtimer.push_back(make_pair(68.0,false));
    obstaclestair.push_back(make_pair(2000.0,850.0));
    obstaclestairtimer.push_back(make_pair(70.0,false));
    obstaclestair.push_back(make_pair(2000.0,650.0));
    obstaclestairtimer.push_back(make_pair(72.0,false));
    obstaclestair.push_back(make_pair(2000.0,450.0));
    obstaclestairtimer.push_back(make_pair(72.5,false));
    obstaclestair.push_back(make_pair(2000.0,450.0));
    obstaclestairtimer.push_back(make_pair(73.0,false));
    obstaclestair.push_back(make_pair(2000.0,450.0));
    obstaclestairtimer.push_back(make_pair(73.5,false));
    obstaclestair.push_back(make_pair(2000.0,450.0));
    obstaclestairtimer.push_back(make_pair(74.0,false));
    obstaclestair.push_back(make_pair(2000.0,450.0));
    obstaclestairtimer.push_back(make_pair(74.5,false));
    obstaclestair.push_back(make_pair(2000.0,450.0));
    obstaclestairtimer.push_back(make_pair(75.0,false));
    obstaclestair.push_back(make_pair(2000.0,450.0));
    obstaclestairtimer.push_back(make_pair(72.0,false));
    obstaclestair.push_back(make_pair(2000.0,850.0));
    obstaclestairtimer.push_back(make_pair(72.5,false));
    obstaclestair.push_back(make_pair(2000.0,850.0));
    obstaclestairtimer.push_back(make_pair(73.0,false));
    obstaclestair.push_back(make_pair(2000.0,850.0));
    obstaclestairtimer.push_back(make_pair(73.5,false));
    obstaclestair.push_back(make_pair(2000.0,850.0));
    obstaclestairtimer.push_back(make_pair(74.0,false));
    obstaclestair.push_back(make_pair(2000.0,850.0));
    obstaclestairtimer.push_back(make_pair(74.5,false));
    obstaclestair.push_back(make_pair(2000.0,850.0));
    obstaclestairtimer.push_back(make_pair(75.0,false));
    obstaclestair.push_back(make_pair(2000.0,850.0));
    obstaclestairtimer.push_back(make_pair(77.0,false));
    obstaclestair.push_back(make_pair(2000.0,650.0));
    obstaclestairtimer.push_back(make_pair(79.0,false));
    obstaclestair.push_back(make_pair(2000.0,450.0));
    obstaclestairtimer.push_back(make_pair(81.0,false));
    obstaclestair.push_back(make_pair(2000.0,650.0));
    obstaclestairtimer.push_back(make_pair(83.0,false));
    obstaclestair.push_back(make_pair(2000.0,850.0));
    obstaclestairtimer.push_back(make_pair(85.0,false));
    obstaclestair.push_back(make_pair(2000.0,650.0));
    obstaclestairtimer.push_back(make_pair(140.0,false));
    obstaclestair.push_back(make_pair(2000.0,750.0));
    obstaclestairtimer.push_back(make_pair(142.0,false));
    obstaclestair.push_back(make_pair(2000.0,750.0));




    //Slide:
    RectangleShape obstacleslidebody(Vector2f(500.0f,500.0f));
    vector<pair<double,bool>>obstacleslidetimer;
    vector<pair<double,double>>obstacleslide;

    obstacleslidetimer.push_back(make_pair(15,false));
    obstacleslide.push_back(make_pair(2000.0,500.0));
    obstacleslidetimer.push_back(make_pair(92,false));
    obstacleslide.push_back(make_pair(2000.0,500.0));

    //rock:
    RectangleShape obstaclerockbody(Vector2f(200.0f,200.0f));

    vector<pair<double,bool>>obstaclerocktimer;
    vector<pair<double,double>>obstaclerock;

    obstaclerocktimer.push_back(make_pair(52.0,false));
    obstaclerock.push_back(make_pair(2000.0,850.0));
    obstaclerocktimer.push_back(make_pair(56.0,false));
    obstaclerock.push_back(make_pair(2000.0,850.0));
    obstaclerocktimer.push_back(make_pair(60.0,false));
    obstaclerock.push_back(make_pair(2000.0,850.0));
    obstaclerocktimer.push_back(make_pair(87.0,false));
    obstaclerock.push_back(make_pair(2000.0,850.0));
    obstaclerocktimer.push_back(make_pair(165.0,false));
    obstaclerock.push_back(make_pair(2000.0,850.0));

    //river:
    RectangleShape obstacleriverbody(Vector2f(250.0f,250.0f));

    vector<pair<double,bool>>obstaclerivertimer;
    vector<pair<double,double>>obstacleriver;

    obstaclerivertimer.push_back(make_pair(20.0,false));
    obstacleriver.push_back(make_pair(2000.0,810.0));
    obstaclerivertimer.push_back(make_pair(61.0,false));
    obstacleriver.push_back(make_pair(2000.0,810.0));
    obstaclerivertimer.push_back(make_pair(62.0,false));
    obstacleriver.push_back(make_pair(2000.0,810.0));
    obstaclerivertimer.push_back(make_pair(63.0,false));
    obstacleriver.push_back(make_pair(2000.0,810.0));
    obstaclerivertimer.push_back(make_pair(64.0,false));
    obstacleriver.push_back(make_pair(2000.0,810.0));
    obstaclerivertimer.push_back(make_pair(65.0,false));
    obstacleriver.push_back(make_pair(2000.0,810.0));
    obstaclerivertimer.push_back(make_pair(66.0,false));
    obstacleriver.push_back(make_pair(2000.0,810.0));
    obstaclerivertimer.push_back(make_pair(67.0,false));
    obstacleriver.push_back(make_pair(2000.0,810.0));
    obstaclerivertimer.push_back(make_pair(68.0,false));
    obstacleriver.push_back(make_pair(2000.0,810.0));
    obstaclerivertimer.push_back(make_pair(69.0,false));
    obstacleriver.push_back(make_pair(2000.0,810.0));
    obstaclerivertimer.push_back(make_pair(70.0,false));
    obstacleriver.push_back(make_pair(2000.0,810.0));
    obstaclerivertimer.push_back(make_pair(71.0,false));
    obstacleriver.push_back(make_pair(2000.0,810.0));
    obstaclerivertimer.push_back(make_pair(72.0,false));
    obstacleriver.push_back(make_pair(2000.0,810.0));
    obstaclerivertimer.push_back(make_pair(73.0,false));
    obstacleriver.push_back(make_pair(2000.0,810.0));
    obstaclerivertimer.push_back(make_pair(74.0,false));
    obstacleriver.push_back(make_pair(2000.0,810.0));
    obstaclerivertimer.push_back(make_pair(75.0,false));
    obstacleriver.push_back(make_pair(2000.0,810.0));
    obstaclerivertimer.push_back(make_pair(76.0,false));
    obstacleriver.push_back(make_pair(2000.0,810.0));
    obstaclerivertimer.push_back(make_pair(77.0,false));
    obstacleriver.push_back(make_pair(2000.0,810.0));
    obstaclerivertimer.push_back(make_pair(78.0,false));
    obstacleriver.push_back(make_pair(2000.0,810.0));
    obstaclerivertimer.push_back(make_pair(79.0,false));
    obstacleriver.push_back(make_pair(2000.0,810.0));
    obstaclerivertimer.push_back(make_pair(80.0,false));
    obstacleriver.push_back(make_pair(2000.0,810.0));
    obstaclerivertimer.push_back(make_pair(81.0,false));
    obstacleriver.push_back(make_pair(2000.0,810.0));
    obstaclerivertimer.push_back(make_pair(82.0,false));
    obstacleriver.push_back(make_pair(2000.0,810.0));
    obstaclerivertimer.push_back(make_pair(83.0,false));
    obstacleriver.push_back(make_pair(2000.0,810.0));
    obstaclerivertimer.push_back(make_pair(84.0,false));
    obstacleriver.push_back(make_pair(2000.0,810.0));
    obstaclerivertimer.push_back(make_pair(85.0,false));
    obstacleriver.push_back(make_pair(2000.0,810.0));
    obstaclerivertimer.push_back(make_pair(86.0,false));
    obstacleriver.push_back(make_pair(2000.0,810.0));


    //hole:
    RectangleShape obstacleholebody(Vector2f(250.0f,400.0f));

    vector<pair<double,bool>>obstacleholetimer;
    vector<pair<double,double>>obstaclehole;

    obstacleholetimer.push_back(make_pair(28.0,false));
    obstaclehole.push_back(make_pair(2000.0,670.0));
    obstacleholetimer.push_back(make_pair(32.0,false));
    obstaclehole.push_back(make_pair(2000.0,670.0));
    obstacleholetimer.push_back(make_pair(33.0,false));
    obstaclehole.push_back(make_pair(2000.0,670.0));
    obstacleholetimer.push_back(make_pair(40.0,false));
    obstaclehole.push_back(make_pair(2000.0,670.0));
    obstacleholetimer.push_back(make_pair(42.0,false));
    obstaclehole.push_back(make_pair(2000.0,670.0));
    obstacleholetimer.push_back(make_pair(44.0,false));
    obstaclehole.push_back(make_pair(2000.0,670.0));
    obstacleholetimer.push_back(make_pair(46.0,false));
    obstaclehole.push_back(make_pair(2000.0,670.0));
    obstacleholetimer.push_back(make_pair(48.0,false));
    obstaclehole.push_back(make_pair(2000.0,670.0));





    //Enemy initiation:
    vector< pair <double,double>>enemy;
    vector<pair<double,bool>>enemyon;

    enemy.push_back(make_pair(2000.0,830.0));
    enemyon.push_back(make_pair(101.0,false));
    enemy.push_back(make_pair(2000.0,830.0));
    enemyon.push_back(make_pair(102.0,false));
    enemy.push_back(make_pair(2000.0,830.0));
    enemyon.push_back(make_pair(105.0,false));
    enemy.push_back(make_pair(2000.0,830.0));
    enemyon.push_back(make_pair(105.0,false));
    enemy.push_back(make_pair(2000.0,830.0));
    enemyon.push_back(make_pair(105.5,false));
    enemy.push_back(make_pair(2000.0,830.0));
    enemyon.push_back(make_pair(105.7,false));
    enemy.push_back(make_pair(2000.0,830.0));
     enemyon.push_back(make_pair(107.6,false));
    enemy.push_back(make_pair(2000.0,830.0));
    enemyon.push_back(make_pair(108.0,false));
    enemy.push_back(make_pair(2000.0,830.0));
    enemyon.push_back(make_pair(110.0,false));
    enemy.push_back(make_pair(2000.0,830.0));
    enemyon.push_back(make_pair(112.0,false));
    enemy.push_back(make_pair(2000.0,830.0));
    enemyon.push_back(make_pair(117.0,false));
    enemy.push_back(make_pair(2000.0,830.0));
    enemyon.push_back(make_pair(119.6,false));
    enemy.push_back(make_pair(2000.0,830.0));
    enemyon.push_back(make_pair(121.0,false));
    enemy.push_back(make_pair(2000.0,830.0));
    enemyon.push_back(make_pair(122.0,false));
    enemy.push_back(make_pair(2000.0,830.0));
    enemyon.push_back(make_pair(125.0,false));
    enemy.push_back(make_pair(2000.0,830.0));
    enemyon.push_back(make_pair(135.0,false));
    enemy.push_back(make_pair(2000.0,830.0));
    enemyon.push_back(make_pair(135.5,false));
    enemy.push_back(make_pair(2000.0,830.0));
    enemyon.push_back(make_pair(137.0,false));
    enemy.push_back(make_pair(2000.0,830.0));
     enemyon.push_back(make_pair(163.0,false));
    enemy.push_back(make_pair(2000.0,830.0));
    enemyon.push_back(make_pair(175.0,false));
    enemy.push_back(make_pair(2000.0,830.0));
    enemyon.push_back(make_pair(176.2,false));
    enemy.push_back(make_pair(2000.0,830.0));
   enemyon.push_back(make_pair(178.0,false));
    enemy.push_back(make_pair(2000.0,830.0));
    enemyon.push_back(make_pair(182.7,false));
    enemy.push_back(make_pair(2000.0,830.0));
    enemyon.push_back(make_pair(187.0,false));
    enemy.push_back(make_pair(2000.0,830.0));
    enemyon.push_back(make_pair(189.0,false));
    enemy.push_back(make_pair(2000.0,830.0));
    enemyon.push_back(make_pair(191.0,false));
    enemy.push_back(make_pair(2000.0,830.0));
    enemyon.push_back(make_pair(192.0,false));
    enemy.push_back(make_pair(2000.0,830.0));
    enemyon.push_back(make_pair(194.0,false));
    enemy.push_back(make_pair(2000.0,830.0));
    enemyon.push_back(make_pair(199.0,false));

   //Enemy 1 initiation:
    vector< pair <double,double>>enemy1;
    vector<pair<double,bool>>enemy1on;
    RectangleShape enemy1body(Vector2f(200.0f,200.0f));
    Texture enemy1texture[10];




    enemy1.push_back(make_pair(2000.0,250.0));
    enemy1on.push_back(make_pair(108.0,false));
    enemy1.push_back(make_pair(2000.0,250.0));
    enemy1on.push_back(make_pair(115.0,false));
    enemy1.push_back(make_pair(2000.0,250.0));
    enemy1on.push_back(make_pair(120.0,false));
    enemy1.push_back(make_pair(2000.0,250.0));
    enemy1on.push_back(make_pair(130.0,false));
    enemy1.push_back(make_pair(2000.0,250.0));
    enemy1on.push_back(make_pair(131.0,false));
    enemy1.push_back(make_pair(2000.0,250.0));
    enemy1on.push_back(make_pair(133.0,false));
    enemy1.push_back(make_pair(2000.0,250.0));
    enemy1on.push_back(make_pair(161.0,false));
    enemy1.push_back(make_pair(2000.0,250.0));
    enemy1on.push_back(make_pair(162.0,false));
    enemy1.push_back(make_pair(2000.0,250.0));
    enemy1on.push_back(make_pair(162.0,false));
    enemy1.push_back(make_pair(2000.0,250.0));
    enemy1on.push_back(make_pair(173.0,false));
    enemy1.push_back(make_pair(2000.0,250.0));
    enemy1on.push_back(make_pair(185.0,false));
    enemy1.push_back(make_pair(2000.0,250.0));
    enemy1on.push_back(make_pair(195.0,false));
     enemy1.push_back(make_pair(2000.0,250.0));
    enemy1on.push_back(make_pair(200.0,false));

    //Venom initiation:
    vector< pair <double,double>>enemy1venom;
    double enemy1venomtimer=1.0;
    RectangleShape enemy1venombody(Vector2f(50.0f,50.0f));
    Texture enemy1venomtexture;


    //Enemy 2 initiation:
    vector< pair <double,double>>enemy2;
    vector<pair<double,bool>>enemy2on;
    RectangleShape enemy2body(Vector2f(150.0f,150.0f));
    Texture enemy2texture[10];




    enemy2.push_back(make_pair(2000.0,830.0));
    enemy2on.push_back(make_pair(107.2,false));
    enemy2.push_back(make_pair(2000.0,830.0));
    enemy2on.push_back(make_pair(107.5,false));
    enemy2.push_back(make_pair(2000.0,830.0));
    enemy2on.push_back(make_pair(107.8,false));
    enemy2.push_back(make_pair(2000.0,830.0));
    enemy2on.push_back(make_pair(108.7,false));
    enemy2.push_back(make_pair(2000.0,830.0));
    enemy2on.push_back(make_pair(108.9,false));
    enemy2.push_back(make_pair(2000.0,830.0));
    enemy2on.push_back(make_pair(113.0,false));
    enemy2.push_back(make_pair(2000.0,830.0));
    enemy2on.push_back(make_pair(115.0,false));
    enemy2.push_back(make_pair(2000.0,830.0));
    enemy2on.push_back(make_pair(116.5,false));
    enemy2.push_back(make_pair(2000.0,830.0));
    enemy2on.push_back(make_pair(118.5,false));
    enemy2.push_back(make_pair(2000.0,830.0));
    enemy2on.push_back(make_pair(123.0,false));
    enemy2.push_back(make_pair(2000.0,830.0));
    enemy2on.push_back(make_pair(124.0,false));
    enemy2.push_back(make_pair(2000.0,830.0));
    enemy2on.push_back(make_pair(154.0,false));
     enemy2.push_back(make_pair(2000.0,830.0));
    enemy2on.push_back(make_pair(155.0,false));
    enemy2.push_back(make_pair(2000.0,830.0));
    enemy2on.push_back(make_pair(158.0,false));
    enemy2.push_back(make_pair(2000.0,830.0));
    enemy2on.push_back(make_pair(159.0,false));
     enemy2.push_back(make_pair(2000.0,830.0));
    enemy2on.push_back(make_pair(160.0,false));
    enemy2.push_back(make_pair(2000.0,830.0));
    enemy2on.push_back(make_pair(164.0,false));
    enemy2.push_back(make_pair(2000.0,830.0));
    enemy2on.push_back(make_pair(180.0,false));
    enemy2.push_back(make_pair(2000.0,830.0));
    enemy2on.push_back(make_pair(184.0,false));
    enemy2.push_back(make_pair(2000.0,830.0));
    enemy2on.push_back(make_pair(185.0,false));
    enemy2.push_back(make_pair(2000.0,830.0));
    enemy2on.push_back(make_pair(188.0,false));
    enemy2.push_back(make_pair(2000.0,830.0));
    enemy2on.push_back(make_pair(196.0,false));
    enemy2.push_back(make_pair(2000.0,830.0));
    enemy2on.push_back(make_pair(197.0,false));


    //Enemy 4 initiation:
    vector< pair <double,double>>enemy4;
    vector<pair<double,bool>>enemy4on;
    RectangleShape enemy4body(Vector2f(150.0f,150.0f));
    Texture enemy4texture[10];



    enemy4.push_back(make_pair(2000.0,830.0));
    enemy4on.push_back(make_pair(117.5,false));
    enemy4.push_back(make_pair(2000.0,830.0));
    enemy4on.push_back(make_pair(120.0,false));
    enemy4.push_back(make_pair(2000.0,830.0));
    enemy4on.push_back(make_pair(126.5,false));
    enemy4.push_back(make_pair(2000.0,830.0));
    enemy4on.push_back(make_pair(127.5,false));
    enemy4.push_back(make_pair(2000.0,830.0));
    enemy4on.push_back(make_pair(134.0,false));
    enemy4.push_back(make_pair(2000.0,830.0));
    enemy4on.push_back(make_pair(150.0,false));
    enemy4.push_back(make_pair(2000.0,830.0));
    enemy4on.push_back(make_pair(151.0,false));
    enemy4.push_back(make_pair(2000.0,830.0));
    enemy4on.push_back(make_pair(152.0,false));
    enemy4.push_back(make_pair(2000.0,830.0));
    enemy4on.push_back(make_pair(165.5,false));
    enemy4.push_back(make_pair(2000.0,830.0));
    enemy4on.push_back(make_pair(186.5,false));
    enemy4.push_back(make_pair(2000.0,830.0));
    enemy4on.push_back(make_pair(192.5,false));
    enemy4.push_back(make_pair(2000.0,830.0));
    enemy4on.push_back(make_pair(193.5,false));
    enemy4.push_back(make_pair(2000.0,830.0));
    enemy4on.push_back(make_pair(198.0,false));


    //Venom 1 initiation:
    vector< pair <double,double>>enemy4venom;
    double enemy4venomtimer=1.0;
    RectangleShape enemy4venombody(Vector2f(50.0f,50.0f));
    Texture enemy4venomtexture;
    enemy4venomtexture.loadFromFile("enemy1/venom/1.png");

    //Enemy boss initiation:
    bool bossalive=true;
    pair <double,double>enemybossxy;
    pair<double,bool>enemybosson;
    double enemyboss=0.0;
    RectangleShape enemybossbody(Vector2f(450.0f,350.0f));
    Texture enemybosstexture[35];

    enemybossxy.first=2000.0;
    enemybossxy.second=650.0;
    enemybosson.first=210.0;
    enemybosson.second=false;



    //Enemy boss shooting initiation:
    vector< pair <double,double>>enemybossshoot;

    bool rockon=true;

    RectangleShape enemybossshootbody(Vector2f(50.0f,50.0f));
    Texture enemybossshoottexture;


    //enemy boss health initiation:

    RectangleShape enemybosshealthbarbody(Vector2f(300.0f,50.0f));
    Texture enemybosshealthbartexture[11];
    double enemybosshealth=1000.0;


    //Cave initiation:
    RectangleShape cavebody(Vector2f(600.0f,600.0f));
    Texture cavetexture;


    pair <double,double>cave;
    pair<double,bool>caveon;

    cave.first=2000;
    cave.second=450.0;
    caveon.first=220.0;
    caveon.second=false;

    //Infinity stone
    bool infinitystoneon=false;
     Texture infinitystonetexture;

    RectangleShape infinitystonebody(Vector2f(620.0f,540.0f));


    //Puzzle on:
    RectangleShape puzzlebody(Vector2f(1500.0f,750.0f));
    Texture puzzletexture;
    puzzletexture.loadFromFile("puzzle.png");
    pair <double,double>puzzle;
    pair <double,double>puzzlea;
    pair <double,double>puzzleb;
    pair <double,double>puzzlec;
    pair<double,bool>puzzleon;
    bool puzzlesolved=false;

    puzzle.first=0.0;
    puzzle.second=150.0;
    puzzleon.first=227.0;
    puzzleon.second=false;

    RectangleShape puzzleabody(Vector2f(300.0f,300.0f));
    Texture puzzleabctexture[4];
    puzzlea.first=0.0;
    puzzlea.second=500.0;

    RectangleShape puzzlebbody(Vector2f(300.0f,300.0f));
    puzzleb.first=400.0;
    puzzleb.second=500.0;

    RectangleShape puzzlecbody(Vector2f(300.0f,300.0f));
    puzzlec.first=820.0;
    puzzlec.second=500.0;

    puzzleabctexture[0].loadFromFile("0.png");
    puzzleabctexture[1].loadFromFile("1.png");
    puzzleabctexture[2].loadFromFile("2.png");
    puzzleabctexture[3].loadFromFile("3.png");

    int a=0,b=0,c=0;
    bool mouseclick=false;



    RenderWindow window(sf::VideoMode(1500, 900), "SFML works!",Style::Fullscreen);
    RectangleShape body6(Vector2f(150.0f,150.0f));
    RectangleShape body5(Vector2f(130.0f,130.0f));
    RectangleShape body2(Vector2f(150.0f,150.0f));
    RectangleShape body1(Vector2f(150.0f,150.0f));
    RectangleShape body0(Vector2f(150.0f,150.0f));
    RectangleShape body3(Vector2f(150.0f,150.0f));
    RectangleShape body(Vector2f(150.0f,150.0f));
     RectangleShape collisionbody(Vector2f(150.0f,150.0f));

    Texture predator,background3texture,background5texture,playertexture3[10],playerdeathtexture[10],playertexture1[10],playertexture2[10],playertexture4[10],playertexture5[10],playertexture6[10],playertexture7[10],playertexture8[9],ex,ex1,bullet1,bullet2,collision;



    Sprite sprite,sprite1, background3sprite;
    RectangleShape bulletsprite1(Vector2f(50.0f,50.0f));
    RectangleShape bulletsprite2(Vector2f(50.0f,50.0f));

    sprite.setTexture(ex);
    sprite1.setTexture(ex1);
    background3sprite.setTexture(background3texture);

    //Character death initiation:
    RectangleShape playerdeathbody(Vector2f(150.0f,150.0f));
    bool death=false;
    bool downfalldeath=false;



    int i=0,pos=0,jump=0,slide=0;
    double time=0,y=810.0,jumptimer=0.0,slidetimer=0.0,stepcount=0.0,collisiontime=0.0;
    bool faceright=true,collisionbool=false;
    Vector2f movement(500.0f,0.0f);
    float deltatime=0.0f;
    Clock clock;



        void initVariables();
    public:
        Playmode();
        virtual ~Playmode();

    protected:


};

#endif // PLAYMODE_H
