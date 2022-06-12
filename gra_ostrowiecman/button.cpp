#include "button.h"

Button::Button()
{

};

bool Button::is_within(sf::Vector2i pos, sf::FloatRect bound)
{
    if ((pos.x<=(bound.left+bound.width))&&(pos.x>=bound.left))
    {
        if ((pos.y<=(bound.top+bound.height))&&(pos.y>=bound.top))
        {
            return true;
        }
    }
    else
    {
        return false;
    }
    return false;
};

void Button::rysuj(int i, int j)
{
    if (j==1)
    {
        setPosition(850+50,80+220*i);
    }
    else if(j==2)
    {
        setPosition(850+250,80+220*i);
    }
    else
    {
        setPosition(2000,2000);
    }
}

Button::Button(const sf::Texture &texture, float scale_x, float scale_y)
{
    setTexture(texture);
    setScale(scale_x,scale_y);
    setPosition(2000,2000);
}




