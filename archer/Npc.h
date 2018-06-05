#ifndef NPC_H
#define NPC_H

#include "Gracz.h"

class Npc: public Gracz
{
    public:
        Npc(bool czySoj, bool czyWielki);
        ~Npc();
        void nazwaTekstury();
        void ruch(bool czyLewo);
        bool sprawdzCzyGigant();
        bool sprawdzCzySojusznik();
        bool czyObrazenia();

    protected:

    private:
        const bool czySojusznik;
        const bool czyGigant;
};

#endif // NPC_H
