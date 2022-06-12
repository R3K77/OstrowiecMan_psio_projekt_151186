#include "textbox.h"

TextBox::TextBox(sf::Font font, int size, float pos_x, float pos_y, std::string text)
{
    setFont(font);
    setFillColor(sf::Color::White);
    setCharacterSize(size);
    setPosition(pos_x, pos_y);
    setString(text);
}
