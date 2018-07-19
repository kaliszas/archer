/*
 * Manager.h
 *
 *  Created on: 04.10.2017
 *      Author: Damian
 */

#ifndef MANAGER_H_
#define MANAGER_H_

#include <vector>

#include "Tryby.h"
//#include "Menu.h"
#include "Gra.h"

class Manager {
	std::vector <Tryby*> stany;
	int obecnyStan;

	enum {MENU, GRA, SKLEP, KONIEC} state;

public:
	Manager(Gra &gr);
	void zmienStan(int zmiana);
	void zarzadzaj(sf::RenderWindow &win);
	void zdarzenia(sf::RenderWindow &win, sf::Event &event);
};

#endif /* MANAGER_H_ */
