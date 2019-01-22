#include<bits/stdc++.h>
#include"SFML\Graphics.hpp"
#include"SFML\Window.hpp"
#include"SFML\System.hpp"
#include"SFML\Audio.hpp"

using namespace sf;

class Bullet1
{
public:
    Sprite shape;

    Bullet1(Texture *texture, Vector2f pos)
    {
        pos.x=pos.x+50;
        shape.setTexture(*texture);
        shape.setPosition(pos);
    }

};

class Player
{
public:
    Sprite shape;
    Texture *texture;
    std::vector<Bullet1> bullets;
    Player(Texture *texture)
    {
        shape.setTexture(*texture);
    }
};

class Enemy
{
public:
    Sprite shape;

    Enemy(Texture *texture, Vector2u windowSize)
    {
        shape.setTexture(*texture);
        // shape.setScale(0.3f, 0.3f);
        shape.setPosition(rand()% (int)(windowSize.x - this->shape.getGlobalBounds().width),0);
    }
};

class faw
{
public:
    Sprite shape;

    faw(Texture *texture, Vector2u pos)
    {
        shape.setTexture(*texture);
        shape.setScale(0.04,0.04);
        pos.x=pos.x+37;
        pos.y=pos.y+65;
        shape.setPosition(Vector2f(pos));
    }
};

