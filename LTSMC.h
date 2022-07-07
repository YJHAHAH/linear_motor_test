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

//������������
#ifdef __SMC_EXPORTS
	#define SMC_API __declspec(dllexport)
#else
	#define SMC_API __declspec(dllimport)
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*********************************************************************************************************
���ܺ��� 
***********************************************************************************************************/
//�������ӳ�ʱʱ��
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
//��д���кţ��ɽ���������ǩ�ϵ����кŻ��߿ͻ��Զ�������к�д����������ϵ籣��
SMC_API short __stdcall smc_write_sn(WORD ConnectNo, uint64 sn);
SMC_API short __stdcall smc_read_sn(WORD ConnectNo, uint64* sn);
SMC_API short __stdcall smc_write_sn_numstring(WORD ConnectNo, const char* sn_str);//sn_str 16�����ַ��� �̶�16���ַ�
SMC_API short __stdcall smc_read_sn_numstring(WORD ConnectNo, char* sn_str);
//�ͻ��Զ��������ַ��������256���ַ�����ͨ����������Ч�����ͻ�Ӧ�ó���
SMC_API short __stdcall smc_write_password(WORD ConnectNo, const char * str_pass);
SMC_API short __stdcall smc_check_password(WORD ConnectNo, const char * str_pass);
//�������޸����룬�������������ƿ������ָ����������Լ��ϴ�BASIC����ʹ��
SMC_API short __stdcall smc_enter_password(WORD ConnectNo, const char * str_pass);
SMC_API short __stdcall smc_modify_password(WORD ConnectNo, const char* spassold, const char* spass);

//�����ļ�����
SMC_API short __stdcall smc_download_parafile(WORD ConnectNo,const char *FileName);
SMC_API short __stdcall smc_upload_parafile(WORD ConnectNo,const char *FileName);
/*********************************************************************************************************
��ȫ���Ʋ���
*********************************************************************************************************/
SMC_API short __stdcall smc_set_el_mode(WORD ConnectNo,WORD axis,WORD enable,WORD el_logic,WORD el_mode);
SMC_API short __stdcall smc_get_el_mode(WORD ConnectNo,WORD axis,WORD *enable,WORD *el_logic,WORD *el_mode);
SMC_API short __stdcall smc_set_emg_mode(WORD ConnectNo,WORD axis,WORD enable,WORD emg_logic);
SMC_API short __stdcall smc_get_emg_mode(WORD ConnectNo,WORD axis,WORD *enable,WORD *emg_logic);
SMC_API short __stdcall smc_set_softlimit_unit(WORD ConnectNo,WORD axis,WORD enable, WORD source_sel,WORD SL_action, double N_limit,double P_limit);
SMC_API short __stdcall smc_get_softlimit_unit(WORD ConnectNo,WORD axis,WORD *enable, WORD *source_sel,WORD *SL_action,double *N_limit,double *P_limit);
/*********************************************************************************************************
�������⹦�ܲ���
*********************************************************************************************************/
SMC_API short __stdcall smc_set_pulse_outmode(WORD ConnectNo,WORD axis,WORD outmode);
SMC_API short __stdcall smc_get_pulse_outmode(WORD ConnectNo,WORD axis,WORD* outmode);
SMC_API short __stdcall smc_set_equiv(WORD ConnectNo,WORD axis, double equiv);
SMC_API short __stdcall smc_get_equiv(WORD ConnectNo,WORD axis, double *equiv);
SMC_API short __stdcall smc_set_backlash_unit(WORD ConnectNo,WORD axis,double backlash);
SMC_API short __stdcall smc_get_backlash_unit(WORD ConnectNo,WORD axis,double *backlash);
//��IOӳ��
SMC_API short __stdcall smc_set_axis_io_map(WORD ConnectNo,WORD Axis,WORD IoType,WORD MapIoType,WORD MapIoIndex,double Filter);
SMC_API short __stdcall smc_get_axis_io_map(WORD ConnectNo,WORD Axis,WORD IoType,WORD* MapIoType,WORD* MapIoIndex,double* Filter);
/*********************************************************************************************************
�����ٶȲ���
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
�����˶�
*********************************************************************************************************/
SMC_API short __stdcall smc_pmove_unit(WORD ConnectNo,WORD axis,double Dist,WORD posi_mode);
SMC_API short __stdcall smc_vmove(WORD ConnectNo,WORD axis,WORD dir);
SMC_API short __stdcall smc_change_speed_unit(WORD ConnectNo,WORD axis, double New_Vel,double Taccdec);
SMC_API short __stdcall smc_reset_target_position_unit(WORD ConnectNo,WORD axis, double New_Pos);
SMC_API short __stdcall smc_update_target_position_unit(WORD ConnectNo,WORD axis, double New_Pos);
//����½����
SMC_API short __stdcall smc_pmove_unit_extern(WORD ConnectNo, WORD axis, double MidPos,double TargetPos, double Min_Vel,double Max_Vel, double stop_Vel, double acc,double dec,double smooth_time,WORD posi_mode);

//�������߶����˶�
SMC_API short __stdcall smc_set_plan_mode(WORD ConnectNo,WORD axis,WORD mode);
SMC_API short __stdcall smc_get_plan_mode(WORD ConnectNo,WORD axis,WORD *mode);
SMC_API short __stdcall smc_pmove_sin_unit(WORD ConnectNo,WORD axis,double Dist,WORD posi_mode,double MaxVel,double MaxAcc);

