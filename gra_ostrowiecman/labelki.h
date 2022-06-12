#ifndef LABELKI_H
#define LABELKI_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "tekstura.h"

class Labelki : public sf::Sprite
{
public:
    Labelki();
    Labelki(const Tekstura &tekstura);
    Labelki(const Tekstura &tekstura, int a, int b, int width, int height);
    void PrzesunTeksture(int a, int b, int width, int height);
    void Znikaj();
    virtual ~Labelki() = default;
};

#endif // LABELKI_H
