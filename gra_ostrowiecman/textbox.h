#ifndef TEXTBOX_H
#define TEXTBOX_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


class TextBox : public sf::Text
{
public:
    TextBox( sf::Font font, int size, float pos_x, float pos_y, std::string text);
};

#endif // TEXTBOX_H
