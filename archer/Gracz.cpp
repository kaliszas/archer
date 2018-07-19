#include "Gracz.h"

Gracz::Gracz()
{
	ustawObrazenia(40);
    animacje.wybierzWielkoscKlatek(0);
    nazwaTekstury();
    animacje.wczytajKlatke(tryb);
}

Gracz::~Gracz()
{

}

void Gracz::ruch(bool czyLewo)
{
	int ile;
	switch(tryb)
	{
	case 0:
		ile=1;
		break;
	case 2:
		ile=-2;
		break;
	default:
		ile=0;
		break;
	}
	animuj();
	animacje.odwrocKlatke(czyLewo);
	animacje.ruch(czyLewo, ile);
}

void Gracz::nazwaTekstury()
{
	std::string tek="tekstury/";
	std::string zwykly="bohaterszablon.png";
	std::string atak="lucznikszablon.png";
	std::string smierc="bohaterszablon.png";
	animacje.wczytajTekstury(tek+zwykly, tek+atak, tek+smierc);
}





