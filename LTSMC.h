#ifndef _LTSMC_LIB_H
#define _LTSMC_LIB_H

#ifndef TRUE
#define TRUE  1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef NULL
#ifdef  __cplusplus
#define NULL    0
#else
#define NULL    ((void *)0)
#endif
#endif

typedef unsigned long   DWORD;
typedef unsigned short  WORD;
typedef unsigned char  uint8; 
typedef signed   char  int8;  
typedef unsigned short uint16;    
typedef signed   short int16;        
typedef unsigned int   uint32;            
typedef signed   int   int32;     
      
//#define VC60 //VC6.0  
#ifdef VC60
	typedef unsigned _int64   uint64;           
	typedef signed   _int64   int64;
#else
	typedef unsigned long long   uint64;           
	typedef signed   long long   int64; 
#endif

#define __SMC_EXPORTS

//定义输入和输出
#ifdef __SMC_EXPORTS
	#define SMC_API __declspec(dllexport)
#else
	#define SMC_API __declspec(dllimport)
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*********************************************************************************************************
功能函数 
***********************************************************************************************************/
//网络链接超时时间
SMC_API short __stdcall smc_set_connect_timeout(DWORD timems);
SMC_API short __stdcall smc_get_connect_status(WORD ConnectNo);
SMC_API short __stdcall smc_set_send_recv_timeout(DWORD SendTimems,DWORD RecvTimems);
SMC_API short __stdcall smc_board_init(WORD ConnectNo,WORD type, char *pconnectstring,DWORD dwBaudRate);
SMC_API short __stdcall smc_board_init_ex(WORD ConnectNo,WORD type, char *pconnectstring,DWORD dwBaudRate, DWORD dwByteSize, DWORD dwParity, DWORD dwStopBits);
SMC_API short __stdcall smc_board_close(WORD ConnectNo);
SMC_API short __stdcall smc_set_connect_debug_time(WORD ConnectNo,DWORD time_s);
SMC_API short __stdcall smc_soft_reset(WORD ConnectNo);
SMC_API short __stdcall smc_board_reset(WORD ConnectNo);
SMC_API short __stdcall smc_get_card_version(WORD ConnectNo,DWORD *CardVersion);
SMC_API short __stdcall smc_get_card_soft_version(WORD ConnectNo,DWORD *FirmID,DWORD *SubFirmID);
SMC_API short __stdcall smc_get_card_lib_version(DWORD *LibVer);
SMC_API short __stdcall smc_get_release_version(WORD ConnectNo,char *ReleaseVersion);
SMC_API short __stdcall smc_get_total_axes(WORD ConnectNo,DWORD *TotalAxis);
SMC_API short __stdcall smc_get_total_ionum(WORD ConnectNo,WORD *TotalIn,WORD *TotalOut);
SMC_API short __stdcall smc_get_total_adcnum(WORD ConnectNo,WORD *TotalIn,WORD *TotalOut);
SMC_API short __stdcall smc_set_debug_mode(WORD mode,const char* FileName);
SMC_API short __stdcall smc_get_debug_mode(WORD* mode,char* FileName);
SMC_API short __stdcall smc_format_flash( WORD ConnectNo);
SMC_API short __stdcall smc_rtc_get_time(WORD ConnectNo,int * year, int * month, int * day, int * hour, int * min, int * sec);
SMC_API short __stdcall smc_rtc_set_time(WORD ConnectNo,int  year, int  month, int  day, int  hour, int  min, int  sec);
SMC_API short __stdcall smc_set_ipaddr( WORD ConnectNo,const char* IpAddr);
SMC_API short __stdcall smc_get_ipaddr( WORD ConnectNo,char* IpAddr);
SMC_API short __stdcall smc_set_com(WORD ConnectNo,WORD com, DWORD dwBaudRate, WORD wByteSize, WORD wParity, WORD wStopBits);
SMC_API short __stdcall smc_get_com(WORD ConnectNo,WORD com, DWORD* dwBaudRate, WORD* wByteSize, WORD* wParity, WORD*dwStopBits);
//读写序列号，可将控制器标签上的序列号或者客户自定义的序列号写入控制器，断电保存
SMC_API short __stdcall smc_write_sn(WORD ConnectNo, uint64 sn);
SMC_API short __stdcall smc_read_sn(WORD ConnectNo, uint64* sn);
SMC_API short __stdcall smc_write_sn_numstring(WORD ConnectNo, const char* sn_str);//sn_str 16进制字符串 固定16个字符
SMC_API short __stdcall smc_read_sn_numstring(WORD ConnectNo, char* sn_str);
//客户自定义密码字符串，最大256个字符，可通过此密码有效保护客户应用程序
SMC_API short __stdcall smc_write_password(WORD ConnectNo, const char * str_pass);
SMC_API short __stdcall smc_check_password(WORD ConnectNo, const char * str_pass);
//登入与修改密码，该密码用作限制控制器恢复出厂设置以及上传BASIC程序使用
SMC_API short __stdcall smc_enter_password(WORD ConnectNo, const char * str_pass);
SMC_API short __stdcall smc_modify_password(WORD ConnectNo, const char* spassold, const char* spass);

//参数文件操作
SMC_API short __stdcall smc_download_parafile(WORD ConnectNo,const char *FileName);
SMC_API short __stdcall smc_upload_parafile(WORD ConnectNo,const char *FileName);
/*********************************************************************************************************
安全机制参数
*********************************************************************************************************/
SMC_API short __stdcall smc_set_el_mode(WORD ConnectNo,WORD axis,WORD enable,WORD el_logic,WORD el_mode);
SMC_API short __stdcall smc_get_el_mode(WORD ConnectNo,WORD axis,WORD *enable,WORD *el_logic,WORD *el_mode);
SMC_API short __stdcall smc_set_emg_mode(WORD ConnectNo,WORD axis,WORD enable,WORD emg_logic);
SMC_API short __stdcall smc_get_emg_mode(WORD ConnectNo,WORD axis,WORD *enable,WORD *emg_logic);
SMC_API short __stdcall smc_set_softlimit_unit(WORD ConnectNo,WORD axis,WORD enable, WORD source_sel,WORD SL_action, double N_limit,double P_limit);
SMC_API short __stdcall smc_get_softlimit_unit(WORD ConnectNo,WORD axis,WORD *enable, WORD *source_sel,WORD *SL_action,double *N_limit,double *P_limit);
/*********************************************************************************************************
单轴特殊功能参数
*********************************************************************************************************/
SMC_API short __stdcall smc_set_pulse_outmode(WORD ConnectNo,WORD axis,WORD outmode);
SMC_API short __stdcall smc_get_pulse_outmode(WORD ConnectNo,WORD axis,WORD* outmode);
SMC_API short __stdcall smc_set_equiv(WORD ConnectNo,WORD axis, double equiv);
SMC_API short __stdcall smc_get_equiv(WORD ConnectNo,WORD axis, double *equiv);
SMC_API short __stdcall smc_set_backlash_unit(WORD ConnectNo,WORD axis,double backlash);
SMC_API short __stdcall smc_get_backlash_unit(WORD ConnectNo,WORD axis,double *backlash);
//轴IO映射
SMC_API short __stdcall smc_set_axis_io_map(WORD ConnectNo,WORD Axis,WORD IoType,WORD MapIoType,WORD MapIoIndex,double Filter);
SMC_API short __stdcall smc_get_axis_io_map(WORD ConnectNo,WORD Axis,WORD IoType,WORD* MapIoType,WORD* MapIoIndex,double* Filter);
/*********************************************************************************************************
单轴速度参数
*********************************************************************************************************/
SMC_API short __stdcall smc_set_profile_unit(WORD ConnectNo,WORD axis,double Min_Vel,double Max_Vel,double Tacc,double Tdec,double Stop_Vel);
SMC_API short __stdcall smc_get_profile_unit(WORD ConnectNo,WORD axis,double* Min_Vel,double* Max_Vel,double* Tacc,double* Tdec,double* Stop_Vel);
SMC_API short __stdcall smc_set_profile_unit_acc(WORD ConnectNo,WORD axis,double Min_Vel,double Max_Vel,double acc,double dec,double Stop_Vel);
SMC_API short __stdcall smc_get_profile_unit_acc(WORD ConnectNo,WORD axis,double* Min_Vel,double* Max_Vel,double* acc,double* dec,double* Stop_Vel);
SMC_API short __stdcall smc_set_s_profile(WORD ConnectNo,WORD axis,WORD s_mode,double s_para);
SMC_API short __stdcall smc_get_s_profile(WORD ConnectNo,WORD axis,WORD s_mode,double *s_para);
SMC_API short __stdcall smc_set_dec_stop_time(WORD ConnectNo,WORD axis,double time);
SMC_API short __stdcall smc_get_dec_stop_time(WORD ConnectNo,WORD axis,double *time); 
/*********************************************************************************************************
单轴运动
*********************************************************************************************************/
SMC_API short __stdcall smc_pmove_unit(WORD ConnectNo,WORD axis,double Dist,WORD posi_mode);
SMC_API short __stdcall smc_vmove(WORD ConnectNo,WORD axis,WORD dir);
SMC_API short __stdcall smc_change_speed_unit(WORD ConnectNo,WORD axis, double New_Vel,double Taccdec);
SMC_API short __stdcall smc_reset_target_position_unit(WORD ConnectNo,WORD axis, double New_Pos);
SMC_API short __stdcall smc_update_target_position_unit(WORD ConnectNo,WORD axis, double New_Pos);
//软着陆功能
SMC_API short __stdcall smc_pmove_unit_extern(WORD ConnectNo, WORD axis, double MidPos,double TargetPos, double Min_Vel,double Max_Vel, double stop_Vel, double acc,double dec,double smooth_time,WORD posi_mode);

