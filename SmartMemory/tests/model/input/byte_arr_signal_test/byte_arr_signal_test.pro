QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_bytearrsignal_test.cpp \
    ../../../../memory_prototype/algorithms/input/bytearrsignal.cpp \
    ../../../../memory_prototype/algorithms/input/inputsignalbase.cpp

HEADERS += \
    ../../../../memory_prototype/algorithms/input/bytearrsignal.h \
    ../../../../memory_prototype/algorithms/input/inputsignalbase.h
