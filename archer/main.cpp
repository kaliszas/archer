
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/VideoMode.hpp>

#include <cstdlib>

#include "Manager.h"
#include "Gra.h"
//#include "Menu.h"
//#include "Sklep.h"

int main()
{
	enum {MENU, GRA, SKLEP, KONIEC};

	srand(time(NULL));
	sf::RenderWindow window(sf::VideoMode(1000, 700), "ARCHER");//, sf::Style::Fullscreen);
	sf::Event event;
	window.setFramerateLimit(60);

	//Sklep sklep;
	//Menu menu;
	Gra game;
	Manager mgr(game);

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
            mgr.zdarzenia(window, event);
		}

		window.clear(sf::Color(60,180,220));
        mgr.zarzadzaj(window);

		window.display();
	}


	return 0;
}



