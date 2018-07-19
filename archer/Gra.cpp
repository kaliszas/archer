#include "Gra.h"

Gra::Gra(): silnik(gracz)
{
    font.loadFromFile("tekstury/coopbl.ttf");
    ziele.loadFromFile("tekstury/grass.png");
    moneta.loadFromFile("tekstury/mon.png");
    mamona.setFont(font);
    trawka.setTexture(ziele);
    pieniazek.setTexture(moneta);
    napis.setString("WYGRANA!!!");
    poziom=1;
    poczatek=1;
    pauza=koniec=0;
    przegrana=wygrana=0;
    pieniadze=5124;
}

void Gra::Inicjalizuj(sf::RenderWindow &win)
{
    if(poczatek)
    {
        resetGracza(win);
        parametryZdrowia();
        parametryPieniazki(win);
        parametryNapisow(win);
    }
    if(silnik.czyWygrana())
    {
    	wygrana=1;
    	napis.setString("WYGRANA!!!");
    }
    else if(silnik.czyPrzegrana())
    {
    	przegrana=1;
    	napis.setString("PRZEGRANA :(");
    }
}

void Gra::Aktualizuj(sf::RenderWindow &win)
{
    if(pauza)
        return;
    if(gracz.sprawdzIleZycia()>0)
    	silnik.sterowanie();
    silnik.sekwencjaKomputera();
    liczPieniazki();
    aktualizujPasekZdrowia();

}

void Gra::Wyswietlaj(sf::RenderWindow &win)
{
    int temp=(ziele.getSize().y-win.getSize().y)*5/8;
    trawka.setTextureRect(sf::IntRect(0, temp, win.getSize().x, win.getSize().y));
    win.draw(trawka);
    win.draw(mamona);
    win.draw(pieniazek);
    win.draw(konturZdrowia);
    win.draw(zdrowie);
    if(wygrana || przegrana)
    	win.draw(napis);
    silnik.rysuj(win);
}

void Gra::obslugaZdarzen(sf::RenderWindow &win, sf::Event &event)
{
	if(event.type == sf::Event::MouseButtonPressed)
	{
		silnik.obslugujNacisnieciaMysz(event);
	}
    if(event.type == sf::Event::MouseButtonReleased)
    {
        //if(event.mouseButton.button == sf::Mouse::Right)
            silnik.spawn(win);
		silnik.obslugujZwolnieniaMysz(event);
    }
    if(event.type == sf::Event::KeyPressed)
	{
        if(event.key.code == sf::Keyboard::Escape)
            pauza= !pauza;
        else
        	silnik.obslugujNacisnieciaPrzycisk(event);
	}
    if(event.type == sf::Event::KeyReleased)
    {
    	silnik.obslugujZwolnieniaPrzycisk(event);
    }
}

void Gra::resetGracza(sf::RenderWindow &win)
{
    poczatek=0;
    gracz.ustawTryb(0);
    gracz.pozStartowa(50, win.getSize().y-110);
    gracz.resetZycia();
}

void Gra::liczPieniazki()
{
    std::ostringstream ssMonety;
    ssMonety << pieniadze;
    mamona.setString(ssMonety.str());
}

void Gra::parametryPieniazki(sf::RenderWindow &win)
{
    liczPieniazki();
    mamona.setFillColor(sf::Color::White);
    mamona.setCharacterSize(30);
    mamona.setPosition(win.getSize().x-mamona.getGlobalBounds().width-50, 20);
    pieniazek.setPosition(mamona.getPosition().x-50, mamona.getPosition().y);
}

void Gra::parametryZdrowia()
{
    konturZdrowia.setSize(sf::Vector2f(240, 20));
    konturZdrowia.setFillColor(sf::Color(0,0,0,0));
    konturZdrowia.setOutlineColor(sf::Color::Black);
    konturZdrowia.setOutlineThickness(5);
    konturZdrowia.setPosition(20, 30);
    aktualizujPasekZdrowia();
    zdrowie.setFillColor(sf::Color(220,50,50));
    zdrowie.setPosition(konturZdrowia.getPosition().x, konturZdrowia.getPosition().y);
}

void Gra::parametryNapisow(sf::RenderWindow &win)
{
	napis.setFont(font);
	napis.setFillColor(sf::Color::Black);
	napis.setCharacterSize(30);
	napis.setOrigin(napis.getGlobalBounds().width/2, napis.getGlobalBounds().height/2);
	napis.setPosition(win.getSize().x/2, win.getSize().y);
}

void Gra::aktualizujPasekZdrowia()
{
    zdrowie.setSize(sf::Vector2f(gracz.sprawdzIleZycia()*2,20));
}