/*********************************************************************************************************
�����˶�
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
//��ԭ��״̬��state��0-δ��ɣ�1-���
SMC_API short __stdcall smc_get_home_result(WORD ConnectNo,WORD axis,WORD* state);
//��λ��ԭ���л���mode��0-Ĭ��ԭ�㣬1-����λ��ԭ�㣬2-����λ��ԭ��
SMC_API short __stdcall smc_set_el_home(WORD ConnectNo,WORD axis,WORD mode);
//20151017������ɺ�����λ��
SMC_API short __stdcall smc_set_home_position_unit(WORD ConnectNo,WORD axis,WORD enable,double position);
SMC_API short __stdcall smc_get_home_position_unit(WORD ConnectNo,WORD axis,WORD *enable,double *position);
SMC_API short __stdcall smc_home_move(WORD ConnectNo,WORD axis);
/*********************************************************************************************************
PVT�˶�
*********************************************************************************************************/
SMC_API short __stdcall smc_pvt_table_unit(WORD ConnectNo,WORD iaxis,DWORD count,double *pTime,double *pPos,double *pVel);
SMC_API short __stdcall smc_pts_table_unit(WORD ConnectNo,WORD iaxis,DWORD count,double *pTime,double *pPos,double *pPercent);
SMC_API short __stdcall smc_pvts_table_unit(WORD ConnectNo,WORD iaxis,DWORD count,double *pTime,double *pPos,double velBegin,double velEnd);
SMC_API short __stdcall smc_ptt_table_unit(WORD ConnectNo,WORD iaxis,DWORD count,double *pTime,double *pPos);
SMC_API short __stdcall smc_pvt_move(WORD ConnectNo,WORD AxisNum,WORD* AxisList);
/*********************************************************************************************************
���׵���͹���˶�
*********************************************************************************************************/
SMC_API short __stdcall smc_cam_table_unit(WORD ConnectNo,WORD MasterAxisNo,WORD SlaveAxisNo,DWORD Count,double *pMasterPos,double *pSlavePos,WORD SrcMode);
SMC_API short __stdcall smc_cam_move(WORD ConnectNo,WORD AxisNo);

/*********************************************************************************************************
�������˶�
*********************************************************************************************************/
SMC_API short __stdcall smc_sine_oscillate_unit(WORD ConnectNo,WORD Axis,double Amplitude,double Frequency);
SMC_API short __stdcall smc_sine_oscillate_stop(WORD ConnectNo,WORD Axis);
/*********************************************************************************************************
�������ϳ��ٶ��˶������ޱ������ᴦ�ڲ岹ģʽ
*********************************************************************************************************/
SMC_API short __stdcall smc_follow_vector_speed_move(WORD ConnectNo,WORD Axis,WORD Crd,double ratio);
/*********************************************************************************************************
�����˶�
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
����岹�ٶȲ�������
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
���ᵥ�β岹�˶�
*********************************************************************************************************/
SMC_API short __stdcall smc_line_unit(WORD ConnectNo,WORD Crd,WORD AxisNum,WORD* AxisList,double* Dist,WORD posi_mode);
SMC_API short __stdcall smc_arc_move_center_unit(WORD ConnectNo,WORD Crd,WORD AxisNum,WORD* AxisList,double *Target_Pos,double *Cen_Pos,WORD Arc_Dir,long Circle,WORD posi_mode);
SMC_API short __stdcall smc_arc_move_radius_unit(WORD ConnectNo,WORD Crd,WORD AxisNum,WORD* AxisList,double *Target_Pos,double Arc_Radius,WORD Arc_Dir,long Circle,WORD posi_mode);
SMC_API short __stdcall smc_arc_move_3points_unit(WORD ConnectNo,WORD Crd,WORD AxisNum,WORD* AxisList,double *Target_Pos,double *Mid_Pos,long Circle,WORD posi_mode);
/*********************************************************************************************************
���������岹�˶�
*********************************************************************************************************/
//С�߶�ǰհ
SMC_API short __stdcall smc_conti_set_lookahead_mode(WORD ConnectNo,WORD Crd,WORD enable,long LookaheadSegments,double PathError,double LookaheadAcc);
SMC_API short __stdcall smc_conti_get_lookahead_mode(WORD ConnectNo,WORD Crd,WORD* enable,long* LookaheadSegments,double* PathError,double* LookaheadAcc);
//Բ������
SMC_API short __stdcall smc_set_arc_limit(WORD ConnectNo,WORD Crd,WORD Enable,double MaxCenAcc=0,double MaxArcError=0);
SMC_API short __stdcall smc_get_arc_limit(WORD ConnectNo,WORD Crd,WORD* Enable,double* MaxCenAcc=NULL,double* MaxArcError=NULL);

