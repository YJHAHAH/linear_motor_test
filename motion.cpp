#include "motion.h"

motion::motion(QObject *parent,board*_board) : QObject(parent){
    motion_init(_board);
}
void motion::motion_init(board*_board)
{
    m_board=_board;
}
WORD motion::home_move()
{
    //unsigned long errcode = 0; //总线错误代码
    WORD axis_statematine=0;//轴状态机
    nmcs_get_axis_state_machine( m_board->ConnectNo,m_board->axis, &axis_statematine);
    if(axis_statematine!=4)
    {
        return 1;
    }
    else{
        this->stop_move();//先停止
        //回零方式参考驱动器，18为正限位上升沿回零，有index信号后改为1或2（第3个数字）
        smc_set_homemode(m_board->ConnectNo, m_board->axis,home_dir,1,home_mode,0);//负向 //默认值 //模式1 负限位+EZ  //脉冲计数
        //起始速度1mm/s,回零速度10mm/s,加速时间,保留值0
        smc_set_home_profile_unit(m_board->ConnectNo, m_board->axis,5*count_convert,10*count_convert,double(1/600),0);//0.02s停止 10mm/s
        smc_home_move(m_board->ConnectNo, m_board->axis);
        WORD state;
        smc_get_home_result(m_board->ConnectNo, m_board->axis,&state);
        if(state==1)//回零完成后指令清零
        {
        smc_set_position_unit(m_board->ConnectNo, m_board->axis,0);
        smc_set_encoder_unit(m_board->ConnectNo, m_board->axis, 0); // 指定轴的编码器位 置清零
        }
        return 0;
    }
}
WORD motion::speed_move()
{
    //unsigned long errcode = 0; //总线错误代码
    WORD axis_statematine=0;//轴状态机
    nmcs_get_axis_state_machine( m_board->ConnectNo, m_board->axis, &axis_statematine);
    if(axis_statematine!=4)
    {
        return 1;
    }
   else
    {
        maxVel = speed*count_convert;//速度设置为5mm/s;
        stopVel=0.1*maxVel;
        startVel=0.1*maxVel;
        Tacc=0.006*maxVel/count_convert;
        Tdec=0.006*maxVel/count_convert;
        smc_set_profile_unit( m_board->ConnectNo, m_board->axis, startVel, maxVel, Tacc, Tdec, stopVel);
        smc_vmove(m_board->ConnectNo, m_board->axis, direction_v); //direction_v 1正 0负
        return 0;
    }
}
WORD motion::position_move()
{    //unsigned long errcode = 0; //总线错误代码
    WORD axis_statematine=0;//轴状态机
    nmcs_get_axis_state_machine( m_board->ConnectNo, m_board->axis, &axis_statematine);
    if(axis_statematine!=4)
    {
        return 1;
    }
    else{
        maxVel = speed*count_convert;//速度设置为5mm/s;
        stopVel=0.1*maxVel;
        startVel=0.1*maxVel;
        Tacc=0.006*maxVel/count_convert;
        Tdec=0.006*maxVel/count_convert;
        smc_set_profile_unit(m_board->ConnectNo,m_board->axis, startVel, maxVel, Tacc, Tdec, stopVel);
        //获取输入框中的文本
        smc_pmove_unit(m_board->ConnectNo, m_board->axis, position*direction_p*count_convert, posi_mode); // 定长运动 direction_p 1正 -1 负
        while(smc_check_done(m_board->ConnectNo, m_board->axis)==0)  //等待电机到位
        {

            int inINP,io_status;
            io_status = smc_axis_io_status(m_board->ConnectNo, m_board->axis);
            inINP = io_status & 0x1000000; // 按位与运算， 读取到位信号 INP
            if(inINP==0)
                break;
        }
    }
    return 0;
}
WORD motion::position_move(double Speed,int Direction,double Position)
{
    maxVel = Speed*count_convert;//速度设置
    stopVel=0.1*maxVel;
    startVel=0.1*maxVel;
    Tacc=0.005*maxVel/count_convert;
    Tdec=0.005*maxVel/count_convert;
    smc_set_profile_unit(m_board->ConnectNo,m_board->axis, startVel, maxVel, Tacc, Tdec, stopVel);
    //获取输入框中的文本
    smc_pmove_unit(m_board->ConnectNo, m_board->axis, Position*Direction*count_convert, posi_mode); // 定长运动 direction_p 1正 -1 负
    while(smc_check_done(m_board->ConnectNo, m_board->axis)==0)  //等待电机到位
    {

        int inINP,io_status;
        io_status = smc_axis_io_status(m_board->ConnectNo, m_board->axis);
        inINP = io_status & 0x1000000; // 按位与运算， 读取到位信号 INP
        if(inINP==0)
            break;
    }
    return 0;
}

WORD motion::stop_move()
{
    //unsigned long errcode = 0; //总线错误代码
    WORD axis_statematine=0;//轴状态机
    nmcs_get_axis_state_machine( m_board->ConnectNo, m_board->axis, &axis_statematine);
    if(axis_statematine!=4)
    {
        return 1;
    }
    else
    {
    maxVel= speed*count_convert;//单位转换
    // 初始速度，停止速度，加速时间，减速时间动态调整
    stopVel=0.05*maxVel;
    startVel=0.05*maxVel;
    Tacc=0.005*maxVel/count_convert;
    Tdec=0.005*maxVel/count_convert;
    smc_set_profile_unit(m_board->ConnectNo, m_board->axis, startVel, maxVel, Tacc, Tdec, stopVel);
    while(smc_check_done(m_board->ConnectNo,m_board->axis)==0)//判断轴运动是否运动
    {
        smc_set_dec_stop_time(m_board->ConnectNo,m_board->axis,Tdec);//设置减速停止时间
        smc_stop(m_board->ConnectNo, m_board->axis, 0);//减速停止
        while(smc_check_done(m_board->ConnectNo,m_board->axis)==1)
            break;
    }
    return 0;
    }
}
//参数设置接口********************************************************************************************
void motion::set_posi_mode(WORD Posi_mode)
{
    this->posi_mode=Posi_mode;

}
void motion::set_speed(double Speed)
{
    this->speed=Speed;
}
void motion::set_position(double Position)
{
    this->position=Position;
}
void motion::set_direction_v(int Direction)
{
    this->direction_v=Direction;
}
void motion::set_direction_p(int Direction)
{
     this->direction_p=Direction;
}
void motion::set_convert(double Convert_const)
{
    this->count_convert=Convert_const;
}
 void motion::set_home(WORD home_mode)
 {
     this->home_mode=home_mode;
     if(home_mode==1) this->home_dir=0;
     if(home_mode==2) this->home_dir=1;
 }
motion::~motion()
{
    m_board=nullptr;
}
//参数信息获取********************************************
double motion::get_count_convert()
{
    return this->count_convert;
}
