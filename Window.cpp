#include <iostream>
#include <SFML/Audio.hpp>
#include "AttachmentsOne.h"
using namespace sf;


bool MainMenuBool = true;
int LvlNum = 0;
bool lead = true;
bool settings = false;
std::vector<Button> gui;
std::vector<Button> setts;
bool setting(bool settings, sf::RenderWindow& appWindow, sf::Music& music, std::vector<Button>& setts, sf::Text &t)
{

		int volume = music.getVolume();
		sf::Event Event;
		if (appWindow.pollEvent(Event))
		{
			switch (Event.type)
			{
			case sf::Event::Closed:
				appWindow.close();
			case sf::Event::MouseMoved:

				break;
			case sf::Event::MouseButtonReleased:
				if (setts[0].isMouseOver(appWindow))
				{
					//std::cout << "jfndk";
					if (volume > 95) {
						volume = 100;
					}
					else {
						volume += 5;
					}
					music.setVolume(volume);

				}
				else if (setts[1].isMouseOver(appWindow))
				{
					//std::cout << "jfndk";
					if (volume < 5) {
						volume = 0;
					}
					else {
						volume -= 5;
					}
					music.setVolume(volume);
				}
				else if (setts[3].isMouseOver(appWindow))
				{
					std::cout << "wethgd";
					lead = true;
					sf::Texture WASD;
					WASD.loadFromFile("Resoureeses\\wasd.png");
					setts[3].setTexture(&WASD);
					sf::Texture arr;
					arr.loadFromFile("Resoureeses\\arro.png");
					setts[2].setTexture(&arr);
					setts[2].drawTo(appWindow);
					setts[3].drawTo(appWindow);
					appWindow.display();
				}
				else if (setts[2].isMouseOver(appWindow))
				{
					lead = false;
					sf::Texture WASD;
					WASD.loadFromFile("Resoureeses\\was.png");
					setts[3].setTexture(&WASD);
					sf::Texture arr;
					arr.loadFromFile("Resoureeses\\ARROS.png");
					setts[2].setTexture(&arr);
					setts[2].drawTo(appWindow);
					setts[3].drawTo(appWindow);
					appWindow.display();
				}
				else if (setts[4].isMouseOver(appWindow))
				{
					Exit(appWindow, true);
				}
				break;
			}
		}
	return false;
}
void Exit(sf::RenderWindow& window, bool Menu)
{
	settings = false;
	MainMenuBool = true;
	CreateWind(window);
}
int CreateWind(sf::RenderWindow& appWindow)
{
	appWindow.clear();
	sf::Music music;
	music.openFromFile("Resoureeses\\mains.ogg");
	music.play();
	music.setLoop(true);
	while (appWindow.isOpen()) {
		sf::Event Event;
		//Event Loop:
		if (appWindow.pollEvent(Event)) {
			switch (Event.type) {

			case sf::Event::Closed:
				appWindow.close();
			case sf::Event::MouseMoved:

				break;
			case sf::Event::MouseButtonReleased:
				if (MainMenuBool && gui[0].isMouseOver(appWindow)) {
					MainMenuBool = false;
					appWindow.clear();
					std::cout << "jfndk";
					GameStart(appWindow, lead, 0, MainMenuBool);
				}
				else if (MainMenuBool && gui[1].isMouseOver(appWindow)) {
					MainMenuBool = false;
					appWindow.clear();
					int vol = music.getVolume();
					setts = ButtonSettings(appWindow, setts);
					sf::Text t;
					t = text(appWindow, vol);
					settings = true;
					appWindow.display();
					while (settings)
					{
						setting(settings, appWindow, music, setts, t);
					}
				}
				break;
			}

			if (MainMenuBool)
			{
				ButtonDraw(appWindow, gui);

			}
			
		}
		appWindow.display();
	}
	return 0;
}
