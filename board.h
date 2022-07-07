#ifndef BOARD_H
#define BOARD_H
#pragma once
#include <QObject>
#include"LTSMC.h"
#include<QHash>
class motion;
class statusObserve;
//struct Axis
//{
//    double S_para = 0.1; // S 段时间
//    WORD _axis = 0; //运动轴
//    WORD outmode = 0; //脉冲输出模式,脉冲+方向
//    double equiv = 1;//脉冲当量，6000units电机走1mm
//    unsigned long errcode = 0; //总线错误代码
//    WORD axis_statematine=0;//轴状态机
//    double pos;//编码器位置
//    WORD ConnectNo=0;
//};

class board : public QObject
{
    Q_OBJECT
public:
    friend class motion;
    friend class statusObserve;
    explicit board(QObject *parent = nullptr);
    int _board_init();
    int _axis_enable();
    bool _axis_disable();
    bool _board_close();
    WORD _get_status();
    void change_axis_number(unsigned int axis_number);
    void change_connect(WORD connect_no,WORD connect_type,char* connect_com,DWORD connect_baud);
private:
    WORD ConnectNo = 0; //连接号，可选0--7
    WORD type = 2; //Type 链接类型：1-串口，2-网口
    char* com = "192.168.5.11";//IP地址
    DWORD baud=115200;//波特率
    //QHash<int,Axis*> _axises;//轴库
    int axis=0;//轴号
     double S_para = 0.1; // S 段时间
     WORD outmode = 0; //脉冲输出模式,脉冲+方向
     double equiv = 1;//脉冲当量，6000units电机走1mm

signals:

};

#endif // BOARD_H
