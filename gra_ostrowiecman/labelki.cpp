#include "labelki.h"

Labelki::Labelki()
{
        setPosition(2000,2000);
}

Labelki::Labelki(const Tekstura &tekstura)
{
    setTexture(tekstura);
    setPosition(2000,2000);
}

Labelki::Labelki(const Tekstura &tekstura, int a, int b, int width, int height)
{
    setTexture(tekstura);
    setTextureRect(sf::IntRect(a,b,width,height));
}

void Labelki::PrzesunTeksture(int a, int b, int width, int height)
{
    setTextureRect(sf::IntRect(a,b,width,height));
}

void Labelki::Znikaj()
{
    setPosition(1280,720);
}
