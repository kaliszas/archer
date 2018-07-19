#ifndef ANIMACJE_H
#define ANIMACJE_H

#include <iostream>

#include <SFML/Graphics.hpp>

class Animacje
{
	int aktualnaKlatka;
	float czasKlatkaRuch, czasKlatkaAtak, czasKlatkaSmierc;

	sf::Texture zwykla, atak, smierc;
	sf::Sprite postac;
	sf::Vector2f k1,k2,k3;
	sf::Clock zegarKlatki;

	void aktualizujKlatke(int szerokosc, int wysokosc);

public:
	Animacje();
    void nastepnaKlatka();
    void resetKlatki();
    void wczytajKlatke(int tryb);
    void wczytajTekstury(std::string sciezkaRuch, std::string sciezkaAtak, std::string sciezkaSmierc);
    void rysuj(sf::RenderWindow &win);
	void pozycjaStartowa(int x, int y);
	void ustawCzasTrwania(int tryb, float czas);
	void resetujZegar();
	void wybierzWielkoscKlatek(int opcja);
	void ruch(bool czyLewo, int ile);
	void odwrocKlatke(bool czyLewo);
	int sprawdzAktualnaKlatke();
	float sprawdzZegarKlatki();
	float sprawdzCzasTrawnia(int tryb);
	sf::FloatRect boundingbox();
};


#endif //ANIMACJE_H
