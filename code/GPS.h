#ifndef _h_GPS_
#define _h_GPS_

#include <zf_device_gps_tau1201.h>
#include <struct_enum.h>
#include <math.h>

void GPS_update(void);
float GPS_calculate_error_angle(float now_angle,float target_angle);
delt_points GPS_deal_point(point GPS_point,point advised_point);
delt_points get_H_point(delt_points A_point,delt_points B_point,delt_points N_point);
delt_points get_C_point(delt_points H_point,delt_points A_point);
float calculate_angle(delt_points C, delt_points N);
void set_servo_duty(delt_points A, delt_points B, delt_points N,float set_servo_duty_yaw);

#endif
