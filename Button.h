// Made by Ben Bollinger

#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class Button {
public:
	Button(sf::Vector2f buttonSize, int charSize, sf::Texture *texture) {
		button.setSize(buttonSize);
		button.setTexture(texture);
		// Get these for later use:
		btnWidth = buttonSize.x;
		btnHeight = buttonSize.y;
	}

	void setBackColor(sf::Color color) {
		button.setFillColor(color);
	}

	void setPosition(sf::Vector2f point) {
		button.setPosition(point);

		// Center text on button:
		float xPos = (point.x + btnWidth / 2);
		float yPos = (point.y + btnHeight / 2.2);
	}
	void setTexture(sf::Texture* texture)
	{
		button.setTexture(texture);
	}
	void drawTo(sf::RenderWindow& window) {
		window.draw(button);
	}
	bool isMouseOver(sf::RenderWindow& window) {
		int mouseX = sf::Mouse::getPosition(window).x;
		int mouseY = sf::Mouse::getPosition(window).y;

		int btnPosX = button.getPosition().x;
		int btnPosY = button.getPosition().y;

		int btnxPosWidth = button.getPosition().x + btnWidth;
		int btnyPosHeight = button.getPosition().y + btnHeight;

		if (mouseX < btnxPosWidth && mouseX > btnPosX && mouseY < btnyPosHeight && mouseY > btnPosY) {
			return true;
		}
		return false;
	}
private:
	sf::RectangleShape button;
	sf::Texture texture;
	int btnWidth;
	int btnHeight;
};

