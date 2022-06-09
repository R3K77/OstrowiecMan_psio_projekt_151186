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
