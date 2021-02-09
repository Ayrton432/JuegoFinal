#include "MenúPrincipal.h"

MenuPrincipal::MenuPrincipal(float width, float hight)
{
	if (!font.loadFromFile("04B_30__.ttf")){}

	mainMenu[0].setFont(font);
	mainMenu[0].setColor(sf::Color::Blue);
	mainMenu[0].setString("Play");
	mainMenu[0].setCharacterSize(50);
	mainMenu[0].setPosition(sf::Vector2f(width / 2 - 50, hight / (Max_main_menu + 1)));

	mainMenu[1].setFont(font);
	mainMenu[1].setColor(sf::Color::White);
	mainMenu[1].setString("Options");
	mainMenu[1].setCharacterSize(50);
	mainMenu[1].setPosition(sf::Vector2f(width / 2 - 50, hight / (Max_main_menu + 1) * 2));

	mainMenu[2].setFont(font);
	mainMenu[2].setColor(sf::Color::Blue);
	mainMenu[2].setString("Exit");
	mainMenu[2].setCharacterSize(50);
	mainMenu[2].setPosition(sf::Vector2f(width / 2 - 50, hight / (Max_main_menu + 1) * 3));

	mainMenuSelected = 0;
}

MenuPrincipal::MenuPrincipal()
{

}

void MenuPrincipal::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < 3; i++)
	{
		window.draw(mainMenu[i]);
	}
}

void MenuPrincipal::moveDown()
{
	if (mainMenuSelected + 1 <= Max_main_menu)
	{
		mainMenu[mainMenuSelected].setColor(sf::Color::White);

		mainMenuSelected++;
		if (mainMenuSelected == 3)
		{
			mainMenuSelected = 0;
		}
		mainMenu[mainMenuSelected].setColor(sf::Color::Blue);
	}
}

void MenuPrincipal::moveUp()
{
	if (mainMenuSelected - 1 >= -1)
	{
		mainMenu[mainMenuSelected].setColor(sf::Color::White);

		mainMenuSelected--;
		if (mainMenuSelected == -1)
		{
			mainMenuSelected = 2;
		}
		mainMenu[mainMenuSelected].setColor(sf::Color::Blue);
	}