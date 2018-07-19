#ifndef NPC_H
#define NPC_H

#include "Postac.h"

class Npc: public Postac
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
