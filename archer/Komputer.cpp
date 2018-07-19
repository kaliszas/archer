#include "Komputer.h"

Komputer::Komputer(std::vector <Npc*> &enemies, std::vector <Npc*> &friends):
                    wrogowie(enemies), sojusznicy(friends)
{

}

void Komputer::animujKomputer()
{
    for(unsigned int i=0; i<jednaPetla(); i++)
    {
        if(i<wrogowie.size())
            wrogowie[i]->ruch(1);
        if(i<sojusznicy.size())
            sojusznicy[i]->ruch(0);
    }
}

void Komputer::rysuj(sf::RenderWindow &win)
{
    for(unsigned int i=0; i<jednaPetla(); i++)
    {
        if(i<wrogowie.size())
            wrogowie[i]->rysuj(win);
        if(i<sojusznicy.size())
            sojusznicy[i]->rysuj(win);
    }
}

unsigned int Komputer::jednaPetla()
{
    if(wrogowie.size()>sojusznicy.size())
        return wrogowie.size();
    return sojusznicy.size();
}

void Komputer::stworzBota(sf::RenderWindow &win, bool czySoj, bool czyGigant)
{
	int wys=(rand()%60)+120;
	if(czySoj)
	{
		if(czyGigant)
			sojusznicy.push_back(new Npc(1,1));
		else
			sojusznicy.push_back(new Npc(1,0));
		sojusznicy[sojusznicy.size()-1]->pozStartowa(-100, win.getSize().y-wys);
	}
	else
	{
		if(czyGigant)
			wrogowie.push_back(new Npc(0,1));
		else
			wrogowie.push_back(new Npc(0,0));
		wrogowie[wrogowie.size()-1]->pozStartowa(win.getSize().x+100, win.getSize().y-wys);
	}
}

void Komputer::smierc()
{
    for(unsigned int i=0; i<jednaPetla(); i++)
    {
        if(i<wrogowie.size())
        {
            if(wrogowie[i]->sprawdzIleZycia()<=0)
            wrogowie[i]->ustawTryb(2);
            if(wrogowie[i]->zniszcz())
            	wrogowie.erase(wrogowie.begin()+i);
        }
        if(i<sojusznicy.size())
        {
            if(sojusznicy[i]->sprawdzIleZycia()<=0)
            sojusznicy[i]->ustawTryb(2);
            if(sojusznicy[i]->zniszcz())
            	sojusznicy.erase(sojusznicy.begin()+i);
        }
    }
}

void Komputer::kolizje(Gracz &gr)
{
	for(unsigned int i=0; i<jednaPetla(); ++i)
	{
		if(i<wrogowie.size())
		{
			if(wrogowie[i]->wykryjKolizje(gr))
			{
				wrogowie[i]->ustawTryb(1);
				if(wrogowie[i]->czyObrazenia())
					gr.zran(wrogowie[i]->sprawdzObrazenia());
			}
			else
				petlaZmianyTrybu(*wrogowie[i], sojusznicy);

		}
		if(i<sojusznicy.size())
			petlaZmianyTrybu(*sojusznicy[i], wrogowie);
	}
}

void Komputer::petlaZmianyTrybu(Npc &bot1, std::vector <Npc*> &boty2)
{
	for(unsigned int j=0; j<boty2.size(); ++j) // bug, nie wykona sie zmiana trybu na 0, jesli nie ma sojusznikow lub wrogow
	{
		if(bot1.wykryjKolizje(*boty2[j]))
		{
			bot1.ustawTryb(1);
			if(bot1.czyObrazenia())
				boty2[j]->zran(bot1.sprawdzObrazenia());
			break;
		}
		else
			bot1.ustawTryb(0);
	}
}

