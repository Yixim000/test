#include <SFML/Graphics.hpp>
#include <iostream>
#include "Click.h"
#include "Data.h"
#include <vector>

using namespace std;
bool isSpriteHover(sf::FloatRect sprite, sf::Vector2f mp)
{
    if (sprite.contains(mp)) {
        return true;
    }
    return false;
}

int main()
{

    sf::RenderWindow window(
        sf::VideoMode(640, 480),
        "Paper, please");
    window.setSize(sf::Vector2u(640, 480));
    window.setFramerateLimit(60); // Limit the frame rate to 60 FPS

    // Disable window resizing
    sf::Event event;

    bool mouseClicked = false;
    bool mouseInsideRect = false;
    bool dragging = false;

    sf::Vector2f mouseRectOffset;

    int mouseX = 0;
    int mouseY = 0;

    std::vector<Shape> shapeVec;
    Shape* currentShape = nullptr;          // keep track of current shape being moved
    for (int i = 0; i < 2; ++i) {
        auto shape = new Shape({ 180,60 });
        if (i == 1)
        {
            shape->shape.setPosition(window.getPosition().x / 2, window.getPosition().y / 2);
        }
        if (i == 0)
        {
            shape->shape.setPosition(window.getPosition().x / 6, window.getPosition().y / 2);
            shape->shape.setFillColor(sf::Color::Red);

        }
        //shape->shape.setPosition(rand() % 1100 + 100, rand() % 650 + 100);
        shapeVec.push_back(*shape);
    }

    Buttons zero(window.getSize().x / 4, window.getSize().y / 20, 34);
    zero.setText("PAPERS, PLEASE", "arial.ttf");

    Buttons one(window.getSize().x / 3, window.getSize().y / 6, 24);
    one.setSprite("texture.png");
    one.setText("Play", "arial.ttf");

    Buttons two(window.getSize().x / 3, window.getSize().y / 3, 24);;
    two.setSprite("texture.png");
    two.setText("Instructions", "arial.ttf");

    Buttons three(window.getSize().x / 3, window.getSize().y / 2, 24);;
    three.setSprite("texture.png");
    three.setText("Authors", "arial.ttf");

    Buttons four(window.getSize().x / 3, window.getSize().y / 3, 24);;
    four.setSprite("texture.png");
    four.setText("Document", "arial.ttf");

    sf::Vector2f mp;
    mp.x = sf::Mouse::getPosition(window).x;
    mp.y = sf::Mouse::getPosition(window).y;

    Buttons exit(window.getSize().x / 1.5, window.getSize().y / 14, 16);
    exit.spritesize = 20;
    exit.setSprite("texture.png");
    exit.setText("Exit X", "arial.ttf");

    Buttons way(window.getSize().x / 10, window.getSize().y / 6, 24);
     way.var1 = 5;
     way.var2 = 5;
     way.setSprite("texture.png");
     way.setText("Check the correctess of the name \n and whether the document is expaired", "arial.ttf");
 
    Buttons info(window.getSize().x / 10, window.getSize().y / 6, 24);
    info.var1 = 5;
    info.var2 = 5;
    info.setSprite("texture.png");
    info.setText("You're a border inspector \n who regulates \n the border checkpoint. \n You must determine \n who to admit \n and who to keep out. \n Good luck.", "arial.ttf");

    Buttons authors(window.getSize().x / 10, window.getSize().y / 6, 24);
    authors.var1 = 5;
    authors.var2 = 5;
    authors.setSprite("texture.png");
    authors.setText(" Authors:\n Dominik Dzida \n Damian Fliegiel \n Martyna Kramarz \n ", "arial.ttf");

    Document doc(window.getSize().x / 10, window.getSize().y / 6, 24);
    doc.var1 = 5;
    doc.var2 = 5;
    doc.createDoc();
    doc.displayDoc();
    
    auto mpos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

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
            if (isSpriteHover(one.sprite.getGlobalBounds(), sf::Vector2f(event.mouseButton.x, event.mouseButton.y)) == true)
            {


                window.create(sf::VideoMode(640, 480), "The button worked!");

                while (window.isOpen()) {
                    while (window.pollEvent(event)) {
                        if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                            window.close();
                        if (event.type == sf::Event::Resized)
                        {
                            // Get the new size and set it back to the original size
                            sf::Vector2u size = window.getSize();
                            window.setSize(sf::Vector2u(640, 480));
                        }

                        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
                            auto shape = new Shape({ 180,60 });
                            shape->shape.setPosition(rand() % 1100 + 100, rand() % 650 + 100);
                            shapeVec.push_back(*shape);
                        }


                    }

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


                    if (isSpriteHover(four.sprite.getGlobalBounds(), sf::Vector2f(event.mouseButton.x, event.mouseButton.y)) == true)
                    {
                        sf::RenderWindow window2(
                            sf::VideoMode(640, 480),
                            "Paper, please");
                        window2.setSize(sf::Vector2u(640, 480));
                        window2.setFramerateLimit(60); // Limit the frame rate to 60 FPS
                        sf::Event event;

                        while (window2.isOpen())
                        {

                            while (window2.pollEvent(event))
                            {

                                if (event.type == sf::Event::Resized)
                                {
                                    // Get the new size and set it back to the original size
                                    sf::Vector2u size = window2.getSize();
                                    window2.setSize(sf::Vector2u(640, 480));
                                }

                                if (isSpriteHover(exit.sprite.getGlobalBounds(), sf::Vector2f(event.mouseButton.x, event.mouseButton.y)) == true)
                                {
                                    window2.close();
                                }

                            }

                            window2.clear();
                            window2.draw(exit.sprite);
                            window2.draw(exit.text);
                            window2.draw(two.sprite);
                            window2.draw(two.text);
                            window2.display();
                        }
                        sf::RenderWindow window3(
                            sf::VideoMode(640, 480),
                            "Paper, please");
                        window3.setSize(sf::Vector2u(640, 480));
                        window3.setFramerateLimit(60); // Limit the frame rate to 60 FPS

                        /*while (window3.isOpen())
                        {
                            sf::Event event;

                            while (window3.pollEvent(event))
                            {
                                if (event.type == sf::Event::Closed)
                                    window3.close();
                                if (event.type == sf::Event::Resized)
                                {
                                    // Get the new size and set it back to the original size
                                    sf::Vector2u size = window3.getSize();
                                    window3.setSize(sf::Vector2u(640, 480));
                                }
                            }
                            if (isSpriteHover(exit.sprite.getGlobalBounds(), sf::Vector2f(event.mouseButton.x, event.mouseButton.y)) == true)
                            {
                                window3.close();
                            }
                            window3.setSize(sf::Vector2u(640, 480));
                            window3.setFramerateLimit(60); // Limit the frame rate to 60 FPS
                            window3.create(sf::VideoMode(640, 480), "The button worked!");
                            window3.clear();
                            window3.draw(exit.sprite);
                            window3.draw(exit.text);
                            window3.draw(info.sprite);
                            window3.draw(info.text);
                            window3.display();

                        }*/
                    }
                }


                if (dragging == true) {
                    for (int i = 0; i < shapeVec.size(); i++) {
                        if (shapeVec[i].selected)
                        {
                            shapeVec[i].shape.setPosition(mpos.x, mpos.y);//zmienić by się zawierało
                            if (shapeVec[i].shape.getPosition().x == two.sprite.getPosition().x && shapeVec[i].shape.getPosition().y == two.sprite.getPosition().y)
                            {
                                if (i == 0)
                                {
                                    shapeVec[i].shape.setFillColor(sf::Color::Magenta);
                                    four.setText("Good", "arial.ttf.ttf");
                                }
                                if (i == 1)
                                {
                                    shapeVec[i].shape.setFillColor(sf::Color::Cyan);
                                    four.setText("Bad", "arial.ttf.ttf");
                                }
                            }
                        }



                    }
                }

                window.clear();

                for (int i = 0; i < shapeVec.size(); i++) {
                    window.draw(shapeVec[i].shape);
                }


                window.draw(four.sprite);
                window.draw(four.text);
                window.draw(exit.sprite);
                window.draw(exit.text);

                window.display();


                if (isSpriteHover(exit.sprite.getGlobalBounds(), sf::Vector2f(event.mouseButton.x, event.mouseButton.y)) == true)
                {
                    goto exit;
                }

            }

        }
        if (isSpriteHover(two.sprite.getGlobalBounds(), sf::Vector2f(event.mouseButton.x, event.mouseButton.y)) == true)
        {
            window.create(sf::VideoMode(640, 480), "The button worked!");
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
                    goto exit;
                }
            }

        }
        if (isSpriteHover(three.sprite.getGlobalBounds(), sf::Vector2f(event.mouseButton.x, event.mouseButton.y)) == true)
        {
            window.create(sf::VideoMode(640, 480), "The button worked!");
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
                    goto exit;
                }
            }
        exit:
            break;
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

    return 0;
}