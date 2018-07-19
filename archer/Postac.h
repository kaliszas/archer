/*
 * Postac.h
 *
 *  Created on: 18.07.2018
 *      Author: Damian
 */

#ifndef POSTAC_H_
#define POSTAC_H_

#include "Animacje.h"

class Postac {
public:
	Postac();
	virtual ~Postac();
	void rysuj(sf::RenderWindow &win);
	void resetZycia();
	int sprawdzIleZycia();
	int sprawdzObrazenia();
	int sprawdzTryb();
	virtual void ruch(bool czyLewo)=0;
	virtual void nazwaTekstury()=0;

	void ustawObrazenia(int naIle);
	void zran(int oIle);
	void ustawTryb(int opcja);
	void pozStartowa(int x, int y);
	bool zniszcz();
	bool wykryjKolizje(Postac &po);

protected:
	Animacje animacje;
	bool zadajObrazenia;
	enum {ZWYKLY, ATAK, SMIERC} tryb;

	void animuj();

private:
	int zycie;
    int maxHp;
    int obrazenia;
    int limitKlatki;
};

#endif /* POSTAC_H_ */
