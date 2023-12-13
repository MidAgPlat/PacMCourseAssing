#include "AttachmentsOne.h"
#include <SFML/Graphics.hpp>
int Lvl[12][12] = { {0,0,0,0,0,0,0,0,0,0,0,0},
					  {0,0,0,0,0,0,0,0,0,0,0,0},
					  {0,0,0,0,0,0,0,0,0,0,0,0},
					  {0,0,0,0,0,0,0,0,0,0,0,0},
					  {0,0,0,0,0,0,0,0,0,0,0,0},
					  {0,0,0,0,0,0,0,0,0,0,0,0},
					  {0,0,0,0,0,0,0,0,0,0,0,0},
					  {0,0,0,0,0,0,0,0,0,0,0,0},
					  {0,0,0,0,0,0,0,0,0,0,0,0},
					  {0,0,0,0,0,0,0,0,0,0,0,0},
					  {0,0,0,0,0,0,0,0,0,0,0,0},
					  {0,0,0,0,0,0,0,0,0,0,0,0} };
int PacI, PacJ;
std::vector<Pacman> pac;
int score = 0;
bool GameBool = true;
int levell = 1;
void LevUpdate()
{
	Lvl[0][0] = 0;
}
void GetLevel(int lev, sf::RenderWindow& window)
{
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			Lvl[i][j] = Levels(lev, i, j);
		}
	}
}
void SetCords(int b, int c)
{
	PacI = b;
	PacJ = c;
}
Pacman PacmanDraw(sf::Vector2f vector, sf::RenderWindow& window)
{
	sf::Texture PacSprite;
	PacSprite.loadFromFile("Resoureeses\\Pacman.png");
	Pacman pacman({ 50,50 }, &PacSprite);
	sf::Vector2f placement{ 100, 100 };
	pacman.setPosition(vector);
	pacman.drawTo(window);
	return pacman;
}
void Do(sf::Vector2f vect, sf::RenderWindow &window)
{
	
}
bool Construct(sf::RenderWindow &window, int lev, int sett)
{
	GameBool = true;
	if (sett == 0)
	{
		GetLevel(lev, window);
		sett = 1;
	}
	if (score == 9500)
	{
		if (lev == 3)
		{
			Exit(window, true);
		}
		GetLevel(lev + 1, window);
		score = 0;
		sett = 1;
	}
	std::string sc = std::to_string(score);
	sf::Font font;
	font.loadFromFile("Resoureeses\\arial\\arial.ttf");
	sf::Text text(sc, font);
	text.setCharacterSize(30);
	text.setStyle(sf::Text::Bold);
	text.setFillColor(sf::Color::White);
	text.setPosition({ 750, 450 });
	window.draw(text);
	ButtonGame(window);
	sf::Vector2f placement{ 100, 100 };
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			int ch = Lvl[i][j];
			switch (ch)
			{
				case 0:
					break;
				case 1:
					WallDraw(placement, window);
					break;
				case 2:
					PointDraw(placement, window);
					break;
				case 3:
					SuperPointDraw(placement, window);
					break;
				case 4:
					PacmanDraw(placement, window);
					getIJVect(placement);
					SetCords(i, j);
					Lvl[i][j] = 0;
					break;
			}
			placement.x += 50;
		}
		placement.y += 50;
		placement.x = 100;
	}
	window.display();
	return true;
}

