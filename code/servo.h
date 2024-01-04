#ifndef _servo_h_
#define _servo_h_

#include <zf_common_typedef.h>
#include <zf_device_gps_tau1201.h>
#include <GPS.h>
#include <struct_enum.h>
#include <zf_device_oled.h>

//SÕ‰œµ¡–
float servo_return_S_error_angle(void);
void servo_change_S_1(float yaw_target_1,float now_yaw);
void servo_change_S_2(float yaw_target_2,float now_yaw);
void servo_change_S_3(float yaw_target_3,float now_yaw);
void servo_change_S_4(float yaw_target_4,float now_yaw);
void servo_change_S(float yaw_target_1,float yaw_target_2,float yaw_target_3,float yaw_target_4,float now_yaw,point start_point,point end_point);
uint32 servo_return_duty_set(void);
int servo_return_S_situation(void);
void servo_change_straight_line(float now_yaw,point first_point,point last_point,point self_point);
float return_passcount_angle(void);

#endif
