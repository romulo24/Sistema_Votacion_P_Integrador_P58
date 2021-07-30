QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    acercade.cpp \
    administrador.cpp \
    certifiicado.cpp \
    estadistica.cpp \
    login.cpp \
    main.cpp \
    usuarios.cpp \
    votacion.cpp \
    votante.cpp

HEADERS += \
    acercade.h \
    administrador.h \
    certifiicado.h \
    estadistica.h \
    login.h \
    usuarios.h \
    votacion.h \
    votante.h

FORMS += \
    acercade.ui \
    administrador.ui \
    certifiicado.ui \
    estadistica.ui \
    login.ui \
    votacion.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Recursos.qrc
