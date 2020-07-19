#include "mainwindow.h"

#include <QApplication>
#include <QtMultimedia/qmediaplayer.h>
#include "QMediaPlaylist"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();



    QMediaPlaylist *playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("qrc:/new/prefix1/resource/bgm.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    QMediaPlayer *music = new QMediaPlayer();
    music->setPlaylist(playlist);
    music->play();



    return a.exec();
}
