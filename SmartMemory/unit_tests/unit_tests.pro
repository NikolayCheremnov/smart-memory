TEMPLATE = app
CONFIG -= qt
CONFIG -= app_bundle
CONFIG += console

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

HEADERS += \

SOURCES += \
    main.cpp

