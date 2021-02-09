#pragma once
#include <SFML\Graphics.hpp>
#define Max_main_menu 3

class MenuPrincipal {
	public:
		MenuPrincipal(float width, float hight);

		void draw(sf::RenderWindow &window);
		void moveUp();
		void moveDown();

		~MenuPrincipal();
	private:
		int mainMenuSelected;
		sf::Font font;
		sf::Text mainMenu[Max_main_menu];
};		