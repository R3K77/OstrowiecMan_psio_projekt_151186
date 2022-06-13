#include "drwal.h"
#include "drzwo.h"
#include <iostream>

Drwal::Drwal()
{
    setPosition(3000,720);
    setScale(0.5,0.5);
    setTextureRect(sf::IntRect(0,0,500,399));
}

void Drwal::TeksturaNaUderzenie(sf::Keyboard::Key RuchWLewo, sf::Keyboard::Key RuchWPrawo, float window_size_x)
{
    if (sf::Keyboard::isKeyPressed(RuchWLewo) || sf::Keyboard::isKeyPressed(RuchWPrawo))
    {
        if (getGlobalBounds().left<window_size_x){
            setTextureRect(sf::IntRect(500, 0, 500, 399));     //przesuwa teksture na uderzenie (o 500pikseli w prawo)
        }
    }
}

void Drwal::Kolizja(std::vector<Drzwo> galaz, std::vector<Drwal> drwal)
{
    for (auto &it: galaz)
    {
        if(it.getGlobalBounds().intersects(drwal[0].getGlobalBounds()))
        {
            std::cout << "kolizja xD" << std::endl;
        }
    }
}

int Drwal::UderzenieLeft(std::vector<Drzwo> &drzewo, std::vector<Drzwo> &branch, int &np)
{
        setTextureRect(sf::IntRect(0, 0, 500, 399));   //powrot z animacji uderzenie
        setScale(0.5,0.5);
        setPosition(drzewo[0].getGlobalBounds().left-200,720-300);
        branch[np].UstawGalaz(drzewo);
        if(np==10)
        { np=0;}
        else
        { np=np+1;}
        for (auto &it: branch)
        {
            it.WDol(it.getGlobalBounds().left, it.getGlobalBounds().top);
        }
        return np;
}


int Drwal::UderzenieRight(std::vector<Drzwo> &drzewo, std::vector<Drzwo> &branch, int &np)
{
        setTextureRect(sf::IntRect(0, 0, 500, 399));   //powrot z animacji uderzenie
        setScale(-0.5,0.5);
        setPosition(drzewo[0].getGlobalBounds().left+drzewo[0].getGlobalBounds().width+202.5,720-300);
        branch[np].UstawGalaz(drzewo);
        if(np==10)
        { np=0;}
        else
        { np=np+1;}
        for (auto &it: branch)
        {
            it.WDol(it.getGlobalBounds().left, it.getGlobalBounds().top);
        }
        return np;
}

//drwal[0].setTextureRect(sf::IntRect(0, 0, 500, 399));   //powrot z animacji uderzenie
//drwal[0].UderzenieRight(drzewo);
//branch[np].UstawGalaz(drzewo);
//if(np==10)
//{ np=0;}
//else
//{ np=np+1;}
//for (auto &it: branch)
//{
//    it.WDol(it.getGlobalBounds().left, it.getGlobalBounds().top);
//}

int Drwal::DodajPunkt()
{
    score=score+1;
    return score;
}


/*
 *         int n;
n=std::rand() % 2;
int np;
np=0;
switch(n)
{
    case 0:
    std::cout << n << std::endl;
    if(np==4)
    {
        np=0;
    }
    else
    {
        np=np+1;
    }
        break;


    case 1:
    std::cout << n << std::endl;
    galaz[n].setPosition(drzewo[2].getGlobalBounds().left-100,drzewo[2].getGlobalBounds().height-20);
    for(auto &it:galaz)
    {
        it.setPosition(it.getGlobalBounds().left,it.getGlobalBounds().top-144);
    }
    if(np==4)
    {
        np=0;
    }
    else
    {
        np=np+1;
    }
        break;


    case 2:
std::cout << n << std::endl;
    if(np==4)
    {
        np=0;
    }
    else
    {
        np=np+1;
    }
        break;
}
*/

/*
else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
{
setScale(-0.5,0.5);
setPosition(drzewo[0].getGlobalBounds().left+drzewo[0].getGlobalBounds().width+202.5,720-300);



}
*/



