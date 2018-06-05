#ifndef GRA_H
#define GRA_H

#include <iostream>
#include <sstream>

#include "Tryby.h"
#include "Mechanika_gry.h"
#include "Komputer.h"
#include "Npc.h"
#include "Gracz.h"

class Gra: public Tryby
{
    public:
        Gra();
        void Inicjalizuj(sf::RenderWindow &win);
        void Aktualizuj(sf::RenderWindow &win);
        void Wyswietlaj(sf::RenderWindow &win);
        void obslugaZdarzen(sf::RenderWindow &win, sf::Event &event);

    protected:

    private:
        Gracz gracz;
        Mechanika_gry silnik;
        bool poczatek, pauza, koniec;
        bool przegrana,wygrana;
        int poziom, pieniadze;

        sf::Font font;
        sf::Text mamona, napis;
        sf::Texture ziele, moneta;
        sf::Sprite trawka, pieniazek;
        sf::RectangleShape konturZdrowia, zdrowie;

        //void sterowanie();
        void resetGracza(sf::RenderWindow &win);
        void liczPieniazki();
        void parametryPieniazki(sf::RenderWindow &win);
        void parametryZdrowia();
        void parametryNapisow(sf::RenderWindow &win);
        void aktualizujPasekZdrowia();
};

#endif // GRA_H
