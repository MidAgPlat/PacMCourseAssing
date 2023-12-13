#include <iostream>
#include "AttachmentsOne.h"
int main()
{
	sf::RenderWindow appWindow(sf::VideoMode(900, 900), "Pacman");
	appWindow.setFramerateLimit(60);
	appWindow.setVerticalSyncEnabled(true);
	appWindow.setKeyRepeatEnabled(false);
    CreateWind(appWindow);
}