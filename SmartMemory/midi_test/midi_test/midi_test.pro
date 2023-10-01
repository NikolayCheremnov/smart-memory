QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target



# adding midi library
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../midi/Old/build-MidiManage-Clone_of_Desktop_Qt_5_15_2_MinGW_32_bit-Debug/release/ -lMidiManage
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../midi/Old/build-MidiManage-Clone_of_Desktop_Qt_5_15_2_MinGW_32_bit-Debug/debug/ -lMidiManage

INCLUDEPATH += $$PWD/../../../../../midi/Old/MidiManage
DEPENDPATH += $$PWD/../../../../../midi/Old/MidiManage
