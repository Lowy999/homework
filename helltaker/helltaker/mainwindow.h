#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <ui_mainwindow.h>
#include "public.h"
#include "gameengine.h"
#include "board.h"
#include <windows.h>
#include <QApplication>
#include <QTime>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void succeed_fail();
    void paintEvent(QPaintEvent *) override;
    void keyPressEvent(QKeyEvent * event) override;
    ~MainWindow();

public slots:
    void push_btn_1();
    void push_btn_2();


private:
    Ui::MainWindow *ui;
    gameEngine* ge;
    int step;
    int blood;
    int where;
    bool fail;
    bool succeed;
    bool finally_succeed;
};

#endif // MAINWINDOW_H
