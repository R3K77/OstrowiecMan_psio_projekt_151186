#include "funkcjevoid.h"


void ZnikanieMenu(Button& settings_tlo, Button &settings_tlo2, Button &settings_drwal, Button &settings_drwal2,
                                  Button& settings_drzewo, Button& settings_drzewo2, Button& logo, Button& single, Button& multi, Labelki& background, Button& info)
{
    settings_tlo.Znikaj();
    settings_tlo2.Znikaj();
    settings_drwal.Znikaj();
    settings_drwal2.Znikaj();
    settings_drzewo.Znikaj();
    settings_drzewo2.Znikaj();
    logo.Znikaj();
    single.Znikaj();
    multi.Znikaj();
    background.Znikaj();
    info.Znikaj();
}

void UstawienieElementow(std::vector<Drzwo> &drzewo, std::vector<Drwal> &drwal, int ktory_drwal, float pos_x)
{
    drwal[ktory_drwal].score=0;
    //ustawienie drzewa
    for (int i=0; i<5; i++) {
        drzewo[i].setPosition(pos_x,720-(i+2)*144);
    }
    //ustawienie drwala
    drwal[ktory_drwal].setPosition(drzewo[ktory_drwal].getGlobalBounds().left-200,720-300);
}

void ZnikanieElementow(std::vector<Drwal> &drwal, std::vector<Drzwo> &branch,std::vector<Drzwo> &drzewo,std::vector<Drzwo> &branch2,std::vector<Drzwo> &drzewo2,
                                            Button& single, Button& multi, Button &info, Button& logo, std::vector<sf::Text> &text, std::vector<Button> &end_button, std::vector<Button> &end, float okno_x)
{
    for (int i=0; i<2; i++) {
        drwal[i].setPosition(3000,720);
    }
    for (auto &it : branch)
    {
        it.setPosition(5000,5000);
    }
    for (auto &it : drzewo)
    {
        it.setPosition(5000,5000);
    }
    for (auto &it : branch2)
    {
        it.setPosition(5000,5000);
    }
    for (auto &it : drzewo2)
    {
        it.setPosition(5000,5000);
    }
    single.setPosition(okno_x/2-single.getGlobalBounds().width/2,286);
    multi.setPosition(okno_x/2-multi.getGlobalBounds().width/2,500);
    logo.setPosition(okno_x/2-logo.getGlobalBounds().width/2,-50);
    text[0].setPosition(2000,2000);
    text[1].setPosition(2000,2000);
    text[2].setPosition(2000,2000);
    text[3].setPosition(2000,2000);
    end[0].setPosition(3000,3000);
    end_button[0].setPosition(3000,3000);
    end[1].setPosition(3000,3000);
    end_button[1].setPosition(3000,3000);
    drwal[0].setScale(0.5,0.5);
    drwal[1].setScale(0.5,0.5);
    info.setPosition(30,-60);
};

void KolizjaZGalezia(std::vector<Drzwo>&branch, std::vector<Drwal> &drwal, int ktory_drwal, sf::Sound &smierc, bool &gra, std::vector<pasekstanu> &pasek_stanu, std::vector<sf::Text> &text, int i, int j,std::vector<Button>& end,  std::vector<Button>& end_button,
                     std::vector<Drzwo> &drzewo, pasekstanu &paseczekuuu, pasekstanu &paseczek)
{
    for (auto &it: branch)
    {
        if(it.getGlobalBounds().intersects(drwal[ktory_drwal].getGlobalBounds()))
        {
            smierc.play();
            gra=false;     //koniec paska
            pasek_stanu[ktory_drwal].UsuwaniePaskow(drwal, ktory_drwal, text, i, j, end, end_button, drzewo);      //usuwanie elementow paska po smierci
            paseczekuuu.UsuwaniePaska();
            paseczek.UsuwaniePaska();
        }
    }
}


void PaskiOdliczajaceCzas(bool &gra, std::vector<Drwal> &drwal, pasekstanu &paseczek, pasekstanu &paseczekuuu, std::vector<pasekstanu>& pasek_stanu, int i, std::vector<Drzwo> &drzewo,
                          std::vector<sf::Text>& text, int a, int b, std::vector<Button> &end, std::vector<Button>& end_button, double& elapsed, sf::Sound &smierc, float size_x, float size_y)
{
if (gra==true)          //Ustawienie pasku stanu
{
    paseczek.PasekTlo(drzewo,0);                    // ustawienie dwoch paskow w tle, aby wybrany pasek
    paseczekuuu.PasekTlo2(drzewo,0);            // mial lepszy efekt zmniejszania sie

    pasek_stanu[i].setPosition(drzewo[0].getGlobalBounds().left+drzewo[0].getGlobalBounds().width+20,10);
    if(pasek_stanu[i].getGlobalBounds().width<=200)
    {
        pasek_stanu[i].FunkcjonalnoscPaska(elapsed, text, a, b, drwal, i, size_x, size_y);
    }
    else    //koniec gry
    {
        gra = false; //koniec paska
        pasek_stanu[i].UsuwaniePaskow(drwal, i, text, a, b, end, end_button, drzewo);   //usuwanie elementow paska po smierci
        paseczek.UsuwaniePaska();
        paseczekuuu.UsuwaniePaska();
        smierc.play();
    }
}
}



void Ustawienia_ZmianaTekstury(Button& settings_tlo, sf::Vector2i mouse_pos, sf::Sprite& sky, Tekstura &skyy, sf::Sound &klikniecie)
{
    if(settings_tlo.is_within(mouse_pos,settings_tlo.getGlobalBounds())==true){
                        sky.setTexture(skyy);
                        klikniecie.play();
                    }
}

void Ustawienia_ZmianaTekstury(Button& settings_drwal, sf::Vector2i mouse_pos, std::vector<Drwal> &drwal, Tekstura &drwal_, sf::Sound &klikniecie)
{
    if(settings_drwal.is_within(mouse_pos,settings_drwal.getGlobalBounds())==true){
        for (auto &it : drwal)
        {
            klikniecie.play();
            it.setTexture(drwal_);
        }
    }
}

void Ustawienia_ZmianaTekstury(Button& settings_drzewo, sf::Vector2i mouse_pos, std::vector<Drzwo>& drzewo, std::vector<Drzwo> &drzewo2, Tekstura &drzewo_, sf::Sound &klikniecie)
{
    if(settings_drzewo.is_within(mouse_pos,settings_drzewo.getGlobalBounds())==true){
                        for (auto &it : drzewo)
                        {
                            klikniecie.play();
                            it.setTexture(drzewo_);
                        }
                        for (auto &it : drzewo2)
                        {
                            klikniecie.play();
                            it.setTexture(drzewo_);
                        }
                    }
}


