#include "pasekstanu.h"

pasekstanu::pasekstanu()
{
    setFillColor(sf::Color::Black);
    setPosition(500,500);
    setSize(sf::Vector2f(0,0));
}



void pasekstanu::PasekTlo2(std::vector<Drzwo> drzewo, int i)
{
        setSize(sf::Vector2f(200,20));
        setFillColor(sf::Color::Red);
        setPosition(drzewo[i].getGlobalBounds().left+drzewo[i].getGlobalBounds().width+20-200,10);
}

void pasekstanu::PasekTlo(std::vector<Drzwo> drzewo, int i)
{
    setSize(sf::Vector2f(206,26));
    setFillColor(sf::Color::Black);
    setPosition(drzewo[i].getGlobalBounds().left+drzewo[i].getGlobalBounds().width+17-200,7);
}

void pasekstanu::FunkcjonalnoscPaska(double elapsed, std::vector<sf::Text> &text, int i, int j, std::vector<Drwal> drwal, int z, float size_x, float size_y)
{
    setSize(sf::Vector2f(-elapsed*delta/10000, 20));
    text[i].setCharacterSize(50);
    text[i].setString(std::to_string(drwal[z].score));
    text[i].setPosition(size_x-text[i].getGlobalBounds().width-10, size_y-text[i].getGlobalBounds().height-20);
    text[j].setScale(1,1);
    text[j].setString("TWOJ WYNIK TO:");
    text[j].setPosition(size_x-text[j].getGlobalBounds().width-10, size_y-100);
}

void pasekstanu::UsuwaniePaska()
{
    setSize(sf::Vector2f(0,0));
}

void pasekstanu::UsuwaniePaskow(std::vector<Drwal>&drwal, int ktory_drwal, std::vector<sf::Text> &text, int i, int j, std::vector<Button>& end,  std::vector<Button>& end_button, std::vector<Drzwo>& drzewo)
{
    setSize(sf::Vector2f(0,0));
    drwal[ktory_drwal].bestscore=drwal[ktory_drwal].score;
    end[ktory_drwal].setPosition(drwal[ktory_drwal].getGlobalBounds().left+80, drwal[ktory_drwal].getGlobalBounds().top+20);
    drwal[ktory_drwal].setPosition(2000,2000);
    end_button[ktory_drwal].setPosition(drzewo[0].getGlobalBounds().left-60, drzewo[0].getGlobalBounds().top-300);
    drwal[ktory_drwal].score=0;
    drwal[ktory_drwal].setScale(0.5,0.5);
    text[i].setCharacterSize(50);
    text[i].setString(std::to_string(drwal[ktory_drwal].bestscore));
    text[i].setPosition(drzewo[0].getGlobalBounds().left+40,
            drzewo[0].getGlobalBounds().top-100);
    text[j].setScale(0.6,0.6);
    text[j].setString("TWOJ WYNIK TO:");
    text[j].setPosition(drzewo[0].getGlobalBounds().left+5,
            drzewo[0].getGlobalBounds().top-140);
}

double pasekstanu::ZmniejszCzas(double &elapsed)
{
    if (delta<=6)
    {
        delta=delta+0.01;
    }
    elapsed=0;
    return elapsed;
}