//正弦曲线定长运动
SMC_API short __stdcall smc_set_plan_mode(WORD ConnectNo,WORD axis,WORD mode);
SMC_API short __stdcall smc_get_plan_mode(WORD ConnectNo,WORD axis,WORD *mode);
SMC_API short __stdcall smc_pmove_sin_unit(WORD ConnectNo,WORD axis,double Dist,WORD posi_mode,double MaxVel,double MaxAcc);

/*********************************************************************************************************
回零运动
*********************************************************************************************************/	
SMC_API short __stdcall smc_set_home_pin_logic(WORD ConnectNo,WORD axis,WORD org_logic,double filter);
SMC_API short __stdcall smc_get_home_pin_logic(WORD ConnectNo,WORD axis,WORD *org_logic,double *filter);
SMC_API short __stdcall smc_set_ez_mode(WORD ConnectNo,WORD axis,WORD ez_logic,WORD ez_mode,double filter);
SMC_API short __stdcall smc_get_ez_mode(WORD ConnectNo,WORD axis,WORD *ez_logic,WORD *ez_mode,double *filter);
SMC_API short __stdcall smc_set_ez_count(WORD ConnectNo,WORD axis,WORD ez_count);
SMC_API short __stdcall smc_get_ez_count(WORD ConnectNo,WORD axis,WORD *ez_count);
SMC_API short __stdcall smc_set_homemode(WORD ConnectNo,WORD axis,WORD home_dir,double vel_mode,WORD mode,WORD pos_source);
SMC_API short __stdcall smc_get_homemode(WORD ConnectNo,WORD axis,WORD *home_dir, double *vel_mode,WORD *home_mode,WORD *pos_source);
SMC_API short __stdcall smc_set_homespeed_unit(WORD ConnectNo,WORD axis,double homespeed);
SMC_API short __stdcall smc_get_homespeed_unit(WORD ConnectNo,WORD axis, double *homespeed);
SMC_API short __stdcall smc_set_home_profile_unit(WORD ConnectNo,WORD axis,double Low_Vel,double High_Vel,double Tacc,double Tdec);
SMC_API short __stdcall smc_get_home_profile_unit(WORD ConnectNo,WORD axis,double* Low_Vel,double* High_Vel,double* Tacc,double* Tdec);
//回原点状态，state：0-未完成，1-完成
SMC_API short __stdcall smc_get_home_result(WORD ConnectNo,WORD axis,WORD* state);
//限位当原点切换，mode：0-默认原点，1-正限位当原点，2-负限位当原点
SMC_API short __stdcall smc_set_el_home(WORD ConnectNo,WORD axis,WORD mode);
//20151017回零完成后设置位置
SMC_API short __stdcall smc_set_home_position_unit(WORD ConnectNo,WORD axis,WORD enable,double position);
SMC_API short __stdcall smc_get_home_position_unit(WORD ConnectNo,WORD axis,WORD *enable,double *position);
SMC_API short __stdcall smc_home_move(WORD ConnectNo,WORD axis);
/*********************************************************************************************************
PVT运动
*********************************************************************************************************/
SMC_API short __stdcall smc_pvt_table_unit(WORD ConnectNo,WORD iaxis,DWORD count,double *pTime,double *pPos,double *pVel);
SMC_API short __stdcall smc_pts_table_unit(WORD ConnectNo,WORD iaxis,DWORD count,double *pTime,double *pPos,double *pPercent);
SMC_API short __stdcall smc_pvts_table_unit(WORD ConnectNo,WORD iaxis,DWORD count,double *pTime,double *pPos,double velBegin,double velEnd);
SMC_API short __stdcall smc_ptt_table_unit(WORD ConnectNo,WORD iaxis,DWORD count,double *pTime,double *pPos);
SMC_API short __stdcall smc_pvt_move(WORD ConnectNo,WORD AxisNum,WORD* AxisList);
/*********************************************************************************************************
简易电子凸轮运动
*********************************************************************************************************/
SMC_API short __stdcall smc_cam_table_unit(WORD ConnectNo,WORD MasterAxisNo,WORD SlaveAxisNo,DWORD Count,double *pMasterPos,double *pSlavePos,WORD SrcMode);
SMC_API short __stdcall smc_cam_move(WORD ConnectNo,WORD AxisNo);

/*********************************************************************************************************
正弦振荡运动
*********************************************************************************************************/
SMC_API short __stdcall smc_sine_oscillate_unit(WORD ConnectNo,WORD Axis,double Amplitude,double Frequency);
SMC_API short __stdcall smc_sine_oscillate_stop(WORD ConnectNo,WORD Axis);
/*********************************************************************************************************
跟随多轴合成速度运动——限被跟随轴处于插补模式
*********************************************************************************************************/
SMC_API short __stdcall smc_follow_vector_speed_move(WORD ConnectNo,WORD Axis,WORD Crd,double ratio);
/*********************************************************************************************************
手轮运动
*********************************************************************************************************/
SMC_API short __stdcall smc_handwheel_set_axislist( WORD ConnectNo, WORD AxisSelIndex,WORD AxisNum,WORD* AxisList	);
SMC_API short __stdcall smc_handwheel_get_axislist( WORD ConnectNo,WORD AxisSelIndex, WORD* AxisNum, WORD* AxisList);
SMC_API short __stdcall smc_handwheel_set_ratiolist( WORD ConnectNo, WORD AxisSelIndex, WORD StartRatioIndex, WORD RatioSelNum, double* RatioList	);
SMC_API short __stdcall smc_handwheel_get_ratiolist( WORD ConnectNo,WORD AxisSelIndex, WORD StartRatioIndex, WORD RatioSelNum,double* RatioList );
SMC_API short __stdcall smc_handwheel_set_mode( WORD ConnectNo, WORD InMode, WORD IfHardEnable );
SMC_API short __stdcall smc_handwheel_get_mode ( WORD ConnectNo, WORD* InMode, WORD*  IfHardEnable );
SMC_API short __stdcall smc_handwheel_set_index( WORD ConnectNo, WORD AxisSelIndex,WORD RatioSelIndex );
SMC_API short __stdcall smc_handwheel_get_index( WORD ConnectNo, WORD* AxisSelIndex,WORD* RatioSelIndex );
SMC_API short __stdcall smc_handwheel_move( WORD ConnectNo, WORD ForceMove );
SMC_API short __stdcall smc_handwheel_stop ( WORD ConnectNo );
/*********************************************************************************************************
多轴插补速度参数设置
*********************************************************************************************************/
SMC_API short __stdcall smc_set_vector_profile_unit(WORD ConnectNo,WORD Crd,double Min_Vel,double Max_Vel,double Tacc,double Tdec,double Stop_Vel);
SMC_API short __stdcall smc_get_vector_profile_unit(WORD ConnectNo,WORD Crd,double* Min_Vel,double* Max_Vel,double* Tacc,double* Tdec,double* Stop_Vel);
SMC_API short __stdcall smc_set_vector_profile_unit_acc(WORD ConnectNo,WORD Crd,double Min_Vel,double Max_Vel,double acc,double dec,double Stop_Vel);
SMC_API short __stdcall smc_get_vector_profile_unit_acc(WORD ConnectNo,WORD Crd,double* Min_Vel,double* Max_Vel,double* acc,double* dec,double* Stop_Vel);
SMC_API short __stdcall smc_set_vector_s_profile(WORD ConnectNo,WORD Crd,WORD s_mode,double s_para);
SMC_API short __stdcall smc_get_vector_s_profile(WORD ConnectNo,WORD Crd,WORD s_mode,double *s_para);
SMC_API short __stdcall smc_set_vector_dec_stop_time(WORD ConnectNo,WORD Crd,double time);
SMC_API short __stdcall smc_get_vector_dec_stop_time(WORD ConnectNo,WORD Crd,double *time);
/*********************************************************************************************************
多轴单段插补运动
*********************************************************************************************************/
SMC_API short __stdcall smc_line_unit(WORD ConnectNo,WORD Crd,WORD AxisNum,WORD* AxisList,double* Dist,WORD posi_mode);
SMC_API short __stdcall smc_arc_move_center_unit(WORD ConnectNo,WORD Crd,WORD AxisNum,WORD* AxisList,double *Target_Pos,double *Cen_Pos,WORD Arc_Dir,long Circle,WORD posi_mode);
SMC_API short __stdcall smc_arc_move_radius_unit(WORD ConnectNo,WORD Crd,WORD AxisNum,WORD* AxisList,double *Target_Pos,double Arc_Radius,WORD Arc_Dir,long Circle,WORD posi_mode);
SMC_API short __stdcall smc_arc_move_3points_unit(WORD ConnectNo,WORD Crd,WORD AxisNum,WORD* AxisList,double *Target_Pos,double *Mid_Pos,long Circle,WORD posi_mode);
/*********************************************************************************************************
多轴连续插补运动
*********************************************************************************************************/
//小线段前瞻
SMC_API short __stdcall smc_conti_set_lookahead_mode(WORD ConnectNo,WORD Crd,WORD enable,long LookaheadSegments,double PathError,double LookaheadAcc);
SMC_API short __stdcall smc_conti_get_lookahead_mode(WORD ConnectNo,WORD Crd,WORD* enable,long* LookaheadSegments,double* PathError,double* LookaheadAcc);
//圆弧限速
SMC_API short __stdcall smc_set_arc_limit(WORD ConnectNo,WORD Crd,WORD Enable,double MaxCenAcc=0,double MaxArcError=0);
SMC_API short __stdcall smc_get_arc_limit(WORD ConnectNo,WORD Crd,WORD* Enable,double* MaxCenAcc=NULL,double* MaxArcError=NULL);

