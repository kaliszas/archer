#include "Mechanika_gry.h"

Mechanika_gry::Mechanika_gry(Gracz &player): gracz(player), komputer(wrogowie, sojusznicy)
{
	idzPrawo=idzLewo=naciagajStrzale=wypuscStrzale=0;
	wygrana=przegrana=0;
}

void Mechanika_gry::spawn(sf::RenderWindow &win)
{
    bool temp=rand()%2;
    //int temp1=(rand()%60)+100;
    if(temp)
    	komputer.stworzBota(win, 0, 0); //sojusznik
    else
    	komputer.stworzBota(win, 1, 0); // wrog
}

void Mechanika_gry::sekwencjaKomputera()
{
	komputer.animujKomputer();
	komputer.kolizje(gracz);
	komputer.smierc();
}

void Mechanika_gry::zadajObrazenia(Gracz &kto, Gracz &komu)
{
	komu.zran(kto.sprawdzObrazenia());
}

void Mechanika_gry::obslugujNacisniecia(sf::Event &eve)
{
	if(eve.key.code == sf::Keyboard::A || eve.key.code == sf::Keyboard::Left)
		idzLewo=1;
	if(eve.key.code == sf::Keyboard::D || eve.key.code == sf::Keyboard::Right)
		idzPrawo=1;
}

void Mechanika_gry::obslugujZwolnienia(sf::Event &eve)
{
	if(eve.key.code == sf::Keyboard::A || eve.key.code == sf::Keyboard::Left)
		idzLewo=0;
	if(eve.key.code == sf::Keyboard::D || eve.key.code == sf::Keyboard::Right)
		idzPrawo=0;
}

void Mechanika_gry::rysuj(sf::RenderWindow &win)
{
	gracz.rysuj(win);
	komputer.rysuj(win);
}

void Mechanika_gry::sterowanie()
{
    if(idzPrawo)
        gracz.ruch(0);
    else if(idzLewo)
        gracz.ruch(1);
}

bool Mechanika_gry::czyWygrana()
{
	return wygrana;
}

bool Mechanika_gry::czyPrzegrana()
{
	return przegrana;
}


