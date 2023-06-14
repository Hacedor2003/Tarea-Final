TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    Logica/Logica.c \
    Interfaz/Menus.c \
    Interfaz/Salidas.c \
    Interfaz/validacion.c

HEADERS += \
    Logica/Datos.h \
    Logica/Logica.h \
    Interfaz/Menus.h \
    Interfaz/Salidas.h \
    Interfaz/validacion.h

