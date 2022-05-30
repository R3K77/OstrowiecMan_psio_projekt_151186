#ifndef LABELKI_H
#define LABELKI_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Labelki : public sf::Sprite
{
public:
    Labelki();
    void Znikaj();
    virtual ~Labelki() = default;
};

#endif // LABELKI_H
