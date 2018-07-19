/*
 * Tryby.h
 *
 *  Created on: 04.10.2017
 *      Author: Damian
 */

#ifndef TRYBY_H_
#define TRYBY_H_

#include <SFML/Graphics.hpp>

class Tryby {
public:
	Tryby();
	virtual ~Tryby();
	virtual void Inicjalizuj(sf::RenderWindow &win)=0;
	virtual void Aktualizuj(sf::RenderWindow &win)=0;
	virtual void Wyswietlaj(sf::RenderWindow &win)=0;
	virtual void obslugaZdarzen(sf::RenderWindow &win, sf::Event &event)=0;
};

#endif /* TRYBY_H_ */
