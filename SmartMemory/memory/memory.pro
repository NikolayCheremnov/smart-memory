QT -= gui

TEMPLATE = lib
DEFINES += MEMORY_LIBRARY

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    graph/boostmemorygraph.cpp \
    graph/memorygraph.cpp \
    memory.cpp

HEADERS += \
    graph/boostmemorygraph.h \
    graph/memorygraph.h \
    memory_global.h \
    memory.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target


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