//�����岹����
SMC_API short __stdcall smc_conti_open_list (WORD ConnectNo,WORD Crd,WORD AxisNum,WORD *AxisList);
SMC_API short __stdcall smc_conti_close_list(WORD ConnectNo,WORD Crd);
SMC_API short __stdcall smc_conti_stop_list (WORD ConnectNo,WORD Crd,WORD stop_mode);
SMC_API short __stdcall smc_conti_pause_list(WORD ConnectNo,WORD Crd);
SMC_API short __stdcall smc_conti_start_list(WORD ConnectNo,WORD Crd);
SMC_API short __stdcall smc_conti_change_speed_ratio (WORD ConnectNo,WORD Crd,double percent);
//�����岹״̬
SMC_API short __stdcall smc_conti_get_run_state(WORD ConnectNo,WORD Crd);
SMC_API long __stdcall smc_conti_remain_space (WORD ConnectNo,WORD Crd);
SMC_API long __stdcall smc_conti_read_current_mark (WORD ConnectNo,WORD Crd);
//�����岹�켣��
SMC_API short __stdcall smc_conti_line_unit(WORD ConnectNo,WORD Crd,WORD AxisNum,WORD* AxisList,double* pPosList,WORD posi_mode,long mark);
SMC_API short __stdcall smc_conti_arc_move_center_unit(WORD ConnectNo,WORD Crd,WORD AxisNum,WORD* AxisList,double *Target_Pos,double *Cen_Pos,WORD Arc_Dir,long Circle,WORD posi_mode,long mark);
SMC_API short __stdcall smc_conti_arc_move_radius_unit(WORD ConnectNo,WORD Crd,WORD AxisNum,WORD* AxisList,double *Target_Pos,double Arc_Radius,WORD Arc_Dir,long Circle,WORD posi_mode,long mark);
SMC_API short __stdcall smc_conti_arc_move_3points_unit(WORD ConnectNo,WORD Crd,WORD AxisNum,WORD* AxisList,double *Target_Pos,double *Mid_Pos,long Circle,WORD posi_mode,long mark);
//�����岹IO����
SMC_API short __stdcall smc_conti_wait_input(WORD ConnectNo,WORD Crd,WORD bitno,WORD on_off,double TimeOut,long mark);
SMC_API short __stdcall smc_conti_delay_outbit_to_start(WORD ConnectNo, WORD Crd, WORD bitno,WORD on_off,double delay_value,WORD delay_mode,double ReverseTime);
SMC_API short __stdcall smc_conti_delay_outbit_to_stop(WORD ConnectNo, WORD Crd, WORD bitno,WORD on_off,double delay_time,double ReverseTime);
SMC_API short __stdcall smc_conti_ahead_outbit_to_stop(WORD ConnectNo, WORD Crd, WORD bitno,WORD on_off,double ahead_value,WORD ahead_mode,double ReverseTime);
SMC_API short __stdcall smc_conti_accurate_outbit_unit(WORD ConnectNo, WORD Crd, WORD cmp_no,WORD on_off,WORD axis,double abs_pos,WORD pos_source,double ReverseTime);
SMC_API short __stdcall smc_conti_write_outbit(WORD ConnectNo, WORD Crd, WORD bitno,WORD on_off,double ReverseTime);
SMC_API short __stdcall smc_conti_clear_io_action(WORD ConnectNo, WORD Crd, DWORD Io_Mask);
SMC_API short __stdcall smc_conti_set_pause_output(WORD ConnectNo,WORD Crd,WORD action,long mask,long state);
SMC_API short __stdcall smc_conti_get_pause_output(WORD ConnectNo,WORD Crd,WORD* action,long* mask,long* state);
//�����岹���⹦��
SMC_API short __stdcall smc_conti_set_override(WORD ConnectNo,WORD Crd,double Percent);
SMC_API short __stdcall smc_conti_set_blend(WORD ConnectNo,WORD Crd,WORD enable);
SMC_API short __stdcall smc_conti_get_blend(WORD ConnectNo,WORD Crd,WORD* enable);
SMC_API short __stdcall smc_conti_pmove_unit(WORD ConnectNo,WORD Crd,WORD axis,double dist,WORD posi_mode,WORD mode,long mark);
SMC_API short __stdcall smc_conti_delay(WORD ConnectNo, WORD Crd,double delay_time,long mark);
//��ȡ��������ľ���
SMC_API short __stdcall smc_get_distance_to_start(WORD CardNo,WORD Crd, double* distance_x, double* distance_y,long imark); 
//���ñ�־λ ��ʾ�Ƿ�ʼ����������
SMC_API short __stdcall smc_set_start_distance_flag(WORD CardNo,WORD Crd,WORD flag); 
SMC_API short __stdcall smc_get_start_distance_flag(WORD CardNo,WORD Crd,WORD *flag); 
/*********************************************************************************************************
PWM����
*********************************************************************************************************/
//��IO���õ������ʹ��
SMC_API short __stdcall smc_set_pwm_enable(WORD ConnectNo,WORD pwm,WORD enable);
SMC_API short __stdcall smc_get_pwm_enable(WORD ConnectNo,WORD pwm,WORD* enable);
SMC_API short __stdcall smc_set_pwm_output(WORD ConnectNo, WORD PwmNo,double fDuty, double fFre);
SMC_API short __stdcall smc_get_pwm_output(WORD ConnectNo,WORD PwmNo,double* fDuty, double* fFre);
SMC_API short __stdcall smc_conti_set_pwm_output(WORD ConnectNo,WORD Crd, WORD PwmNo,double fDuty, double fFre);
/**********PWM�ٶȸ���***********************************************************************************
mode:����ģʽ0-������ ����״̬ 1-������ ����͵�ƽ2-������ ����ߵ�ƽ3-���� ռ�ձ��Զ�����4-���� Ƶ���Զ�����
MaxVel:��������ٶȣ���λunit
MaxValue:������ռ�ձȻ���Ƶ��
OutValue���������Ƶ�ʻ�ռ�ձ�
*******************************************************************************************************/
SMC_API short __stdcall smc_set_pwm_follow_speed(WORD ConnectNo,WORD pwm_no,WORD mode,double MaxVel,double MaxValue,double OutValue);
SMC_API short __stdcall smc_get_pwm_follow_speed(WORD ConnectNo,WORD pwm_no,WORD* mode,double* MaxVel,double* MaxValue,double* OutValue);
//����PWM���ض�Ӧ��ռ�ձ�
SMC_API short __stdcall smc_set_pwm_onoff_duty(WORD ConnectNo, WORD PwmNo,double fOnDuty, double fOffDuty);
SMC_API short __stdcall smc_get_pwm_onoff_duty(WORD ConnectNo, WORD PwmNo,double* fOnDuty, double* fOffDuty);

