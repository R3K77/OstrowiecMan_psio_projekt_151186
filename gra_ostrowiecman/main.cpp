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


//  OKNO INFORMACJI
void tworcy()
{
    // create the window
        sf::RenderWindow window2(sf::VideoMode(800, 600), "OstrowiecMan - informacje");

    // WCZYTUJEMY CZCIONKE
        sf::Font font;
        if (!font.loadFromFile("BAHNSCHRIFT.TTF"))
        {
            std::cerr << "Could not load font" << std::endl;
        }

    //TEKSTURA LOGA POLITECHNIKI
        Tekstura poli_("polibuda.png");

    // LATAJACE LOGO POLITECHNIKI W TLE
        Settings poli;
        poli.setTexture(poli_);
        poli.setScale(0.2,0.2);
        poli.setPosition(10,10);

    //DEKLAROWANIE TEXTBOXOW
        std::vector<sf::Text> text;
        for (int i=0; i<7; i++) {
            text.emplace_back();
            text[i].setFont(font);
            text[i].setFillColor(sf::Color::White);
            text[i].setCharacterSize(25);
            text[i].setPosition(30,30+30*i);
        }
    //USTAWIENIE NAPISOW DO TEXTBOXOW
        text[0].setString("Tworca:   Bartlomiej Szalwach             Nr albumu:   151186");
        text[1].setString("WARiE,    AiR,    sem II,");
        text[2].setString(" ");
        text[3].setString("Dodatkowe informacje:");
        text[4].setString("Pod klawiszem escape znajduje sie panel ustawien tekstur");
        text[5].setString("Lewy gracz - sterowanie A oraz D");
        text[6].setString("Prawy gracz - sterowanie strzalkami lewo i prawo");

    //GLOWNA PETLA OKNA INFORMACJI
        while (window2.isOpen()) {
            sf::Event event;
            while (window2.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window2.close();
            }

            // clear the window with black color
            window2.clear(sf::Color::Black);

        //ANIMACJA LOGA POLIBUDY W TLE
            poli.rotate(0.007);
            poli.move(poli.a,poli.b);
            poli.odbijaj();

        //RYSOWANIE WSZYSTKICH ELEMENTOW W OKNIE INFORMACJI
            window2.draw(poli);
            for (auto &it : text)
            {
                window2.draw(it);
            }


            // end the current frame
            window2.display();
        }
}

