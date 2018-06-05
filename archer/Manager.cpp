/*
 * Manager.cpp
 *
 *  Created on: 04.10.2017
 *      Author: Damian
 */

#include "Manager.h"

Manager::Manager(Gra &gr)
{
	zmienStan(GRA);
	stany.push_back(new Gra);
	//stany.push_back(&me);
	stany.push_back(&gr);

}

void Manager::zmienStan(int zmiana)
{
	switch(zmiana)
	{
	case MENU:
		state=MENU;
		break;
	case GRA:
		state=GRA;
		break;
	case SKLEP:
		state=SKLEP;
		break;
	case KONIEC:
		state=KONIEC;
		break;
	default:
		state=MENU; // powrot do menu
		break;
	}
	obecnyStan=state;

}

void Manager::zarzadzaj(sf::RenderWindow &win)
{
	stany[obecnyStan]->Inicjalizuj(win);
	stany[obecnyStan]->Aktualizuj(win);
	stany[obecnyStan]->Wyswietlaj(win);
}

void Manager::zdarzenia(sf::RenderWindow &win, sf::Event &event)
{
	stany[obecnyStan]->obslugaZdarzen(win, event);
}
