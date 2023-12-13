#pragma once
#include "Button.h"
#include "Object.h"
#include "Pacman.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
int CreateWind(sf::RenderWindow& appWindow);//window creation
std::vector<Button> ButtonDraw(sf::RenderWindow& appWindow, std::vector<Button>& vect);
bool GameStart(sf::RenderWindow& window, bool lead, int sett, bool MainMenuBool);
std::vector<Button> ButtonSettings(sf::RenderWindow& appWindow, std::vector<Button> bb);
void MusicVolume(sf::Music &musc, Button Plus, Button Minus, sf::RenderWindow& window);
Button ButtonGame(sf::RenderWindow& appWindow);
void WallDraw(sf::Vector2f vector, sf::RenderWindow &window);
void PointDraw(sf::Vector2f vector, sf::RenderWindow& window);
void SuperPointDraw(sf::Vector2f vector, sf::RenderWindow& window);
bool Construct(sf::RenderWindow& window, int lev, int sett);
void getIJVect(sf::Vector2f vect);
bool MoveCh(int num);
void ArroMove(sf::RenderWindow& window, int lev, bool lead, bool MainMenuBool);
void WASDmove(sf::RenderWindow& window, int lev, bool lead, bool MainMenuBool);
void SetCords(int b, int c);
void buttons(sf::RenderWindow& window);
void StopGameChoise(bool statement, sf::RenderWindow& window, bool lead, bool Menu);
int Levels(int lvl, int i, int j);
void GetLevel(int lev, sf::RenderWindow &window);
void LevUpdate();
sf::Text text(sf::RenderWindow& appWindow, int volume);
void Exit(sf::RenderWindow& appWindow, bool menu);
