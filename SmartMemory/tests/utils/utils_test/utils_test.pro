QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_utils_test.cpp \
    ../../../memory_prototype/utils/bithelper.cpp \
    ../../../memory_prototype/utils/randomizer.cpp

HEADERS += \
    ../../../memory_prototype/utils/bithelper.h \
    ../../../memory_prototype/utils/randomizer.h
