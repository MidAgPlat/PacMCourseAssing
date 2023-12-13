#include "Button.h"
#include <SFML/Audio.hpp>


std::vector<Button> ButtonDraw(sf::RenderWindow& appWindow, std::vector<Button>& vect)
{
	sf::Texture startSprite;
	startSprite.loadFromFile("Resoureeses\\bStart.png");
	Button start({ 250, 150 }, 30, &startSprite);
	start.setPosition({ 350, 150 });
	sf::Texture settingsSprite;
	settingsSprite.loadFromFile("Resoureeses\\bSettings.png");
	Button settings({ 250, 150 }, 30, &settingsSprite);
	settings.setPosition({ 350, 350 });
	vect.push_back(start);
	vect.push_back(settings);
	start.drawTo(appWindow);
	settings.drawTo(appWindow);
	return vect;
}

std::vector<Button> ButtonSettings(sf::RenderWindow& appWindow, std::vector<Button> bb)
{
	sf::Texture soundUpSprite;
	soundUpSprite.loadFromFile("Resoureeses\\Plus.png");
	Button sUp({ 150, 150 }, 30, &soundUpSprite);
	sUp.setPosition({ 550, 450 });
	sf::Texture soundDownSprite;
	soundDownSprite.loadFromFile("Resoureeses\\Minus.png");
	Button sDown({ 150, 150 }, 30, &soundDownSprite);
	sDown.setPosition({ 250, 450 });
	sf::Texture WASD;
	WASD.loadFromFile("Resoureeses\\WASD.png");
	Button wasd({ 250, 150 }, 30, &WASD);
	wasd.setPosition({ 500, 150 });
	sf::Texture ARROS;
	ARROS.loadFromFile("Resoureeses\\arro.png");
	Button arros({ 250, 150 }, 30, &ARROS);
	arros.setPosition({ 200, 150 });
	sf::Texture stopS;
	stopS.loadFromFile("Resoureeses\\Resume.png");
	Button stop({ 100, 100 }, 30, &stopS);
	stop.setPosition({ 750, 800 });
	stop.drawTo(appWindow);
	sUp.drawTo(appWindow);
	sDown.drawTo(appWindow);
	arros.drawTo(appWindow);
	wasd.drawTo(appWindow);
	bb.push_back(sUp);
	bb.push_back(sDown);
	bb.push_back(arros);
	bb.push_back(wasd);
	bb.push_back(stop);
	return bb;

}

sf::Text text(sf::RenderWindow& appWindow, int volume)
{
	std::string vol = std::to_string(volume);
	sf::Font font;
	font.loadFromFile("Resoureeses\\arial\\arial.ttf");
	sf::Text text(vol, font);
	text.setCharacterSize(30);
	text.setStyle(sf::Text::Bold);
	text.setFillColor(sf::Color::White);
	text.setPosition({ 450, 450 });
	appWindow.draw(text);
	return text;
}
Button ButtonGame(sf::RenderWindow& appWindow)
{
	sf::Texture stopS;
	stopS.loadFromFile("Resoureeses\\Resume.png");
	Button stop({ 100, 100 }, 30, &stopS);
	stop.setPosition({ 750, 50 });
	stop.drawTo(appWindow);
	return stop;
}

