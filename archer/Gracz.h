#ifndef GRACZ_H
#define GRACZ_H

#include <iostream>
#include <SFML/Graphics.hpp>

#include "Animacje.h"


class Gracz
{
    public:
        Gracz();
        virtual ~Gracz();
        void resetZycia();
        void ustawObrazenia(int naIle);
        void zran(int oIle);
        void ustawTryb(int opcja);
        void pozStartowa(int x, int y);
        virtual void ruch(bool czyLewo);
        void animuj();
        virtual void nazwaTekstury();
        void rysuj(sf::RenderWindow &win);
        bool zniszcz();
        bool wykryjKolizje(Gracz &gr);
        int sprawdzIleZycia();
        int sprawdzObrazenia();
        int sprawdzTryb();

        sf::FloatRect boundingbox();
    protected:

        Animacje animacje;
        bool zadajObrazenia;
        enum {ZWYKLY, ATAK, SMIERC} tryb;

    private:
        int zycie;
        int obrazenia;
        int limitKlatki;

};

#endif // GRACZ_H