//连续插补控制
SMC_API short __stdcall smc_conti_open_list (WORD ConnectNo,WORD Crd,WORD AxisNum,WORD *AxisList);
SMC_API short __stdcall smc_conti_close_list(WORD ConnectNo,WORD Crd);
SMC_API short __stdcall smc_conti_stop_list (WORD ConnectNo,WORD Crd,WORD stop_mode);
SMC_API short __stdcall smc_conti_pause_list(WORD ConnectNo,WORD Crd);
SMC_API short __stdcall smc_conti_start_list(WORD ConnectNo,WORD Crd);
SMC_API short __stdcall smc_conti_change_speed_ratio (WORD ConnectNo,WORD Crd,double percent);
//连续插补状态
SMC_API short __stdcall smc_conti_get_run_state(WORD ConnectNo,WORD Crd);
SMC_API long __stdcall smc_conti_remain_space (WORD ConnectNo,WORD Crd);
SMC_API long __stdcall smc_conti_read_current_mark (WORD ConnectNo,WORD Crd);
//连续插补轨迹段
SMC_API short __stdcall smc_conti_line_unit(WORD ConnectNo,WORD Crd,WORD AxisNum,WORD* AxisList,double* pPosList,WORD posi_mode,long mark);
SMC_API short __stdcall smc_conti_arc_move_center_unit(WORD ConnectNo,WORD Crd,WORD AxisNum,WORD* AxisList,double *Target_Pos,double *Cen_Pos,WORD Arc_Dir,long Circle,WORD posi_mode,long mark);
SMC_API short __stdcall smc_conti_arc_move_radius_unit(WORD ConnectNo,WORD Crd,WORD AxisNum,WORD* AxisList,double *Target_Pos,double Arc_Radius,WORD Arc_Dir,long Circle,WORD posi_mode,long mark);
SMC_API short __stdcall smc_conti_arc_move_3points_unit(WORD ConnectNo,WORD Crd,WORD AxisNum,WORD* AxisList,double *Target_Pos,double *Mid_Pos,long Circle,WORD posi_mode,long mark);
//连续插补IO功能
SMC_API short __stdcall smc_conti_wait_input(WORD ConnectNo,WORD Crd,WORD bitno,WORD on_off,double TimeOut,long mark);
SMC_API short __stdcall smc_conti_delay_outbit_to_start(WORD ConnectNo, WORD Crd, WORD bitno,WORD on_off,double delay_value,WORD delay_mode,double ReverseTime);
SMC_API short __stdcall smc_conti_delay_outbit_to_stop(WORD ConnectNo, WORD Crd, WORD bitno,WORD on_off,double delay_time,double ReverseTime);
SMC_API short __stdcall smc_conti_ahead_outbit_to_stop(WORD ConnectNo, WORD Crd, WORD bitno,WORD on_off,double ahead_value,WORD ahead_mode,double ReverseTime);
SMC_API short __stdcall smc_conti_accurate_outbit_unit(WORD ConnectNo, WORD Crd, WORD cmp_no,WORD on_off,WORD axis,double abs_pos,WORD pos_source,double ReverseTime);
SMC_API short __stdcall smc_conti_write_outbit(WORD ConnectNo, WORD Crd, WORD bitno,WORD on_off,double ReverseTime);
SMC_API short __stdcall smc_conti_clear_io_action(WORD ConnectNo, WORD Crd, DWORD Io_Mask);
SMC_API short __stdcall smc_conti_set_pause_output(WORD ConnectNo,WORD Crd,WORD action,long mask,long state);
SMC_API short __stdcall smc_conti_get_pause_output(WORD ConnectNo,WORD Crd,WORD* action,long* mask,long* state);
//连续插补特殊功能
SMC_API short __stdcall smc_conti_set_override(WORD ConnectNo,WORD Crd,double Percent);
SMC_API short __stdcall smc_conti_set_blend(WORD ConnectNo,WORD Crd,WORD enable);
SMC_API short __stdcall smc_conti_get_blend(WORD ConnectNo,WORD Crd,WORD* enable);
SMC_API short __stdcall smc_conti_pmove_unit(WORD ConnectNo,WORD Crd,WORD axis,double dist,WORD posi_mode,WORD mode,long mark);
SMC_API short __stdcall smc_conti_delay(WORD ConnectNo, WORD Crd,double delay_time,long mark);
//读取相对于起点的距离
SMC_API short __stdcall smc_get_distance_to_start(WORD CardNo,WORD Crd, double* distance_x, double* distance_y,long imark); 
//设置标志位 表示是否开始计算相对起点
SMC_API short __stdcall smc_set_start_distance_flag(WORD CardNo,WORD Crd,WORD flag); 
SMC_API short __stdcall smc_get_start_distance_flag(WORD CardNo,WORD Crd,WORD *flag); 
/*********************************************************************************************************
PWM功能
*********************************************************************************************************/
//与IO复用的情况下使用
SMC_API short __stdcall smc_set_pwm_enable(WORD ConnectNo,WORD pwm,WORD enable);
SMC_API short __stdcall smc_get_pwm_enable(WORD ConnectNo,WORD pwm,WORD* enable);
SMC_API short __stdcall smc_set_pwm_output(WORD ConnectNo, WORD PwmNo,double fDuty, double fFre);
SMC_API short __stdcall smc_get_pwm_output(WORD ConnectNo,WORD PwmNo,double* fDuty, double* fFre);
SMC_API short __stdcall smc_conti_set_pwm_output(WORD ConnectNo,WORD Crd, WORD PwmNo,double fDuty, double fFre);
/**********PWM速度跟随***********************************************************************************
mode:跟随模式0-不跟随 保持状态 1-不跟随 输出低电平2-不跟随 输出高电平3-跟随 占空比自动调整4-跟随 频率自动调整
MaxVel:最大运行速度，单位unit
MaxValue:最大输出占空比或者频率
OutValue：设置输出频率或占空比
*******************************************************************************************************/
SMC_API short __stdcall smc_set_pwm_follow_speed(WORD ConnectNo,WORD pwm_no,WORD mode,double MaxVel,double MaxValue,double OutValue);
SMC_API short __stdcall smc_get_pwm_follow_speed(WORD ConnectNo,WORD pwm_no,WORD* mode,double* MaxVel,double* MaxValue,double* OutValue);
//设置PWM开关对应的占空比
SMC_API short __stdcall smc_set_pwm_onoff_duty(WORD ConnectNo, WORD PwmNo,double fOnDuty, double fOffDuty);
SMC_API short __stdcall smc_get_pwm_onoff_duty(WORD ConnectNo, WORD PwmNo,double* fOnDuty, double* fOffDuty);

