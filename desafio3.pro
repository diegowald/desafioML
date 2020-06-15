TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt

DEFINES += DATABASE_PGSQL

SOURCES += \
        DTO-odb.cxx \
        dnaanalyzer.cpp \
        dnaparser.cpp \
        mainVersion3.cpp \
        statisticscalculator.cpp \
        statisticsparser.cpp

HEADERS += \
  DTO-odb.hxx \
  database.hpp \
  dnaanalyzer.h \
  dnaparser.h \
  DTO.h \
  statisticscalculator.h \
  statisticsparser.h

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/served/lib/release/ -lserved
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/served/lib/debug/ -lserved
else:unix: LIBS += -L$$PWD/served/lib/ -lserved


INCLUDEPATH += $$PWD/served/src
DEPENDPATH += $$PWD/served/src

# For asio
LIBS += -lpthread -lboost_system -lboost_date_time


# For ODB
LIBS += -L$$PWD/third-party/libodb-2.4.0/odb/.libs/ -lodb

INCLUDEPATH += $$PWD/third-party/libodb-2.4.0/odb/libs
DEPENDPATH += $$PWD/third-party/libodb-2.4.0/odb/libs

LIBS += -L$$PWD/third-party/libodb-pgsql-2.4.0/odb/pgsql/.libs/ -lodb-pgsql

INCLUDEPATH += $$PWD/third-party/libodb-2.4.0/odb/libs
DEPENDPATH += $$PWD/third-party/libodb-2.4.0/odb/libs


LIBS += -L$$PWD/libodb-boost-2.4.0/odb/boost/.libs/ -lodb-boost

DISTFILES += \
  DTO-odb.ixx
