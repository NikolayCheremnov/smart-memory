QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        algorithms/cell/icellsidefeedactivationstrategy.cpp \
        algorithms/cell/sufficientcellactivationstrategy.cpp \
        algorithms/inhibition/iinhibitionastrategy.cpp \
        algorithms/inhibition/localthresholdinhibitionstrategy.cpp \
        algorithms/input/bytearrsignal.cpp \
        algorithms/input/inputsignalbase.cpp \
        algorithms/column/bitscountinputstrategy.cpp \
        algorithms/column/icolumnactivationstrategy.cpp \
        algorithms/column/icolumninputstrategy.cpp \
        algorithms/column/percentagecolumnactivationstrategy.cpp \
        algorithms/learning/ilearningstrategy.cpp \
        algorithms/learning/standardlearningstrategy.cpp \
        algorithms/overlap/ioverlappingstrategy.cpp \
        algorithms/initializer/randommemoryregioninitializer.cpp \
        algorithms/overlap/minoverlappingstrategy.cpp \
        algorithms/segment/isegmentactivationstrategy.cpp \
        algorithms/segment/percentagesegmentactivationstrategy.cpp \
        algorithms/sensor/charsensor.cpp \
        algorithms/sensor/ipulsedispatcher.cpp \
        algorithms/sensor/isensor.cpp \
        algorithms/sensor/mappulsedispatcher.cpp \
        algorithms/spatial/ispatialviewsrategy.cpp \
        algorithms/spatial/localradiusspatialviewstrategy.cpp \
        algorithms/synapse/isynapseactivationstrategy.cpp \
        algorithms/synapse/simplethresholdsynapseactivationstrategy.cpp \
        algorithms/temporal/enoughstatelearningstrategy.cpp \
        algorithms/temporal/ilateralcatalyst.cpp \
        algorithms/temporal/ilateralinhibitor.cpp \
        algorithms/temporal/irecognitionstrategy.cpp \
        algorithms/temporal/itemporallearningstrategy.cpp \
        algorithms/temporal/linearlateralbooster.cpp \
        algorithms/temporal/temporalstatesrecognitionstrategy.cpp \
        factory/model/corticalcolumnfactory.cpp \
        factory/model/dendriticsegmentfactory.cpp \
        factory/model/memorycellfactory.cpp \
        factory/model/memoryregionfactory.cpp \
        factory/model/synapsefactory.cpp \
        graph_utils/dotgenerator.cpp \
        graph_utils/graphvizimagegenerator.cpp \
        main.cpp \
        model/corticalcolumn.cpp \
        model/dendriticsegment.cpp \
        model/memorycell.cpp \
        model/memoryregion.cpp \
        model/memorystructure.cpp \
        model/synapse.cpp \
        utils/bithelper.cpp \
        utils/randomizer.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    algorithms/cell/icellsidefeedactivationstrategy.h \
    algorithms/cell/sufficientcellactivationstrategy.h \
    algorithms/inhibition/iinhibitionastrategy.h \
    algorithms/inhibition/localthresholdinhibitionstrategy.h \
    algorithms/input/bytearrsignal.h \
    algorithms/input/input.h \
    algorithms/input/inputsignalbase.h \
    algorithms/column/bitscountinputstrategy.h \
    algorithms/column/icolumnactivationstrategy.h \
    algorithms/column/icolumninputstrategy.h \
    algorithms/column/percentagecolumnactivationstrategy.h \
    algorithms/learning/ilearningstrategy.h \
    algorithms/learning/standardlearningstrategy.h \
    algorithms/overlap/ioverlappingstrategy.h \
    algorithms/initializer/randommemoryregioninitializer.h \
    algorithms/overlap/minoverlappingstrategy.h \
    algorithms/segment/isegmentactivationstrategy.h \
    algorithms/segment/percentagesegmentactivationstrategy.h \
    algorithms/segment/segment.h \
    algorithms/sensor/charsensor.h \
    algorithms/sensor/ipulsedispatcher.h \
    algorithms/sensor/isensor.h \
    algorithms/sensor/mappulsedispatcher.h \
    algorithms/sensor/sensor.h \
    algorithms/spatial/ispatialviewsrategy.h \
    algorithms/spatial/localradiusspatialviewstrategy.h \
    algorithms/synapse/isynapseactivationstrategy.h \
    algorithms/synapse/simplethresholdsynapseactivationstrategy.h \
    algorithms/temporal/enoughstatelearningstrategy.h \
    algorithms/temporal/ilateralcatalyst.h \
    algorithms/temporal/ilateralinhibitor.h \
    algorithms/temporal/irecognitionstrategy.h \
    algorithms/temporal/itemporallearningstrategy.h \
    algorithms/temporal/linearlateralbooster.h \
    algorithms/temporal/temporal.h \
    algorithms/temporal/temporalstatesrecognitionstrategy.h \
    factory/model/corticalcolumnfactory.h \
    factory/model/dendriticsegmentfactory.h \
    factory/model/memorycellfactory.h \
    factory/model/memoryregionfactory.h \
    factory/model/synapsefactory.h \
    graph_utils/dotgenerator.h \
    graph_utils/graphvizimagegenerator.h \
    model/corticalcolumn.h \
    model/datatypes.h \
    model/dendriticsegment.h \
    model/memorycell.h \
    model/memoryregion.h \
    model/memorystructure.h \
    model/synapse.h \
    utils/bithelper.h \
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