SMC_API short __stdcall smc_set_pwm_follow_onoff(WORD ConnectNo, WORD PwmNo,WORD Crd,WORD on_off);
SMC_API short __stdcall smc_get_pwm_follow_onoff(WORD ConnectNo, WORD PwmNo,WORD *Crd,WORD *on_off);

SMC_API short __stdcall smc_conti_delay_pwm_to_start(WORD ConnectNo, WORD Crd, WORD pwmno,WORD on_off,double delay_value,WORD delay_mode,double ReverseTime);
SMC_API short __stdcall smc_conti_ahead_pwm_to_stop(WORD ConnectNo, WORD Crd, WORD bitno,WORD on_off,double ahead_value,WORD ahead_mode,double ReverseTime);
SMC_API short __stdcall smc_conti_write_pwm(WORD ConnectNo, WORD Crd, WORD pwmno,WORD on_off,double ReverseTime);

/*********************************************************************************************************
SMC106A定制功能
*********************************************************************************************************/
SMC_API short __stdcall smc_laser_set_output(WORD ConnectNo,WORD Enable,WORD Width);
SMC_API short __stdcall smc_laser_get_output(WORD ConnectNo,WORD* Enable,WORD* Width);
/*********************************************************************************************************
编码器功能
*********************************************************************************************************/
SMC_API short __stdcall smc_set_counter_inmode(WORD ConnectNo,WORD axis,WORD mode);
SMC_API short __stdcall smc_get_counter_inmode(WORD ConnectNo,WORD axis,WORD *mode);
SMC_API short __stdcall smc_set_counter_reverse(WORD ConnectNo,WORD axis,WORD reverse);
SMC_API short __stdcall smc_get_counter_reverse(WORD ConnectNo,WORD axis,WORD *reverse);
SMC_API short __stdcall smc_set_encoder_unit(WORD ConnectNo,WORD axis, double pos);
SMC_API short __stdcall smc_get_encoder_unit(WORD ConnectNo,WORD axis, double * pos);
/*********************************************************************************************************
辅助编码器功能
*********************************************************************************************************/
SMC_API short __stdcall smc_set_extra_encoder_mode(WORD ConnectNo,WORD channel,WORD inmode);
SMC_API short __stdcall smc_get_extra_encoder_mode(WORD ConnectNo,WORD channel,WORD* inmode);
SMC_API short __stdcall smc_set_extra_encoder(WORD ConnectNo,WORD channel, int pos);
SMC_API short __stdcall smc_get_extra_encoder(WORD ConnectNo,WORD channel, int * pos);
/*********************************************************************************************************
通用IO操作
*********************************************************************************************************/	
SMC_API short __stdcall smc_read_inbit(WORD ConnectNo,WORD bitno);
SMC_API short __stdcall smc_write_outbit(WORD ConnectNo,WORD bitno,WORD on_off);
SMC_API short __stdcall smc_read_outbit(WORD ConnectNo,WORD bitno);
SMC_API DWORD __stdcall smc_read_inport(WORD ConnectNo,WORD portno);
SMC_API DWORD __stdcall smc_read_outport(WORD ConnectNo,WORD portno);
SMC_API short __stdcall smc_write_outport(WORD ConnectNo,WORD portno,DWORD outport_val);

SMC_API short __stdcall smc_read_inbit_ex(WORD ConnectNo,WORD bitno,WORD *state);
SMC_API short __stdcall smc_read_outbit_ex(WORD ConnectNo,WORD bitno,WORD *state);
SMC_API short __stdcall smc_read_inport_ex(WORD ConnectNo,WORD portno,DWORD *state);
SMC_API short __stdcall smc_read_outport_ex(WORD ConnectNo,WORD portno,DWORD *state);

//通用IO特殊功能 SMC104不支持
SMC_API short __stdcall smc_reverse_outbit(WORD ConnectNo,WORD bitno,double reverse_time);
//设置IO输出一定脉冲个数的PWM波形曲线
SMC_API short __stdcall smc_set_io_pwmoutput(WORD ConnectNo,WORD outbit,double time1, double time2, DWORD counts);
//清除IO输出PWM波形曲线
SMC_API short __stdcall smc_clear_io_pwmoutput(WORD ConnectNo,WORD outbit);
SMC_API short __stdcall smc_set_io_count_mode(WORD ConnectNo,WORD bitno,WORD mode,double filter);
SMC_API short __stdcall smc_get_io_count_mode(WORD ConnectNo,WORD bitno,WORD *mode,double* filter);
SMC_API short __stdcall smc_set_io_count_value(WORD ConnectNo,WORD bitno,DWORD CountValue);
SMC_API short __stdcall smc_get_io_count_value(WORD ConnectNo,WORD bitno,DWORD* CountValue);
//虚拟IO映射 用于输入滤波功能  SMC104不支持
SMC_API short __stdcall smc_set_io_map_virtual(WORD ConnectNo,WORD bitno,WORD MapIoType,WORD MapIoIndex,double Filter);
SMC_API short __stdcall smc_get_io_map_virtual(WORD ConnectNo,WORD bitno,WORD* MapIoType,WORD* MapIoIndex,double* Filter);
SMC_API short __stdcall smc_read_inbit_virtual(WORD ConnectNo,WORD bitno); 
/*********************************************************************************************************
专用IO操作
*********************************************************************************************************/
SMC_API short __stdcall smc_set_io_dstp_mode(WORD ConnectNo,WORD axis,WORD enable,WORD logic); 
SMC_API short __stdcall smc_get_io_dstp_mode(WORD ConnectNo,WORD axis,WORD *enable,WORD *logic);	
SMC_API short __stdcall smc_set_alm_mode(WORD ConnectNo,WORD axis,WORD enable,WORD alm_logic,WORD alm_action);
SMC_API short __stdcall smc_get_alm_mode(WORD ConnectNo,WORD axis,WORD *enable,WORD *alm_logic,WORD *alm_action);
SMC_API short __stdcall smc_set_inp_mode(WORD ConnectNo,WORD axis,WORD enable,WORD inp_logic);
SMC_API short __stdcall smc_get_inp_mode(WORD ConnectNo,WORD axis,WORD *enable,WORD *inp_logic);
SMC_API short __stdcall smc_write_sevon_pin(WORD ConnectNo,WORD axis,WORD on_off);
SMC_API short __stdcall smc_read_sevon_pin(WORD ConnectNo,WORD axis);
SMC_API short __stdcall smc_write_erc_pin(WORD ConnectNo,WORD axis,WORD on_off);
SMC_API short __stdcall smc_read_erc_pin(WORD ConnectNo,WORD axis); 	
SMC_API short __stdcall smc_read_alarm_pin(WORD ConnectNo,WORD axis);
SMC_API short __stdcall smc_read_inp_pin(WORD ConnectNo,WORD axis);
SMC_API short __stdcall smc_read_org_pin(WORD ConnectNo,WORD axis);
SMC_API short __stdcall smc_read_elp_pin(WORD ConnectNo,WORD axis);
SMC_API short __stdcall smc_read_eln_pin(WORD ConnectNo,WORD axis);
SMC_API short __stdcall smc_read_emg_pin(WORD ConnectNo,WORD axis);
SMC_API short __stdcall smc_read_ez_pin(WORD ConnectNo,WORD axis);
SMC_API short __stdcall smc_read_rdy_pin(WORD ConnectNo,WORD axis);
SMC_API short __stdcall smc_read_cmp_pin(WORD ConnectNo,WORD axis);
SMC_API short __stdcall smc_write_cmp_pin(WORD ConnectNo,WORD axis, WORD on_off);

