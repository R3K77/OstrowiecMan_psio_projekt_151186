#ifndef BUTTON_H
#define BUTTON_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <labelki.h>

class Button :public Labelki
{
public:
    Button();
    bool is_within(sf::Vector2i pos, sf::FloatRect rec_bound);
    void rysuj(int i, int j);

};

#endif // BUTTON_H
