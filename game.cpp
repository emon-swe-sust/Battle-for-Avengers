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
        shape.setScale(0.07f, 0.07f);
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
        shape.setScale(0.07f, 0.07f);
    }
};

class Enemy
{
public:
    Sprite shape;

    Enemy(Texture *texture, Vector2u windowSize)
    {
        shape.setTexture(*texture);
        shape.setScale(0.07f, 0.07f);
        shape.setPosition(rand()% (int)(windowSize.x - this->shape.getGlobalBounds().width),0);
    }
};

int main()
{
    srand(time(NULL));

    RenderWindow window(VideoMode(1300,800),"Battle For Avenger");
    window.setFramerateLimit(60);

    Font font;
    font.loadFromFile("Fonts/fine.ttf");

    Texture stark,thor,spider,halk,thanos,bullet1,bullet2,bullet3,bullet4,stone,space1;

    Color barr(252, 13, 13), notSelected(121, 130, 59, 100), beat(200, 20, 20), dev(255, 255, 255, 100);

    SoundBuffer bullettune,crashtune,coll;

    Music gamemusic;
    gamemusic.openFromFile("Music/game.wav");
    gamemusic.setVolume(1000);

    stark.loadFromFile("Textures/stark.png");
    thor.loadFromFile("Textures/thor.png");
    thanos.loadFromFile("Textures/thanos.png");
    halk.loadFromFile("Textures/halk.png");
    spider.loadFromFile("Textures/spider.png");
    bullet1.loadFromFile("Textures/bullet1.png");
    bullet2.loadFromFile("Textures/bullet2.png");
    bullet3.loadFromFile("Textures/bullet3.png");
    bullet4.loadFromFile("Textures/bullet4.png");
    stone.loadFromFile("Textures/stone.png");
    space1.loadFromFile("Textures/space3.png");
    bullettune.loadFromFile("Music/bullet.wav");
    crashtune.loadFromFile("Music/crash.wav");
    coll.loadFromFile("Music/collision.wav");

    Sound fire(bullettune),crash(crashtune),collision(coll);

    Sprite bg1(space1);
    bg1.setScale(1.55f,1.6f);

    Text scoretxt,gameovertxt,lifetxt,mgzntxt;

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
    gameovertxt.setPosition(100.f, window.getSize().y / 2);
    gameovertxt.setString("GAME OVER!");

    bool stage1=true;

    //Player init
    int score = 0;
    Player player(&halk);
    int shootTimer = 20;

    RectangleShape bar(Vector2f(window.getSize().x+50,100));
    bar.setFillColor(Color::White);
    bar.setPosition(window.getPosition().x/2-155,window.getSize().y-50);

    //Enemy init
    int enemySpawnTimer = 0,life=10;
    std::vector<Enemy> enemies;


    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        ///gameloop
        if(life>0)
        {
            ///stage1
            if(score<50)
            {
                int mgzn;
                if(stage1)
                {
                    gamemusic.play();
                    gamemusic.setLoop(true);
                    player.shape.setPosition(Vector2f(window.getSize().x/2,window.getSize().y-150));
                    mgzn=100;
                    stage1 = false;
                }
                if (Keyboard::isKeyPressed(Keyboard::Left))
                    player.shape.move(-10.f, 0.f);
                if (Keyboard::isKeyPressed(Keyboard::Right))
                    player.shape.move(10.f, 0.f);

                ///collision with window
                if (player.shape.getPosition().x <= 0) //Left
                    player.shape.setPosition(0.f, player.shape.getPosition().y);
                if (player.shape.getPosition().x >= window.getSize().x - player.shape.getGlobalBounds().width) //Right
                    player.shape.setPosition(window.getSize().x - player.shape.getGlobalBounds().width, player.shape.getPosition().y);

                if (shootTimer < 15)
                    shootTimer++;

                if ((Mouse::isButtonPressed(Mouse::Left)||Keyboard::isKeyPressed(Keyboard::Space)) && shootTimer >= 15) //Shooting
                {
                    fire.play();
                    mgzn--;
                    player.bullets.push_back(Bullet1(&bullet2, player.shape.getPosition()));
                    shootTimer = 0; //reset timer
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
                            break;
                        }
                    }
                }
                //Enemy
                if (enemySpawnTimer < 10)
                    enemySpawnTimer++;

                //enemy spawn
                if (enemySpawnTimer >= 10 && score < 25)
                {
                    enemies.push_back(Enemy(&stone, window.getSize()));
                    enemySpawnTimer = 0; //reset timer
                }

                if (enemySpawnTimer >= 6 && score >= 25)
                {
                    enemies.push_back(Enemy(&stone, window.getSize()));
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
                        break;
                    }
                    scoretxt.setString("Score: " + std::to_string(score));

                }

                RectangleShape health(Vector2f(life*20,25));
                health.setFillColor(Color::Green);
                health.setPosition(550,window.getSize().y-35);

                RectangleShape magazine(Vector2f(mgzn*2,25));
                magazine.setFillColor(Color::Red);
                magazine.setPosition(1050,window.getSize().y-35);


                window.clear();
                window.draw(bg1);
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
                if(life<0)
                    window.draw(gameovertxt);
                window.display();
            }

            ///stage 2

            else if(score >50 && score <100)
            {

            }

            ///stage 3

            else
            {

            }

        }
    }
    return 0;
}

