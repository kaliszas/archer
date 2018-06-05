#include "Gracz.h"

Gracz::Gracz()
{
    zycie=120;
    ustawObrazenia(40);
    limitKlatki=4;
    tryb=ZWYKLY;
    animacje.wybierzWielkoscKlatek(0);
    nazwaTekstury();
    animacje.wczytajKlatke(tryb);
}

Gracz::~Gracz()
{

}

void Gracz::resetZycia()
{
    zycie=120;
}

void Gracz::ustawObrazenia(int naIle)
{
    obrazenia=naIle;
}

bool Gracz::zniszcz()
{
	if(tryb==SMIERC)
	{
		if(animacje.sprawdzAktualnaKlatke()==limitKlatki)
			return 1;
	}
	return 0;
}

bool Gracz::wykryjKolizje(Gracz &gr)
{
	if(this->animacje.boundingbox().intersects(gr.animacje.boundingbox()))
		return 1;
	return 0;
}

void Gracz::zran(int oIle)
{
	zycie-=oIle;
}

void Gracz::ustawTryb(int opcja)
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

void Gracz::pozStartowa(int x, int y)
{
	animacje.pozycjaStartowa(x, y);
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

void Gracz::animuj()
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

void Gracz::nazwaTekstury()
{
	std::string tek="tekstury/";
	std::string zwykly="bohaterszablon.png";
	std::string atak="lucznikszablon.png";
	std::string smierc="bohaterszablon.png";
	animacje.wczytajTekstury(tek+zwykly, tek+atak, tek+smierc);
}

void Gracz::rysuj(sf::RenderWindow &win)
{
	animacje.rysuj(win);
}

int Gracz::sprawdzIleZycia()
{
    return zycie;
}

int Gracz::sprawdzObrazenia()
{
    return obrazenia;
}

int Gracz::sprawdzTryb()
{
    return tryb;
}