SMC_API short __stdcall smc_set_pwm_follow_onoff(WORD ConnectNo, WORD PwmNo,WORD Crd,WORD on_off);
SMC_API short __stdcall smc_get_pwm_follow_onoff(WORD ConnectNo, WORD PwmNo,WORD *Crd,WORD *on_off);

SMC_API short __stdcall smc_conti_delay_pwm_to_start(WORD ConnectNo, WORD Crd, WORD pwmno,WORD on_off,double delay_value,WORD delay_mode,double ReverseTime);
SMC_API short __stdcall smc_conti_ahead_pwm_to_stop(WORD ConnectNo, WORD Crd, WORD bitno,WORD on_off,double ahead_value,WORD ahead_mode,double ReverseTime);
SMC_API short __stdcall smc_conti_write_pwm(WORD ConnectNo, WORD Crd, WORD pwmno,WORD on_off,double ReverseTime);

/*********************************************************************************************************
SMC106A���ƹ���
*********************************************************************************************************/
SMC_API short __stdcall smc_laser_set_output(WORD ConnectNo,WORD Enable,WORD Width);
SMC_API short __stdcall smc_laser_get_output(WORD ConnectNo,WORD* Enable,WORD* Width);
/*********************************************************************************************************
����������
*********************************************************************************************************/
SMC_API short __stdcall smc_set_counter_inmode(WORD ConnectNo,WORD axis,WORD mode);
SMC_API short __stdcall smc_get_counter_inmode(WORD ConnectNo,WORD axis,WORD *mode);
SMC_API short __stdcall smc_set_counter_reverse(WORD ConnectNo,WORD axis,WORD reverse);
SMC_API short __stdcall smc_get_counter_reverse(WORD ConnectNo,WORD axis,WORD *reverse);
SMC_API short __stdcall smc_set_encoder_unit(WORD ConnectNo,WORD axis, double pos);
SMC_API short __stdcall smc_get_encoder_unit(WORD ConnectNo,WORD axis, double * pos);
/*********************************************************************************************************
��������������
*********************************************************************************************************/
SMC_API short __stdcall smc_set_extra_encoder_mode(WORD ConnectNo,WORD channel,WORD inmode);
SMC_API short __stdcall smc_get_extra_encoder_mode(WORD ConnectNo,WORD channel,WORD* inmode);
SMC_API short __stdcall smc_set_extra_encoder(WORD ConnectNo,WORD channel, int pos);
SMC_API short __stdcall smc_get_extra_encoder(WORD ConnectNo,WORD channel, int * pos);
/*********************************************************************************************************
ͨ��IO����
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

//ͨ��IO���⹦�� SMC104��֧��
SMC_API short __stdcall smc_reverse_outbit(WORD ConnectNo,WORD bitno,double reverse_time);
//����IO���һ�����������PWM��������
SMC_API short __stdcall smc_set_io_pwmoutput(WORD ConnectNo,WORD outbit,double time1, double time2, DWORD counts);
//���IO���PWM��������
SMC_API short __stdcall smc_clear_io_pwmoutput(WORD ConnectNo,WORD outbit);
SMC_API short __stdcall smc_set_io_count_mode(WORD ConnectNo,WORD bitno,WORD mode,double filter);
SMC_API short __stdcall smc_get_io_count_mode(WORD ConnectNo,WORD bitno,WORD *mode,double* filter);
SMC_API short __stdcall smc_set_io_count_value(WORD ConnectNo,WORD bitno,DWORD CountValue);
SMC_API short __stdcall smc_get_io_count_value(WORD ConnectNo,WORD bitno,DWORD* CountValue);
//����IOӳ�� ���������˲�����  SMC104��֧��
SMC_API short __stdcall smc_set_io_map_virtual(WORD ConnectNo,WORD bitno,WORD MapIoType,WORD MapIoIndex,double Filter);
SMC_API short __stdcall smc_get_io_map_virtual(WORD ConnectNo,WORD bitno,WORD* MapIoType,WORD* MapIoIndex,double* Filter);
SMC_API short __stdcall smc_read_inbit_virtual(WORD ConnectNo,WORD bitno); 
/*********************************************************************************************************
ר��IO����
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
λ�ñȽ�
*********************************************************************************************************/
//����λ�ñȽ�		 
SMC_API short __stdcall smc_compare_set_config(WORD ConnectNo,WORD axis,WORD enable, WORD cmp_source); 	//���ñȽ���
SMC_API short __stdcall smc_compare_get_config(WORD ConnectNo,WORD axis,WORD *enable, WORD *cmp_source);	//��ȡ���ñȽ���
SMC_API short __stdcall smc_compare_clear_points(WORD ConnectNo,WORD axis); 	//������бȽϵ�
SMC_API short __stdcall smc_compare_add_point_unit(WORD ConnectNo,WORD axis,double pos,WORD dir, WORD action,DWORD actpara); 	//��ӱȽϵ�
SMC_API short __stdcall smc_compare_add_point_cycle(WORD ConnectNo,WORD axis,double pos,WORD dir, DWORD bitno,DWORD cycle,WORD level);//�����߲�Ʒʹ�� ��ӱȽϵ�
SMC_API short __stdcall smc_compare_get_current_point_unit(WORD ConnectNo,WORD axis,double *pos); 	//��ȡ��ǰ�Ƚϵ�
SMC_API short __stdcall smc_compare_get_points_runned(WORD ConnectNo,WORD axis,long *pointNum); 	//��ѯ�Ѿ��ȽϹ��ĵ�
SMC_API short __stdcall smc_compare_get_points_remained(WORD ConnectNo,WORD axis,long *pointNum); 	//��ѯ���Լ���ıȽϵ�����
//��άλ�ñȽ�
SMC_API short __stdcall smc_compare_set_config_extern(WORD ConnectNo,WORD enable, WORD cmp_source); 	//���ñȽ���
SMC_API short __stdcall smc_compare_get_config_extern(WORD ConnectNo,WORD *enable, WORD *cmp_source);	//��ȡ���ñȽ���
SMC_API short __stdcall smc_compare_clear_points_extern(WORD ConnectNo); 	//������бȽϵ�
SMC_API short __stdcall smc_compare_add_point_extern_unit(WORD ConnectNo,WORD* axis,double* pos,WORD* dir, WORD action,DWORD actpara); 	//�������λ�ñȽϵ�
SMC_API short __stdcall smc_compare_add_point_cycle_2d(WORD ConnectNo,WORD* axis,double* pos,WORD* dir, DWORD bitno,DWORD cycle,WORD level); //�����߲�Ʒʹ�� ��ӱȽϵ�
SMC_API short __stdcall smc_compare_get_current_point_extern_unit(WORD ConnectNo,double *pos); 	//��ȡ��ǰ�Ƚϵ�
SMC_API short __stdcall smc_compare_get_points_runned_extern(WORD ConnectNo,long *pointNum); 	//��ѯ�Ѿ��ȽϹ��ĵ�
SMC_API short __stdcall smc_compare_get_points_remained_extern(WORD ConnectNo,long *pointNum); 	//��ѯ���Լ���ıȽϵ�����
//����λ�ñȽ�
SMC_API short __stdcall smc_hcmp_set_mode(WORD ConnectNo,WORD hcmp, WORD cmp_mode);
SMC_API short __stdcall smc_hcmp_get_mode(WORD ConnectNo,WORD hcmp, WORD* cmp_mode);
SMC_API short __stdcall smc_hcmp_set_config(WORD ConnectNo,WORD hcmp,WORD axis, WORD cmp_source, WORD cmp_logic,long time);
SMC_API short __stdcall smc_hcmp_get_config(WORD ConnectNo,WORD hcmp,WORD* axis, WORD* cmp_source, WORD* cmp_logic,long* time);
SMC_API short __stdcall smc_hcmp_add_point_unit(WORD ConnectNo,WORD hcmp, double cmp_pos);
SMC_API short __stdcall smc_hcmp_set_liner_unit(WORD ConnectNo,WORD hcmp, double Increment,long Count);
SMC_API short __stdcall smc_hcmp_get_liner_unit(WORD ConnectNo,WORD hcmp, double* Increment,long* Count);
SMC_API short __stdcall smc_hcmp_get_current_state_unit(WORD ConnectNo,WORD hcmp,long *remained_points,double *current_point,long *runned_points); 
SMC_API short __stdcall smc_hcmp_clear_points(WORD ConnectNo,WORD hcmp);
//��ά����λ�ñȽ�
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
ԭ������
*********************************************************************************************************/	
SMC_API short __stdcall smc_set_homelatch_mode(WORD ConnectNo,WORD axis,WORD enable,WORD logic,WORD source);
SMC_API short __stdcall smc_get_homelatch_mode(WORD ConnectNo,WORD axis,WORD* enable,WORD* logic,WORD* source);
SMC_API long __stdcall smc_get_homelatch_flag(WORD ConnectNo,WORD axis);
SMC_API short __stdcall smc_reset_homelatch_flag(WORD ConnectNo,WORD axis);
SMC_API short __stdcall smc_get_homelatch_value_unit(WORD ConnectNo,WORD axis,double* pos_by_mm);
/*********************************************************************************************************
EZ����
*********************************************************************************************************/	
SMC_API short __stdcall smc_set_ezlatch_mode(WORD ConnectNo,WORD axis,WORD enable,WORD logic,WORD source);
SMC_API short __stdcall smc_get_ezlatch_mode(WORD ConnectNo,WORD axis,WORD* enable,WORD* logic,WORD* source);
SMC_API long __stdcall smc_get_ezlatch_flag(WORD ConnectNo,WORD axis);
SMC_API short __stdcall smc_reset_ezlatch_flag(WORD ConnectNo,WORD axis);
SMC_API short __stdcall smc_get_ezlatch_value_unit(WORD ConnectNo,WORD axis,double* pos_by_mm);
/*********************************************************************************************************
��������
*********************************************************************************************************/
SMC_API short __stdcall smc_set_ltc_mode(WORD ConnectNo,WORD axis,WORD ltc_logic,WORD ltc_mode,double filter);
SMC_API short __stdcall smc_get_ltc_mode(WORD ConnectNo,WORD axis,WORD*ltc_logic,WORD*ltc_mode,double *filter);
SMC_API short __stdcall smc_set_latch_mode(WORD ConnectNo,WORD axis,WORD all_enable,WORD latch_source,WORD triger_chunnel);
SMC_API short __stdcall smc_get_latch_mode(WORD ConnectNo,WORD axis,WORD* all_enable,WORD* latch_source,WORD* triger_chunnel);
SMC_API short __stdcall smc_get_latch_flag(WORD ConnectNo,WORD axis);
SMC_API short __stdcall smc_reset_latch_flag(WORD ConnectNo,WORD axis);
SMC_API short __stdcall smc_get_latch_value_unit(WORD ConnectNo,WORD axis,double* pos_by_mm);
/*********************************************************************************************************
�������� �¹滮20170308
*********************************************************************************************************/
//����������������ģʽ0-�������棬1-�������棻�������0-�½��أ�1-�����أ�2-˫���أ��˲�ʱ�䣬��λus
SMC_API short __stdcall smc_ltc_set_mode(WORD ConnectNo,WORD latch,WORD ltc_mode,WORD ltc_logic,double filter);
SMC_API short __stdcall smc_ltc_get_mode(WORD ConnectNo,WORD latch,WORD *ltc_mode,WORD *ltc_logic,double *filter);
//��������Դ��0-ָ��λ�ã�1-����������λ��
SMC_API short __stdcall smc_ltc_set_source(WORD ConnectNo,WORD latch,WORD axis,WORD ltc_source);
SMC_API short __stdcall smc_ltc_get_source(WORD ConnectNo,WORD latch,WORD axis,WORD *ltc_source);
//��λ������
SMC_API short __stdcall smc_ltc_reset(WORD ConnectNo,WORD latch);
//��ȡ�������
SMC_API short __stdcall smc_ltc_get_number(WORD ConnectNo,WORD latch,WORD axis,int *number);
//��ȡ����ֵ
SMC_API short __stdcall smc_ltc_get_value_unit(WORD ConnectNo,WORD latch,WORD axis,double *value);
/*********************************************************************************************************
������� 20170626
*********************************************************************************************************/
//����������������ģʽ0-�������棬1-�������棻�������0-�½��أ�1-�����أ�2-˫���أ��˲�ʱ�䣬��λus
SMC_API short __stdcall smc_softltc_set_mode(WORD ConnectNo,WORD latch,WORD ltc_enable,WORD ltc_mode,WORD ltc_inbit,WORD ltc_logic,double filter);
SMC_API short __stdcall smc_softltc_get_mode(WORD ConnectNo,WORD latch,WORD *ltc_enable,WORD *ltc_mode,WORD *ltc_inbit,WORD *ltc_logic,double *filter);
//��������Դ��0-ָ��λ�ã�1-����������λ��
SMC_API short __stdcall smc_softltc_set_source(WORD ConnectNo,WORD latch,WORD axis,WORD ltc_source);
SMC_API short __stdcall smc_softltc_get_source(WORD ConnectNo,WORD latch,WORD axis,WORD *ltc_source);
//��λ������
SMC_API short __stdcall smc_softltc_reset(WORD ConnectNo,WORD latch);
//��ȡ�������
SMC_API short __stdcall smc_softltc_get_number(WORD ConnectNo,WORD latch,WORD axis,int *number);
//��ȡ����ֵ
SMC_API short __stdcall smc_softltc_get_value_unit(WORD ConnectNo,WORD latch,WORD axis,double *value);
/*********************************************************************************************************
ģ��������
*********************************************************************************************************/
SMC_API short __stdcall smc_set_ain_action(WORD ConnectNo,WORD channel,WORD mode,double fvoltage,WORD action,double actpara);
SMC_API short __stdcall smc_get_ain_action(WORD ConnectNo,WORD channel,WORD* mode,double* fvoltage,WORD* action,double* actpara);
SMC_API short __stdcall smc_get_ain_state(WORD ConnectNo,WORD channel);
SMC_API short __stdcall smc_set_ain_state(WORD ConnectNo,WORD channel);
SMC_API double __stdcall smc_get_ain(WORD ConnectNo,WORD channel);
SMC_API short __stdcall smc_set_da_output(WORD ConnectNo, WORD channel,double Vout);
SMC_API short __stdcall smc_get_da_output(WORD ConnectNo,WORD channel,double* Vout);
/*********************************************************************************************************
�ļ�����
*********************************************************************************************************/
SMC_API short __stdcall smc_download_file(WORD ConnectNo, const char* pfilename, const char* pfilenameinControl,WORD filetype);
SMC_API short __stdcall smc_download_memfile(WORD ConnectNo, const char* pbuffer, uint32 buffsize, const char* pfilenameinControl,WORD filetype);
SMC_API short __stdcall smc_upload_file(WORD ConnectNo, const char* pfilename, const char* pfilenameinControl, WORD filetype);
SMC_API short __stdcall smc_upload_memfile(WORD ConnectNo, char* pbuffer, uint32 buffsize, const char* pfilenameinControl, uint32* puifilesize,WORD filetype);
SMC_API short __stdcall smc_download_file_to_ram(WORD ConnectNo, const char* pfilename,WORD filetype);
SMC_API short __stdcall smc_download_memfile_to_ram(WORD ConnectNo, const char* pbuffer, uint32 buffsize,WORD filetype);
SMC_API short __stdcall smc_get_progress(WORD ConnectNo,float* process);
/********************************************************************************************************
U���ļ�����
*********************************************************************************************************/
SMC_API short __stdcall smc_udisk_get_state(WORD ConnectNo,WORD *state);
SMC_API short __stdcall smc_udisk_check_file(WORD ConnectNo,char* filename,int* filesize,WORD filetype);
SMC_API short __stdcall smc_udisk_get_first_file(WORD ConnectNo,char* filename,int* filesize,int* fileid,WORD filetype);
SMC_API short __stdcall smc_udisk_get_next_file(WORD ConnectNo,char* filename,int* filesize,int* fileid,WORD filetype);
SMC_API short __stdcall smc_udisk_copy_file(WORD ConnectNo,const char* SrcFileName,const char* DstFileName,WORD filetype,WORD mode);
/*********************************************************************************************************
�Ĵ�������
*********************************************************************************************************/
//Modbus�Ĵ���
SMC_API short __stdcall smc_set_modbus_0x(WORD ConnectNo, WORD start, WORD inum, char* pdata);
SMC_API short __stdcall smc_get_modbus_0x(WORD ConnectNo, WORD start, WORD inum, char* pdata);
SMC_API short __stdcall smc_set_modbus_4x(WORD ConnectNo, WORD start, WORD inum, WORD* pdata);
SMC_API short __stdcall smc_get_modbus_4x(WORD ConnectNo, WORD start, WORD inum, WORD* pdata);
//���籣�ּĴ���
SMC_API short __stdcall smc_set_persistent_reg(WORD ConnectNo, DWORD start, DWORD inum, const char* pdata);
SMC_API short __stdcall smc_get_persistent_reg(WORD ConnectNo, DWORD start, DWORD inum, char* pdata);
//���·���������
SMC_API short __stdcall smc_set_persistent_reg_byte(WORD ConnectNo, DWORD start, DWORD inum, const char* pdata);
SMC_API short __stdcall smc_get_persistent_reg_byte(WORD ConnectNo, DWORD start, DWORD inum, char* pdata);
SMC_API short __stdcall smc_set_persistent_reg_float(WORD ConnectNo, DWORD start, DWORD inum, const float* pdata);
SMC_API short __stdcall smc_get_persistent_reg_float(WORD ConnectNo, DWORD start, DWORD inum, float* pdata);
SMC_API short __stdcall smc_set_persistent_reg_int(WORD ConnectNo, DWORD start, DWORD inum, const int* pdata);
SMC_API short __stdcall smc_get_persistent_reg_int(WORD ConnectNo, DWORD start, DWORD inum, int* pdata);
SMC_API short __stdcall smc_set_persistent_reg_short(WORD ConnectNo, DWORD start, DWORD inum, const short* pdata);
SMC_API short __stdcall smc_get_persistent_reg_short(WORD ConnectNo, DWORD start, DWORD inum, short* pdata);
/*********************************************************************************************************
Basic�������
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
G����������
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
״̬���
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
���ݲɼ�
***************************************************************************************************************************/
SMC_API short __stdcall smc_trace_set_source(WORD ConnectNo,WORD source);
//��������ʵʱ�ɼ�����
SMC_API short __stdcall smc_read_trace_data(WORD ConnectNo,WORD axis,long bufsize,double *time,double *pos,double *vel,double *acc,long *recv_num);
//�������ݲɼ������ļ�
SMC_API short __stdcall smc_trace_start(WORD ConnectNo,WORD AxisNum,WORD *AxisList);
SMC_API short __stdcall smc_trace_stop(WORD ConnectNo);
//filetype==100�ɼ��ļ�
//SMC_API short __stdcall smc_upload_file(WORD ConnectNo, const char* pfilename, const char* pfilenameinControl, WORD filetype);
//SMC_API short __stdcall smc_upload_memfile(WORD ConnectNo, char* pbuffer, uint32 buffsize, const char* pfilenameinControl, uint32* puifilesize,WORD filetype);

