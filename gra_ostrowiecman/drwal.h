#ifndef DRWAL_H
#define DRWAL_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include "drzwo.h"

class Drwal:public sf::Sprite
{
public:
    int bestscore;
    int score=0;
    Drwal();
    int UderzenieLeft(std::vector<Drzwo> &drzewo, std::vector<Drzwo>& branch, int &np);
    int UderzenieRight(std::vector<Drzwo> &drzewo, std::vector<Drzwo> &branch, int &np);
    void Kolizja(std::vector<Drzwo> galaz, std::vector<Drwal> drwal);
    void TeksturaNaUderzenie(sf::Keyboard::Key RuchWLewo, sf::Keyboard::Key RuchWPrawo, float window_size_x);
    int DodajPunkt();
};

#endif // DRWAL_H
