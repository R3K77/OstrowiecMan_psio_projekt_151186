#ifndef TEKSTURA_H
#define TEKSTURA_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>


class Tekstura : public sf::Texture
{
public:
    Tekstura(const std::string &nawa_pliku);
};

#endif // TEKSTURA_H
