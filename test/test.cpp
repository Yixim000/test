#include <SFML/Graphics.hpp>
#include "Click.h"

#include <vector>
//Problemy z projektem z moją częścią:
//1. Nie działają exity
//2. Z jakiegoś powodu usuwają się od razu 3 życia i nie wiem czemu
using namespace std;
bool isSpriteHover(sf::FloatRect sprite, sf::Vector2f mp) //Check if ywo shapes contain one another
{
    if (sprite.contains(mp)) {
        return true;
    }
    return false;
}

int main()
{

    sf::RenderWindow window(
        sf::VideoMode(740, 580),
        "Paper, please");
   window.setSize(sf::Vector2u(740, 580));
   window.setFramerateLimit(60); // Limit the frame rate to 60 FPS

    // Disable window resizing
    sf::Event event;
  
    bool mouseClicked = false;
    bool mouseInsideRect = false;
    bool dragging = false;
    bool d{};
    bool w{};
    sf::Vector2f mouseRectOffset;

    int mouseX = 0;
    int mouseY = 0;

   
    std::vector<Shape> shapeVec;
    Shape* currentShape = nullptr;          // keep track of current shape being moved
    for (int i = 0; i < 2; ++i) {
        auto shape = new Shape({ 90,30 });
        if (i == 1)
        {
            shape->shape.setPosition(window.getPosition().x / 1.2, window.getPosition().y / 1.6);
        }
        if (i == 0)
        {
            shape->shape.setPosition(window.getPosition().x /8, window.getPosition().y / 1.6);
            shape->shape.setFillColor(sf::Color::Red);
          

        }
        shapeVec.push_back(*shape);
    } 
    
    float num = 3;
    std::vector<Circle> circlevec;
    std::vector<Circle>::iterator a;

    Circle* currentCircle = nullptr;          // keep track of current live
    for (int i = 0; i < num; ++i)
    {
        auto shape = new Circle({ 90,30 });
            shape->shape.setPosition(window.getPosition().x / 6 +15 * i, window.getPosition().y / 20);
            shape->shape.setFillColor(sf::Color::Red);
 circlevec.push_back(*shape);
    }
    Buttons zero(window.getSize().x / 4, window.getSize().y / 20, 34); //creating all of buttons
    zero.setText("PAPERS, PLEASE", "arial.ttf");

    Buttons one(window.getSize().x / 3, window.getSize().y / 6, 24);
    one.setSprite("texture.png");
    one.setText("Play", "arial.ttf");

    Buttons two(window.getSize().x / 3, window.getSize().y / 3, 24);;
    two.setSprite("texture.png");
    two.setText("Instructions", "arial.ttf");

    Buttons three(window.getSize().x / 3, window.getSize().y / 2, 24);;
    three.setSprite("heart.png");
    three.setText("Authors", "arial.ttf");

    Buttons four(window.getSize().x /3,window.getSize().y / 4, 24);;
    four.setSprite("texture.png");
    four.setText("Document", "arial.ttf");
    int t = 0;
    sf::Vector2f mp; //vector that keeps track of the mouse position
    mp.x = sf::Mouse::getPosition(window).x;
    mp.y = sf::Mouse::getPosition(window).y;

    Buttons exit(window.getSize().x /1.35,window.getSize().y / 42, 16);
    exit.spritesize = 20;
    exit.setSprite("texture.png");
    exit.setText("Exit X", "arial.ttf");

    Buttons way(window.getSize().x / 22, window.getSize().y / 2, 20); // instructions 
    way.var1 = 3;
    way.var2 = 5;
    way.setSprite("texture.png");
    way.setText("Check the correctess\n of the name \n and whether the document\n is expaired", "arial.ttf");

    Document doc(window.getSize().x / 2, window.getSize().y / 2, 24);
    doc.var1 = 3;
    doc.var2 = 5;
    doc.createDoc();
    doc.displayDoc();

    Buttons info(window.getSize().x / 10, window.getSize().y / 6, 24); //explanation of the game
    info.var1 = 5;
    info.var2 = 4;
    info.setSprite("texture.png");
    info.setText("You're a border inspector \n who regulates \n the border checkpoint. \n You must determine \n who to admit \n and who to keep out. \n Good luck.", "arial.ttf");

    Buttons authors(window.getSize().x / 10, window.getSize().y / 6, 24);
    authors.var1 = 5;
    authors.var2 = 5;
    authors.setSprite("texture.png");
    authors.setText(" Authors:\n Dominik Dzida \n Damian Fliegiel \n Martyna Kramarz \n ", "arial.ttf");

    Buttons instruct(window.getSize().x / 21, window.getSize().y / 14, 16);
    instruct.spritesize = 20;
    instruct.setSprite("texture.png");
    instruct.setText("How", "arial.ttf");

    Buttons live(window.getPosition().x / 17, window.getPosition().y / 20, 16);
    live.spritesize = 20;
    live.setSprite("texture.png");
    live.setText("Lives ", "arial.ttf");


    bool hearts{};
    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                window.close();

            if (event.type == sf::Event::Resized)
            {
                // Get the new size and set it back to the original size
                sf::Vector2u size = window.getSize();
                window.setSize(sf::Vector2u(640, 480));
            }
        }

        window.clear();
        window.draw(zero.text);
        window.draw(one.sprite);
        window.draw(one.text);
        window.draw(two.sprite);
        window.draw(two.text);
        window.draw(three.sprite);
        window.draw(three.text);
        window.display();

        if (isSpriteHover(one.sprite.getGlobalBounds(), sf::Vector2f(event.mouseButton.x, event.mouseButton.y)) == true)
        {


            window.create(sf::VideoMode(740, 580), "PAPERS, PLEASE!");

            while (window.isOpen()) {
                while (window.pollEvent(event)) {
                    if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                        window.close();
                    if (event.type == sf::Event::Resized)
                    {
                        // Get the new size and set it back to the original size
                        sf::Vector2u size = window.getSize();
                        window.setSize(sf::Vector2u(740, 580));
                    }

                    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
                        auto shape = new Shape({ 180,60 });
                        shape->shape.setPosition(rand() % 1100 + 100, rand() % 650 + 100);
                        shapeVec.push_back(*shape);
                    }


                }
                while (num > 0)
                {
                    // get the mouse position
                    auto mpos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

                    // Moving the shapes
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                        if (mpos.x >= 0 && mpos.x < window.getSize().x && mpos.y >= 0 * mpos.y < window.getSize().y && !dragging) {
                            dragging = true;
                            for (auto& it : shapeVec) {
                                if (it.shape.getGlobalBounds().contains(mpos.x, mpos.y)) {
                                    it.selected = true;
                                    currentShape = &it;
                                    break;
                                }
                            }
                        }
                    }
                    else {

                        dragging = false;
                        if (currentShape)
                            currentShape->selected = false;
                    }

                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                        if (isSpriteHover(four.sprite.getGlobalBounds(), sf::Vector2f(event.mouseButton.x, event.mouseButton.y)) == true)
                        {
                            d = 1;

                        }
                        if (isSpriteHover(instruct.sprite.getGlobalBounds(), sf::Vector2f(event.mouseButton.x, event.mouseButton.y)) == true)
                        {
                            w = 1;
                        }
                    }

                    if (dragging == true) {

                        for (int i = 0; i < 2; i++) {

                            if (shapeVec[i].selected)
                            {
                                shapeVec[i].shape.setPosition(mpos.x, mpos.y);
                                if ((isSpriteHover(four.sprite.getGlobalBounds(), sf::Vector2f(shapeVec[i].shape.getPosition().x, shapeVec[i].shape.getPosition().y)) == true))
                                {
                                    if (i == 0)
                                    {
                                        shapeVec[i].shape.setFillColor(sf::Color::Magenta);
                                        four.setText("Good", "arial.ttf");
                                        num--;
                                        break;

                                    }
                                    if (i == 1)
                                    {
                                        shapeVec[i].shape.setFillColor(sf::Color::Cyan);
                                        four.setText("Bad", "arial.ttf");


                                    }
                                    break;
                                }


                            }
                        }
                    }

                        window.clear();

                        for (int i = 0; i < shapeVec.size(); ++i) {
                            window.draw(shapeVec[i].shape);
                        }
                        for (int i = 0; i < num; i++) {
                            window.draw(circlevec[i].shape);
                        }

                        window.draw(four.sprite);
                        window.draw(four.text);
                        window.draw(exit.sprite);
                        window.draw(exit.text);
                        window.draw(instruct.sprite);
                        window.draw(instruct.text);
                        if (w == 1)
                        {
                            window.draw(way.sprite);
                            window.draw(way.text);
                        }
                        if (d == 1)
                        {
                            window.draw(doc.sprite);
                            window.draw(doc.text);
                        }
                        window.draw(live.sprite);
                        window.draw(live.text);
                        window.display();


                    }


                    if (isSpriteHover(exit.sprite.getGlobalBounds(), sf::Vector2f(event.mouseButton.x, event.mouseButton.y)) == true)
                    {

                    }

                }

            }
        
        if (isSpriteHover(two.sprite.getGlobalBounds(), sf::Vector2f(event.mouseButton.x, event.mouseButton.y)) == true)
        {
       
            window.create(sf::VideoMode(640, 480), "Papers, please!");
            window.clear();
            window.draw(exit.sprite);
            window.draw(exit.text);
            window.draw(info.sprite);
            window.draw(info.text);
            window.display();

            while (window.isOpen())
            {
                sf::Event event;

                while (window.pollEvent(event))
                {
                    if (event.type == sf::Event::Closed)
                        window.close();
                    if (event.type == sf::Event::Resized)
                    {
                        // Get the new size and set it back to the original size
                        sf::Vector2u size = window.getSize();
                        window.setSize(sf::Vector2u(640, 480));
                    }
                }
                if (isSpriteHover(exit.sprite.getGlobalBounds(), sf::Vector2f(event.mouseButton.x, event.mouseButton.y)) == true)
                {
               

                }
            }

        }
        if (isSpriteHover(three.sprite.getGlobalBounds(), sf::Vector2f(event.mouseButton.x, event.mouseButton.y)) == true)
        {
        
            window.create(sf::VideoMode(640, 480), "Papers, please!");
            window.clear();
            window.draw(exit.sprite);
            window.draw(exit.text);
            window.draw(authors.sprite);
            window.draw(authors.text);
            window.display();

            while (window.isOpen())
            {
                sf::Event event;

                while (window.pollEvent(event))
                {
                    if (event.type == sf::Event::Closed)
                        window.close();

                }

                if (isSpriteHover(exit.sprite.getGlobalBounds(), sf::Vector2f(event.mouseButton.x, event.mouseButton.y)) == true)
                {

                }

                // exit:
                  //   break;
            }

            window.clear();
            window.draw(zero.text);
            window.draw(one.sprite);
            window.draw(one.text);
            window.draw(two.sprite);
            window.draw(two.text);
            window.draw(three.sprite);
            window.draw(three.text);
            window.display();

        }
    }
        return 0;
    
}
