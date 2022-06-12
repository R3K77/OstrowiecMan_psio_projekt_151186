#include "tekstura.h"

Tekstura::Tekstura(const std::string &nazwa_pliku)
{
    if(!loadFromFile(nazwa_pliku)){
         std::cerr << "Blad wgrywania pliku" << std::endl;
    }
}
