#ifndef BUTTON_H
#define BUTTON_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <labelki.h>

class Button :public Labelki
{
public:
    Button();
    Button(const sf::Texture &texture, float scale_x, float scale_y);
    Button(const sf::Texture &texture, float scale_x, float scale_y, float pos_x, float pos_y);
    bool is_within(sf::Vector2i pos, sf::FloatRect rec_bound);
    void rysuj(int i, int j);

};

#endif // BUTTON_H
