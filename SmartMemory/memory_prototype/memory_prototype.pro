QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        algorithms/column/icolumnactivationstrategy.cpp \
        algorithms/column/simplepercentagecolumnactivationstrategy.cpp \
        algorithms/randommemoryregioninitializer.cpp \
        algorithms/synapse/isynapseactivationstrategy.cpp \
        algorithms/synapse/simplethresholdsynapseactivationstrategy.cpp \
        graph_utils/dotgenerator.cpp \
        main.cpp \
        model/corticalcolumn.cpp \
        model/dendriticsegment.cpp \
        model/memorycell.cpp \
        model/memoryregion.cpp \
        model/memorystructure.cpp \
        model/synapse.cpp \
        utils/randomizer.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    algorithms/column/icolumnactivationstrategy.h \
    algorithms/column/simplepercentagecolumnactivationstrategy.h \
    algorithms/randommemoryregioninitializer.h \
    algorithms/synapse/isynapseactivationstrategy.h \
    algorithms/synapse/simplethresholdsynapseactivationstrategy.h \
    graph_utils/dotgenerator.h \
    model/corticalcolumn.h \
    model/datatypes.h \
    model/dendriticsegment.h \
    model/memorycell.h \
    model/memoryregion.h \
    model/memorystructure.h \
    model/synapse.h \
    utils/randomizer.h

# adding boost
greaterThan(QT_MAJOR_VERSION, 4) {
    TARGET_ARCH=$${QT_ARCH}
} else {
    TARGET_ARCH=$${QMAKE_HOST.arch}
}

contains(TARGET_ARCH, x86_64) {
    ARCHITECTURE = x64
} else {
    ARCHITECTURE = x86
}

win32-g++:contains(ARCHITECTURE, x86): {
    INCLUDEPATH += D:/DevKit/boost/boost_1_82_0/boost_mingw810_32/include/boost-1_82
}
