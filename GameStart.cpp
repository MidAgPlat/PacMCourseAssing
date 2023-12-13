#include <SFML/Graphics.hpp>
#include "AttachmentsOne.h"
int lev = 1;
bool GameStart(sf::RenderWindow& window, bool lead, int sett, bool MainMenuBool) {
	while (Construct(window, lev, sett))
	{
		if (lead)
		{
			WASDmove(window,lev, lead, MainMenuBool);
		}
		else
		{
			ArroMove(window,lev,lead, MainMenuBool);
		}
	}
	return true;
}