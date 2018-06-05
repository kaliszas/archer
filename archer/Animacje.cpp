#include "Animacje.h"

Animacje::Animacje()
{
	aktualnaKlatka=0;
	czasKlatkaRuch=czasKlatkaAtak=czasKlatkaSmierc=0.3;
	k1=sf::Vector2f();
	k2=sf::Vector2f();
	k3=sf::Vector2f();
}


void Animacje::nastepnaKlatka()
{
    aktualnaKlatka++;
}

void Animacje::resetKlatki()
{
    aktualnaKlatka=0;
}

void Animacje::aktualizujKlatke(int szerokosc, int wysokosc)
{
    postac.setTextureRect(sf::IntRect(aktualnaKlatka*szerokosc,0,szerokosc,wysokosc));
    postac.setOrigin(postac.getGlobalBounds().width/2, postac.getGlobalBounds().height/2);
}

void Animacje::odwrocKlatke(bool czyLewo)
{
    if(czyLewo)
        postac.setScale(sf::Vector2f(-1,1));
    else
        postac.setScale(sf::Vector2f(1,1));
}

void Animacje::wczytajKlatke(int tryb)
{
    switch(tryb)
    {
    case 0:
    	postac.setTexture(zwykla);
        aktualizujKlatke(k1.x, k1.y);
        break;
    case 1:
    	postac.setTexture(atak);
        aktualizujKlatke(k2.x, k2.y);
        break;
    case 2:
    	postac.setTexture(smierc);
        aktualizujKlatke(k3.x, k3.y);
        break;
    default:
        break;
    }
}

void Animacje::wybierzWielkoscKlatek(int opcja)
{
	switch(opcja)
	{
	case 0: //gracz
		k1=sf::Vector2f(75,156);
		k2=sf::Vector2f(105,156);
		k3=sf::Vector2f(105,156);
		break;
	case 1: // maly
		k1=sf::Vector2f(112,198);
		k2=sf::Vector2f(130,198);
		k3=sf::Vector2f(165,198);
		break;
	case 2: // gigant
		k1=sf::Vector2f(189,298);
		k2=sf::Vector2f(195,298);
		k3=sf::Vector2f(250,298);
		break;

	}
}

int Animacje::sprawdzAktualnaKlatke()
{
    return aktualnaKlatka;
}

sf::FloatRect Animacje::boundingbox()
{
    sf::FloatRect temp=postac.getGlobalBounds();
    temp.width=postac.getGlobalBounds().width/3;
    return temp;
}

void Animacje::wczytajTekstury(std::string sciezkaRuch, std::string sciezkaAtak, std::string sciezkaSmierc)
{
    zwykla.loadFromFile(sciezkaRuch);
    atak.loadFromFile(sciezkaAtak);
    smierc.loadFromFile(sciezkaSmierc);
}

void Animacje::rysuj(sf::RenderWindow &win)
{
    win.draw(postac);
}

void Animacje::pozycjaStartowa(int x, int y)
{
    postac.setPosition(x, y);
}

void Animacje::ustawCzasTrwania(int tryb, float czas)
{
	switch(tryb)
	{
	case 0:
		czasKlatkaRuch=czas;
		break;
	case 1:
		czasKlatkaAtak=czas;
		break;
	case 2:
		czasKlatkaSmierc=czas;
		break;
	default:
		break;
	}
}

void Animacje::resetujZegar()
{
	zegarKlatki.restart();
}

void Animacje::ruch(bool czyLewo, int ile)
{
    if(czyLewo)
        postac.move(-ile,0);
    else
        postac.move(ile,0);
}

float Animacje::sprawdzZegarKlatki()
{
	return zegarKlatki.getElapsedTime().asSeconds();
}

float Animacje::sprawdzCzasTrawnia(int tryb)
{
	switch(tryb)
	{
	case 0:
		return czasKlatkaRuch;
	case 1:
		return czasKlatkaAtak;
	case 2:
		return czasKlatkaSmierc;
	default:
		return czasKlatkaSmierc;
	}
}
