#ifndef KOMPUTER_H
#define KOMPUTER_H

#include <vector>

#include "Npc.h"
#include "Gracz.h"

class Komputer
{
    public:
        Komputer(std::vector <Npc*> &enemies, std::vector <Npc*> &friends);
        void animujKomputer();
        void stworzBota(sf::RenderWindow &win, bool czySoj, bool czyGigant);
        void kolizje(Gracz &gr);
        void smierc();
        void rysuj(sf::RenderWindow &win);

    protected:

    private:
        std::vector <Npc*> &wrogowie;
        std::vector <Npc*> &sojusznicy;

        void petlaZmianyTrybu(Npc &bot1, std::vector <Npc*> &boty2);
        unsigned int jednaPetla(); // sprawdz ktory kontener jest wiekszy

};

#endif // ANIMACJE_H
