QT = core
QT += widgets

SOURCES += \
    formulario.cpp \
    login.cpp \
    main.cpp \
    ej14.cpp

HEADERS += \
    ej14.h \
    formulario.h \
    login.h

FORMS += \
    ej14.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