/*********************************************************************************************************
����ר�ú���
PortNo���߶˿ں�
0-CANopen0
1-CANopen1
2-EtherCAT0
3-EtherCAT1
*********************************************************************************************************/
/*************************************** CANopen **************************************/
//��λCANopen��վ
SMC_API short __stdcall nmcs_reset_canopen(WORD ConnectNo);
//��λRTEX��վ
SMC_API short __stdcall nmcs_reset_rtex(WORD ConnectNo);
//��λEtherCAT��վ
SMC_API short __stdcall nmcs_reset_etc(WORD ConnectNo);
SMC_API short __stdcall nmcs_axis_io_status(WORD ConnectNo,WORD axis);	//��ȡָ�����й��˶��źŵ�״̬
//��ȡ�������Ķ�ʧ��Ϣ
SMC_API short __stdcall nmcs_get_LostHeartbeat_Nodes(WORD ConnectNo,WORD PortNo,WORD* NodeID,WORD* NodeNum);
//��ȡ����������Ϣ
SMC_API short __stdcall nmcs_get_EmergeneyMessege_Nodes(WORD ConnectNo,WORD PortNo,DWORD* NodeMsg,WORD* MsgNum);
SMC_API short __stdcall nmcs_SendNmtCommand(WORD ConnectNo,WORD PortNo,WORD NodeID,WORD NmtCommand);
//��������ź�
SMC_API short __stdcall nmcs_set_alarm_clear(WORD ConnectNo,WORD PortNo,WORD NodeNo);
//ͬ���˶�
SMC_API short __stdcall nmcs_syn_move_unit(WORD ConnectNo,WORD AxisNum,WORD* AxisList,double* Position,WORD* PosiMode);

