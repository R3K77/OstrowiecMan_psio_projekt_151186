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

void tworcy()
{
    // create the window
        sf::RenderWindow window2(sf::VideoMode(800, 600), "OstrowiecMan - informacje");

        sf::Font font;
        if (!font.loadFromFile("BAHNSCHRIFT.TTF"))
        {
            std::cerr << "Could not load font" << std::endl;
        }

        sf::Texture poli_;
        if(!poli_.loadFromFile("polibuda.png")){
            std::cerr << "Could not load texture" << std::endl;
        }

        Settings poli;
        poli.setTexture(poli_);
        poli.setScale(0.2,0.2);
        poli.setPosition(10,10);
        poli.setOrigin(poli.getGlobalBounds().width,poli.getGlobalBounds().height);


        std::vector<sf::Text> text;
        for (int i=0; i<7; i++) {
            text.emplace_back();
            text[i].setFont(font);
            text[i].setFillColor(sf::Color::White);
            text[i].setCharacterSize(25);
            text[i].setPosition(30,30+30*i);
        }
        text[0].setString("Tworca:   Bartlomiej Szalwach             Nr albumu:   151186");
        text[1].setString("WARiE,    AiR,    sem II,");
        text[2].setString(" ");
        text[3].setString("Dodatkowe informacje:");
        text[4].setString("Pod klawiszem escape znajduje sie panel ustawien tekstur");
        text[5].setString("Lewy gracz - sterowanie A oraz D");
        text[6].setString("Prawy gracz - sterowanie strzalkami lewo i prawo");

        while (window2.isOpen()) {
            sf::Event event;
            while (window2.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window2.close();
            }

            // clear the window with black color
            window2.clear(sf::Color::Black);

            poli.rotate(0.007);
            poli.move(poli.a,poli.b);
            poli.odbijaj();

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
    bool gra=false;
    bool gra2=false;
    bool ustawienia = false;
    double elapsed;
    double elapsed2;
    pasekstanu paseczek;
    pasekstanu paseczek2;
    pasekstanu paseczekuuu;
    pasekstanu paseczekuuu2;
    Labelki background;


    //MUZYKA

    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("uderzenie5.wav")){
        std::cerr << "Could not load texture" << std::endl;
    }
    sf::SoundBuffer buffer_;
    if (!buffer_.loadFromFile("uderzenie6.wav")){
        std::cerr << "Could not load texture" << std::endl;
    }

    sf::SoundBuffer buffer1;
    if (!buffer1.loadFromFile("klik.wav")){
        std::cerr << "Could not load texture" << std::endl;
    }
    sf::SoundBuffer buffer2;
    if (!buffer2.loadFromFile("niepukaj.wav")){
        std::cerr << "Could not load texture" << std::endl;
    }
    sf::SoundBuffer buffer3;
    if (!buffer3.loadFromFile("smierc.wav")){
        std::cerr << "Could not load texture" << std::endl;
    }


    // load something into the sound buffer...

    sf::Sound uderzenie;
    uderzenie.setBuffer(buffer);
    sf::Sound uderzenie2;
    uderzenie2.setBuffer(buffer_);
    sf::Sound niepukaj;
    niepukaj.setBuffer(buffer2);

    sf::Sound klikniecie;
    klikniecie.setBuffer(buffer1);

    sf::Sound smierc;
    smierc.setBuffer(buffer3);






    //CZCIONKA
    sf::Font font;
    if (!font.loadFromFile("BAHNSCHRIFT.TTF"))
    {
        std::cerr << "Could not load font" << std::endl;
    }

    //std::vector<std::unique_ptr<sf::Drawable>> shapes;
    int np=0;
    // create the window
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Ostrowiec Man", sf::Style::Titlebar | sf::Style::Close);
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);




    //TEKSTURY DO USTAWIEN
    sf::Texture ustawieniaa;
    if(!ustawieniaa.loadFromFile("ustawienia.png")){
        std::cerr << "Could not load texture" << std::endl;
    }
    background.setTexture(ustawieniaa);
    background.setPosition(2000,2000);



    //TLO
    sf::Texture skyy2;
    if(!skyy2.loadFromFile("sky2.png")){
        std::cerr << "Could not load texture" << std::endl;
    }
    sf::Texture skyy;
    if(!skyy.loadFromFile("sky.png")){
        std::cerr << "Could not load texture" << std::endl;
    }
    sf::Sprite sky;
    sky.setTexture(skyy2);
    sky.scale(double(window.getSize().x)/skyy.getSize().x,double(window.getSize().y)/skyy.getSize().y);



    //LOGO
    Button logo;
    // auto _logo = std::make_unique<sf::RectangleShape>;
    sf::Texture logo_;
    if(!logo_.loadFromFile("logo.png")){
        std::cerr << "Could not load texture" << std::endl;
    }
    logo.setTexture(logo_);
    logo.scale(0.5,0.5);
    logo.setPosition(window.getSize().x/2-logo.getGlobalBounds().width/2,-50);

    //PRZYCISK SINGLE I MULTI
    Button single;
    Button multi;
    Button info;
    std::vector<Button> end_button;
    std::vector<Button> end;
    sf::Texture single_;
    if(!single_.loadFromFile("singleplayer.png")){
        std::cerr << "Could not load texture" << std::endl;
    }
    sf::Texture multi_;
    if(!multi_.loadFromFile("multiplayer.png")){
        std::cerr << "Could not load texture" << std::endl;
    }
    sf::Texture end_;
    if(!end_.loadFromFile("grob.png")){
        std::cerr << "Could not load texture" << std::endl;
    }
    sf::Texture end_button_;
    if(!end_button_.loadFromFile("end_button.png")){
        std::cerr << "Could not load texture" << std::endl;
    }
    sf::Texture info_;
    if(!info_.loadFromFile("info.png")){
        std::cerr << "Could not load texture" << std::endl;
    }

    single.setTexture(single_);
    multi.setTexture(multi_);
    info.setTexture(info_);
    single.scale(0.6,0.6);
    multi.scale(0.6,0.6);
    info.scale(0.3,0.3);
    single.setPosition(window.getSize().x/2-single.getGlobalBounds().width/2,286);
    multi.setPosition(window.getSize().x/2-multi.getGlobalBounds().width/2,500);
    info.setPosition(30,-60);
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


    //DRZEWO
    sf::Texture drzewo_;
    if(!drzewo_.loadFromFile("wood.png")){
        std::cerr << "Could not load texture" << std::endl;
    }
    sf::Texture drzewo2_;
    if(!drzewo2_.loadFromFile("wood2.png")){
        std::cerr << "Could not load texture" << std::endl;
    }
    std::vector<Drzwo> drzewo;
    for (int i=0; i<6; i++) {
        drzewo.emplace_back();
        drzewo[i].setTexture(drzewo_);
        drzewo[i].setPosition(3000,720);
        drzewo[i].setScale(0.12,0.12);
    }
    std::vector<Drzwo> drzewo2;
    for (int i=0; i<6; i++) {
        drzewo2.emplace_back();
        drzewo2[i].setTexture(drzewo_);
        drzewo2[i].setPosition(3000,720);
        drzewo2[i].setScale(0.12,0.12);
    }

    //GALEZIE
    sf::Texture branch_;
    if(!branch_.loadFromFile("branch.png")){
        std::cerr << "Could not load texture" << std::endl;
    }
    std::vector<Drzwo> branch;
    for (int i=0; i<10; i++) {
        branch.emplace_back();
        branch[i].setTexture(branch_);
        branch[i].setPosition(5000,0);
        branch[i].setScale(0.12,0.12);
    }
    std::vector<Drzwo> branch2;
    for (int i=0; i<10; i++) {
        branch2.emplace_back();
        branch2[i].setTexture(branch_);
        branch2[i].setPosition(5000,0);
        branch2[i].setScale(0.12,0.12);
    }


    //DRWAL
    sf::Texture drwal_;
    if(!drwal_.loadFromFile("drwaldick.png")){
        std::cerr << "Could not load texture" << std::endl;
    }
    sf::Texture drwal_1;
    if(!drwal_1.loadFromFile("drwaldick1.png")){
        std::cerr << "Could not load texture" << std::endl;
    }
    sf::Texture drwal2_;
    if(!drwal2_.loadFromFile("drwalkuba.png")){
        std::cerr << "Could not load texture" << std::endl;
    }
    sf::Texture drwal2_1;
    if(!drwal2_1.loadFromFile("drwalkuba2.png")){
        std::cerr << "Could not load texture" << std::endl;
    }

    sf::Texture drwal_lewo=drwal_;
    sf::Texture drwal_prawo=drwal_1;


    std::vector<Drwal> drwal;
    for (int i=0; i<2; i++) {
        drwal.emplace_back();
        drwal[i].setTexture(drwal_lewo);
        drwal[i].setPosition(3000,720);
        drwal[i].setScale(0.5,0.5);
    }

    //PASEK STANU (ODLICZANIE CZASU)
    sf::Clock timer;
    sf::Clock timer2;
    std::vector<pasekstanu> pasek_stanu;
    for (int i=0; i<2; i++) {
        pasek_stanu.emplace_back();
        pasek_stanu[i].setFillColor(sf::Color::Black);
        pasek_stanu[i].setPosition(500,500);
        pasek_stanu[i].setSize(sf::Vector2f(0,0));
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

    //SETTINGS
    Button settings_tlo;
    settings_tlo.setTexture(skyy);
    settings_tlo.setScale(0.07,0.07);
    settings_tlo.setPosition(2000,2000);
    Button settings_tlo2;
    settings_tlo2.setTexture(skyy2);
    settings_tlo2.setScale(0.07,0.07);
    settings_tlo2.setPosition(2000,2000);
    Button settings_drwal;
    settings_drwal.setTexture(drwal_);
    settings_drwal.setScale(0.3,0.3);
    settings_drwal.setPosition(2000,2000);
    Button settings_drwal2;
    settings_drwal2.setTexture(drwal2_);
    settings_drwal2.setScale(0.3,0.3);
    settings_drwal2.setPosition(2000,2000);
    Button settings_drzewo;
    settings_drzewo.setTexture(drzewo_);
    settings_drzewo.setScale(0.1,0.1);
    settings_drzewo.setPosition(2000,2000);
    Button settings_drzewo2;
    settings_drzewo2.setTexture(drzewo2_);
    settings_drzewo2.setScale(0.1,0.1);
    settings_drzewo2.setPosition(2000,2000);










    // run the program as long as the window is open
    while (window.isOpen()) {

        //PASKI STANU NA GORZE:
        elapsed+=timer.restart().asMicroseconds();
        elapsed2+=timer2.restart().asMicroseconds();


        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();

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
                    klikniecie.play();
                    background.setPosition(2000,2000);
                    ustawienia = false;
                    settings_tlo.Znikaj();
                    settings_tlo2.Znikaj();
                    settings_drwal.Znikaj();
                    settings_drwal2.Znikaj();
                    settings_drzewo.Znikaj();
                    settings_drzewo2.Znikaj();
                    drwal[0].score=0;
                    pasek_stanu[0].delta=1.2;
                    logo.Znikaj();
                    single.Znikaj();
                    multi.Znikaj();
                    //ustawienie drzewa
                    for (int i=0; i<5; i++) {
                        drzewo[i].setPosition(window.getSize().x/2-60,window.getSize().y-(i+2)*144);
                    }
                    //ustawienie drwala
                    drwal[0].setPosition(drzewo[0].getGlobalBounds().left-200,window.getSize().y-300);

                }
                else if(multi.is_within(mouse_pos,multi_bound)==true)
                {
                    klikniecie.play();
                    //GIERKA MULTIPLAYER
                    background.setPosition(2000,2000);
                    ustawienia = false;
                    settings_tlo.Znikaj();
                    settings_tlo2.Znikaj();
                    settings_drwal.Znikaj();
                    settings_drwal2.Znikaj();
                    settings_drzewo.Znikaj();
                    settings_drzewo2.Znikaj();
                    pasek_stanu[0].delta=1.2;
                    pasek_stanu[1].delta=1.2;
                    logo.Znikaj();
                    single.Znikaj();
                    multi.Znikaj();
                    //ustawienie drzewa
                    for (int i=0; i<5; i++) {
                        drzewo2[i].setPosition(window.getSize().x/4-60,window.getSize().y-(i+2)*144);
                    }
                    for (int i=0; i<5; i++) {
                        drzewo[i].setPosition(3*window.getSize().x/4-60,window.getSize().y-(i+2)*144);
                    }
                    drwal[0].setPosition(drzewo[0].getGlobalBounds().left-200,window.getSize().y-300);
                    drwal[1].setPosition(drzewo2[0].getGlobalBounds().left-200,window.getSize().y-300);
                }
                else if(end[0].is_within(mouse_pos,end0_bound)==true)
                {
                    klikniecie.play();
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
                    single.setPosition(window.getSize().x/2-single.getGlobalBounds().width/2,286);
                    multi.setPosition(window.getSize().x/2-multi.getGlobalBounds().width/2,500);
                    logo.setPosition(window.getSize().x/2-logo.getGlobalBounds().width/2,-50);
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
                }
                else if(end[1].is_within(mouse_pos,end1_bound)==true)
                {
                    klikniecie.play();
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
                    single.setPosition(window.getSize().x/2-single.getGlobalBounds().width/2,286);
                    multi.setPosition(window.getSize().x/2-multi.getGlobalBounds().width/2,500);
                    logo.setPosition(window.getSize().x/2-logo.getGlobalBounds().width/2,-50);
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
                        drwal_lewo=drwal_;
                        drwal_prawo=drwal_1;
                        it.setTexture(drwal_);
                    }
                }
                else if(settings_drwal2.is_within(sf::Mouse::getPosition(window),settings_drwal2.getGlobalBounds())==true){
                    for (auto &it : drwal)
                    {
                        klikniecie.play();
                        drwal_lewo=drwal2_;
                        drwal_prawo=drwal2_1;
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
                        drwal[0].setTexture(drwal_prawo);
                    }
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                {
                    if (drwal[1].getGlobalBounds().left<window.getSize().x){
                        drwal[1].setTexture(drwal_prawo);
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

                        int r=rand()%41;
                        if (r==1)
                        {
                            niepukaj.play();
                        }
                        else
                        {
                            uderzenie.play();
                        }

                        //pasek
                        gra = true;
                        elapsed=0;
                        if (pasek_stanu[0].delta<=6)
                        {
                            pasek_stanu[0].delta=pasek_stanu[0].delta+0.01;
                        }
                        //uderzenia i resp galezi
                        drwal[0].setTexture(drwal_lewo);
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
                                smierc.play();
                                gra = false; //koniec paska
                                pasek_stanu[0].setSize(sf::Vector2f(0,0));      //koniec paska
                                paseczek.setSize(sf::Vector2f(0,0));
                                paseczekuuu.setSize(sf::Vector2f(0,0));
                                drwal[0].bestscore=drwal[0].score;
                                end[0].setPosition(drwal[0].getGlobalBounds().left+80, drwal[0].getGlobalBounds().top+20);
                                drwal[0].setPosition(2000,2000);
                                end_button[0].setPosition(drzewo[0].getGlobalBounds().left-60, drzewo[0].getGlobalBounds().top-300);
                                drwal[0].score=0;
                                drwal[0].setScale(0.5,0.5);
                                text[0].setCharacterSize(50);
                                text[0].setString(std::to_string(drwal[0].bestscore));
                                text[0].setPosition(drzewo[0].getGlobalBounds().left+40,
                                        drzewo[0].getGlobalBounds().top-100);
                                text[1].setScale(0.6,0.6);
                                text[1].setString("TWOJ WYNIK TO:");
                                text[1].setPosition(drzewo[0].getGlobalBounds().left+5,
                                        drzewo[0].getGlobalBounds().top-140);
                            }
                        }

                        drwal[0].score=drwal[0].score+1;
                    }
                    if (event.key.code == sf::Keyboard::Right)
                    {
                        int r=rand()%41;
                        if (r==1)
                        {
                            niepukaj.play();
                        }
                        else
                        {
                            uderzenie.play();
                        }

                        //pasek
                        gra = true;
                        elapsed=0;
                        if (pasek_stanu[0].delta<=6)
                        {
                            pasek_stanu[0].delta=pasek_stanu[0].delta+0.01;
                        }
                        //uderzenia i resp galezi
                        drwal[0].setTexture(drwal_lewo);
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
                                smierc.play();
                                gra = false;        //koniec paska
                                pasek_stanu[0].setSize(sf::Vector2f(0,0));  //koniec paska
                                paseczek.setSize(sf::Vector2f(0,0));
                                paseczekuuu.setSize(sf::Vector2f(0,0));
                                drwal[0].bestscore=drwal[0].score;
                                end[0].setPosition(drwal[0].getGlobalBounds().left+80, drwal[0].getGlobalBounds().top+20);
                                drwal[0].setPosition(2000,2000);
                                end_button[0].setPosition(drzewo[0].getGlobalBounds().left-60, drzewo[0].getGlobalBounds().top-300);
                                drwal[0].score=0;
                                drwal[0].setScale(0.5,0.5);
                                text[0].setCharacterSize(50);
                                text[0].setString(std::to_string(drwal[0].bestscore));
                                text[0].setPosition(drzewo[0].getGlobalBounds().left+40,
                                        drzewo[0].getGlobalBounds().top-100);
                                text[1].setScale(0.6,0.6);
                                text[1].setString("TWOJ WYNIK TO:");
                                text[1].setPosition(drzewo[0].getGlobalBounds().left+5,
                                        drzewo[0].getGlobalBounds().top-140);
                            }
                        }
                        drwal[0].score=drwal[0].score+1;

                    }
                }

                if(drwal[1].getGlobalBounds().left<window.getSize().x)  //zabezpieczenie przed ruchem poza ekranem
                {
                    if (event.key.code == sf::Keyboard::A)
                    {
                        int r=rand()%21;
                        if (r==1)
                        {
                            niepukaj.play();
                        }
                        else
                        {
                            uderzenie2.play();
                        }
                        //pasek
                        gra2 = true;
                        elapsed2=0;
                        if (pasek_stanu[1].delta<=6)
                        {
                            pasek_stanu[1].delta=pasek_stanu[1].delta+0.01;
                        }
                        //uderzenia i resp galezi
                        drwal[1].setTexture(drwal_lewo);
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
                                pasek_stanu[1].setSize(sf::Vector2f(0,0));      //koniec paska
                                paseczek2.setSize(sf::Vector2f(0,0));
                                paseczekuuu2.setSize(sf::Vector2f(0,0));
                                drwal[1].bestscore=drwal[1].score;
                                end[1].setPosition(drwal[1].getGlobalBounds().left+80, drwal[1].getGlobalBounds().top+20);
                                drwal[1].setPosition(2000,2000);
                                end_button[1].setPosition(drzewo2[0].getGlobalBounds().left-60, drzewo2[0].getGlobalBounds().top-300);
                                drwal[1].score=0;
                                drwal[1].setScale(0.5,0.5);
                                text[2].setCharacterSize(50);
                                text[2].setString(std::to_string(drwal[1].bestscore));
                                text[2].setPosition(drzewo2[0].getGlobalBounds().left+40,
                                        drzewo2[0].getGlobalBounds().top-100);
                                text[3].setScale(0.6,0.6);
                                text[3].setString("TWOJ WYNIK TO:");
                                text[3].setPosition(drzewo2[0].getGlobalBounds().left+5,
                                        drzewo2[0].getGlobalBounds().top-140);
                            }
                        }
                        drwal[1].score=drwal[1].score+1;
                    }
                    if (event.key.code == sf::Keyboard::D)
                    {
                        int r=rand()%21;
                        if (r==1)
                        {
                            niepukaj.play();
                        }
                        else
                        {
                            uderzenie2.play();
                        }
                        //pasek
                        gra2 = true;
                        elapsed2=0;
                        if (pasek_stanu[1].delta<=6)
                        {
                            pasek_stanu[1].delta=pasek_stanu[1].delta+0.01;
                        }
                        //uderzenia i resp galezi
                        drwal[1].setTexture(drwal_lewo);
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
                                gra2=false; //koniec paska
                                pasek_stanu[1].setSize(sf::Vector2f(0,0));  //koniec paska
                                paseczek2.setSize(sf::Vector2f(0,0));
                                paseczekuuu2.setSize(sf::Vector2f(0,0));
                                drwal[1].bestscore=drwal[1].score;
                                end[1].setPosition(drwal[1].getGlobalBounds().left+80, drwal[1].getGlobalBounds().top+20);
                                drwal[1].setPosition(2000,2000);
                                end_button[1].setPosition(drzewo2[0].getGlobalBounds().left-60, drzewo2[0].getGlobalBounds().top-300);
                                drwal[1].score=0;
                                drwal[1].setScale(0.5,0.5);
                                text[2].setCharacterSize(50);
                                text[2].setString(std::to_string(drwal[1].bestscore));
                                text[2].setPosition(drzewo2[0].getGlobalBounds().left+40,
                                        drzewo2[0].getGlobalBounds().top-100);
                                text[3].setScale(0.6,0.6);
                                text[3].setString("TWOJ WYNIK TO:");
                                text[3].setPosition(drzewo2[0].getGlobalBounds().left+5,
                                        drzewo2[0].getGlobalBounds().top-140);

                            }
                        }
                        drwal[1].score=drwal[1].score+1;
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
                            settings_tlo2.rysuj(0,2);
                            settings_drwal.rysuj(1,1);
                            settings_drwal2.rysuj(1,2);
                            settings_drzewo.rysuj(2,1);
                            settings_drzewo2.rysuj(2,2);


                        }
                        else
                        {
                            background.setPosition(2000,2000);
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


        //ZABAWA Z PASKIEM STANU, TEN OD CZASU :(((

        if (gra==true)
        {
            paseczek.setSize(sf::Vector2f(206,26));
            paseczek.setFillColor(sf::Color::Black);
            paseczek.setPosition(drzewo[0].getGlobalBounds().left+drzewo[0].getGlobalBounds().width+17-200,7);
            paseczekuuu.setSize(sf::Vector2f(200,20));
            paseczekuuu.setFillColor(sf::Color::Red);
            paseczekuuu.setPosition(drzewo[0].getGlobalBounds().left+drzewo[0].getGlobalBounds().width+20-200,10);
            pasek_stanu[0].setPosition(drzewo[0].getGlobalBounds().left+drzewo[0].getGlobalBounds().width+20,10);
            if(pasek_stanu[0].getGlobalBounds().width<=200)
            {
                pasek_stanu[0].setSize(sf::Vector2f(-elapsed*pasek_stanu[0].delta/10000, 20));
                text[0].setCharacterSize(50);
                text[0].setString(std::to_string(drwal[0].score));
                text[0].setPosition(window.getSize().x-text[0].getGlobalBounds().width-10,
                        window.getSize().y-text[0].getGlobalBounds().height-20);
                text[1].setScale(1,1);
                text[1].setString("TWOJ WYNIK TO:");
                text[1].setPosition(window.getSize().x-text[1].getGlobalBounds().width-10,
                        window.getSize().y-100);
            }
            else    //koniec gry
            {
                smierc.play();
                gra = false; //koniec paska
                pasek_stanu[0].setSize(sf::Vector2f(0,0));      //koniec paska
                drwal[0].bestscore=drwal[0].score;
                end[0].setPosition(drwal[0].getGlobalBounds().left+80, drwal[0].getGlobalBounds().top+20);
                drwal[0].setPosition(2000,2000);
                end_button[0].setPosition(drzewo[0].getGlobalBounds().left-60, drzewo[0].getGlobalBounds().top-300);
                drwal[0].score=0;
                drwal[0].setScale(0.5,0.5);
                text[0].setCharacterSize(50);
                text[0].setString(std::to_string(drwal[0].bestscore));
                text[0].setPosition(drzewo[0].getGlobalBounds().left+40,
                        drzewo[0].getGlobalBounds().top-100);
                text[1].setScale(0.6,0.6);
                text[1].setString("TWOJ WYNIK TO:");
                text[1].setPosition(drzewo[0].getGlobalBounds().left+5,
                        drzewo[0].getGlobalBounds().top-140);
                paseczekuuu.setSize(sf::Vector2f(0,0));
                paseczek.setSize(sf::Vector2f(0,0));
            }
        }
        if (gra2==true)
        {
            paseczek2.setSize(sf::Vector2f(206,26));
            paseczek2.setFillColor(sf::Color::Black);
            paseczek2.setPosition(drzewo2[0].getGlobalBounds().left+drzewo2[0].getGlobalBounds().width+17-200,7);
            paseczekuuu2.setSize(sf::Vector2f(200,20));
            paseczekuuu2.setFillColor(sf::Color::Red);
            paseczekuuu2.setPosition(drzewo2[0].getGlobalBounds().left+drzewo2[0].getGlobalBounds().width+20-200,10);
            pasek_stanu[1].setPosition(drzewo2[0].getGlobalBounds().left+drzewo2[0].getGlobalBounds().width+20,10);

            if(pasek_stanu[1].getGlobalBounds().width<=200)
            {
                pasek_stanu[1].setSize(sf::Vector2f(-elapsed2*pasek_stanu[1].delta/10000, 20));
                text[2].setCharacterSize(50);
                text[2].setString(std::to_string(drwal[1].score));
                text[2].setPosition(10,
                                    window.getSize().y-text[2].getGlobalBounds().height-20);
                text[3].setScale(1,1);
                text[3].setString("TWOJ WYNIK TO:");
                text[3].setPosition(10,
                                    window.getSize().y-100);

            }
            else    //koniec gry
            {
                smierc.play();
                gra2=false;     //koniec paska
                pasek_stanu[1].setSize(sf::Vector2f(0,0));      //koniec paska
                paseczek2.setSize(sf::Vector2f(0,0));
                paseczekuuu2.setSize(sf::Vector2f(0,0));
                drwal[1].bestscore=drwal[1].score;
                end[1].setPosition(drwal[1].getGlobalBounds().left+80, drwal[1].getGlobalBounds().top+20);
                drwal[1].setPosition(2000,2000);
                end_button[1].setPosition(drzewo2[0].getGlobalBounds().left-60, drzewo2[0].getGlobalBounds().top-300);
                drwal[1].score=0;
                drwal[1].setScale(0.5,0.5);
                text[2].setCharacterSize(50);
                text[2].setString(std::to_string(drwal[1].bestscore));
                text[2].setPosition(drzewo2[0].getGlobalBounds().left+40,
                        drzewo2[0].getGlobalBounds().top-100);
                text[3].setScale(0.6,0.6);
                text[3].setString("TWOJ WYNIK TO:");
                text[3].setPosition(drzewo2[0].getGlobalBounds().left+5,
                        drzewo2[0].getGlobalBounds().top-140);
            }
        }





        // clear the window with black color, zamalowujemy; zostawia czarne okno
        window.clear(sf::Color::Black);

        // draw everything here...
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

        // end the current frame
        window.display();
    }
    return 0;
}
