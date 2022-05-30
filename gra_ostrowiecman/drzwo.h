#ifndef DRZWO_H
#define DRZWO_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Drzwo :public sf::Sprite
{
public:
    Drzwo();
    void UstawGalaz(std::vector<Drzwo> drzewo);
    void WDol(double x, double y);

};

#endif // DRZWO_H
