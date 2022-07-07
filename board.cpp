#include "board.h"

board::board(QObject *parent) : QObject(parent){}
int board::_board_init(){
    unsigned long errcode=0;
    nmcs_get_errcode(ConnectNo, 2, &errcode);
    if(errcode!=0)
    {
        nmcs_clear_errcode(ConnectNo,2);//清除总线错误
        return -1;
    }
    else
    {
        if(smc_board_init(ConnectNo, type, com, baud)!=0)
        {
            return 1;
        }
    smc_set_pulse_outmode(ConnectNo,axis,outmode);//设脉冲输出模式
    smc_set_equiv(ConnectNo,axis, equiv); //设置脉冲当量值
    smc_set_s_profile(ConnectNo,axis, 0, S_para); //设置 S 段速度参数
    smc_set_position_unit(ConnectNo, axis, 0); // 指定轴的指令位置清零
    smc_set_encoder_unit(ConnectNo, axis, 0); // 指定轴的编码器位 置清零
    nmcs_get_errcode(ConnectNo, 2, &errcode);//获取总线状态
     return errcode==0?0:1;
    }
}

int board::_axis_enable(){
    //轴使能前先判断总线状态
    unsigned long errcode = 0; //总线错误代码
    WORD axis_statematine=0;//轴状态机
    nmcs_get_errcode(ConnectNo, 2, &errcode);
    if(errcode==0)
    {
        nmcs_set_axis_enable(ConnectNo,axis);
        nmcs_get_axis_state_machine(ConnectNo,axis,&axis_statematine);
        return axis_statematine==4 ? 0 :1;
    }
    else
    {
        return -1;
    }
}
bool board::_axis_disable()
{
    //unsigned long errcode = 0; //总线错误代码
    WORD axis_statematine=0;//轴状态机
    nmcs_get_axis_state_machine(ConnectNo,axis,&axis_statematine);
    if(axis_statematine==4)
    {
       short ret=nmcs_set_axis_disable(ConnectNo,axis);
        if(ret!=0) return false;
    }
    return true;
}
bool board::_board_close(){
   // unsigned long errcode = 0; //总线错误代码
    WORD axis_statematine=0;//轴状态机
    this->_axis_disable();
    smc_board_close(ConnectNo);//关闭控制器，释放系统资源
    nmcs_get_axis_state_machine(ConnectNo,axis,&axis_statematine);
    if(axis_statematine==0)
        return true;
    else
        return false;
}

void board::change_connect(WORD connect_no,WORD connect_type,char* connect_com,DWORD connect_baud)
{
    this->ConnectNo=connect_no;
    this->type=connect_type;
    this->com=connect_com;
    this->baud=connect_baud;
}
WORD board::_get_status(){
    WORD Axis_statematine=0;//轴状态机
    double Pos;
    smc_get_position_unit(ConnectNo,axis,&Pos);// 读取指定轴的指令位置
    nmcs_get_axis_state_machine(ConnectNo,axis,&Axis_statematine);//获取总线状态机状态
    return Axis_statematine;
}

