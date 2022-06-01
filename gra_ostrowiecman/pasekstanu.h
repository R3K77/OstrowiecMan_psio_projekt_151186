#ifndef PASEKSTANU_H
#define PASEKSTANU_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <labelki.h>

class pasekstanu : public sf::RectangleShape
{
public:
    float delta=1.2;
    pasekstanu();
};

#endif // PASEKSTANU_H