SMC_API short __stdcall smc_read_sevon_pin_ex(WORD ConnectNo,WORD axis,WORD *state);
SMC_API short __stdcall smc_read_erc_pin_ex(WORD ConnectNo,WORD axis,WORD *state); 
SMC_API short __stdcall smc_read_alarm_pin_ex(WORD ConnectNo,WORD axis,WORD *state);
SMC_API short __stdcall smc_read_inp_pin_ex(WORD ConnectNo,WORD axis,WORD *state);
SMC_API short __stdcall smc_read_org_pin_ex(WORD ConnectNo,WORD uiaxis,WORD *state);
SMC_API short __stdcall smc_read_elp_pin_ex(WORD ConnectNo,WORD uiaxis,WORD *state);
SMC_API short __stdcall smc_read_eln_pin_ex(WORD ConnectNo,WORD uiaxis,WORD *state);
SMC_API short __stdcall smc_read_emg_pin_ex(WORD ConnectNo,WORD uiaxis,WORD *state);
SMC_API short __stdcall smc_read_ez_pin_ex(WORD ConnectNo,WORD axis,WORD *state);
SMC_API short __stdcall smc_read_rdy_pin_ex(WORD ConnectNo,WORD axis,WORD *state);
/*********************************************************************************************************
位置比较
*********************************************************************************************************/
//单轴位置比较		 
SMC_API short __stdcall smc_compare_set_config(WORD ConnectNo,WORD axis,WORD enable, WORD cmp_source); 	//配置比较器
SMC_API short __stdcall smc_compare_get_config(WORD ConnectNo,WORD axis,WORD *enable, WORD *cmp_source);	//读取配置比较器
SMC_API short __stdcall smc_compare_clear_points(WORD ConnectNo,WORD axis); 	//清除所有比较点
SMC_API short __stdcall smc_compare_add_point_unit(WORD ConnectNo,WORD axis,double pos,WORD dir, WORD action,DWORD actpara); 	//添加比较点
SMC_API short __stdcall smc_compare_add_point_cycle(WORD ConnectNo,WORD axis,double pos,WORD dir, DWORD bitno,DWORD cycle,WORD level);//纯总线产品使用 添加比较点
SMC_API short __stdcall smc_compare_get_current_point_unit(WORD ConnectNo,WORD axis,double *pos); 	//读取当前比较点
SMC_API short __stdcall smc_compare_get_points_runned(WORD ConnectNo,WORD axis,long *pointNum); 	//查询已经比较过的点
SMC_API short __stdcall smc_compare_get_points_remained(WORD ConnectNo,WORD axis,long *pointNum); 	//查询可以加入的比较点数量
//二维位置比较
SMC_API short __stdcall smc_compare_set_config_extern(WORD ConnectNo,WORD enable, WORD cmp_source); 	//配置比较器
SMC_API short __stdcall smc_compare_get_config_extern(WORD ConnectNo,WORD *enable, WORD *cmp_source);	//读取配置比较器
SMC_API short __stdcall smc_compare_clear_points_extern(WORD ConnectNo); 	//清除所有比较点
SMC_API short __stdcall smc_compare_add_point_extern_unit(WORD ConnectNo,WORD* axis,double* pos,WORD* dir, WORD action,DWORD actpara); 	//添加两轴位置比较点
SMC_API short __stdcall smc_compare_add_point_cycle_2d(WORD ConnectNo,WORD* axis,double* pos,WORD* dir, DWORD bitno,DWORD cycle,WORD level); //纯总线产品使用 添加比较点
SMC_API short __stdcall smc_compare_get_current_point_extern_unit(WORD ConnectNo,double *pos); 	//读取当前比较点
SMC_API short __stdcall smc_compare_get_points_runned_extern(WORD ConnectNo,long *pointNum); 	//查询已经比较过的点
SMC_API short __stdcall smc_compare_get_points_remained_extern(WORD ConnectNo,long *pointNum); 	//查询可以加入的比较点数量
//高速位置比较
SMC_API short __stdcall smc_hcmp_set_mode(WORD ConnectNo,WORD hcmp, WORD cmp_mode);
SMC_API short __stdcall smc_hcmp_get_mode(WORD ConnectNo,WORD hcmp, WORD* cmp_mode);
SMC_API short __stdcall smc_hcmp_set_config(WORD ConnectNo,WORD hcmp,WORD axis, WORD cmp_source, WORD cmp_logic,long time);
SMC_API short __stdcall smc_hcmp_get_config(WORD ConnectNo,WORD hcmp,WORD* axis, WORD* cmp_source, WORD* cmp_logic,long* time);
SMC_API short __stdcall smc_hcmp_add_point_unit(WORD ConnectNo,WORD hcmp, double cmp_pos);
SMC_API short __stdcall smc_hcmp_set_liner_unit(WORD ConnectNo,WORD hcmp, double Increment,long Count);
SMC_API short __stdcall smc_hcmp_get_liner_unit(WORD ConnectNo,WORD hcmp, double* Increment,long* Count);
SMC_API short __stdcall smc_hcmp_get_current_state_unit(WORD ConnectNo,WORD hcmp,long *remained_points,double *current_point,long *runned_points); 
SMC_API short __stdcall smc_hcmp_clear_points(WORD ConnectNo,WORD hcmp);
//二维高速位置比较
SMC_API short __stdcall smc_hcmp_2d_set_enable(WORD ConnectNo,WORD hcmp, WORD cmp_enable);
SMC_API short __stdcall smc_hcmp_2d_get_enable(WORD ConnectNo,WORD hcmp, WORD *cmp_enable);
SMC_API short __stdcall smc_hcmp_2d_set_config_unit(WORD ConnectNo,WORD hcmp,WORD cmp_mode,WORD x_axis, WORD x_cmp_source, double x_cmp_error, WORD y_axis, WORD y_cmp_source, double y_cmp_error,WORD cmp_logic,int time);
SMC_API short __stdcall smc_hcmp_2d_get_config_unit(WORD ConnectNo,WORD hcmp,WORD *cmp_mode,WORD *x_axis, WORD *x_cmp_source,double *x_cmp_error,  WORD *y_axis, WORD *y_cmp_source, double *y_cmp_error, WORD *cmp_logic,int *time);
SMC_API short __stdcall smc_hcmp_2d_set_pwmoutput(WORD ConnectNo,WORD hcmp,WORD pwm_enable,double duty,double freq,WORD pwm_number);
SMC_API short __stdcall smc_hcmp_2d_get_pwmoutput(WORD ConnectNo,WORD hcmp,WORD *pwm_enable,double *duty,double *freq,WORD *pwm_number);
SMC_API short __stdcall smc_hcmp_2d_add_point_unit(WORD ConnectNo,WORD hcmp, double x_cmp_pos, double y_cmp_pos,WORD cmp_outbit);
SMC_API short __stdcall smc_hcmp_2d_get_current_state(WORD ConnectNo,WORD hcmp,int *remained_points,double *x_current_point,double *y_current_point,int *runned_points,WORD *current_state,WORD *current_outbit); 
SMC_API short __stdcall smc_hcmp_2d_clear_points(WORD ConnectNo,WORD hcmp);
SMC_API short __stdcall smc_hcmp_2d_force_output(WORD ConnectNo,WORD hcmp,WORD outbit);
/*********************************************************************************************************
原点锁存
*********************************************************************************************************/	
SMC_API short __stdcall smc_set_homelatch_mode(WORD ConnectNo,WORD axis,WORD enable,WORD logic,WORD source);
SMC_API short __stdcall smc_get_homelatch_mode(WORD ConnectNo,WORD axis,WORD* enable,WORD* logic,WORD* source);
SMC_API long __stdcall smc_get_homelatch_flag(WORD ConnectNo,WORD axis);
SMC_API short __stdcall smc_reset_homelatch_flag(WORD ConnectNo,WORD axis);
SMC_API short __stdcall smc_get_homelatch_value_unit(WORD ConnectNo,WORD axis,double* pos_by_mm);
/*********************************************************************************************************
EZ锁存
*********************************************************************************************************/	
SMC_API short __stdcall smc_set_ezlatch_mode(WORD ConnectNo,WORD axis,WORD enable,WORD logic,WORD source);
SMC_API short __stdcall smc_get_ezlatch_mode(WORD ConnectNo,WORD axis,WORD* enable,WORD* logic,WORD* source);
SMC_API long __stdcall smc_get_ezlatch_flag(WORD ConnectNo,WORD axis);
SMC_API short __stdcall smc_reset_ezlatch_flag(WORD ConnectNo,WORD axis);
SMC_API short __stdcall smc_get_ezlatch_value_unit(WORD ConnectNo,WORD axis,double* pos_by_mm);
/*********************************************************************************************************
高速锁存
*********************************************************************************************************/
SMC_API short __stdcall smc_set_ltc_mode(WORD ConnectNo,WORD axis,WORD ltc_logic,WORD ltc_mode,double filter);
SMC_API short __stdcall smc_get_ltc_mode(WORD ConnectNo,WORD axis,WORD*ltc_logic,WORD*ltc_mode,double *filter);
SMC_API short __stdcall smc_set_latch_mode(WORD ConnectNo,WORD axis,WORD all_enable,WORD latch_source,WORD triger_chunnel);
SMC_API short __stdcall smc_get_latch_mode(WORD ConnectNo,WORD axis,WORD* all_enable,WORD* latch_source,WORD* triger_chunnel);
SMC_API short __stdcall smc_get_latch_flag(WORD ConnectNo,WORD axis);
SMC_API short __stdcall smc_reset_latch_flag(WORD ConnectNo,WORD axis);
SMC_API short __stdcall smc_get_latch_value_unit(WORD ConnectNo,WORD axis,double* pos_by_mm);
/*********************************************************************************************************
高速锁存 新规划20170308
*********************************************************************************************************/
//配置锁存器：锁存模式0-单次锁存，1-连续锁存；锁存边沿0-下降沿，1-上升沿，2-双边沿；滤波时间，单位us
SMC_API short __stdcall smc_ltc_set_mode(WORD ConnectNo,WORD latch,WORD ltc_mode,WORD ltc_logic,double filter);
SMC_API short __stdcall smc_ltc_get_mode(WORD ConnectNo,WORD latch,WORD *ltc_mode,WORD *ltc_logic,double *filter);
//配置锁存源：0-指令位置，1-编码器反馈位置
SMC_API short __stdcall smc_ltc_set_source(WORD ConnectNo,WORD latch,WORD axis,WORD ltc_source);
SMC_API short __stdcall smc_ltc_get_source(WORD ConnectNo,WORD latch,WORD axis,WORD *ltc_source);
//复位锁存器
SMC_API short __stdcall smc_ltc_reset(WORD ConnectNo,WORD latch);
//读取锁存个数
SMC_API short __stdcall smc_ltc_get_number(WORD ConnectNo,WORD latch,WORD axis,int *number);
//读取锁存值
SMC_API short __stdcall smc_ltc_get_value_unit(WORD ConnectNo,WORD latch,WORD axis,double *value);
/*********************************************************************************************************
软件锁存 20170626
*********************************************************************************************************/
//配置锁存器：锁存模式0-单次锁存，1-连续锁存；锁存边沿0-下降沿，1-上升沿，2-双边沿；滤波时间，单位us
SMC_API short __stdcall smc_softltc_set_mode(WORD ConnectNo,WORD latch,WORD ltc_enable,WORD ltc_mode,WORD ltc_inbit,WORD ltc_logic,double filter);
SMC_API short __stdcall smc_softltc_get_mode(WORD ConnectNo,WORD latch,WORD *ltc_enable,WORD *ltc_mode,WORD *ltc_inbit,WORD *ltc_logic,double *filter);
//配置锁存源：0-指令位置，1-编码器反馈位置
SMC_API short __stdcall smc_softltc_set_source(WORD ConnectNo,WORD latch,WORD axis,WORD ltc_source);
SMC_API short __stdcall smc_softltc_get_source(WORD ConnectNo,WORD latch,WORD axis,WORD *ltc_source);
//复位锁存器
SMC_API short __stdcall smc_softltc_reset(WORD ConnectNo,WORD latch);
//读取锁存个数
SMC_API short __stdcall smc_softltc_get_number(WORD ConnectNo,WORD latch,WORD axis,int *number);
//读取锁存值
SMC_API short __stdcall smc_softltc_get_value_unit(WORD ConnectNo,WORD latch,WORD axis,double *value);
/*********************************************************************************************************
模拟量操作
*********************************************************************************************************/
SMC_API short __stdcall smc_set_ain_action(WORD ConnectNo,WORD channel,WORD mode,double fvoltage,WORD action,double actpara);
SMC_API short __stdcall smc_get_ain_action(WORD ConnectNo,WORD channel,WORD* mode,double* fvoltage,WORD* action,double* actpara);
SMC_API short __stdcall smc_get_ain_state(WORD ConnectNo,WORD channel);
SMC_API short __stdcall smc_set_ain_state(WORD ConnectNo,WORD channel);
SMC_API double __stdcall smc_get_ain(WORD ConnectNo,WORD channel);
SMC_API short __stdcall smc_set_da_output(WORD ConnectNo, WORD channel,double Vout);
SMC_API short __stdcall smc_get_da_output(WORD ConnectNo,WORD channel,double* Vout);
/*********************************************************************************************************
文件操作
*********************************************************************************************************/
SMC_API short __stdcall smc_download_file(WORD ConnectNo, const char* pfilename, const char* pfilenameinControl,WORD filetype);
SMC_API short __stdcall smc_download_memfile(WORD ConnectNo, const char* pbuffer, uint32 buffsize, const char* pfilenameinControl,WORD filetype);
SMC_API short __stdcall smc_upload_file(WORD ConnectNo, const char* pfilename, const char* pfilenameinControl, WORD filetype);
SMC_API short __stdcall smc_upload_memfile(WORD ConnectNo, char* pbuffer, uint32 buffsize, const char* pfilenameinControl, uint32* puifilesize,WORD filetype);
SMC_API short __stdcall smc_download_file_to_ram(WORD ConnectNo, const char* pfilename,WORD filetype);
SMC_API short __stdcall smc_download_memfile_to_ram(WORD ConnectNo, const char* pbuffer, uint32 buffsize,WORD filetype);
SMC_API short __stdcall smc_get_progress(WORD ConnectNo,float* process);
/********************************************************************************************************
U盘文件管理
*********************************************************************************************************/
SMC_API short __stdcall smc_udisk_get_state(WORD ConnectNo,WORD *state);
SMC_API short __stdcall smc_udisk_check_file(WORD ConnectNo,char* filename,int* filesize,WORD filetype);
SMC_API short __stdcall smc_udisk_get_first_file(WORD ConnectNo,char* filename,int* filesize,int* fileid,WORD filetype);
SMC_API short __stdcall smc_udisk_get_next_file(WORD ConnectNo,char* filename,int* filesize,int* fileid,WORD filetype);
SMC_API short __stdcall smc_udisk_copy_file(WORD ConnectNo,const char* SrcFileName,const char* DstFileName,WORD filetype,WORD mode);
/*********************************************************************************************************
寄存器操作
*********************************************************************************************************/
//Modbus寄存器
SMC_API short __stdcall smc_set_modbus_0x(WORD ConnectNo, WORD start, WORD inum, char* pdata);
SMC_API short __stdcall smc_get_modbus_0x(WORD ConnectNo, WORD start, WORD inum, char* pdata);
SMC_API short __stdcall smc_set_modbus_4x(WORD ConnectNo, WORD start, WORD inum, WORD* pdata);
SMC_API short __stdcall smc_get_modbus_4x(WORD ConnectNo, WORD start, WORD inum, WORD* pdata);
//掉电保持寄存器
SMC_API short __stdcall smc_set_persistent_reg(WORD ConnectNo, DWORD start, DWORD inum, const char* pdata);
SMC_API short __stdcall smc_get_persistent_reg(WORD ConnectNo, DWORD start, DWORD inum, char* pdata);
//以下分类型区间
SMC_API short __stdcall smc_set_persistent_reg_byte(WORD ConnectNo, DWORD start, DWORD inum, const char* pdata);
SMC_API short __stdcall smc_get_persistent_reg_byte(WORD ConnectNo, DWORD start, DWORD inum, char* pdata);
SMC_API short __stdcall smc_set_persistent_reg_float(WORD ConnectNo, DWORD start, DWORD inum, const float* pdata);
SMC_API short __stdcall smc_get_persistent_reg_float(WORD ConnectNo, DWORD start, DWORD inum, float* pdata);
SMC_API short __stdcall smc_set_persistent_reg_int(WORD ConnectNo, DWORD start, DWORD inum, const int* pdata);
SMC_API short __stdcall smc_get_persistent_reg_int(WORD ConnectNo, DWORD start, DWORD inum, int* pdata);
SMC_API short __stdcall smc_set_persistent_reg_short(WORD ConnectNo, DWORD start, DWORD inum, const short* pdata);
SMC_API short __stdcall smc_get_persistent_reg_short(WORD ConnectNo, DWORD start, DWORD inum, short* pdata);
/*********************************************************************************************************
Basic程序控制
*********************************************************************************************************/
SMC_API short __stdcall smc_read_array(WORD ConnectNo ,const char* name,uint32 index,int64* var,int32 *num);
SMC_API short __stdcall smc_modify_array(WORD ConnectNo ,const char* name,uint32 index,int64* var,int32 num);
SMC_API short __stdcall smc_read_var(WORD ConnectNo,const char* varstring, int64* var,int32 *num);
SMC_API short __stdcall smc_modify_var(WORD ConnectNo,const char*varstring, int64* var,int32 varnum);
SMC_API short __stdcall smc_write_array(WORD ConnectNo ,const char* name,uint32 startindex,int64* var,int32 num);

