#ifndef SETTINGS_H
#define SETTINGS_H

#include "labelki.h"
#include "drwal.h"
#include "drzwo.h"


class Settings : public Labelki
{
public:
    float a=0.03;
    float b=0.03;
    void rysuj(int i, int j);
    void odbijaj();
    Settings();

};

#endif // SETTINGS_H