/*************************************** EtherCAT **************************************/
//ֹͣEtherCATЭ��ջ
SMC_API short __stdcall nmcs_stop_etc(WORD ConnectNo,WORD* ETCState);
//��ȡEtherCAT��״̬
SMC_API short __stdcall nmcs_get_axis_state_machine(WORD ConnectNo,WORD axis, WORD* Axis_StateMachine);

//����ʹ�ܺ���
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
*����˵����RTEX������дEEPROM����
*
*
**************************************************************/
SMC_API short __stdcall nmcs_write_slave_eeprom(WORD ConnectNo,WORD axis);
/**************************************************************
*index:rtex�������Ĳ�������
*subindex:rtex��������index����µĲ������
*para_data:�����Ĳ���ֵ
**************************************************************/
SMC_API short __stdcall nmcs_read_parameter(WORD ConnectNo,WORD axis,WORD index, WORD subindex,DWORD* para_data);
/**************************************************************
*index:rtex�������Ĳ�������
*subindex:rtex��������index����µĲ������
*para_data:�����Ĳ���ֵ
**************************************************************/
SMC_API short __stdcall nmcs_read_parameter_attributes(WORD ConnectNo,WORD axis,WORD index, WORD subindex,DWORD* para_data);
//����RTEX�������ڱ�(us)
SMC_API short __stdcall nmcs_set_cmdcycletime(WORD ConnectNo,WORD PortNum,DWORD cmdtime);
SMC_API short __stdcall nmcs_get_cmdcycletime(WORD ConnectNo,WORD PortNum,DWORD* cmdtime);
SMC_API short __stdcall nmcs_start_log(WORD ConnectNo,WORD chan,WORD node, WORD Ifenable);
SMC_API short __stdcall nmcs_get_log(WORD ConnectNo,WORD chan,WORD node, DWORD* data);
SMC_API short __stdcall nmcs_config_atuo_log(WORD ConnectNo,WORD ifenable,WORD dir,WORD byte_index,WORD mask,WORD condition,DWORD counter);
SMC_API short __stdcall nmcs_get_log_state(WORD ConnectNo,WORD chan, DWORD* state);
SMC_API short __stdcall nmcs_driver_reset(WORD ConnectNo,WORD axis);

