QT = core
QT += gui
QT += widgets
QT += network
QT += sql

# CONFIG += c++17 cmdline # Linea la Cual hace que se abra la Consola al mismo tiempo que se ejecuta

HEADERS += \
    admindb.h \
    bloqueado.h \
    clima.h \
    form.h \
    formulario.h \
    login.h \
    mapa.h \
    weather.h

SOURCES += \
    admindb.cpp \
    bloqueado.cpp \
    clima.cpp \
    form.cpp \
    formulario.cpp \
    login.cpp \
    main.cpp \
    mapa.cpp \
    weather.cpp
