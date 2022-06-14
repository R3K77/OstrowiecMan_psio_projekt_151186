#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <button.h>
#include <drzwo.h>
#include <drwal.h>
#include <pasekstanu.h>
#include <iostream>
#include <vector>
#include "settings.h"
#include "textbox.h"
#include "tekstura.h"
#include "funkcjevoid.h"

int main() {

    Tekstura skyy2("sky2.png");                 //tlo
    Tekstura drzewo_("wood.png"), drzewo2_("wood2.png");           //pierwsza tekstura drzewa (to z minecraft)
    Tekstura branch_("branch.png");         //tekstura galezi
    Tekstura drwal_("drwal_maciek.png"), drwal2_("drwal_kuba.png");               //tekstury obu drwali

    sf::Sprite sky;
    sky.setTexture(skyy2);

    std::vector<Drzwo> drzewo;         //DRZEWO dla pierwszego gracza
    for (int i=0; i<6; i++) {
        drzewo.emplace_back();
        drzewo[i].setTexture(drzewo_);
    }
    std::vector<Drzwo> drzewo2;     //DRZEWO dla drugiego gracza
    for (int i=0; i<6; i++) {
        drzewo2.emplace_back();
        drzewo2[i].setTexture(drzewo_);
    }
    std::vector<Drzwo> branch;          //GALEZIE dla pierwszego gracza
    for (int i=0; i<10; i++) {
        branch.emplace_back();
        branch[i].setTexture(branch_);
    }
    std::vector<Drzwo> branch2;       //GALEZIE dla pierwszego gracza
    for (int i=0; i<10; i++) {
        branch2.emplace_back();
        branch2[i].setTexture(branch_);
    }
    std::vector<Drwal> drwal;           //DRWALE (dwoch graczy w jednym wektorze)
    for (int i=0; i<2; i++) {
        drwal.emplace_back();
        drwal[i].setTexture(drwal_);
    }

    menu_glowne(drzewo, drzewo2, branch, branch2, drwal, sky);
    return 0;
}