/*************************************** EtherCAT & CANopen**************************************/
SMC_API short __stdcall nmcs_get_axis_type(WORD ConnectNo,WORD axis, WORD* Axis_Type);

//��վ�����ֵ�
SMC_API short __stdcall nmcs_set_node_od(WORD ConnectNo,WORD PortNo,WORD NodeNo, WORD Index,WORD SubIndex,WORD ValLength,DWORD Value);
SMC_API short __stdcall nmcs_get_node_od(WORD ConnectNo,WORD PortNo,WORD NodeNo, WORD Index,WORD SubIndex,WORD ValLength,DWORD* Value);

//���ߴ���
SMC_API short __stdcall nmcs_get_card_errcode(WORD ConnectNo,DWORD *Errcode);
SMC_API short __stdcall nmcs_clear_card_errcode(WORD ConnectNo);

SMC_API short __stdcall nmcs_get_errcode(WORD ConnectNo,WORD PortNo,DWORD *Errcode);
SMC_API short __stdcall nmcs_clear_errcode(WORD ConnectNo,WORD PortNo);

SMC_API short __stdcall nmcs_get_axis_errcode(WORD ConnectNo,WORD axis,DWORD *Errcode);
SMC_API short __stdcall nmcs_clear_axis_errcode(WORD ConnectNo,WORD iaxis);

