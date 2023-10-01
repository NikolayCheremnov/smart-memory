#include <QCoreApplication>

#include <iostream>

#include <midimanage.h>

void read_midi_file();
void read_all_events_midi_file();

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    read_all_events_midi_file();

    return a.exec();
}

void read_all_events_midi_file() {
    MidiManage manager("D:\\CherepNick\\ASTU\\magistracy\\diploma\\project\\smart-memory\\build-SmartMemory-Desktop_Qt_5_15_2_MinGW_32_bit-Debug\\midi_test\\midi_test\\debug\\programmatic.mid", "0");
    auto events = manager.events();
    for (auto event : events) {
        //
        manager.playRecordSound(10, 65, 110, 1000);
    }
}

void read_midi_file() {
    MidiManage manager("D:\\CherepNick\\ASTU\\magistracy\\diploma\\project\\smart-memory\\build-SmartMemory-Desktop_Qt_5_15_2_MinGW_32_bit-Debug\\midi_test\\midi_test\\debug\\programmatic.mid", "0");
//    qDebug() << manager.greetings();
//    qDebug() << manager.devices();
//    qDebug() << manager.getFileDuration();

    //manager.loadFile("K:\\TestMidi\\CrazyFrog.mid");
    //manager.connectOut("0");

    //QObject::connect(&manager, SIGNAL(finished()), &a, SLOT(quit()));


    std::string choice = "play";
    if (choice == "play") {
        manager.play();
    }
    if (choice == "pause") {
        manager.pause();
    }
    if (choice == "stop") {
        manager.stop();
    }

}