SMC_API short __stdcall smc_read_array_ex(WORD ConnectNo ,const char* name,uint32 index,double* var,int32 *num);
SMC_API short __stdcall smc_modify_array_ex(WORD ConnectNo ,const char* name,uint32 index,double* var,int32 num);
SMC_API short __stdcall smc_read_var_ex(WORD ConnectNo,const char* varstring, double* var,int32 *num);
SMC_API short __stdcall smc_modify_var_ex(WORD ConnectNo,const char*varstring, double* var,int32 varnum);
SMC_API short __stdcall smc_write_array_ex(WORD ConnectNo ,const char* name,uint32 startindex,double* var,int32 num);

SMC_API short __stdcall smc_get_stringtype(WORD ConnectNo,const char* varstring,int32* m_Type,int32* num);
SMC_API short __stdcall smc_basic_delete_file(WORD ConnectNo);
SMC_API short __stdcall smc_basic_run(WORD ConnectNo);
SMC_API short __stdcall smc_basic_stop(WORD ConnectNo);
SMC_API short __stdcall smc_basic_pause(WORD ConnectNo);
SMC_API short __stdcall smc_basic_step_run(WORD ConnectNo);
SMC_API short __stdcall smc_basic_step_over(WORD ConnectNo);
SMC_API short __stdcall smc_basic_continue_run(WORD ConnectNo);
SMC_API short __stdcall smc_basic_state(WORD ConnectNo, WORD* State);
SMC_API short __stdcall smc_basic_current_line(WORD ConnectNo, uint32* line);
SMC_API short __stdcall smc_basic_break_info(WORD ConnectNo, uint32* line,uint32 linenum);
SMC_API short __stdcall smc_basic_message(WORD ConnectNo, char * pbuff, uint32 uimax, uint32 *puiread);
SMC_API short __stdcall smc_basic_command(WORD ConnectNo, const char* pszCommand, char* psResponse, uint32 uiResponseLength);
/*********************************************************************************************************
G代码程序控制
*********************************************************************************************************/
SMC_API short __stdcall smc_gcode_check_file(WORD ConnectNo, const char* pfilenameinControl, uint8 *pbIfExist, uint32 *pFileSize);
SMC_API short __stdcall smc_gcode_get_first_file(WORD ConnectNo,char* pfilenameinControl,uint32* pFileSize);
SMC_API short __stdcall smc_gcode_get_next_file(WORD ConnectNo,char* pfilenameinControl,uint32* pFileSize);
SMC_API short __stdcall smc_gcode_start(WORD ConnectNo);
SMC_API short __stdcall smc_gcode_stop(WORD ConnectNo);
SMC_API short __stdcall smc_gcode_pause(WORD ConnectNo);
SMC_API short __stdcall smc_gcode_state(WORD ConnectNo,  WORD* State);
SMC_API short __stdcall smc_gcode_set_current_file(WORD ConnectNo,const char* pFileName);
SMC_API short __stdcall smc_gcode_get_current_file(WORD ConnectNo,char* pfilenameinControl,WORD *fileid);
SMC_API short __stdcall smc_gcode_current_line(WORD ConnectNo,uint32* line,char* pCurLine);
SMC_API short __stdcall smc_gcode_get_current_line(WORD ConnectNo,uint32* line,char* pCurLine);
SMC_API short __stdcall smc_gcode_check_file_id(WORD ConnectNo, WORD fileid, char *pFileName,uint32 *pFileSize, uint32 *pTotalLine);
SMC_API short __stdcall smc_gcode_check_file_name(WORD ConnectNo,const char *pFileName, WORD *fileid, uint32 *pFileSize, uint32 *pTotalLine);
SMC_API short __stdcall smc_gcode_get_file_profile(WORD ConnectNo,uint32* maxfilenum,uint32* maxfilesize,uint32* savedfilenum);
SMC_API short __stdcall smc_gcode_add_line(WORD ConnectNo,const char *strline);
SMC_API short __stdcall smc_gcode_add_line_array(WORD ConnectNo,int arraysize,const float* linearray);
SMC_API short __stdcall smc_gcode_insert_line(WORD ConnectNo,int lineno,const char *strline);
SMC_API short __stdcall smc_gcode_insert_line_array(WORD ConnectNo,int lineno,int arraysize,const float *linearray);
SMC_API short __stdcall smc_gcode_modify_line(WORD ConnectNo,int lineno,const char *strline);
SMC_API short __stdcall smc_gcode_modify_line_array(WORD ConnectNo,int lineno,int arraysize,const float *linearray);
SMC_API short __stdcall smc_gcode_delete_line(WORD ConnectNo,int lineno);
SMC_API short __stdcall smc_gcode_get_line(WORD ConnectNo,uint32 line,char *strLine);
SMC_API short __stdcall smc_gcode_get_line_array(WORD ConnectNo,int lineno,int *arraysize,float *linearray);
SMC_API short __stdcall smc_gcode_create_file(WORD ConnectNo,const char *FileName);
SMC_API short __stdcall smc_gcode_save_file(WORD ConnectNo,const char *FileName);
SMC_API short __stdcall smc_gcode_copy_file(WORD ConnectNo,const char* strFileName,const char* newFileName);
SMC_API short __stdcall smc_gcode_rename_file(WORD ConnectNo,const char* strFileName,const char* newFileName);
SMC_API short __stdcall smc_gcode_delete_fileid(WORD ConnectNo,int fileid);
SMC_API short __stdcall smc_gcode_delete_file(WORD ConnectNo, const char* pfilenameinControl);
SMC_API short __stdcall smc_gcode_clear_file(WORD ConnectNo);
SMC_API short __stdcall smc_gcode_get_fileid(WORD ConnectNo,uint32 fileid,char *pFileName,uint32 *filesize);
SMC_API short __stdcall smc_gcode_set_step_state(WORD ConnectNo,WORD state);
SMC_API short __stdcall smc_gcode_get_step_state(WORD ConnectNo,WORD *state);
SMC_API short __stdcall smc_gcode_stop_reason(WORD ConnectNo,WORD *stop_reason);

