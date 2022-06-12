#include "drzwo.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

Drzwo::Drzwo()
{

}

void Drzwo::WDol(double x, double y)
{
    if(y>480)
    {
        setPosition(3000,0);
    }
    else
    {
        setPosition(x,y+144);
    }
}

void Drzwo::UstawGalaz(std::vector<Drzwo> drzewo)
{
    int n;
    n=std::rand() % 3;

    switch(n)
    {
        case 0:

            break;


        case 1:
        setPosition(drzewo[4].getGlobalBounds().left-135,-90);
            break;


        case 2:
        setPosition(drzewo[4].getGlobalBounds().left+130,-90);
            break;
    }
}

