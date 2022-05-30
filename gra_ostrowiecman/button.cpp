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


