TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    lib/pen.cpp \
    lib/cpen.cpp \
    aluno/arvore.cpp \
    aluno/fractal01.cpp

HEADERS += \
    lib/cpen.h \
    lib/sfLine.h \
    lib/pen.h


CONFIG += c++11
LIBS += -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
