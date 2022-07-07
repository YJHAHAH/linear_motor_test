#ifndef CIRCLETEST_H
#define CIRCLETEST_H

#include <QObject>
#include"motion.h"
#include<QThread>

class circleTest : public QObject
{
    Q_OBJECT
public:
    explicit circleTest(QObject *parent = nullptr,motion* motion=nullptr);
    void circle_test(int circle_times,int circle_points, double length,double speed,int direction);
    ~circleTest();
    bool stop_flag=false;
private:
    motion* mymotion;
signals:
    void update_process(int circles,int points);
    void test_complete();
    void test_stop();

};

#endif // CIRCLETEST_H
