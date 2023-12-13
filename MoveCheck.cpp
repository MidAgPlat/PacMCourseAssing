#include <SFML/Graphics.hpp>
#include <iostream>
sf::Vector2f PacVect;
void getIJVect(sf::Vector2f vect)
{
	PacVect = vect;
}
bool MoveCh(int num) 
{
	if (num == 1) {
		return false;
	}
	return true;
}

