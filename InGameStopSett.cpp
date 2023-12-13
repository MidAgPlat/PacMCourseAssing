#include "AttachmentsOne.h"

std::vector <Button> butt;
void buttons(sf::RenderWindow& window)
{
	sf::Texture Again;
	Again.loadFromFile("Resoureeses\\Again.png");
	Button agai({ 100,100 }, 30, &Again);
	agai.setPosition({ 300, 450 });
	sf::Texture Resume;
	Resume.loadFromFile("Resoureeses\\Resume.png");
	Button res({ 100, 100 }, 30, &Resume);
	res.setPosition({ 450, 450 });
	sf::Texture Exit;
	Exit.loadFromFile("Resoureeses\\Exit.png");
	Button ex({ 100,100 }, 30, &Exit);
	ex.setPosition({ 600, 450 });
	ex.drawTo(window);
	res.drawTo(window);
	agai.drawTo(window);
	butt.push_back(ex);
	butt.push_back(res);
	butt.push_back(agai);
	window.display();
}
void StopGameChoise(bool statement, sf::RenderWindow& window, bool lead, bool Menu)
{
	while (!statement)
	{
		sf::Event event;
		if (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
			case sf::Event::MouseButtonReleased:
				if (butt[1].isMouseOver(window)) {
					GameStart(window, lead, 1, Menu);
				}
				else if (butt[0].isMouseOver(window))
				{
					Exit(window, Menu);
				}
				else if (butt[2].isMouseOver(window))
				{
					GameStart(window, lead, 0, Menu);
				}
				break;
			}
		}
	}

}