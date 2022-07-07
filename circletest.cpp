 #include "circletest.h"

circleTest::circleTest(QObject *parent,motion* motion) : QObject(parent),mymotion(motion){}
void circleTest::circle_test(int circle_times,int circle_points, double length,double speed,int direction)
{
    int temp=circle_points;
    int circle_cnt=circle_times*2;
    while(circle_cnt>0)
    {
        while(circle_points>0)
        {
           mymotion->position_move(speed,direction,length);
           emit update_process(circle_cnt, circle_points);
            QThread::msleep(5000);//延时5s
            if(stop_flag)
            {
                mymotion->stop_move();
                emit test_stop();
                return;
            }
            circle_points--;
        }
        direction*=-1;
        circle_points=temp;
        circle_cnt--;
    }
    emit test_complete();

}
circleTest::~circleTest()
{
    mymotion=nullptr;
}
