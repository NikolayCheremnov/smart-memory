QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

INCLUDEPATH += ../../../../memory_prototype

SOURCES += \
    ../../../../memory_prototype/factory/model/corticalcolumnfactory.cpp \
    ../../../../memory_prototype/factory/model/dendriticsegmentfactory.cpp \
    ../../../../memory_prototype/factory/model/memorycellfactory.cpp \
    ../../../../memory_prototype/factory/model/synapsefactory.cpp \
    tst_algorithmscolumn_test.cpp \
    ../../../../memory_prototype/algorithms/column/bitscountinputstrategy.cpp \
    ../../../../memory_prototype/algorithms/column/icolumnactivationstrategy.cpp \
    ../../../../memory_prototype/algorithms/column/icolumninputstrategy.cpp \
    ../../../../memory_prototype/algorithms/column/percentagecolumnactivationstrategy.cpp \
    ../../../../memory_prototype/model/corticalcolumn.cpp \
    ../../../../memory_prototype/model/dendriticsegment.cpp \
    ../../../../memory_prototype/model/input/bytearrsignal.cpp \
    ../../../../memory_prototype/model/input/inputsignalbase.cpp \
    ../../../../memory_prototype/model/memorycell.cpp \
    ../../../../memory_prototype/model/memoryregion.cpp \
    ../../../../memory_prototype/model/memorystructure.cpp \
    ../../../../memory_prototype/model/synapse.cpp \
    ../../../../memory_prototype/utils/bithelper.cpp

HEADERS += \
    ../../../../memory_prototype/algorithms/column/bitscountinputstrategy.h \
    ../../../../memory_prototype/algorithms/column/icolumnactivationstrategy.h \
    ../../../../memory_prototype/algorithms/column/icolumninputstrategy.h \
    ../../../../memory_prototype/algorithms/column/percentagecolumnactivationstrategy.h \
    ../../../../memory_prototype/factory/model/corticalcolumnfactory.h \
    ../../../../memory_prototype/factory/model/dendriticsegmentfactory.h \
    ../../../../memory_prototype/factory/model/memorycellfactory.h \
    ../../../../memory_prototype/factory/model/synapsefactory.h \
    ../../../../memory_prototype/model/corticalcolumn.h \
    ../../../../memory_prototype/model/datatypes.h \
    ../../../../memory_prototype/model/dendriticsegment.h \
    ../../../../memory_prototype/model/input/bytearrsignal.h \
    ../../../../memory_prototype/model/input/inputsignalbase.h \
    ../../../../memory_prototype/model/memorycell.h \
    ../../../../memory_prototype/model/memoryregion.h \
    ../../../../memory_prototype/model/memorystructure.h \
    ../../../../memory_prototype/model/synapse.h \
    ../../../../memory_prototype/utils/bithelper.h

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
