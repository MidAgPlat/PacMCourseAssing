#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
extern int score, key;
class Pacman
{
public:
	Pacman(sf::Vector2f ObjSize, sf::Texture* texture)
	{
		pacman.setSize(ObjSize);
		pacman.setTexture(texture);

		pacWidth = ObjSize.x;
		pacHeight = ObjSize.y;
	}
	void setPosition(sf::Vector2f point) {
		pacman.setPosition(point);
	}
	void drawTo(sf::RenderWindow& window) {
		window.draw(pacman);
	}
	void Move(sf::Vector2f vect)
	{
		pacman.setPosition(vect);
	}
private:
	sf::RectangleShape pacman;
	sf::Texture texture;
	int pacWidth;
	int pacHeight;
};

