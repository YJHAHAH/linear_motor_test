#include "statusobserve.h"

statusObserve::statusObserve(QObject *parent,board* board) : QObject(parent),myboard(board){}
void statusObserve:: status_update()
{

    double pos;
    WORD status_word;
    WORD ConnectNo(myboard->ConnectNo);
    WORD axis(myboard->axis);
    while(1)
    {
    smc_get_position_unit(ConnectNo,axis,&pos);
    nmcs_get_axis_state_machine(ConnectNo,axis,&status_word);

    emit status( pos,int(status_word));
    QThread::msleep(500);//线程睡眠500ms
    if(stop_flag) break;
    }


}
 statusObserve::~statusObserve()
 {
     myboard=nullptr;
 }
