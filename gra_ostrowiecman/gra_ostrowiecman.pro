TEMPLATE = app
CONFIG += console c++19
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += "C:/SFML-2.5.1/include"

LIBS += -L"C:/SFML-2.5.1/lib"
CONFIG(debug, debug|release){
    LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-system-d -lsfml-window-d
} else {
    LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window
}

SOURCES += \
        button.cpp \
        drwal.cpp \
        drzwo.cpp \
        funkcjevoid.cpp \
        labelki.cpp \
        main.cpp \
        pasekstanu.cpp \
        settings.cpp \
        tekstura.cpp \
        textbox.cpp

HEADERS += \
    button.h \
    drwal.h \
    drzwo.h \
    funkcjevoid.h \
    pasekstanu.h \
    settings.h \
    tekstura.h \
    textbox.h
