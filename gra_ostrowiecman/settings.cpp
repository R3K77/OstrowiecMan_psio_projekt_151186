#include "settings.h"

Settings::Settings()
{
    setPosition(2000,2000);
}

void Settings::rysuj(int i, int j)
{
    if (j==1)
    {
        setPosition(850+50,70+70*i);
    }
    else if(j==2)
    {
        setPosition(850+250,70+70*i);
    }
    else
    {
        setPosition(2000,2000);
    }
}

void Settings::odbijaj()
{
    sf::Rect bounding_box=getGlobalBounds();
            if( bounding_box.left<=0)
            {
                a=std::abs(a);
            }
            else if(bounding_box.left+bounding_box.width>=800)
            {
                a=-std::abs(a);
            }
            if(bounding_box.top<=0)
            {
                b=std::abs(b);
            }
            else if(bounding_box.top+bounding_box.height>=600)
            {
                b=-std::abs(b);
            }
}
