#ifndef MECHANIKA_GRY_H
#define MECHANIKA_GRY_H

#include <vector>

#include "Npc.h"
#include "Gracz.h"
#include "Komputer.h"

class Mechanika_gry
{
    public:
        Mechanika_gry(Gracz &player);
        void spawn(sf::RenderWindow &win);
        void sekwencjaKomputera();
        void zadajObrazenia(Gracz &kto, Gracz &komu);
        void sterowanie();
        void zabij();
        void resetGracza(sf::RenderWindow &win);
        void obslugujNacisnieciaPrzycisk(sf::Event &eve);
        void obslugujNacisnieciaMysz(sf::Event &eve);
        void obslugujZwolnieniaPrzycisk(sf::Event &eve);
        void obslugujZwolnieniaMysz(sf::Event &eve);
        void rysuj(sf::RenderWindow &win);
        bool czyWygrana();
        bool czyPrzegrana();


    protected:

    private:
        Gracz &gracz;
        Komputer komputer;
        std::vector <Npc*> wrogowie;
        std::vector <Npc*> sojusznicy;
        bool idzLewo, idzPrawo, naciagajStrzale, wypuscStrzale;
        bool wygrana, przegrana;



};

#endif // MECHANIKA_GRY_H
