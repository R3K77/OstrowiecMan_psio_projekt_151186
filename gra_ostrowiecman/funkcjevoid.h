#ifndef FUNKCJEVOID_H
#define FUNKCJEVOID_H
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

void ZnikanieMenu(Button& settings_tlo, Button &settings_tlo2, Button &settings_drwal, Button &settings_drwal2,
                                  Button& settings_drzewo, Button& settings_drzewo2, Button& logo, Button& single, Button& multi, Labelki& background, Button& info);

void UstawienieElementow(std::vector<Drzwo> &drzewo, std::vector<Drwal> &drwal, int ktory_drwal, float pos_x);

void ZnikanieElementow(std::vector<Drwal> &drwal, std::vector<Drzwo> &branch,std::vector<Drzwo> &drzewo,std::vector<Drzwo> &branch2,std::vector<Drzwo> &drzewo2,
                                            Button& single, Button& multi, Button &info, Button& logo, std::vector<sf::Text> &text, std::vector<Button> &end_button, std::vector<Button> &end, float okno_x);

void KolizjaZGalezia(std::vector<Drzwo>&branch, std::vector<Drwal> &drwal, int ktory_drwal, sf::Sound &smierc, bool &gra, std::vector<pasekstanu> &pasek_stanu, std::vector<sf::Text> &text, int i, int j,std::vector<Button>& end,  std::vector<Button>& end_button,
                     std::vector<Drzwo> &drzewo, pasekstanu &paseczekuuu, pasekstanu &paseczek);

void PaskiOdliczajaceCzas(bool &gra, std::vector<Drwal> &drwal, pasekstanu &paseczek, pasekstanu &paseczekuuu, std::vector<pasekstanu>& pasek_stanu, int i, std::vector<Drzwo> &drzewo,
                          std::vector<sf::Text>& text, int a, int b, std::vector<Button> &end, std::vector<Button>& end_button, double& elapsed, sf::Sound &smierc, float size_x, float size_y);

void Ustawienia_ZmianaTekstury(Button &settings_tlo, sf::Vector2i mouse_pos, sf::Sprite& sky, Tekstura &skyy, sf::Sound &klikniecie);

void Ustawienia_ZmianaTekstury(Button& settings_drwal, sf::Vector2i mouse_pos, std::vector<Drwal> &drwal, Tekstura &drwal_, sf::Sound &klikniecie);

void Ustawienia_ZmianaTekstury(Button& settings_drzewo, sf::Vector2i mouse_pos, std::vector<Drzwo> &drzewo, std::vector<Drzwo> &drzewo2, Tekstura &drzewo_, sf::Sound &klikniecie);

#endif // FUNKCJEVOID_H
