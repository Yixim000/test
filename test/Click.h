#pragma once
#include <SFML/Graphics.hpp>
#include "Data.h"
#include <iostream>
#include<string>
#include <vector>
using namespace std;
class Shape
{
public:
	Shape(sf::Vector2f size) {
		shape.setSize(size);
		shape.setFillColor(sf::Color::Green);
		shape.setOutlineThickness(1.f);
		shape.setOutlineColor(sf::Color::Black);
	}
	sf::RectangleShape shape;
	bool selected = false;

	Shape() {};
};
class Window
{
public:

	Window(sf::Vector2u size)
	{
		window.setSize(sf::Vector2u(640, 480));
		window.setTitle("Papers, please");
		window.setFramerateLimit(60); // Limit the frame rate to 60 FPS
		window.getPosition();

	}
	void creating(bool ifshapes)
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
	}
	sf::RenderWindow window;
	Window() {};

};

class Buttons :public Window
{
public:
	int x{}, y{}, sizeText{};
	int var1 = 1;
	int var2 = 3;
	int spritesize = 60;
	Buttons(int xx, int yy, int sizeT);
	Buttons() {};
	void setSprite(string spritename);
	void setText(string text, string fontname);
	sf::Font font;
	sf::Sprite sprite;
	sf::Text text;
};
class Document :public Buttons, public DataBaseInput
{
public:
	string a;
	Document(int xx, int yy, int sizeT);
	string createDoc();
	void displayDoc();
};


