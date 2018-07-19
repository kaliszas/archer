#include "Npc.h"

Npc::Npc(bool czySoj, bool czyWielki): czySojusznik(czySoj), czyGigant(czyWielki)
{
	zadajObrazenia=1;
    if(czyGigant)
    {
        ustawObrazenia(72);
        zran(-100);
        animacje.wybierzWielkoscKlatek(2);
    }
    else
        animacje.wybierzWielkoscKlatek(1);
    nazwaTekstury();
    animacje.ustawCzasTrwania(ATAK, 0.2);
}

Npc::~Npc()
{

}

void Npc::nazwaTekstury()
{
	std::string tek="tekstury/";
	std::string zwykly,atak,smierc;
    if(czySojusznik)
    {
        if(czyGigant)
        {
        	zwykly="Gigasojusznikszablon.png";
			atak="GigasojAtakSzablon.png";
        	smierc="gigaSojSmiercSzablon.png";
        }
        else
        {
        	zwykly="sojusznikszablon.png";
			atak="sojAtakSzablon.png";
			smierc="sojSmiercSzablon.png";
        }
    }
    else
    {
        if(czyGigant)
		{
			zwykly="Gigawrogszablon.png";
			atak="GigawrogAtakSzablon.png";
			smierc="gigaWrogSmiercSzablon.png";
		}
        else
        {
        	zwykly="wrogszablon.png";
			atak="wrogAtakSzablon.png";
			smierc="wrogSmiercSzablon.png";
        }
    }
    animacje.wczytajTekstury(tek+zwykly, tek+atak, tek+smierc);
}

void Npc::ruch(bool czyLewo)
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
	animacje.ruch(czyLewo, ile);
}

bool Npc::sprawdzCzyGigant()
{
    return czyGigant;
}

bool Npc::sprawdzCzySojusznik()
{
    return czySojusznik;
}

bool Npc::czyObrazenia()
{
	if(zadajObrazenia && tryb==ATAK && animacje.sprawdzAktualnaKlatke()==5)
	{
		zadajObrazenia=0;
		return 1;
	}
	return 0;
}