/*********************************************************************************************************
状态监控
*********************************************************************************************************/
SMC_API short __stdcall smc_emg_stop(WORD ConnectNo);
SMC_API short __stdcall smc_check_done(WORD ConnectNo,WORD axis);
SMC_API short __stdcall smc_stop(WORD ConnectNo,WORD axis,WORD stop_mode);
SMC_API short __stdcall smc_check_done_multicoor(WORD ConnectNo,WORD Crd);
SMC_API short __stdcall smc_stop_multicoor(WORD ConnectNo,WORD Crd,WORD stop_mode);
SMC_API DWORD __stdcall smc_axis_io_status(WORD ConnectNo,WORD axis);
SMC_API DWORD __stdcall smc_axis_io_enable_status(WORD ConnectNo,WORD axis);
SMC_API short __stdcall smc_get_axis_run_mode(WORD ConnectNo, WORD axis,WORD* run_mode);
SMC_API short __stdcall smc_read_current_speed_unit(WORD ConnectNo,WORD axis, double *current_speed);
SMC_API short __stdcall smc_set_position_unit(WORD ConnectNo,WORD axis, double pos);
SMC_API short __stdcall smc_get_position_unit(WORD ConnectNo,WORD axis, double * pos);
SMC_API short __stdcall smc_get_target_position_unit(WORD ConnectNo,WORD axis, double * pos);
SMC_API short __stdcall smc_set_workpos_unit(WORD ConnectNo,WORD axis, double pos);
SMC_API short __stdcall smc_get_workpos_unit(WORD ConnectNo,WORD axis, double *pos);
SMC_API short __stdcall smc_get_stop_reason(WORD ConnectNo,WORD axis,long* StopReason);
SMC_API short __stdcall smc_clear_stop_reason(WORD ConnectNo,WORD axis);

/**************************************************************************************************************************
数据采集
***************************************************************************************************************************/
SMC_API short __stdcall smc_trace_set_source(WORD ConnectNo,WORD source);
//单轴数据实时采集调用
SMC_API short __stdcall smc_read_trace_data(WORD ConnectNo,WORD axis,long bufsize,double *time,double *pos,double *vel,double *acc,long *recv_num);
//多轴数据采集缓存文件
SMC_API short __stdcall smc_trace_start(WORD ConnectNo,WORD AxisNum,WORD *AxisList);
SMC_API short __stdcall smc_trace_stop(WORD ConnectNo);
//filetype==100采集文件
//SMC_API short __stdcall smc_upload_file(WORD ConnectNo, const char* pfilename, const char* pfilenameinControl, WORD filetype);
//SMC_API short __stdcall smc_upload_memfile(WORD ConnectNo, char* pbuffer, uint32 buffsize, const char* pfilenameinControl, uint32* puifilesize,WORD filetype);

