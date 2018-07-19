/*
 * Postac.cpp
 *
 *  Created on: 18.07.2018
 *      Author: Damian
 */

#include "Postac.h"

Postac::Postac() {
	ustawObrazenia(0);
	maxHp=120;
	zycie=maxHp;
	limitKlatki=4;
	tryb=ZWYKLY;
}

Postac::~Postac()
{

}

void Postac::rysuj(sf::RenderWindow &win)
{
	animacje.rysuj(win);
}

int Postac::sprawdzIleZycia()
{
    return zycie;
}

int Postac::sprawdzObrazenia()
{
    return obrazenia;
}

int Postac::sprawdzTryb()
{
    return tryb;
}


void Postac::ustawObrazenia(int naIle)
{
    obrazenia=naIle;
}

void Postac::resetZycia()
{
	zycie=maxHp;
}

bool Postac::zniszcz()
{
	if(tryb==SMIERC)
	{
		if(animacje.sprawdzAktualnaKlatke()==limitKlatki)
			return 1;
	}
	return 0;
}

bool Postac::wykryjKolizje(Postac &po)
{
	if(this->animacje.boundingbox().intersects(po.animacje.boundingbox()))
		return 1;
	return 0;
}

void Postac::zran(int oIle)
{
	zycie-=oIle;
}

void Postac::ustawTryb(int opcja)
{
	if(opcja==tryb || tryb==SMIERC)
		return;
	animacje.resetKlatki();
    switch(opcja)
    {
    case ZWYKLY:
        tryb=ZWYKLY;
        limitKlatki=4;
        break;
    case ATAK:
        tryb=ATAK;
        limitKlatki=7;
        break;
    case SMIERC:
        tryb=SMIERC;
        limitKlatki=5;
        break;
    default:
    	tryb=ZWYKLY;
        limitKlatki=4;
        break;
    }
}

void Postac::pozStartowa(int x, int y)
{
	animacje.pozycjaStartowa(x, y);
}

void Postac::animuj()
{
	if(animacje.sprawdzAktualnaKlatke()== limitKlatki)
	{
		animacje.resetKlatki();
		zadajObrazenia=1;
	}
	if(animacje.sprawdzZegarKlatki()>animacje.sprawdzCzasTrawnia(tryb))
	{
		animacje.resetujZegar();
		animacje.wczytajKlatke(tryb);
		animacje.nastepnaKlatka();
	}
}