int main() {
    bool gra=false;                          //czy trwa gra pierwszego gracza
    bool gra2=false;                        //czy trwa gra drugiego gracza
    bool ustawienia = false;            //czy sa wlaczone ustawienia
    double elapsed;                        //przechowuje czas do licznika pierwszego gracza
    double elapsed2;                      //przechowuje czas do licznika drugiego gracza
    pasekstanu paseczek;              //licznik czasu dla pierwszego gracza
    pasekstanu paseczek2;            //licznik czasu dla drugiego gracza
    pasekstanu paseczekuuu;        //tło licznika czasu dla pierwszego gracza
    pasekstanu paseczekuuu2;      //tło licznika czasu dla drugiego gracza
    int np=0;                                   //licznik galezi przy sprawdzaniu kolizji

    //MUZYKA
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("uderzenie5.wav")){
        std::cerr << "Could not load sound" << std::endl;
    }
    sf::SoundBuffer buffer_;
    if (!buffer_.loadFromFile("uderzenie6.wav")){
        std::cerr << "Could not load sound" << std::endl;
    }
    sf::SoundBuffer buffer1;
    if (!buffer1.loadFromFile("klik.wav")){
        std::cerr << "Could not load sound" << std::endl;
    }
    sf::SoundBuffer buffer3;
    if (!buffer3.loadFromFile("smierc.wav")){
        std::cerr << "Could not load sound" << std::endl;
    }
    sf::Sound uderzenie;
    uderzenie.setBuffer(buffer);
    sf::Sound uderzenie2;
    uderzenie2.setBuffer(buffer_);
    sf::Sound klikniecie;
    klikniecie.setBuffer(buffer1);
    sf::Sound smierc;
    smierc.setBuffer(buffer3);

    //WCZYTANIE CZCIONKI
    sf::Font font;
    if (!font.loadFromFile("BAHNSCHRIFT.TTF"))
    {
        std::cerr << "Could not load font" << std::endl;
    }

    //TWORZENIE OKNA
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Ostrowiec Man", sf::Style::Titlebar | sf::Style::Close);
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);   //limit klatek na sekunde ustawiony na 60

    //WCZYTYWANIE TEKSTUR:
    Tekstura ustawieniaa("ustawienia.png");     // szare (troche przezroczyste) tlo w ustawieniach
    Tekstura skyy2("sky2.png");     //pierwsze tlo
    Tekstura skyy("sky.png");         //drugie tlo
    sf::Sprite sky;
    sky.setTexture(skyy2);
    sky.scale(double(window.getSize().x)/skyy.getSize().x,double(window.getSize().y)/skyy.getSize().y); //wyskalowanie tla do wielkosci okna
    Tekstura logo_("logo.png");     //logo ostrowiecman
    Tekstura single_("singleplayer.png");   //przycisk singleplayer
    Tekstura multi_("multiplayer.png");     //przycisk multiplayer
    Tekstura end_("grob.png");                 //grob pokazujacy sie po smierci
    Tekstura end_button_("end_button.png");     //przycisk powrot do menu glownego
    Tekstura info_("info.png");                 //przycisk do otwarcia okna informacje (void tworcy())
    Tekstura drzewo_("wood.png");           //pierwsza tekstura drzewa (to z minecraft)
    Tekstura drzewo2_("wood2.png");      //druga tekstura drzewa (to bardziej realne)
    Tekstura branch_("branch.png");         //tekstura galezi
    Tekstura drwal_("drwal_maciek.png");              //tekstury obu drwali
    Tekstura drwal2_("drwal_kuba.png");               //tekstury obu drwali

    //TWORZENIE PRZYCISKOW, nadawanie im tekstur i skalowanie
    Button logo(logo_,0.5,0.5);                       ///logo ostrowiecmana w menu glownym
    logo.setPosition(window.getSize().x/2-logo.getGlobalBounds().width/2,-50);
    Button single(single_,0.6,0.6);                  ///przycisk singleplayer w menu glownym
    Button multi(multi_, 0.6,0.6);                   ///przycisk multiplayer w menu glownym
    Button info(info_,0.3,0.3);                       ///przycisk informacje w menu glownym
    std::vector<Button> end_button;                                                                                                  ///
    std::vector<Button> end;                                                                                                               ///
    single.setPosition(window.getSize().x/2-single.getGlobalBounds().width/2,286);                ///   przyciski sluzace do powrotu do menu glownego
    multi.setPosition(window.getSize().x/2-multi.getGlobalBounds().width/2,500);                  ///   po smierci gracza
    info.setPosition(30,-60);                                                                                                              ///
    for (int i=0; i<2; i++)
    {
        end.emplace_back();
        end[i].setTexture(end_);
        end[i].scale(0.2,0.2);
        end[i].setPosition(2000,2000);
        end_button.emplace_back();
        end_button[i].setTexture(end_button_);
        end_button[i].scale(0.5,0.5);
        end_button[i].setPosition(2000,2000);
    }

    //WCZYTYWANIE ELEMENTOW GRY I INNYCH
    Labelki background(ustawieniaa);                           // tlo w ustawieniach
    std::vector<Drzwo> drzewo;         //DRZEWO dla pierwszego gracza
    for (int i=0; i<6; i++) {
        drzewo.emplace_back();
        drzewo[i].setTexture(drzewo_);
        drzewo[i].setPosition(3000,720);
        drzewo[i].setScale(0.12,0.12);
    }
    std::vector<Drzwo> drzewo2;     //DRZEWO dla drugiego gracza
    for (int i=0; i<6; i++) {
        drzewo2.emplace_back();
        drzewo2[i].setTexture(drzewo_);
        drzewo2[i].setPosition(3000,720);
        drzewo2[i].setScale(0.12,0.12);
    }
    std::vector<Drzwo> branch;          //GALEZIE dla pierwszego gracza
    for (int i=0; i<10; i++) {
        branch.emplace_back();
        branch[i].setTexture(branch_);
        branch[i].setPosition(5000,0);
        branch[i].setScale(0.12,0.12);
    }
    std::vector<Drzwo> branch2;       //GALEZIE dla pierwszego gracza
    for (int i=0; i<10; i++) {
        branch2.emplace_back();
        branch2[i].setTexture(branch_);
        branch2[i].setPosition(5000,0);
        branch2[i].setScale(0.12,0.12);
    }
    std::vector<Drwal> drwal;           //DRWALE (dwoch graczy w jednym wektorze)
    for (int i=0; i<2; i++) {
        drwal.emplace_back();
        drwal[i].setTexture(drwal_);
        drwal[i].setPosition(3000,720);
        drwal[i].setScale(0.5,0.5);
        drwal[i].setTextureRect(sf::IntRect(0,0,500,399));
    }


    //Tworzenie przyciskow do okna ustawien
    Button settings_tlo(skyy,0.07,0.07);
    Button settings_tlo2(skyy2,0.07,0.07);
    Button settings_drwal(drwal_,0.3,0.3);
    settings_drwal.setTextureRect(sf::IntRect(0,0,500,399));
    Button settings_drwal2(drwal2_,0.3,0.3);
    settings_drwal2.setTextureRect(sf::IntRect(0,0,500,399));
    Button settings_drzewo(drzewo_,0.1,0.1);
    Button settings_drzewo2(drzewo2_,0.1,0.1);

    //PASEK STANU (ODLICZANIE CZASU)
    sf::Clock timer;    //timer dla gracza nr 1
    sf::Clock timer2;   //timer dla gracza nr 2
    std::vector<pasekstanu> pasek_stanu;    //pasek stanu tworzony jest w wektorze, aby obslugiwal rowniez drugiego gracza
    for (int i=0; i<2; i++) {
        pasek_stanu.emplace_back();
    }

    //TEXT NA PRZEGRANA:
    std::vector<sf::Text> text;
    for (int i=0; i<4; i++) {
        text.emplace_back();
        text[i].setFont(font);
        text[i].setFillColor(sf::Color::White);
        text[i].setCharacterSize(32);
        text[i].setPosition(2000,2000);
        text[i].setString("TWOJ WYNIK TO:");
    }

    // run the program as long as the window is open
    while (window.isOpen()) {
        elapsed+=timer.restart().asMicroseconds();            //ODLICZANIE CZASU W PASKU STANU DLA PIERWSZEGO GRACZA
        elapsed2+=timer2.restart().asMicroseconds();        //ODLICZANIE CZASU W PASKU STANU DLA DRUGIEGO GRACZA

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed){
                window.close();}
            if (event.type == sf::Event::MouseButtonPressed)
            {
                sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
                sf::FloatRect single_bound = single.getGlobalBounds();
                sf::FloatRect multi_bound = multi.getGlobalBounds();
                sf::FloatRect end0_bound = end_button[0].getGlobalBounds();
                sf::FloatRect end1_bound = end_button[1].getGlobalBounds();
                if(single.is_within(mouse_pos,single_bound)==true)
                {
                    //GIERKA SINGLEPLAYER
                    klikniecie.play();  //dzwiek klikniecia przycisku
                    ustawienia = false;
                    ZnikanieMenu(settings_tlo, settings_tlo2, settings_drwal, settings_drwal2, settings_drzewo, settings_drzewo2, logo, single, multi, background,info);
                    drwal[0].score=0;                       //reset wyniku gracza1
                    pasek_stanu[0].delta=1.2;         //reset zwiekszania sie paska stanu
                    UstawienieElementow(drzewo, drwal, 0, 1280/2-60);           //Funkcja opisana na gorze maina
                }
                else if(multi.is_within(mouse_pos,multi_bound)==true)
                {
                    klikniecie.play();
                    //GIERKA MULTIPLAYER
                    ustawienia = false;
                    ZnikanieMenu(settings_tlo, settings_tlo2, settings_drwal, settings_drwal2, settings_drzewo, settings_drzewo2, logo, single, multi,background,info);
                    pasek_stanu[0].delta=1.2;       //reset zwiekszania sie paska stanu
                    pasek_stanu[1].delta=1.2;       //reset zwiekszania sie paska stanu
                    UstawienieElementow(drzewo, drwal, 0, 3*window.getSize().x/4-60);                 //Funkcja opisana na gorze maina
                    UstawienieElementow(drzewo2, drwal, 1, window.getSize().x/4-60);          //Funkcja opisana na gorze maina
                }
                else if(end[0].is_within(mouse_pos,end0_bound)==true)
                {
                    klikniecie.play();
                    ZnikanieElementow(drwal, branch,drzewo,branch2,drzewo2,single,multi, info,logo,text,end_button,  end, window.getSize().x);
                }
                else if(end[1].is_within(mouse_pos,end1_bound)==true)
                {
                    klikniecie.play();
                    ZnikanieElementow(drwal, branch,drzewo,branch2,drzewo2,single,multi, info, logo,text,end_button,  end, window.getSize().x);
                }
                else if(info.is_within(sf::Mouse::getPosition(window),info.getGlobalBounds())==true)
                {
                    tworcy();
                }
                else if(settings_tlo.is_within(sf::Mouse::getPosition(window),settings_tlo.getGlobalBounds())==true){
                    sky.setTexture(skyy);
                    klikniecie.play();
                }
                else if(settings_tlo2.is_within(sf::Mouse::getPosition(window),settings_tlo2.getGlobalBounds())==true){
                    sky.setTexture(skyy2);
                    klikniecie.play();
                }
                else if(settings_drwal.is_within(sf::Mouse::getPosition(window),settings_drwal.getGlobalBounds())==true){
                    for (auto &it : drwal)
                    {
                        klikniecie.play();
                        it.setTexture(drwal_);
                    }
                }
                else if(settings_drwal2.is_within(sf::Mouse::getPosition(window),settings_drwal2.getGlobalBounds())==true){
                    for (auto &it : drwal)
                    {
                        klikniecie.play();
                        it.setTexture(drwal2_);
                    }
                }
                else if(settings_drzewo.is_within(sf::Mouse::getPosition(window),settings_drzewo.getGlobalBounds())==true){
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
                else if(settings_drzewo2.is_within(sf::Mouse::getPosition(window),settings_drzewo2.getGlobalBounds())==true){
                    for (auto &it : drzewo)
                    {
                        klikniecie.play();
                        it.setTexture(drzewo2_);
                    }
                    for (auto &it : drzewo2)
                    {
                        klikniecie.play();
                        it.setTexture(drzewo2_);
                    }
                }
            }

            //ZMIANA TEKSTURY PRZY UDERZENIU DRWALA
            if (event.type == sf::Event::KeyPressed)
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                {
                    if (drwal[0].getGlobalBounds().left<window.getSize().x){
                        drwal[0].setTextureRect(sf::IntRect(500, 0, 500, 399));     //przesuwa teksture na uderzenie (o 500pikseli w prawo)
                    }
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                {
                    if (drwal[1].getGlobalBounds().left<window.getSize().x){
                        drwal[1].setTextureRect(sf::IntRect(500,0,500,399));        //przesuwa teksture na uderzenie (o 500pikseli w prawo)
                    }
                }
            }

            //STEROWANIE
            if (event.type == sf::Event::KeyReleased)
            {
                if(drwal[0].getGlobalBounds().left<window.getSize().x)      //zabezpieczenie przed ruchem poza ekranem
                {
                    if (event.key.code == sf::Keyboard::Left)
                    {
                            uderzenie.play();
                        //pasek
                        gra = true;
                        elapsed=0;
                        pasek_stanu[0].ZmniejszCzas();
                        ///uderzenia i pojawianie sie galezi:
                        drwal[0].setTextureRect(sf::IntRect(0, 0, 500, 399));       //powrot z animacji uderzenie
                        drwal[0].UderzenieLeft(drzewo);
                        branch[np].UstawGalaz(drzewo);
                        if(np==10)
                        { np=0;}
                        else
                        { np=np+1;}
                        for (auto &it: branch)
                        {
                            it.WDol(it.getGlobalBounds().left, it.getGlobalBounds().top);
                        }
                        //KOLIZJE Z GALEZIA DLA PIERWSZEGO GRACZA
                        for (auto &it: branch)
                        {
                            if(it.getGlobalBounds().intersects(drwal[0].getGlobalBounds()))
                            {
                                gra = false; //koniec paska
                                pasek_stanu[0].UsuwaniePaskow(drwal, 0, text, 0, 1, end, end_button, drzewo);       //usuwanie elementow paska po smierci
                                paseczek.UsuwaniePaska();
                                paseczekuuu.UsuwaniePaska();
                                smierc.play();
                            }
                        }

                        drwal[0].DodajPunkt();
                    }
                    if (event.key.code == sf::Keyboard::Right)
                    {
                       uderzenie.play();
                        gra = true;
                        elapsed=0;
                        pasek_stanu[0].ZmniejszCzas();
                        ///uderzenia i pojawianie sie galezi:
                        drwal[0].setTextureRect(sf::IntRect(0, 0, 500, 399));   //powrot z animacji uderzenie
                        drwal[0].UderzenieRight(drzewo);
                        branch[np].UstawGalaz(drzewo);
                        if(np==10)
                        { np=0;}
                        else
                        { np=np+1;}
                        for (auto &it: branch)
                        {
                            it.WDol(it.getGlobalBounds().left, it.getGlobalBounds().top);
                        }
                        //KOLIZJE Z GALEZIA DLA PIERWSZEGO GRACZA
                        for (auto &it: branch)
                        {
                            if(it.getGlobalBounds().intersects(drwal[0].getGlobalBounds()))
                            {
                                gra = false; //koniec paska
                                pasek_stanu[0].UsuwaniePaskow(drwal, 0, text, 0, 1, end, end_button, drzewo);       //usuwanie elementow paska po smierci
                                paseczek.UsuwaniePaska();
                                paseczekuuu.UsuwaniePaska();
                                smierc.play();
                            }
                        }
                        drwal[0].DodajPunkt();
                    }
                }

                if(drwal[1].getGlobalBounds().left<window.getSize().x)  //zabezpieczenie przed ruchem poza ekranem
                {
                    if (event.key.code == sf::Keyboard::A)
                    {
                            uderzenie2.play();
                        gra2 = true;
                        elapsed2=0;
                        pasek_stanu[1].ZmniejszCzas();
                        //uderzenia i resp galezi
                        drwal[1].setTextureRect(sf::IntRect(0, 0, 500, 399));   //powrot z animacji uderzenie
                        drwal[1].UderzenieA(drzewo2);
                        branch2[np].UstawGalaz(drzewo2);
                        if(np==10)
                        { np=0;}
                        else
                        { np=np+1;}
                        for (auto &it: branch2)
                        {
                            it.WDol(it.getGlobalBounds().left, it.getGlobalBounds().top);
                        }
                        //KOLIZJE Z GALEZIA DLA DRUGIEGO GRACZA
                        for (auto &it: branch2)
                        {
                            if(it.getGlobalBounds().intersects(drwal[1].getGlobalBounds()))
                            {
                                smierc.play();
                                gra2=false;     //koniec paska
                                pasek_stanu[1].UsuwaniePaskow(drwal, 1, text, 2, 3, end, end_button, drzewo2);      //usuwanie elementow paska po smierci
                                paseczekuuu2.UsuwaniePaska();
                                paseczek2.UsuwaniePaska();
                            }
                        }
                        drwal[1].DodajPunkt();
                    }
                    if (event.key.code == sf::Keyboard::D)
                    {
                            uderzenie2.play();
                        //pasek
                        gra2 = true;
                        elapsed2=0;
                        pasek_stanu[1].ZmniejszCzas();
                        //uderzenia i resp galezi
                        drwal[1].setTextureRect(sf::IntRect(0, 0, 500, 399));
                        drwal[1].UderzenieD(drzewo2);
                        branch2[np].UstawGalaz(drzewo2);
                        if(np==10)
                        { np=0;}
                        else
                        { np=np+1;}
                        for (auto &it: branch2)
                        {
                            it.WDol(it.getGlobalBounds().left, it.getGlobalBounds().top);
                        }
                        //KOLIZJE Z GALEZIA DLA DRUGIEGO GRACZA
                        for (auto &it: branch2)
                        {
                            if(it.getGlobalBounds().intersects(drwal[1].getGlobalBounds()))
                            {
                                smierc.play();
                                gra2=false;     //koniec paska
                                pasek_stanu[1].UsuwaniePaskow(drwal, 1, text, 2, 3, end, end_button, drzewo2);      //usuwanie elementow paska po smierci
                                paseczekuuu2.UsuwaniePaska();
                                paseczek2.UsuwaniePaska();
                            }
                        }
                        drwal[1].DodajPunkt();
                    }
                }
                if (logo.getGlobalBounds().left<1200)
                {
                    if (event.key.code == sf::Keyboard::Escape)
                    {
                        if (ustawienia==false)
                        {
                            background.setPosition(850,0);
                            ustawienia = true;
                            settings_tlo.rysuj(0,1);
                            settings_tlo2.rysuj(0,2);                 // pierwsza wartosc to wiersz, a druga to kolumna
                            settings_drwal.rysuj(1,1);               // w oknie ustawien
                            settings_drwal2.rysuj(1,2);
                            settings_drzewo.rysuj(2,1);
                            settings_drzewo2.rysuj(2,2);
                        }
                        else
                        {
                            background.Znikaj();
                            ustawienia = false;
                            settings_tlo.Znikaj();
                            settings_tlo2.Znikaj();
                            settings_drwal.Znikaj();
                            settings_drwal2.Znikaj();
                            settings_drzewo.Znikaj();
                            settings_drzewo2.Znikaj();
                        }
                    }
                }
            }
        }

        if (gra==true)          //Ustawienie pasku stanu
        {
            paseczek.PasekTlo(drzewo,0);                    // ustawienie dwoch paskow w tle, aby wybrany pasek
            paseczekuuu.PasekTlo2(drzewo,0);            // mial lepszy efekt zmniejszania sie

            pasek_stanu[0].setPosition(drzewo[0].getGlobalBounds().left+drzewo[0].getGlobalBounds().width+20,10);
            if(pasek_stanu[0].getGlobalBounds().width<=200)
            {
                pasek_stanu[0].FunkcjonalnoscPaska(elapsed, text, 0, 1, drwal, 0, window.getSize().x, window.getSize().y);
            }
            else    //koniec gry
            {
                gra = false; //koniec paska
                pasek_stanu[0].UsuwaniePaskow(drwal, 0, text, 0, 1, end, end_button, drzewo);   //usuwanie elementow paska po smierci
                paseczek.UsuwaniePaska();
                paseczekuuu.UsuwaniePaska();
                smierc.play();
            }
        }
        if (gra2==true)
        {
            paseczek2.PasekTlo(drzewo2,0);                  // ustawienie dwoch paskow w tle, aby wybrany pasek
            paseczekuuu2.PasekTlo2(drzewo2,0);          // mial lepszy efekt zmniejszania sie
            pasek_stanu[1].setPosition(drzewo2[0].getGlobalBounds().left+drzewo2[0].getGlobalBounds().width+20,10);
            if(pasek_stanu[1].getGlobalBounds().width<=200)
            {
                pasek_stanu[1].FunkcjonalnoscPaska(elapsed2, text, 2, 3, drwal, 1, 250, window.getSize().y);
            }
            else    //koniec gry
            {
                smierc.play();
                gra2=false;     //koniec paska
                pasek_stanu[1].UsuwaniePaskow(drwal, 1, text, 2, 3, end, end_button, drzewo2);      //usuwanie elementow paska po smierci
                paseczekuuu2.UsuwaniePaska();
                paseczek2.UsuwaniePaska();
            }
        }
        // RYSOWANIE WSZYSTKI ELEMENTOW:
        window.draw(sky);
        window.draw(logo);
        window.draw(single);
        window.draw(multi);
        window.draw(info);
        for (auto &it : drzewo) {
            window.draw(it);
        }
        for (auto &it : drzewo2) {
            window.draw(it);
        }
        for (auto &it : branch) {
            window.draw(it);
        }
        for (auto &it : branch2) {
            window.draw(it);
        }
        for (auto &it : end)
        {
            window.draw(it);
        }
        for (auto &it : end_button)
        {
            window.draw(it);
        }
        for (auto &it : drwal) {
            window.draw(it);
        }
        window.draw(paseczek);
        window.draw(paseczek2);
        window.draw(paseczekuuu);
        window.draw(paseczekuuu2);
        for (auto &it : pasek_stanu){
            window.draw(it);
        }
        for (auto &it : text)
        {
            window.draw(it);
        }
        window.draw(background);
        window.draw(settings_tlo);
        window.draw(settings_tlo2);
        window.draw(settings_drwal);
        window.draw(settings_drwal2);
        window.draw(settings_drzewo);
        window.draw(settings_drzewo2);
        window.display();
    }
    return 0;
}
