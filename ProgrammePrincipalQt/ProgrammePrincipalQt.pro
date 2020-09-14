TEMPLATE = app
TARGET = ProgrammePrincipalQt
QT += core \
    gui
HEADERS += desinscriptionpersonne.h \
    electeurinterface.h \
    candidatinterface.h \
    programmeprincipalqt.h
SOURCES += desinscriptionpersonne.cpp \
    electeurinterface.cpp \
    candidatinterface.cpp \
    main.cpp \
    programmeprincipalqt.cpp
FORMS += desinscriptionpersonne.ui \
    electeurinterface.ui \
    candidatinterface.ui \
    programmeprincipalqt.ui
RESOURCES += 
LIBS += "../source/Debug/libsource.a"
INCLUDEPATH += "../source/."
