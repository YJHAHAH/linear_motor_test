#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#pragma execution_character_set("utf-8")
#include <QMainWindow>
#include "motion.h"
#include "board.h"
#include "circletest.h"
#include "statusobserve.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    friend class mythread;
    MainWindow(QWidget *parent = nullptr);
    void Board_init();
    void Axis_enable();
    void Axis_disable();
    void Board_close();
    void Speed_move( int direction);
    void Move_stop();
    void Position_move(int direction);
    void Home_move();
    void update_status(double pos,int status_word);
    void circle_test(int direction);
    void circle_stop();
    void circle_comlete();
    void test_stop();
    void circle_process(int circles,int points);
    void observe_stop();
    void quit_thread(QThread* thread);
    ~MainWindow();
    signals:
    void  circle_start(int circle_times,int circle_points, double length,double speed,int direction);

private:
    Ui::MainWindow *ui;
    board* myboard;
    motion* mymotion;
    QThread* mythread1;
    QThread* mythread2;
    statusObserve* myobserver;
    circleTest* mytest;
};
#endif // MAINWINDOW_H
