#ifndef GRACZ_H
#define GRACZ_H

#include <iostream>
#include <SFML/Graphics.hpp>

#include "Postac.h"


class Gracz: public Postac
{
    public:
        Gracz();
        ~Gracz();
        void ruch(bool czyLewo);
        void nazwaTekstury();


        sf::FloatRect boundingbox();
};

#endif // GRACZ_H
