#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class Object
{
public:
	Object(sf::Vector2f ObjSize, sf::Texture* texture)
	{
		object.setSize(ObjSize);
		object.setTexture(texture);

		objWidth = ObjSize.x;
		objHeight = ObjSize.y;
	}
	void setPosition(sf::Vector2f point) {
		object.setPosition(point);
		// Center text on button:
		float xPos = (point.x + objWidth / 2);
		float yPos = (point.y + objHeight / 2.2);
	}
	void drawTo(sf::RenderWindow& window) {
		window.draw(object);
	}
private:
	sf::RectangleShape object;
	sf::Texture texture;
	int objWidth;
	int objHeight;
};