void WASDmove(sf::RenderWindow& window, int lev, bool lead, bool MainMenuBool)
{
	while (true)
	{

		sf::Event Event;
		//Event Loop:
		if (window.pollEvent(Event)) {
			switch (Event.type) {

			case sf::Event::Closed:
				window.close();
			case sf::Event::MouseButtonReleased:
				if (GameBool && ButtonGame(window).isMouseOver(window)) {
					GameBool = false;
					window.clear();
					buttons(window);
					StopGameChoise(GameBool, window, lead, MainMenuBool);
				}
				break;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			{
				if (MoveCh(Lvl[PacI-1][PacJ]))
				{
					if (Lvl[PacI - 1][PacJ] == 2)
					{
						score += 150;
					}
					else if (Lvl[PacI - 1][PacJ] == 3)
					{
						score += 500;
					}
					Lvl[PacI][PacJ] = 0;
					Lvl[PacI - 1][PacJ] = 4;
					SetCords(PacI - 1, PacJ);
					
					window.clear();
					Construct(window,lev,1);
				}
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				
				if (MoveCh(Lvl[PacI][PacJ-1]))
				{
					if (Lvl[PacI][PacJ-1] == 2)
					{
						score += 150;
					}
					else if (Lvl[PacI][PacJ - 1] == 3)
					{
						score += 500;
					}
					Lvl[PacI][PacJ] = 0;
					Lvl[PacI][PacJ-1] = 4;
					SetCords(PacI, PacJ-1);
					window.clear();
					Construct(window,lev,1);
				}
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
				
				if (MoveCh(Lvl[PacI + 1][PacJ]))
				{
					if (Lvl[PacI + 1][PacJ] == 2)
					{
						score += 150;
					}
					else if (Lvl[PacI + 1][PacJ] == 3)
					{
						score += 500;
					}
					Lvl[PacI][PacJ] = 0;
					Lvl[PacI + 1][PacJ] = 4;
					SetCords(PacI + 1, PacJ);
					window.clear();
					Construct(window,lev,1);
				}
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{

				if (MoveCh(Lvl[PacI][PacJ+1]))
				{
					if (Lvl[PacI][PacJ+1] == 2)
					{
						score += 150;
					}
					else if (Lvl[PacI][PacJ+1] == 3)
					{
						score += 500;
					}
					Lvl[PacI][PacJ] = 0;
					Lvl[PacI][PacJ+1] = 4;
					SetCords(PacI, PacJ+1);
					window.clear();
					Construct(window,lev,1);
				}
			}

		}
	}
}
void ArroMove(sf::RenderWindow& window, int lev, bool lead, bool MainMenuBool)
{
	while (true)
	{

		sf::Event Event;
		//Event Loop:
		if (window.pollEvent(Event)) {
			switch (Event.type) {

			case sf::Event::Closed:
				window.close();
			case sf::Event::MouseButtonReleased:
				if (GameBool && ButtonGame(window).isMouseOver(window)) {
					GameBool = false;
					buttons(window);
					StopGameChoise(GameBool, window, lead, MainMenuBool);
				}
				break;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				if (MoveCh(Lvl[PacI - 1][PacJ]))
				{
					if (Lvl[PacI - 1][PacJ] == 2)
					{
						score += 150;
					}
					else if (Lvl[PacI - 1][PacJ] == 3)
					{
						score += 500;
					}
					Lvl[PacI][PacJ] = 0;
					Lvl[PacI - 1][PacJ] = 4;
					SetCords(PacI - 1, PacJ);

					window.clear();
					Construct(window,lev,1);
				}
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{

				if (MoveCh(Lvl[PacI][PacJ - 1]))
				{
					if (Lvl[PacI][PacJ - 1] == 2)
					{
						score += 150;
					}
					else if (Lvl[PacI][PacJ - 1] == 3)
					{
						score += 500;
					}
					Lvl[PacI][PacJ] = 0;
					Lvl[PacI][PacJ - 1] = 4;
					SetCords(PacI, PacJ - 1);
					window.clear();
					Construct(window,lev,1);
				}
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{

				if (MoveCh(Lvl[PacI + 1][PacJ]))
				{
					if (Lvl[PacI + 1][PacJ] == 2)
					{
						score += 150;
					}
					else if (Lvl[PacI + 1][PacJ] == 3)
					{
						score += 500;
					}
					Lvl[PacI][PacJ] = 0;
					Lvl[PacI + 1][PacJ] = 4;
					SetCords(PacI + 1, PacJ);
					window.clear();
					Construct(window,lev,1);
				}
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{

				if (MoveCh(Lvl[PacI][PacJ + 1]))
				{
					if (Lvl[PacI][PacJ + 1] == 2)
					{
						score += 150;
					}
					else if (Lvl[PacI][PacJ + 1] == 3)
					{
						score += 500;
					}
					Lvl[PacI][PacJ] = 0;
					Lvl[PacI][PacJ + 1] = 4;
					SetCords(PacI, PacJ + 1);
					window.clear();
					Construct(window,lev,1);
				}
			}
		}
	}
} 