/*********************************************************************************************************
总线专用函数
PortNo总线端口号
0-CANopen0
1-CANopen1
2-EtherCAT0
3-EtherCAT1
*********************************************************************************************************/
/*************************************** CANopen **************************************/
//复位CANopen主站
SMC_API short __stdcall nmcs_reset_canopen(WORD ConnectNo);
//复位RTEX主站
SMC_API short __stdcall nmcs_reset_rtex(WORD ConnectNo);
//复位EtherCAT主站
SMC_API short __stdcall nmcs_reset_etc(WORD ConnectNo);
SMC_API short __stdcall nmcs_axis_io_status(WORD ConnectNo,WORD axis);	//读取指定轴有关运动信号的状态
//获取心跳报文丢失信息
SMC_API short __stdcall nmcs_get_LostHeartbeat_Nodes(WORD ConnectNo,WORD PortNo,WORD* NodeID,WORD* NodeNum);
//获取紧急报文信息
SMC_API short __stdcall nmcs_get_EmergeneyMessege_Nodes(WORD ConnectNo,WORD PortNo,DWORD* NodeMsg,WORD* MsgNum);
SMC_API short __stdcall nmcs_SendNmtCommand(WORD ConnectNo,WORD PortNo,WORD NodeID,WORD NmtCommand);
//清除报警信号
SMC_API short __stdcall nmcs_set_alarm_clear(WORD ConnectNo,WORD PortNo,WORD NodeNo);
//同步运动
SMC_API short __stdcall nmcs_syn_move_unit(WORD ConnectNo,WORD AxisNum,WORD* AxisList,double* Position,WORD* PosiMode);

/*************************************** EtherCAT **************************************/
//停止EtherCAT协议栈
SMC_API short __stdcall nmcs_stop_etc(WORD ConnectNo,WORD* ETCState);
//读取EtherCAT轴状态
SMC_API short __stdcall nmcs_get_axis_state_machine(WORD ConnectNo,WORD axis, WORD* Axis_StateMachine);

//单轴使能函数
SMC_API short __stdcall nmcs_set_axis_enable(WORD ConnectNo ,WORD axis);
SMC_API short __stdcall nmcs_set_axis_disable(WORD ConnectNo,WORD axis);

SMC_API DWORD __stdcall nmcs_get_axis_io_out(WORD ConnectNo,WORD axis);
SMC_API short __stdcall nmcs_set_axis_io_out(WORD ConnectNo,WORD axis,DWORD  iostate);
SMC_API DWORD __stdcall nmcs_get_axis_io_in(WORD ConnectNo,WORD axis);

SMC_API short __stdcall nmcs_get_cycletime(WORD ConnectNo,WORD PortNo,DWORD* CycleTime);

SMC_API short __stdcall nmcs_write_rxpdo_extra(WORD ConnectNo,WORD PortNo,WORD address,WORD DataLen,DWORD Value);
SMC_API short __stdcall nmcs_read_rxpdo_extra(WORD ConnectNo,WORD PortNo,WORD address,WORD DataLen,DWORD* Value);
SMC_API short __stdcall nmcs_read_txpdo_extra(WORD ConnectNo,WORD PortNo,WORD address,WORD DataLen,DWORD* Value);

/*************************************** RTEX **************************************/
SMC_API short __stdcall nmcs_start_connect(WORD ConnectNo,WORD chan,WORD*info,WORD* len);
SMC_API short __stdcall nmcs_get_vendor_info(WORD ConnectNo,WORD axis,char* info,WORD* len);
SMC_API short __stdcall nmcs_get_slave_type_info(WORD ConnectNo,WORD axis,char* info,WORD* len);
SMC_API short __stdcall nmcs_get_slave_name_info(WORD ConnectNo,WORD axis,char* info,WORD* len);
SMC_API short __stdcall nmcs_get_slave_version_info(WORD ConnectNo,WORD axis,char* info,WORD* len);

SMC_API short __stdcall nmcs_write_parameter(WORD ConnectNo,WORD axis,WORD index, WORD subindex,DWORD para_data);
/**************************************************************
*功能说明：RTEX驱动器写EEPROM操作
*
*
**************************************************************/
SMC_API short __stdcall nmcs_write_slave_eeprom(WORD ConnectNo,WORD axis);
/**************************************************************
*index:rtex驱动器的参数分类
*subindex:rtex驱动器在index类别下的参数编号
*para_data:读出的参数值
**************************************************************/
SMC_API short __stdcall nmcs_read_parameter(WORD ConnectNo,WORD axis,WORD index, WORD subindex,DWORD* para_data);
/**************************************************************
*index:rtex驱动器的参数分类
*subindex:rtex驱动器在index类别下的参数编号
*para_data:读出的参数值
**************************************************************/
SMC_API short __stdcall nmcs_read_parameter_attributes(WORD ConnectNo,WORD axis,WORD index, WORD subindex,DWORD* para_data);
//设置RTEX总线周期比(us)
SMC_API short __stdcall nmcs_set_cmdcycletime(WORD ConnectNo,WORD PortNum,DWORD cmdtime);
SMC_API short __stdcall nmcs_get_cmdcycletime(WORD ConnectNo,WORD PortNum,DWORD* cmdtime);
SMC_API short __stdcall nmcs_start_log(WORD ConnectNo,WORD chan,WORD node, WORD Ifenable);
SMC_API short __stdcall nmcs_get_log(WORD ConnectNo,WORD chan,WORD node, DWORD* data);
SMC_API short __stdcall nmcs_config_atuo_log(WORD ConnectNo,WORD ifenable,WORD dir,WORD byte_index,WORD mask,WORD condition,DWORD counter);
SMC_API short __stdcall nmcs_get_log_state(WORD ConnectNo,WORD chan, DWORD* state);
SMC_API short __stdcall nmcs_driver_reset(WORD ConnectNo,WORD axis);

/*************************************** EtherCAT & CANopen**************************************/
SMC_API short __stdcall nmcs_get_axis_type(WORD ConnectNo,WORD axis, WORD* Axis_Type);

//从站对象字典
SMC_API short __stdcall nmcs_set_node_od(WORD ConnectNo,WORD PortNo,WORD NodeNo, WORD Index,WORD SubIndex,WORD ValLength,DWORD Value);
SMC_API short __stdcall nmcs_get_node_od(WORD ConnectNo,WORD PortNo,WORD NodeNo, WORD Index,WORD SubIndex,WORD ValLength,DWORD* Value);

//总线错误
SMC_API short __stdcall nmcs_get_card_errcode(WORD ConnectNo,DWORD *Errcode);
SMC_API short __stdcall nmcs_clear_card_errcode(WORD ConnectNo);

SMC_API short __stdcall nmcs_get_errcode(WORD ConnectNo,WORD PortNo,DWORD *Errcode);
SMC_API short __stdcall nmcs_clear_errcode(WORD ConnectNo,WORD PortNo);

SMC_API short __stdcall nmcs_get_axis_errcode(WORD ConnectNo,WORD axis,DWORD *Errcode);
SMC_API short __stdcall nmcs_clear_axis_errcode(WORD ConnectNo,WORD iaxis);

//读取轴数、IO数、模拟量数
SMC_API short __stdcall nmcs_get_total_axes(WORD ConnectNo,DWORD *TotalAxis);
SMC_API short __stdcall nmcs_get_total_ionum(WORD ConnectNo,WORD *TotalIn,WORD *TotalOut);
SMC_API short __stdcall nmcs_get_total_adcnum(WORD ConnectNo,WORD *TotalIn,WORD *TotalOut);

//按节点操作扩展IO
SMC_API short __stdcall nmcs_read_inbit_extern(WORD ConnectNo,WORD PortNo,WORD NodeID,WORD BitNo,WORD *IoValue);
SMC_API short __stdcall nmcs_read_inport_extern(WORD ConnectNo,WORD PortNo,WORD NodeID,WORD IoPortNo,DWORD *IoValue);
SMC_API short __stdcall nmcs_write_outbit_extern(WORD ConnectNo,WORD PortNo,WORD NodeID,WORD BitNo,WORD IoValue);
SMC_API short __stdcall nmcs_write_outport_extern(WORD ConnectNo,WORD PortNo,WORD NodeID,WORD IoPortNo,DWORD IoValue);
SMC_API short __stdcall nmcs_read_outbit_extern(WORD ConnectNo,WORD PortNo,WORD NodeID,WORD BitNo,WORD *IoValue);
SMC_API short __stdcall nmcs_read_outport_extern(WORD ConnectNo,WORD PortNo,WORD NodeID,WORD IoPortNo,DWORD *IoValue);

//转矩控制功能函数
SMC_API short __stdcall nmcs_torque_move(WORD CardNo,WORD axis,int Torque,WORD PosLimitValid,double PosLimitValue,WORD PosMode);
SMC_API short __stdcall nmcs_change_torque(WORD CardNo,WORD axis,int Torque);
SMC_API short __stdcall nmcs_get_torque(WORD CardNo,WORD axis,int* Torque);

#ifdef __cplusplus
}
#endif

#endif