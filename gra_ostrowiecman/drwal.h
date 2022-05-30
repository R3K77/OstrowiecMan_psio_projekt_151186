#ifndef DRWAL_H
#define DRWAL_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "drzwo.h"

class Drwal:public sf::Sprite
{
public:
    int bestscore;
    int score=0;
    Drwal();
    void UderzenieLeft(std::vector<Drzwo> drzewo);
    void UderzenieRight(std::vector<Drzwo> drzewo);
    void UderzenieA(std::vector<Drzwo> drzewo);
    void UderzenieD(std::vector<Drzwo> drzewo);
    void Kolizja(std::vector<Drzwo> galaz, std::vector<Drwal> drwal);
};

#endif // DRWAL_H
