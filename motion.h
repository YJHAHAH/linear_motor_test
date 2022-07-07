#ifndef MOTION_H
#define MOTION_H

#include<QObject>
#include"LTSMC.h"
#include"board.h"
class motion : public QObject
{
    Q_OBJECT
public:
    explicit motion(QObject *parent = nullptr,board *_board=nullptr);
    void motion_init(board *_board);
    WORD home_move();
    WORD speed_move();
    WORD position_move();
    WORD position_move(double Speed,int Direction,double Position);
    WORD stop_move();
    ~motion ();
    void set_posi_mode(WORD Posi_mode);
    void set_speed(double Speed);
    void set_position(double Position);
    void set_direction_p(int Direction);
    void set_direction_v(int Direction);
    void set_convert(double Convert_const);
    void set_home(WORD home_mode);
    double get_count_convert();
private:
    board *m_board;
    unsigned int axis_number;
    WORD posi_mode=0;//0 相对坐标 1 绝对坐标
    double speed=5;//速度 mm
    double startVel ; // 起始速度
    double maxVel = 12000; // 运行速度，counts 2mm/s
    double Tacc ; // 加速时间
    double Tdec ; // 减速时间
    double stopVel ; // 停止速度
    double position;//距离
    int direction_v;//方向 速度运转
    int direction_p;//方向 位置运转
    double count_convert =6000;
    WORD home_dir=1;
    WORD home_mode=2;
signals:

};

#endif // MOTION_H
