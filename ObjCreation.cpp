#include "Object.h"
#include "Pacman.h"
#include <SFML/Graphics.hpp>

void WallDraw(sf::Vector2f vector, sf::RenderWindow& window)
{
	sf::Texture wallSprite;
	wallSprite.loadFromFile("Resoureeses\\Wall.png");
	Object wall({ 50, 50 }, &wallSprite);
	wall.setPosition(vector);
	wall.drawTo(window);
}

void PointDraw(sf::Vector2f vector, sf::RenderWindow& window)
{
	sf::Texture pointSprite;
	pointSprite.loadFromFile("Resoureeses\\Point.png");
	Object point({ 50, 50 }, &pointSprite);
	point.setPosition(vector);
	point.drawTo(window);
}

void SuperPointDraw(sf::Vector2f vector, sf::RenderWindow& window)
{
	sf::Texture SpointSprite;
	SpointSprite.loadFromFile("Resoureeses\\SuperPoint.png");
	Object superPoint({ 50, 50 }, &SpointSprite);
	superPoint.setPosition(vector);
	superPoint.drawTo(window);
}