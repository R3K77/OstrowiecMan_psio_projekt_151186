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

//  OKNO INFORMACJI
void tworcy()
{
    // create the window
        sf::RenderWindow window2(sf::VideoMode(800, 600), "OstrowiecMan - informacje", sf::Style::Titlebar | sf::Style::Close);     //Titlebar oraz Close blokuje rozszerzanie okna oraz zmienianie jego wielkosci

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
                if (event.type == sf::Event::Closed){window2.close();}
            }

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
    int np=0;                                   //licznik galezi przy sprawdzaniu kolizji dla pierwszego gracza
    int np2=0;                                   //licznik galezi przy sprawdzaniu kolizji dla drugiego gracza
    sf::Clock timer;                    //timer dla gracza nr 1
    sf::Clock timer2;               //timer dla gracza nr 2

    //MUZYKA
    sf::SoundBuffer buffer;         if (!buffer.loadFromFile("uderzenie5.wav")){std::cerr << "Could not load sound" << std::endl;}
    sf::SoundBuffer buffer_;       if (!buffer_.loadFromFile("uderzenie6.wav")){std::cerr << "Could not load sound" << std::endl;}
    sf::SoundBuffer buffer1;        if (!buffer1.loadFromFile("klik.wav")){std::cerr << "Could not load sound" << std::endl;}
    sf::SoundBuffer buffer3;        if (!buffer3.loadFromFile("smierc.wav")){std::cerr << "Could not load sound" << std::endl;}
    sf::Sound uderzenie;            uderzenie.setBuffer(buffer);
    sf::Sound uderzenie2;          uderzenie2.setBuffer(buffer_);
    sf::Sound klikniecie;             klikniecie.setBuffer(buffer1);
    sf::Sound smierc;                  smierc.setBuffer(buffer3);

    //WCZYTANIE CZCIONKI
    sf::Font font;                  if (!font.loadFromFile("BAHNSCHRIFT.TTF")){std::cerr << "Could not load font" << std::endl;}

    //TWORZENIE OKNA
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Ostrowiec Man", sf::Style::Titlebar | sf::Style::Close);     //Titlebar oraz Close blokuje rozszerzanie okna oraz zmienianie jego wielkosci
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);   //limit klatek na sekunde ustawiony na 60

    //WCZYTYWANIE TEKSTUR:
    Tekstura ustawieniaa("ustawienia.png");     // szare (troche przezroczyste) tlo w ustawieniach
    Tekstura skyy2("sky2.png"), skyy("sky.png");     //tla
    Tekstura logo_("logo.png"), single_("singleplayer.png"), multi_("multiplayer.png"), end_button_("end_button.png"),info_("info.png");    //przyciski: logo, singleplayer, multiplayer, przycisk powrotu do menu po smierci, przycisk do otwarcia okna informacji(void tworcy())
    Tekstura end_("grob.png");                 //grob pokazujacy sie po smierci
    Tekstura drzewo_("wood.png"), drzewo2_("wood2.png");           //pierwsza tekstura drzewa (to z minecraft)
    Tekstura branch_("branch.png");         //tekstura galezi
    Tekstura drwal_("drwal_maciek.png"), drwal2_("drwal_kuba.png");               //tekstury obu drwali

    sf::Sprite sky;
    sky.setTexture(skyy2);
    sky.scale(double(window.getSize().x)/skyy.getSize().x,double(window.getSize().y)/skyy.getSize().y); //wyskalowanie tla do wielkosci okna

    //TWORZENIE PRZYCISKOW, nadawanie im tekstur i skalowanie (glownie w w konstruktorze)
    Button logo(logo_,0.5,0.5, window.getSize().x/2-282/2, -50);                       ///logo ostrowiecmana w menu glownym
    Button single(single_,0.6,0.6,window.getSize().x/2-232.2/2, 286);                  ///przycisk singleplayer w menu glownym
    Button multi(multi_, 0.6,0.6, window.getSize().x/2-232.2/2, 500);                   ///przycisk multiplayer w menu glownym
    Button info(info_,0.3,0.3, 30,-60);                                                                                                     ///przycisk informacje w menu glownym
    std::vector<Button> end_button;                                                                                                     //przycisk po smierci
    std::vector<Button> end;                                                                                                               //grob po smierci
    for (int i=0; i<2; i++)
    {
        end.emplace_back();
        end[i].setTexture(end_);                                                                ///grob po smierci
        end_button.emplace_back();
        end_button[i].setTexture(end_button_);                          ///przycisk sluzacy do powrotu
        end_button[i].scale(2.3,2.3);                                              ///do menu glownego po smierci
    }

    //WCZYTYWANIE ELEMENTOW GRY I INNYCH
    Labelki background(ustawieniaa);                           // tlo w ustawieniach
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

    //Tworzenie przyciskow do okna ustawien
    Button settings_tlo(skyy,0.07,0.07);
    Button settings_tlo2(skyy2,0.07,0.07);
    Button settings_drwal(drwal_,0.3,0.3);
    settings_drwal.setTextureRect(sf::IntRect(0,0,500,399));
    Button settings_drwal2(drwal2_,0.3,0.3);
    settings_drwal2.setTextureRect(sf::IntRect(0,0,500,399));
    Button settings_drzewo(drzewo_,0.1,0.1);
    Button settings_drzewo2(drzewo2_,0.1,0.1);

    std::vector<pasekstanu> pasek_stanu;    //pasek stanu tworzony jest w wektorze, aby obslugiwal rowniez drugiego gracza
    for (int i=0; i<2; i++) {
        pasek_stanu.emplace_back();
    }

    //TEXT NA PRZEGRANA:
    std::vector<sf::Text> text;
    for (int i=0; i<4; i++) {                   //po dwa textboxy na gracza
        text.emplace_back();
        text[i].setFont(font);
        text[i].setFillColor(sf::Color::White);
        text[i].setCharacterSize(32);
        text[i].setPosition(2000,2000);
        text[i].setString("TWOJ WYNIK TO:");
    }

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
                if(single.is_within(mouse_pos,single.getGlobalBounds())==true)
                {
                    //GIERKA SINGLEPLAYER
                    klikniecie.play();  //dzwiek klikniecia przycisku
                    ustawienia = false;
                    ZnikanieMenu(settings_tlo, settings_tlo2, settings_drwal, settings_drwal2, settings_drzewo, settings_drzewo2, logo, single, multi, background,info);
                    drwal[0].score=0;                       //reset wyniku gracza1
                    pasek_stanu[0].delta=1.2;         //reset zwiekszania sie paska stanu
                    UstawienieElementow(drzewo, drwal, 0, 1280/2-60);           //Funkcja opisana na gorze maina
                }
                else if(multi.is_within(mouse_pos,multi.getGlobalBounds())==true)
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
                else if(end[0].is_within(mouse_pos,end_button[0].getGlobalBounds())==true)
                {
                    klikniecie.play();
                    ZnikanieElementow(drwal, branch,drzewo,branch2,drzewo2,single,multi, info,logo,text,end_button,  end, window.getSize().x);
                }
                else if(end[1].is_within(mouse_pos,end_button[1].getGlobalBounds())==true)
                {
                    klikniecie.play();
                    ZnikanieElementow(drwal, branch,drzewo,branch2,drzewo2,single,multi, info, logo,text,end_button,  end, window.getSize().x);
                }
                else if(info.is_within(mouse_pos,info.getGlobalBounds())==true)
                {
                    tworcy();
                }
                // Zmiana tekstur w menu ustawien pod klawiszem Escape:
                 Ustawienia_ZmianaTekstury(settings_drzewo, mouse_pos, drzewo, drzewo2, drzewo_, klikniecie);
                 Ustawienia_ZmianaTekstury(settings_drzewo2, mouse_pos, drzewo, drzewo2, drzewo2_, klikniecie);
                 Ustawienia_ZmianaTekstury(settings_tlo, mouse_pos, sky, skyy, klikniecie);
                 Ustawienia_ZmianaTekstury(settings_tlo2, mouse_pos, sky, skyy2, klikniecie);
                 Ustawienia_ZmianaTekstury(settings_drwal, mouse_pos, drwal, drwal_, klikniecie);
                 Ustawienia_ZmianaTekstury(settings_drwal2, mouse_pos, drwal, drwal2_, klikniecie);
            }
            if (event.type == sf::Event::KeyPressed)                //ZMIANA TEKSTURY PRZY UDERZENIU DRWALA
            {
                drwal[0].TeksturaNaUderzenie(sf::Keyboard::Left, sf::Keyboard::Right, window.getSize().x);
                drwal[1].TeksturaNaUderzenie(sf::Keyboard::A, sf::Keyboard::D, window.getSize().x);
            }
            if (event.type == sf::Event::KeyReleased)           //STEROWANIE
            {
                if(drwal[0].getGlobalBounds().left<window.getSize().x)      //zabezpieczenie przed ruchem poza ekranem
                {
                    if (event.key.code == sf::Keyboard::Left)
                    {
                            uderzenie.play();
                        //pasek
                        gra = true;
                        pasek_stanu[0].ZmniejszCzas(elapsed);        //reset czasu na liczniku po uderzeniu oraz ograniczenie limitu maksymalnego czasu do osiagniecia
                        ///uderzenia i pojawianie sie galezi:
                        drwal[0].UderzenieLeft(drzewo, branch, np);
                        //KOLIZJE Z GALEZIA DLA PIERWSZEGO GRACZA
                        KolizjaZGalezia(branch, drwal, 0, smierc, gra, pasek_stanu, text, 0,1, end, end_button, drzewo, paseczekuuu, paseczek);
                        drwal[0].DodajPunkt();
                    }
                    if (event.key.code == sf::Keyboard::Right)
                    {
                       uderzenie.play();
                        gra = true;
                        pasek_stanu[0].ZmniejszCzas(elapsed);                  //reset czasu na liczniku po uderzeniu oraz ograniczenie limitu maksymalnego czasu do osiagniecia
                        ///uderzenia i pojawianie sie galezi:
                        drwal[0].UderzenieRight(drzewo, branch, np);
                        //KOLIZJE Z GALEZIA DLA PIERWSZEGO GRACZA
                        KolizjaZGalezia(branch, drwal, 0, smierc, gra, pasek_stanu, text, 0,1, end, end_button, drzewo, paseczekuuu, paseczek);
                        drwal[0].DodajPunkt();
                    }
                }

                if(drwal[1].getGlobalBounds().left<window.getSize().x)  //zabezpieczenie przed ruchem poza ekranem
                {
                    if (event.key.code == sf::Keyboard::A)
                    {
                            uderzenie2.play();
                        gra2 = true;
                        pasek_stanu[1].ZmniejszCzas(elapsed2);
                        //uderzenia i resp galezi
                        drwal[1].UderzenieLeft(drzewo2, branch2, np2);
                        KolizjaZGalezia(branch2, drwal, 1, smierc, gra2, pasek_stanu, text, 2,3, end, end_button, drzewo2, paseczekuuu2, paseczek2);    //KOLIZJE Z GALEZIA DLA DRUGIEGO GRACZA
                        drwal[1].DodajPunkt();
                    }
                    if (event.key.code == sf::Keyboard::D)
                    {
                        uderzenie2.play();
                        gra2 = true;        //gra jest kontynuowana
                        pasek_stanu[1].ZmniejszCzas(elapsed2);          //reset czasu na liczniku po uderzeniu oraz zmniejszenie limitu do osiagniecia
                        //uderzenia i resp galezi
                        drwal[1].UderzenieRight(drzewo2, branch2, np2);
                        KolizjaZGalezia(branch2, drwal, 1, smierc, gra2, pasek_stanu, text, 2,3, end, end_button, drzewo2, paseczekuuu2, paseczek2);    //KOLIZJE Z GALEZIA DLA DRUGIEGO GRACZA
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
        PaskiOdliczajaceCzas(gra, drwal, paseczek, paseczekuuu, pasek_stanu, 0, drzewo, text, 0, 1, end,end_button,elapsed, smierc, window.getSize().x, window.getSize().y);
        PaskiOdliczajaceCzas(gra2, drwal, paseczek2, paseczekuuu2, pasek_stanu, 1, drzewo2, text, 2, 3, end,end_button,elapsed2, smierc, 250, window.getSize().y);

        // RYSOWANIE WSZYSTKI ELEMENTOW:
        window.draw(sky);                                                        //tlo
        window.draw(logo);                                                       //logo ostrowiecman (na gorze menu glownego)
        window.draw(single);                                                    //przycisk singleplayer
        window.draw(multi);                                                     //przycisk multiplayer
        window.draw(info);                                                       //przycisk informacje (menu glowne po lewej na gorze)
        for (auto &it : drzewo){window.draw(it);}                     //pnie drzewa dla gracza pierwszego
        for (auto &it : drzewo2){window.draw(it);}                  //pnie drzewa dla gracza drugiego
        for (auto &it : branch){window.draw(it);}                       //galezie dla gracza pierwszego
        for (auto &it : branch2){window.draw(it);}                      //galezie dla gracza drugiego
        for (auto &it : end){window.draw(it);}                          //groby po smierci
        for (auto &it : end_button){window.draw(it);}                   //przycisk powrotu do menu
        for (auto &it : drwal){window.draw(it);}                    //no i drwale <3
        window.draw(paseczek);                          //ponizej rysowanie paska odliczajacego czas
        window.draw(paseczek2);
        window.draw(paseczekuuu);
        window.draw(paseczekuuu2);
        for (auto &it : pasek_stanu){window.draw(it);}
        for (auto &it : text){window.draw(it);}         //textboxy
        window.draw(background);            //Ponizej rysowanie okna ustawien
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
