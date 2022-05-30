#include "drwal.h"
#include "drzwo.h"
#include <iostream>

Drwal::Drwal()
{

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

void Drwal::UderzenieLeft(std::vector<Drzwo> drzewo)
{
        setScale(0.5,0.5);
        setPosition(drzewo[0].getGlobalBounds().left-200,720-300);
}

void Drwal::UderzenieRight(std::vector<Drzwo> drzewo)
{
        setScale(-0.5,0.5);
        setPosition(drzewo[0].getGlobalBounds().left+drzewo[0].getGlobalBounds().width+202.5,720-300);
}

void Drwal::UderzenieA(std::vector<Drzwo> drzewo)
    {
        setScale(0.5,0.5);
        setPosition(drzewo[0].getGlobalBounds().left-200,720-300);
    }

void Drwal::UderzenieD(std::vector<Drzwo> drzewo)
    {
        setScale(-0.5,0.5);
        setPosition(drzewo[0].getGlobalBounds().left+drzewo[0].getGlobalBounds().width+202.5,720-300);
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