int main()
{
    srand(time(NULL));

    RenderWindow window(VideoMode(1300,800),"Battle For Avenger");
    window.setFramerateLimit(60);

    Font font,style,style1,schng;
    font.loadFromFile("Fonts/fine.ttf");
    style.loadFromFile("Fonts/font4.TTF");
    style1.loadFromFile("Fonts/font6.TTF");
    schng.loadFromFile("Fonts/font3.TTF");

    Texture stark,thor,pathr,spider,bos,halk,thanos,boma,bullet1,bullet2,bullet3,bullet4,stone,space1,mbg,space2,space3,Fire,step1,step2,step3,step4,stg,lovee,pri;

    Color barr(252, 13, 13), notSelected(51, 255, 51),done(255,255,0), beat(200, 20, 20), dev(255, 255, 255, 100),Spark;

    SoundBuffer bullettune,crashtune,coll,button,button1;

    Clock key,agun,schange,agun1,agun2,loove,prii;
    float time=0.0f,aguntime=0.0f,stchange=0.0f,aguntime1=0.0f,aguntime2=0.0f,lve=0.0f,pr=0.0f;

    Music gamemusic,menumusic;
    gamemusic.openFromFile("Music/game.wav");
    gamemusic.setVolume(1000);
    menumusic.openFromFile("Music/menu.wav");
    menumusic.setVolume(1000);

    stark.loadFromFile("Textures/stark.png");
    thor.loadFromFile("Textures/thor1.png");
    thanos.loadFromFile("Textures/thanos.png");
    halk.loadFromFile("Textures/halk.png");
    spider.loadFromFile("Textures/spider.png");
    bullet1.loadFromFile("Textures/bullet1.png");
    bullet2.loadFromFile("Textures/bullet2.png");
    bullet3.loadFromFile("Textures/bullet3.png");
    bullet4.loadFromFile("Textures/bullet4.png");
    stone.loadFromFile("Textures/stone.png");
    space1.loadFromFile("Textures/space5.jpg");
    bullettune.loadFromFile("Music/bullet.wav");
    crashtune.loadFromFile("Music/crash.wav");
    coll.loadFromFile("Music/collision.wav");
    mbg.loadFromFile("Textures/menu.jpg");
    space2.loadFromFile("Textures/space2.jpg");
    space3.loadFromFile("Textures/space3.jpg");
    button1.loadFromFile("Music/button.wav");
    button.loadFromFile("Music/select.wav");
    Fire.loadFromFile("Textures/fire.png");
    step1.loadFromFile("Textures/step1.png");
    step2.loadFromFile("Textures/step2.png");
    step3.loadFromFile("Textures/step3.png");
    step4.loadFromFile("Textures/step4.png");
    stg.loadFromFile("Textures/75665.jpg");
    boma.loadFromFile("Textures/stone1.png");
    lovee.loadFromFile("Textures/love.png");
    pri.loadFromFile("Textures/guldi.png");
    pathr.loadFromFile("Textures/pathor.png");
    bos.loadFromFile("Textures/bos.png");


    Sound fire(bullettune),crash(crashtune),collision(coll),menubutton(button1),menuok(button);

    Sprite bg1(space1),bg2(space1),menubg(mbg),Stark(stark),Thanos(thanos),Thor(thor),Thor1(thor),Thor2(thor),Hulk(halk),bg3(space2),bg4(space2),bg5(space3),bg6(space3)
    ,lbg1(space2),lbg2(space2),lbg3(space3),lbg4(space3),menupic1(space1),menupic2(space2),menupic3(space3),spark(Fire),ep1(step1),ep2(step2),ep3(step3),ep4(step4),
    Step1(step1),Step2(step2),Step3(step3),Step4(step4),spchange(stg),sbg1(space1),sbg2(space2),sbg3(space3),guli(bullet2),tep1(step1),tep2(step2),tep3(step3),tep4(step4)
    ,love(lovee),prize(pri),hero(thor),vilen(thanos);

    Step1.setScale(0.3f,0.3f);
    Step2.setScale(0.3f,0.3f);
    Step3.setScale(0.3f,0.3f);
    Step4.setScale(0.3f,0.3f);
    tep1.setScale(0.3f,0.3f);
    tep2.setScale(0.3f,0.3f);
    tep3.setScale(0.3f,0.3f);
    tep4.setScale(0.3f,0.3f);
    ep1.setScale(0.3f,0.3f);
    ep1.setScale(0.3f,0.3f);
    ep1.setScale(0.3f,0.3f);
    ep1.setScale(0.3f,0.3f);
    bg1.setScale(0.6f,0.34f);
    bg2.setScale(0.6f,0.34f);
    bg3.setScale(0.7f,0.9f);
    bg4.setScale(0.7f,0.9f);
    menubg.setScale(0.34f,0.38f);
    menubg.setPosition(0.0f,0.0f);
    spark.setScale(0.3f,0.3f);
    spchange.setScale(0.92f,0.7);
    spchange.setPosition(0.0f,0.0f);
    guli.setScale(0.04,0.04);
    love.setScale(0.25,0.25);
    prize.setScale(0.1,0.1);
    hero.setScale(0.05,0.05);
    vilen.setScale(0.18,0.18);

    hero.rotate(270.f);

    Text scoretxt,gameovertxt,lifetxt,mgzntxt,welcometxt,gametxt,newgametxt,highscoretxt,stagetxt,helptxt,exittxt,loadgametxt,st1,st2,st3;

    gametxt.setFont(style);
    gametxt.setString("Battle For Avenger!");
    gametxt.setCharacterSize(80);
    gametxt.setScale(1.f,1.f);
    gametxt.setFillColor(Color::Red);

    newgametxt.setFont(style1);
    newgametxt.setString("New Game :");
    newgametxt.setCharacterSize(80);
    newgametxt.setScale(0.7f,0.7f);
    newgametxt.setFillColor(notSelected);

    loadgametxt.setFont(style1);
    loadgametxt.setString("Load Game :");
    loadgametxt.setCharacterSize(80);
    loadgametxt.setScale(0.7f,0.7f);
    loadgametxt.setFillColor(notSelected);

    stagetxt.setFont(style1);
    stagetxt.setString("Stages :");
    stagetxt.setCharacterSize(80);
    stagetxt.setScale(0.7f,0.7f);
    stagetxt.setFillColor(notSelected);

    helptxt.setFont(style1);
    helptxt.setString("Instruction :");
    helptxt.setCharacterSize(80);
    helptxt.setScale(0.7f,0.7f);
    helptxt.setFillColor(notSelected);

    exittxt.setFont(style1);
    exittxt.setString("Exit :");
    exittxt.setCharacterSize(80);
    exittxt.setScale(0.7f,0.7f);
    exittxt.setFillColor(notSelected);

    scoretxt.setFont(font);
    scoretxt.setCharacterSize(20);
    scoretxt.setScale(1.5,1.5);
    scoretxt.setFillColor(Color::Blue);
    scoretxt.setPosition(20.f, window.getSize().y-40);

    lifetxt.setFont(font);
    lifetxt.setCharacterSize(20);
    lifetxt.setScale(1.5,1.5);
    lifetxt.setFillColor(Color::Green);
    lifetxt.setPosition(458.f, window.getSize().y-40);
    lifetxt.setString("Life:");

    mgzntxt.setFont(font);
    mgzntxt.setCharacterSize(20);
    mgzntxt.setScale(1.5,1.5);
    mgzntxt.setFillColor(Color::Red);
    mgzntxt.setPosition(933.f, window.getSize().y-40);
    mgzntxt.setString("Bullet:");

    gameovertxt.setFont(font);
    gameovertxt.setCharacterSize(30);
    gameovertxt.setFillColor(Color::Red);
    gameovertxt.setPosition(400.f, window.getSize().y / 2-80);
    gameovertxt.setScale(2.5f,2.5f);
    gameovertxt.setString("GAME OVER!");

    welcometxt.setFont(font);
    welcometxt.setCharacterSize(30);
    welcometxt.setFillColor(Color::Green);
    welcometxt.setPosition(400.f, window.getSize().y / 2+100);
    welcometxt.setScale(2.0f,2.0f);
    welcometxt.setString("Congratulation !");

    st1.setFont(schng);
    st1.setString("Stage: 1");

    st2.setFont(schng);
    st2.setString("Stage: 2");

    st3.setFont(schng);
    st3.setString("Stage: 3");

    bool stage1=true,stage2=true,stage3=true,menu=true,me=true,level1=true,level2=false,level3=false,agunbool1=false,blll2=false,agunbool2=false,blll1=false,agunbool=false,blll=false,stages=false
    ,dekha = false,up=false,down=false;

    //Player init
    int score = 0,mgzn=100,k=0,l,score1=0,score2=0,score3=0,jan=10,le=1,ve=1,left1=0,right1=1,left2=1,right2=0;
    Player player(&halk),player1(&stark),player2(&stark);
    player.shape.setScale(0.07f,0.07f);
    player1.shape.setScale(0.05f,0.05f);
    int shootTimer = 20,vtime=0;

    RectangleShape bar(Vector2f(window.getSize().x+50,100));
    bar.setFillColor(Color::White);
    bar.setPosition(window.getPosition().x/2-155,window.getSize().y-50);

    //Enemy init
    int enemySpawnTimer = 0,life=10,bala=10,dekhi=0;
    std::vector<Enemy> enemies;
    std::vector<faw> enemy;
    std::vector<Bullet1> goli;
    std::vector<Bullet1> pathor;
    std::vector<Bullet1> boss;

    unsigned menuselect = 1,sou=1,pran1=10,pran2=10;


    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        ///menu
        if(menu)
        {
            if(me)
            {
                menumusic.play();
                menumusic.setLoop(true);
                dekhi = 0;
                jan=20;
                dekha=false;

                Thanos.setRotation(55.f);
                Thanos.setScale(0.25f,0.25f);
                Hulk.setRotation(55.f);
                Hulk.setScale(0.10f,0.10f);
                Thor.setRotation(20.f);
                Thor.setScale(0.09f,0.09f);
                Stark.setScale(0.08f,0.08f);

                gametxt.setPosition(250.f,-100.f);///250,25
                newgametxt.setPosition(window.getSize().x,200.f);///600,200
                loadgametxt.setPosition(window.getSize().x,280.f);///580,280
                stagetxt.setPosition(window.getSize().x,360.f);///687,360
                helptxt.setPosition(window.getSize().x,440.f);///521,440
                exittxt.setPosition(window.getSize().x,520.f);///740,520

                Hulk.setPosition(0.f,400.f);///hulk280,400
                Thanos.setPosition(200.f,0.f);///thanos200,250
                Thor.setPosition(320.f,window.getSize().y);///thor320,550
                Stark.setPosition(window.getSize().x,600);///stark440,600
                menupic1.setScale(0.05f,0.05f);
                menupic1.setPosition(600.f,100.f);
                me=false;
            }

            time=key.getElapsedTime().asSeconds();

            if(Keyboard::isKeyPressed(Keyboard::Down) && time > 0.2)
            {
                menubutton.play();
                menuselect++;
                key.restart();
            }
            if(Keyboard::isKeyPressed(Keyboard::Up) && time > 0.2)
            {
                menubutton.play();
                menuselect--;
                key.restart();
            }
            if(Keyboard::isKeyPressed(Keyboard::Enter) && time > 0.2)
            {
                menuok.play();
                key.restart();
                if(menuselect%5 == 1)
                {
                    score = 0;
                    score1=0;
                    score2=0;
                    score3=0;
                    pran1=10;
                    pran2=10;
                    life = 10;
                    mgzn=100;
                    enemies.clear();
                    enemy.clear();
                    enemySpawnTimer=0;
                    bala=10;
                    menumusic.stop();
                    gamemusic.play();
                    schange.restart();
                    if(ve==0)
                    {
                        if(le==1)
                            level1=true;
                        else if(le==2)
                            level2=true;
                        else
                            level3=true;
                    }
                    else
                        ve=0;
                    gamemusic.setLoop(true);
                    menu = false;
                }
                else if(menuselect%5 == 2)
                {
                    menumusic.stop();
                    gamemusic.play();
                    if(ve==0)
                    {
                        if(le==1)
                            level1=true;
                        else if(le==2)
                            level2=true;
                        else
                            level3=true;
                    }
                    else
                        ve=0;
                    if(Keyboard::isKeyPressed(Keyboard::Escape))
                        {
                            gamemusic.stop();
                            menumusic.play();
                            menumusic.setLoop(true);
                            menu=true;
                            stages=false;
                            me=true;

                        }
                    gamemusic.setLoop(true);
                    menu= false;
                }
                else if(menuselect%5 == 3)
                {
                    sou=1;
                    ve=0;
                    menu=false;
                    level1=false;
                    level2=false;
                    level3=false;
                    stages=true;

                }
                else if(menuselect%5==0)
                {
                    window.close();
                }
            }

            if(menuselect%5==1)
            {
                newgametxt.setFillColor(done);
                loadgametxt.setFillColor(notSelected);
                stagetxt.setFillColor(notSelected);
                helptxt.setFillColor(notSelected);
                exittxt.setFillColor(notSelected);
            }
            else if(menuselect%5==2)
            {
                loadgametxt.setFillColor(done);
                stagetxt.setFillColor(notSelected);
                helptxt.setFillColor(notSelected);
                exittxt.setFillColor(notSelected);
                newgametxt.setFillColor(notSelected);
            }
            else if(menuselect%5==3)
            {
                stagetxt.setFillColor(done);
                helptxt.setFillColor(notSelected);
                exittxt.setFillColor(notSelected);
                newgametxt.setFillColor(notSelected);
                loadgametxt.setFillColor(notSelected);
            }
            else if(menuselect%5==4)
            {
                helptxt.setFillColor(done);
                exittxt.setFillColor(notSelected);
                newgametxt.setFillColor(notSelected);
                loadgametxt.setFillColor(notSelected);
                stagetxt.setFillColor(notSelected);
            }
            else if(menuselect%5==0)
            {
                exittxt.setFillColor(done);
                newgametxt.setFillColor(notSelected);
                loadgametxt.setFillColor(notSelected);
                stagetxt.setFillColor(notSelected);
                helptxt.setFillColor(notSelected);
            }

            if(newgametxt.getPosition().x!=600)
                newgametxt.move(-10.f,0.f);
            if(loadgametxt.getPosition().x!=580)
                loadgametxt.move(-10.f,0.f);
            if(stagetxt.getPosition().x!=690)
                stagetxt.move(-10.f,0.f);
            if(helptxt.getPosition().x!=520)
                helptxt.move(-10.f,0.f);
            if(exittxt.getPosition().x!=740)
                exittxt.move(-10.f,0.f);
            if(gametxt.getPosition().y!=25)
                gametxt.move(0.f,5.0f);

            if(Hulk.getPosition().x!=280)
                Hulk.move(5.f,0.f);
            if(Thanos.getPosition().y!=250)
                Thanos.move(0.f,5.f);
            if(Thor.getPosition().y!=550)
                Thor.move(0.f,-5.f);
            if(Stark.getPosition().x!=440)
                Stark.move(-10.f,0.f);

            window.clear();
            window.draw(menubg);
            window.draw(Thanos);
            window.draw(Hulk);
            window.draw(Thor);
            window.draw(Stark);
            window.draw(gametxt);
            window.draw(newgametxt);
            window.draw(loadgametxt);
            window.draw(stagetxt);
            window.draw(helptxt);
            window.draw(exittxt);
            window.display();
        }

        if(stages)
        {
            window.clear();
            window.draw(menubg);
            st1.setCharacterSize(70);
            st1.setFillColor(Color::Red);
            st1.setPosition(220.f,window.getSize().y/2-330);
            st2.setCharacterSize(70);
            st2.setFillColor(Color::White);
            st2.setPosition(220.f,window.getSize().y/2-70);
            st3.setCharacterSize(70);
            st3.setFillColor(Color::White);
            st3.setPosition(220.f,window.getSize().y/2+190);
            sbg1.setPosition(590.0,window.getSize().y/2-390);
            sbg1.setScale(0.09,0.09);
            sbg1.setColor(Color(255,255,255,170));
            sbg2.setPosition(590.0,window.getSize().y/2-120);
            sbg2.setScale(.18,.16);
            sbg3.setPosition(590.0,window.getSize().y/2+160);
            sbg3.setScale(0.18,0.17);
            time=key.getElapsedTime().asSeconds();
            if(Keyboard::isKeyPressed(Keyboard::Up) && time > 0.2)
            {
                sou--;
                menubutton.play();
                key.restart();
            }
            if(Keyboard::isKeyPressed(Keyboard::Down) && time > 0.2)
            {
                sou++;
                menubutton.play();
                key.restart();
            }
            if(Keyboard::isKeyPressed(Keyboard::Enter) && time > 0.2)
            {
                key.restart();
                menuok.play();
                score1=0;
                score2=0;
                score3=0;
                stages=false;
                menu=true;
                me=true;
                ve=1;
                if(sou%3 == 1)
                {
                    level1=true;
                    level2=false;
                    level3=false;
                }
                else if(sou%3 == 2)
                {
                    level1=false;
                    level2=true;
                    level3=false;
                }
                else if(sou%3 == 0)
                {
                    level1=false;
                    level2=false;
                    level3=true;
                }
            }
            if(Keyboard::isKeyPressed(Keyboard::Escape) && time > 0.2)
            {
                key.restart();
                stages=false;
                menu=true;
            }
            if(sou%3 == 1)
            {
                st1.setFillColor(Color::Red);
                st2.setFillColor(Color::White);
                st3.setFillColor(Color::White);
                sbg1.setColor(Color(255,255,255));
                sbg2.setColor(Color(255,255,255,180));
                sbg3.setColor(Color(255,255,255,180));
            }
            else if(sou%3 == 2)
            {
                st1.setFillColor(Color::White);
                st2.setFillColor(Color::Red);
                st3.setFillColor(Color::White);
                sbg1.setColor(Color(255,255,255,180));
                sbg2.setColor(Color(255,255,255));
                sbg3.setColor(Color(255,255,255,180));
            }
            else if(sou%3 == 0)
            {
                st1.setFillColor(Color::White);
                st2.setFillColor(Color::White);
                st3.setFillColor(Color::Red);
                sbg1.setColor(Color(255,255,255,180));
                sbg2.setColor(Color(255,255,255,180));
                sbg3.setColor(Color(255,255,255));
            }
            window.draw(sbg1);
            window.draw(sbg2);
            window.draw(sbg3);
            window.draw(st1);
            window.draw(st2);
            window.draw(st3);
            window.display();
        }

        ///gameloop
        if((life>0 && (level1 || level2 || level3 ) && !menu) || dekha)
        {
            ///stage1
            if(level1)
            {
                stchange=schange.getElapsedTime().asSeconds();
                if(stchange < 2.0)
                {
                    window.clear();
                    window.draw(spchange);
                    st1.setCharacterSize(130);
                    st1.setFillColor(Color::White);
                    st1.setPosition(420.f,window.getSize().y/2-90);
                    window.draw(st1);
                    window.display();
                }
                else
                {

                    if(stage1)
                    {
                        gamemusic.play();
                        gamemusic.setLoop(true);
                        bg1.setPosition(0.f,0.f);
                        bg2.setPosition(0.f,bg1.getPosition().y-window.getSize().y+70);
                        player.shape.setPosition(Vector2f(window.getSize().x/2,window.getSize().y-150));
                        mgzn=100;
                        stage1 = false;
                    }
                    if(Keyboard::isKeyPressed(Keyboard::Left))
                        player.shape.move(-10.f, 0.f);
                    if(Keyboard::isKeyPressed(Keyboard::Right))
                        player.shape.move(10.f, 0.f);
                    if(Keyboard::isKeyPressed(Keyboard::Escape))
                    {
                        gamemusic.stop();
                        menumusic.play();
                        menumusic.setLoop(true);
                        menu=true;
                        stages=false;
                        le=1;
                        me=true;
                    }

                    ///collision with window
                    if (player.shape.getPosition().x <= 0) //Left
                        player.shape.setPosition(0.f, player.shape.getPosition().y);
                    if (player.shape.getPosition().x >= window.getSize().x - player.shape.getGlobalBounds().width) //Right
                        player.shape.setPosition(window.getSize().x - player.shape.getGlobalBounds().width, player.shape.getPosition().y);

                    if (shootTimer < 15)
                        shootTimer++;

                    if ((Mouse::isButtonPressed(Mouse::Left)||Keyboard::isKeyPressed(Keyboard::Space)) && shootTimer >= 15 && mgzn > 0) //Shooting
                    {
                        fire.play();
                        mgzn--;
                        player.bullets.push_back(Bullet1(&bullet2, player.shape.getPosition()));
                        player.bullets[player.bullets.size()-1].shape.setScale(0.07f,0.07f);
                        player.bullets[player.bullets.size()-1].shape.setPosition(Vector2f(player.shape.getPosition().x+39,player.shape.getPosition().y));

                        shootTimer = 0; //reset timer
                    }
                    if(mgzn==0 || life == 0)
                    {

                        gamemusic.stop();
                        menumusic.play();
                        menumusic.setLoop(true);
                        menu=true;
                        me=true;
                    }

                    for (size_t i = 0; i < player.bullets.size(); i++)
                    {
                        //Move
                        player.bullets[i].shape.move(0.f, -20.f);

                        //Out of window bounds
                        if (player.bullets[i].shape.getPosition().x > window.getSize().x)
                        {
                            player.bullets.erase(player.bullets.begin() + i);
                            break;
                        }

                        for (size_t k = 0; k < enemies.size(); k++)
                        {
                            if (player.bullets[i].shape.getGlobalBounds().intersects(enemies[k].shape.getGlobalBounds()))
                            {
                                crash.play();
                                enemies.erase(enemies.begin() + k);
                                player.bullets.erase(player.bullets.begin() + i);
                                score++;
                                score1++;
                                break;
                            }
                        }
                    }
                    //Enemy
                    if (enemySpawnTimer < 10)
                        enemySpawnTimer++;


                    //enemy spawn
                    if (enemySpawnTimer >= 10 && score1 < 25)
                    {
                        enemies.push_back(Enemy(&stone, window.getSize()));
                        enemies[enemies.size()-1].shape.setScale(0.3f,0.3f);
                        enemySpawnTimer = 0; //reset timer
                    }

                    if (enemySpawnTimer >= 6 && score1 >= 25)
                    {
                        enemies.push_back(Enemy(&stone, window.getSize()));
                        enemies[enemies.size()-1].shape.setScale(0.4f,0.4f);
                        enemySpawnTimer = 0; //reset timer
                    }

                    for (size_t i = 0; i < enemies.size(); i++)
                    {
                        enemies[i].shape.move(0.f, 6.0f);

                        if (enemies[i].shape.getPosition().y >= window.getSize().y - enemies[i].shape.getGlobalBounds().height)
                        {
                            enemies.erase(enemies.begin() + i);
                            break;
                        }

                        if (enemies[i].shape.getGlobalBounds().intersects(player.shape.getGlobalBounds()))
                        {
                            collision.play();
                            enemies.erase(enemies.begin() + i);
                            life--; // PLAYER TAKE DAMAGE
                            agunbool=true;
                            blll=true;
                            break;
                        }
                        scoretxt.setString("Remaining: " + std::to_string(50-score));
                    }

                    RectangleShape health(Vector2f(life*20,25));
                    health.setFillColor(Color::Green);
                    health.setPosition(550,window.getSize().y-35);

                    RectangleShape magazine(Vector2f(mgzn*2,25));
                    magazine.setFillColor(Color::Red);
                    magazine.setPosition(1050,window.getSize().y-35);

                    bg1.move(0.f,0.7f);
                    bg2.move(0.f,0.7f);
                    if(bg1.getPosition().y>0)
                        bg2.setPosition(0.f,bg1.getPosition().y+70-window.getSize().y);
                    if(bg2.getPosition().y>0)
                        bg1.setPosition(0.f,bg2.getPosition().y+70-window.getSize().y);

                    window.clear();
                    window.draw(bg1);
                    window.draw(bg2);
                    window.draw(player.shape);

                    for (size_t i = 0; i < player.bullets.size(); i++)
                        window.draw(player.bullets[i].shape);

                    for (size_t i = 0; i < enemies.size(); i++)
                        window.draw(enemies[i].shape);

                    window.draw(bar);
                    window.draw(scoretxt);
                    window.draw(lifetxt);
                    window.draw(mgzntxt);
                    window.draw(magazine);
                    window.draw(health);

                    if(blll)
                    {
                        agun.restart();
                        blll=false;
                    }
                    aguntime=agun.getElapsedTime().asSeconds();

                    if(agunbool)
                    {
                        if(aguntime <0.15)
                        {
                            Step1.setPosition(player.shape.getPosition().x,player.shape.getPosition().y+20);
                            window.draw(Step1);
                        }
                        if(aguntime > 0.15 &&  aguntime <= 0.3)
                        {
                            Step2.setPosition(player.shape.getPosition().x,player.shape.getPosition().y+20);
                            window.draw(Step2);
                        }
                        if(aguntime > 0.3 &&  aguntime <= 0.45)
                        {
                            Step3.setPosition(player.shape.getPosition().x,player.shape.getPosition().y+20);
                            window.draw(Step3);
                        }
                        if(aguntime > 0.45 && aguntime <= 0.6)
                        {
                            Step4.setPosition(player.shape.getPosition().x,player.shape.getPosition().y+20);
                            window.draw(Step4);
                        }
                        if(aguntime > 0.6)
                            agunbool=false;
                    }
                    if(life==0 || dekha)
                    {
                        window.clear(Color::White);
                        if(dekhi < 100)
                        {
                            life--;
                            dekha=true;
                            dekhi++;
                        }
                        else
                        {
                            dekha = false;
                            me =true;
                            menu=true;
                        }

                        window.draw(gameovertxt);

                    }
                    window.display();
                    if(score>49)
                    {
                        score1=0;
                        life=5;
                        mgzn=100;
                        level1=false;
                        level2=true;
                        schange.restart();
                    }
                }

                ///stage 2
            }
            else if(level2)
            {
                stchange=schange.getElapsedTime().asSeconds();
                if(stchange < 2.0)
                {
                    window.clear();
                    window.draw(spchange);
                    st2.setCharacterSize(130);
                    pran1=20;
                    pran2=20;
                    st2.setFillColor(Color::White);
                    st2.setPosition(420.f,window.getSize().y/2-90);
                    window.draw(st2);
                    window.display();
                    bool stage2=true;
                }
                else
                {
                    if(stage2)
                    {
                        loove.restart();
                        prii.restart();
                        love.setPosition(200.f,2000.f);
                        prize.setPosition(200.f,2000.f);
                        gamemusic.play();
                        gamemusic.setLoop(true);
                        bg3.setPosition(0.f,0.f);
                        bg4.setPosition(0.f,bg3.getPosition().y-1000);
                        player1.shape.setPosition(Vector2f(window.getSize().x/2,window.getSize().y-150));
                        mgzn=100;
                        Thor1.setPosition(10.f,25.f);
                        Thor2.setPosition(window.getSize().x-100,25.f);
                        Thor1.setScale(0.05,0.05);
                        dekha = false;
                        Thor2.setScale(0.05,0.05);
                        stage2 = false;
                    }
                    lve=loove.getElapsedTime().asSeconds();
                    pr=prii.getElapsedTime().asSeconds();

                    if(Keyboard::isKeyPressed(Keyboard::Left))
                        player1.shape.move(-10.f, 0.f);
                    if(Keyboard::isKeyPressed(Keyboard::Right))
                        player1.shape.move(10.f, 0.f);
                    if(Keyboard::isKeyPressed(Keyboard::Up))
                        player1.shape.move(0.f, -10.f);
                    if(Keyboard::isKeyPressed(Keyboard::Down))
                        player1.shape.move(0.f, 10.f);
                    if(Keyboard::isKeyPressed(Keyboard::Escape))
                    {
                        gamemusic.stop();
                        menumusic.play();
                        menumusic.setLoop(true);
                        menu=true;
                        stages=false;
                        me=true;
                        level2=false;
                        le=2;
                    }
                    bg3.move(0.f,0.45f);
                    bg4.move(0.f,0.45f);
                    if(left1==1)
                        Thor1.move(-5.f,0.f);
                    if(right1==1)
                        Thor1.move(5.f,0.f);
                    if(left2==1)
                        Thor2.move(-5.f,0.f);
                    if(right2==1)
                        Thor2.move(5.f,0.f);
                    if(Thor1.getPosition().x<10)
                    {
                        left1=0;
                        right1=1;
                    }
                    if(Thor1.getPosition().x>window.getSize().x-100)
                    {
                        right1=0;
                        left1=1;
                    }
                    if(Thor2.getPosition().x<10)
                    {
                        left2=0;
                        right2=1;
                    }
                    if(Thor2.getPosition().x>window.getSize().x-100)
                    {
                        right2=0;
                        left2=1;
                    }
                    if(enemySpawnTimer<20)
                        enemySpawnTimer++;
                    if(bala<30)
                        bala++;

                    ///bullet from the opponent
                    if(enemySpawnTimer >= 20 && pran1 > 0)
                    {
                        enemy.push_back(faw(&boma,Vector2u(Thor1.getPosition())));
                        enemy[enemy.size()-1].shape.setScale(0.07f,0.07f);
                        enemySpawnTimer=0;
                    }
                    if(bala>=30 && pran2 > 0)
                    {
                        enemy.push_back(faw(&boma,Vector2u(Thor2.getPosition())));
                        enemy[enemy.size()-1].shape.setScale(0.07f,0.07f);
                        bala=0;
                    }

                    ///Collision
                    for(int kl=0; kl<enemy.size(); kl++)
                    {
                        enemy[kl].shape.move(0.f,10.f);
                        if(enemy[kl].shape.getPosition().y > window.getSize().y)
                        {
                            enemy.erase(enemy.begin()+kl);
                        }
                        if(enemy[kl].shape.getGlobalBounds().intersects(player1.shape.getGlobalBounds()))
                        {
                            enemy.erase(enemy.begin()+kl);
                            collision.play();
                            life--;
                            if(life==0)
                                dekhi=0;
                            agunbool = true;
                            blll=true;
                        }
                        for(int ml=0; ml < player1.bullets.size(); ml++)
                        {
                            if(enemy[kl].shape.getGlobalBounds().intersects(player1.bullets[ml].shape.getGlobalBounds()))
                            {
                                enemy.erase(enemy.begin()+kl);
                                player1.bullets.erase(player1.bullets.begin()+ml);
                            }
                        }
                    }

                    for(int kl=0; kl<player1.bullets.size(); kl++)
                    {
                        if(player1.bullets[kl].shape.getGlobalBounds().intersects(Thor1.getGlobalBounds()) && pran1 > 0)
                            pran1--, player1.bullets.erase(player1.bullets.begin()+kl),blll1=true,agunbool1=true,collision.play();
                        if(player1.bullets[kl].shape.getGlobalBounds().intersects(Thor2.getGlobalBounds()) && pran2 > 0)
                            pran2--, player1.bullets.erase(player1.bullets.begin()+kl),blll2=true,agunbool2=true,collision.play();
                    }

                    if(bg3.getPosition().y-bg3.getLocalBounds().height+120>0)
                        bg3.setPosition(0.f,bg4.getPosition().y-bg4.getLocalBounds().height+120);
                    if(bg4.getPosition().y-bg4.getLocalBounds().height+120>0)
                        bg4.setPosition(0.f,bg3.getPosition().y-bg3.getLocalBounds().height+120);

                    ///collision with window
                    if (player1.shape.getPosition().x <= 0) //Left
                        player1.shape.setPosition(0.f, player1.shape.getPosition().y);
                    if (player1.shape.getPosition().x >= window.getSize().x - player1.shape.getGlobalBounds().width) //Right
                        player1.shape.setPosition(window.getSize().x - player1.shape.getGlobalBounds().width, player1.shape.getPosition().y);
                    if(player1.shape.getPosition().y<=0)
                        player1.shape.setPosition(player1.shape.getPosition().x,0.f);
                    if(player1.shape.getPosition().y >= window.getSize().y-player1.shape.getGlobalBounds().height-40)
                        player1.shape.setPosition(player1.shape.getPosition().x,window.getSize().y-player1.shape.getGlobalBounds().height-40);

                    if (shootTimer < 15)
                        shootTimer++;

                    if ((Mouse::isButtonPressed(Mouse::Left)||Keyboard::isKeyPressed(Keyboard::Space)) && shootTimer >= 15 && mgzn > 0) //Shooting
                    {
                        fire.play();
                        mgzn--;
                        player1.bullets.push_back(Bullet1(&bullet4, player1.shape.getPosition()));
                        player1.bullets[player1.bullets.size()-1].shape.setScale(0.2f,0.2f);
                        player1.bullets[player1.bullets.size()-1].shape.setPosition(Vector2f(player1.shape.getPosition().x+40,player1.shape.getPosition().y));
                        shootTimer = 0; //reset timer
                    }

                    if(mgzn==0 || life == 0)
                    {

                        gamemusic.stop();
                        menumusic.play();
                        menumusic.setLoop(true);
                    }

                    for (size_t i = 0; i < player1.bullets.size(); i++)
                    {
                        //Move
                        player1.bullets[i].shape.move(0.f, -20.f);

                        //Out of window bounds
                        if (player1.bullets[i].shape.getPosition().x > window.getSize().x)
                        {
                            player1.bullets.erase(player1.bullets.begin() + i);
                            break;
                        }
                    }



                    RectangleShape health(Vector2f(life*20,25));
                    health.setFillColor(Color::Green);
                    health.setPosition(550,window.getSize().y-35);

                    RectangleShape magazine(Vector2f(mgzn*2,25));
                    magazine.setFillColor(Color::Red);
                    magazine.setPosition(1050,window.getSize().y-35);


                    window.clear();

                    window.draw(bg3);
                    window.draw(bg4);
                    window.draw(player1.shape);
                    for(int kl=0; kl<enemy.size(); kl++)
                    {
                        window.draw(enemy[kl].shape);
                    }


                    if(lve>9.0f )
                    {
                        love.setPosition(rand() % window.getSize().x,0);
                        loove.restart();
                        lve=0.0f;
                    }
                    if(pr>10.0f)
                    {
                        prize.setPosition(rand() % window.getSize().x,0);
                        prii.restart();
                        pr=0.0f;
                    }
                    love.move(0.f,10.f);
                    prize.move(0.f,10.f);
                    window.draw(prize);
                    window.draw(love);
                    window.draw(bar);
                    window.draw(lifetxt);
                    window.draw(mgzntxt);
                    window.draw(magazine);
                    window.draw(health);
                    if(love.getGlobalBounds().intersects(player1.shape.getGlobalBounds()))
                    {
                        if(life<10 && life >0)
                        life=life+2;
                        love.setPosition(200.f,2000.f);
                    }
                    if(prize.getGlobalBounds().intersects(player1.shape.getGlobalBounds()))
                    {
                        if(mgzn<100)
                            mgzn=mgzn+10;
                        prize.setPosition(200.f,2000.f);
                    }

                    for (size_t i = 0; i < player1.bullets.size(); i++)
                        window.draw(player1.bullets[i].shape);

                    if(blll)
                    {
                        agun.restart();
                        blll=false;
                    }

                    aguntime=agun.getElapsedTime().asSeconds();

                    if(agunbool)
                    {
                        if(aguntime <0.15)
                        {
                            Step1.setPosition(player1.shape.getPosition().x+11,player1.shape.getPosition().y+20);
                            window.draw(Step1);
                        }
                        if(aguntime > 0.15 &&  aguntime <= 0.3)
                        {
                            Step2.setPosition(player1.shape.getPosition().x+11,player1.shape.getPosition().y+20);
                            window.draw(Step2);
                        }
                        if(aguntime > 0.3 &&  aguntime <= 0.45)
                        {
                            Step3.setPosition(player1.shape.getPosition().x+11,player1.shape.getPosition().y+20);
                            window.draw(Step3);
                        }
                        if(aguntime > 0.45 && aguntime <= 0.6)
                        {
                            Step4.setPosition(player1.shape.getPosition().x+11,player1.shape.getPosition().y+20);
                            window.draw(Step4);
                        }
                        if(aguntime > 0.6)
                            agunbool=false;
                    }

                    if(blll1)
                    {
                        agun1.restart();
                        blll1=false;
                    }
                    aguntime1=agun1.getElapsedTime().asSeconds();

                    if(agunbool1)
                    {
                        if(aguntime1 <0.15)
                        {
                            tep1.setPosition(Thor1.getPosition().x+11,Thor1.getPosition().y+20);
                            window.draw(tep1);
                        }
                        if(aguntime1 > 0.15 &&  aguntime1 <= 0.3)
                        {
                            tep2.setPosition(Thor1.getPosition().x+11,Thor1.getPosition().y+20);
                            window.draw(tep2);
                        }
                        if(aguntime1 > 0.3 &&  aguntime1 <= 0.45)
                        {
                            tep3.setPosition(Thor1.getPosition().x+11,Thor1.getPosition().y+20);
                            window.draw(tep3);
                        }
                        if(aguntime1 > 0.45 && aguntime1 <= 0.6)
                        {
                            tep4.setPosition(Thor1.getPosition().x+11,Thor1.getPosition().y+20);
                            window.draw(tep4);
                        }
                        if(aguntime1 > 0.6)
                            agunbool1=false;
                    }

                    if(blll2)
                    {
                        agun2.restart();
                        blll2=false;
                        agunbool2=true;
                    }
                    aguntime2=agun2.getElapsedTime().asSeconds();

                    if(agunbool2)
                    {
                        if(aguntime2 <0.15)
                        {
                            ep1.setPosition(Thor2.getPosition().x+11,Thor2.getPosition().y+20);
                            window.draw(ep1);
                        }
                        if(aguntime2 > 0.15 &&  aguntime1 <= 0.3)
                        {
                            ep2.setPosition(Thor2.getPosition().x+11,Thor2.getPosition().y+20);
                            window.draw(ep2);
                        }
                        if(aguntime2 > 0.3 &&  aguntime1 <= 0.45)
                        {
                            ep3.setPosition(Thor2.getPosition().x+11,Thor2.getPosition().y+20);
                            window.draw(ep3);
                        }
                        if(aguntime2 > 0.45 && aguntime1 <= 0.6)
                        {
                            ep4.setPosition(Thor2.getPosition().x+11,Thor2.getPosition().y+20);
                            window.draw(ep4);
                        }
                        if(aguntime2 > 0.6)
                            agunbool2=false;
                    }


                    RectangleShape pra1(Vector2f((unsigned)pran1*6,10));
                    pra1.setFillColor(Color::Red);
                    pra1.setPosition((unsigned)Thor1.getPosition().x,(unsigned)Thor1.getPosition().y-13);

                    RectangleShape pra2(Vector2f((unsigned)pran2*6,10));
                    pra2.setFillColor(Color::Red);
                    pra2.setPosition((unsigned)Thor2.getPosition().x,(unsigned)Thor2.getPosition().y-13);
                    if(pran1 > 0)
                    {
                        window.draw(Thor1);
                        window.draw(pra1);
                    }
                    if(pran2 > 0)
                    {
                        window.draw(Thor2);
                        window.draw(pra2);
                    }
                    if((pran1 == 0 && pran2 == 0))
                    {
                        life=10;
                        level2=false;
                        level3=true;
                        schange.restart();
                        mgzn=100;
                    }
                    if(life==0 || dekha)
                    {
                         window.clear(Color::White);
                        if(dekhi < 100)
                        {
                            life--;
                            dekha=true;
                            dekhi++;
                        }
                        else
                        {
                            dekha = false;
                            me=true;
                            menu=true;
                            gamemusic.stop();
                            menumusic.play();
                            menumusic.setLoop(true);
                        }

                        window.draw(gameovertxt);

                    }
                    window.display();
                }

            }

            ///stage 3

            else if(level3)
            {
                stchange=schange.getElapsedTime().asSeconds();
                if(stchange < 2.0)
                {
                    window.clear();
                    window.draw(spchange);
                    st3.setCharacterSize(130);
                    st3.setFillColor(Color::White);
                    st3.setPosition(420.f,window.getSize().y/2-90);
                    window.draw(st3);
                    jan=20;
                    vilen.setPosition(window.getSize().x-150,300.f);
                    window.display();
                    up=true;
                    blll1=false;
                    blll=false;
                    agunbool=false;
                    bool stage3=true;
                }
                else
                {
                    if(stage3)
                    {
                        gamemusic.play();
                        gamemusic.setLoop(true);
                        bg5.setPosition(0.f,-100.f);
                        hero.setPosition(Vector2f(50,window.getSize().y/2));
                        mgzn=100;
                        jan=50;
                        stage3=false;
                    }

                    if(Keyboard::isKeyPressed(Keyboard::Left))
                        hero.move(-10.f, 0.f);
                    if(Keyboard::isKeyPressed(Keyboard::Right))
                        hero.move(10.f, 0.f);
                    if(Keyboard::isKeyPressed(Keyboard::Up))
                        hero.move(0.f, -10.f);
                    if(Keyboard::isKeyPressed(Keyboard::Down))
                        hero.move(0.f, 10.f);
                    if(Keyboard::isKeyPressed(Keyboard::Escape))
                    {
                        gamemusic.stop();
                        menumusic.play();
                        menumusic.setLoop(true);
                        menu=true;
                        stages=false;
                        me=true;
                        level3=false;
                        le=3;
                    }
                    if (hero.getPosition().x <= 0) //Left
                        hero.setPosition(0.f, hero.getPosition().y);
                    if (hero.getPosition().x >= window.getSize().x - hero.getGlobalBounds().width) //Right
                        hero.setPosition(window.getSize().x - hero.getGlobalBounds().width, hero.getPosition().y);
                    if(hero.getPosition().y<=80)
                        hero.setPosition(hero.getPosition().x,80.f);
                    if(hero.getPosition().y >= window.getSize().y-hero.getGlobalBounds().height+30)
                        hero.setPosition(hero.getPosition().x,window.getSize().y-hero.getGlobalBounds().height+30);

                     if (shootTimer < 15)
                        shootTimer++;

                    if ((Mouse::isButtonPressed(Mouse::Left)||Keyboard::isKeyPressed(Keyboard::Space)) && shootTimer >= 15 && mgzn > 0) //Shooting
                    {
                        fire.play();
                        mgzn--;
                        goli.push_back(Bullet1(&bullet3,Vector2f(hero.getPosition().x,hero.getPosition().y)));
                        goli[goli.size()-1].shape.setScale(0.12f,0.12f);
                        goli[goli.size()-1].shape.setPosition(Vector2f(hero.getPosition().x+13,hero.getPosition().y-60));
                        shootTimer = 0; //reset timer
                    }
                    for(int bl=0;bl < goli.size();bl++)
                    {
                        goli[bl].shape.move(10.f,0.f);
                        if(goli[bl].shape.getPosition().x > window.getSize().x)
                            goli.erase(goli.begin()+bl);
                        if(goli[bl].shape.getGlobalBounds().intersects(vilen.getGlobalBounds()))
                        {
                            crash.play();
                            goli.erase(goli.begin()+bl);
                            jan--;
                            blll1=true;
                            agunbool1=true;
                        }
                        for(int kl=0;kl < pathor.size() ; kl++)
                        {
                            if(goli[bl].shape.getGlobalBounds().intersects(pathor[kl].shape.getGlobalBounds()))
                            {
                                crash.play();
                                goli.erase(goli.begin()+bl);
                                pathor.erase(pathor.begin()+kl);
                            }
                        }
                        for(int kl=0; kl<boss.size(); kl++)
                        {
                            if(goli[bl].shape.getGlobalBounds().intersects(boss[kl].shape.getGlobalBounds()))
                            {
                                crash.play();
                                goli.erase(goli.begin()+bl);
                                boss.erase(boss.begin()+kl);
                            }
                        }
                    }

                    if (enemySpawnTimer < 15)
                        enemySpawnTimer++;

                    if(vtime < 70)
                        vtime++;

                    if(vtime >=70 )
                    {
                        boss.push_back(Bullet1(&bos,Vector2f(0.0,0.0)));
                        boss[boss.size()-1].shape.setPosition(vilen.getPosition().x,vilen.getPosition().y-10);
                        boss[boss.size()-1].shape.setScale(0.25,0.25);
                        vtime=0;
                    }
                    for(int bl=0; bl < boss.size(); bl++)
                    {
                        boss[bl].shape.move(-15.f,0.f);
                        if(boss[bl].shape.getPosition().x < -30)
                            boss.erase(boss.begin()+bl);
                        if(boss[bl].shape.getGlobalBounds().intersects(hero.getGlobalBounds()))
                        {
                            life--;
                            boss.erase(boss.begin()+bl);
                            blll=true;
                            collision.play();
                            agunbool=true;
                        }

                    }

                    if (enemySpawnTimer >= 15)
                    {
                        pathor.push_back(Bullet1(&pathr, Vector2f(0.0,0.0)));
                        pathor[pathor.size()-1].shape.setPosition(window.getSize().x , rand() % window.getSize().y);
                        pathor[pathor.size()-1].shape.setScale(0.3f,0.3f);
                        enemySpawnTimer = 0; //reset timer
                    }

                    for(int bl=0; bl < pathor.size(); bl++)
                    {
                        pathor[bl].shape.move(-10.f,0.f);
                        if(pathor[bl].shape.getPosition().x < -30)
                            pathor.erase(pathor.begin()+bl);
                        if(pathor[bl].shape.getGlobalBounds().intersects(hero.getGlobalBounds()))
                        {
                            life--;
                            pathor.erase(pathor.begin()+bl);
                            blll=true;
                            collision.play();
                            agunbool=true;
                        }
                    }

                    if(up)
                    {
                        vilen.move(0,-5.f);
                        if(vilen.getPosition().y < 40)
                        {
                            up=false;
                            down=true;
                        }
                    }
                    if(down)
                    {
                        vilen.move(0.f,5.f);
                        if(vilen.getPosition().y > window.getSize().y - 180)
                        {
                            up=true;
                            down=false;
                        }
                    }
                    window.clear();
                    window.draw(bg5);

                    for(int bl=0;bl<goli.size();bl++)
                        window.draw(goli[bl].shape);
                    for(int bl=0 ; bl < pathor.size(); bl++)
                        window.draw(pathor[bl].shape);
                    for(int bl=0 ; bl < boss.size(); bl++)
                        window.draw(boss[bl].shape);

                    window.draw(hero);

                    if(blll)
                    {
                        agun.restart();
                        agunbool=true;
                        blll=false;
                    }
                    aguntime=agun.getElapsedTime().asSeconds();

                    if(agunbool)
                    {
                        if(aguntime <0.15)
                        {
                            Step1.setPosition(hero.getPosition().x,hero.getPosition().y-72);
                            window.draw(Step1);
                        }
                        if(aguntime > 0.15 &&  aguntime <= 0.3)
                        {
                            Step2.setPosition(hero.getPosition().x,hero.getPosition().y-72);
                            window.draw(Step2);
                        }
                        if(aguntime > 0.3 &&  aguntime <= 0.45)
                        {
                            Step3.setPosition(hero.getPosition().x,hero.getPosition().y-72);
                            window.draw(Step3);
                        }
                        if(aguntime > 0.45 && aguntime <= 0.6)
                        {
                            Step4.setPosition(hero.getPosition().x,hero.getPosition().y-72);
                            window.draw(Step4);
                        }
                        if(aguntime > 0.6)
                            agunbool=false;
                    }

                    RectangleShape health(Vector2f(life*20,25));
                    health.setFillColor(Color::Green);
                    health.setPosition(550,window.getSize().y-35);

                    RectangleShape magazine(Vector2f(mgzn*2,25));
                    magazine.setFillColor(Color::Red);
                    magazine.setPosition(1050,window.getSize().y-35);

                    RectangleShape jn(Vector2f((unsigned)jan*2.5,10));
                    jn.setFillColor(Color::Red);
                    jn.setPosition((unsigned)vilen.getPosition().x,(unsigned)vilen.getPosition().y-20);

                    window.draw(jn);
                    window.draw(bar);
                    window.draw(lifetxt);
                    window.draw(mgzntxt);
                    window.draw(magazine);
                    window.draw(health);
                    window.draw(vilen);
                    if(blll1)
                    {
                        agun1.restart();
                        blll1=false;
                    }
                    aguntime1=agun1.getElapsedTime().asSeconds();

                    if(agunbool1)
                    {
                        if(aguntime1 <0.15)
                        {
                            tep1.setPosition(vilen.getPosition().x-11,vilen.getPosition().y+20);
                            window.draw(tep1);
                        }
                        if(aguntime1 > 0.15 &&  aguntime1 <= 0.3)
                        {
                            tep2.setPosition(vilen.getPosition().x+11,vilen.getPosition().y+20);
                            window.draw(tep2);
                        }
                        if(aguntime1 > 0.3 &&  aguntime1 <= 0.45)
                        {
                            tep3.setPosition(vilen.getPosition().x+11,vilen.getPosition().y+20);
                            window.draw(tep3);
                        }
                        if(aguntime1 > 0.45 && aguntime1 <= 0.6)
                        {
                            tep4.setPosition(vilen.getPosition().x+11,vilen.getPosition().y+20);
                            window.draw(tep4);
                        }
                        if(aguntime1 > 0.6)
                            agunbool1=false;
                    }

                    if(life==0 || dekha || mgzn ==0)
                    {

                         window.clear(Color::White);
                        if(dekhi < 100)
                        {
                            life=-1;
                            dekha=true;
                            dekhi++;
                        }
                        else
                        {
                            dekha = false;
                            me=true;
                            menu=true;
                            gamemusic.stop();
                            menumusic.play();
                            menumusic.setLoop(true);
                        }

                        window.draw(gameovertxt);
                    }
                    if((jan==0 || dekha) && life !=-1)
                    {
                         window.clear(Color::White);
                        if(dekhi < 1000)
                        {
                            jan--;
                            dekha=true;
                            dekhi++;
                        }
                        else
                        {
                            dekha = false;
                            me=true;
                            menu=true;
                            gamemusic.stop();
                            menumusic.play();
                            menumusic.setLoop(true);
                        }
                        window.draw(gameovertxt);
                        window.draw(welcometxt);
                    }
                    window.display();
                }

            }
        }

    }
    return 0;
}