//��ȡ������IO����ģ������
SMC_API short __stdcall nmcs_get_total_axes(WORD ConnectNo,DWORD *TotalAxis);
SMC_API short __stdcall nmcs_get_total_ionum(WORD ConnectNo,WORD *TotalIn,WORD *TotalOut);
SMC_API short __stdcall nmcs_get_total_adcnum(WORD ConnectNo,WORD *TotalIn,WORD *TotalOut);

//���ڵ������չIO
SMC_API short __stdcall nmcs_read_inbit_extern(WORD ConnectNo,WORD PortNo,WORD NodeID,WORD BitNo,WORD *IoValue);
SMC_API short __stdcall nmcs_read_inport_extern(WORD ConnectNo,WORD PortNo,WORD NodeID,WORD IoPortNo,DWORD *IoValue);
SMC_API short __stdcall nmcs_write_outbit_extern(WORD ConnectNo,WORD PortNo,WORD NodeID,WORD BitNo,WORD IoValue);
SMC_API short __stdcall nmcs_write_outport_extern(WORD ConnectNo,WORD PortNo,WORD NodeID,WORD IoPortNo,DWORD IoValue);
SMC_API short __stdcall nmcs_read_outbit_extern(WORD ConnectNo,WORD PortNo,WORD NodeID,WORD BitNo,WORD *IoValue);
SMC_API short __stdcall nmcs_read_outport_extern(WORD ConnectNo,WORD PortNo,WORD NodeID,WORD IoPortNo,DWORD *IoValue);

//ת�ؿ��ƹ��ܺ���
SMC_API short __stdcall nmcs_torque_move(WORD CardNo,WORD axis,int Torque,WORD PosLimitValid,double PosLimitValue,WORD PosMode);
SMC_API short __stdcall nmcs_change_torque(WORD CardNo,WORD axis,int Torque);
SMC_API short __stdcall nmcs_get_torque(WORD CardNo,WORD axis,int* Torque);

#ifdef __cplusplus
}
#endif

#endif