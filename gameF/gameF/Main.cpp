#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Main_menu.h"
#include "Engine.h"

using namespace std;

int page_number;

int main()
{
	while (true)
	{
		sf::RenderWindow window(sf::VideoMode(600, 600), "SFML_Main_menu");

		sf::Music music1;
		if (!music1.openFromFile("menu_s.ogg")){}
		
		sf::Music music2;
		if (!music2.openFromFile("doom_map.ogg")){}

		Main_menu menu(600, 600);

		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					window.close();
				}
				if (event.type == sf::Event::KeyReleased)
				{
					music1.play();
					if (event.key.code == sf::Keyboard::Up)
					{
						menu.moveUp();
						break;
					}
					if (event.key.code == sf::Keyboard::Down)
					{
						menu.moveDown();
						break;
					}

					if (event.key.code == sf::Keyboard::Return)
					{
						int *x;
						
						if (menu.mainMenuPressed() == 0)
						{
							music2.play();
							window.close();
							page_number = 0;
						}
						if (menu.mainMenuPressed() == 1)
						{
							window.close();
							page_number = 1;
						}
						if (menu.mainMenuPressed() == 2)
						{
							window.close();
							page_number = 2;
						}
					}
				}
			}
			window.clear();
			menu.draw(window);
			window.display();
		}
		
		if (page_number == 0)  //Play
		{
			Engine::init();
			while (Engine::isRunning())
			{		
				Engine::handleEvents();
				Engine::render();
				music1.stop();
			}

			system("pause");
		}
		if (page_number == 1)  //Settings
		{
			sf::RenderWindow window_play(sf::VideoMode(600, 600), "Settings", sf::Style::Close);
			while (window_play.isOpen())
			{
				sf::Event event;
				while (window_play.pollEvent(event))
				{
					if (event.type == sf::Event::Closed)
					{
						window_play.close();
					}
				}
				window_play.clear();
				window_play.display();
			}
		}
		if (page_number == 2)  //Exit
		{
			break;
		}
	}

	return 0;
}