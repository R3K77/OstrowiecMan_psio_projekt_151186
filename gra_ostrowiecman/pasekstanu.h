#ifndef PASEKSTANU_H
#define PASEKSTANU_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <labelki.h>
#include "drzwo.h"
#include "drwal.h"
#include "button.h"

class pasekstanu : public sf::RectangleShape
{
public:
    float delta=1.2;
    void PasekTlo2(std::vector<Drzwo> drzewo, int i);
    void PasekTlo(std::vector<Drzwo> drzewo, int i);
    void FunkcjonalnoscPaska(double elapsed, std::vector<sf::Text> &text, int i, int j, std::vector<Drwal> drwal, int z, float size_x, float size_y);
    double ZmniejszCzas(double& elapsed);
    void UsuwaniePaska();
    void UsuwaniePaskow(std::vector<Drwal>&drwal, int ktory_drwal, std::vector<sf::Text> &text, int i, int j, std::vector<Button>& end,  std::vector<Button>& end_button, std::vector<Drzwo>& drzewo);


    pasekstanu();
};

#endif // PASEKSTANU_H
