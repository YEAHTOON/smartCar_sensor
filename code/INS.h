#ifndef _INS_H_
#define _INS_H_

#include <zf_device_imu963ra.h>
#include <math.h>
#include <zf_device_ips200.h>
#include <zf_device_gps_tau1201.h>
#include <zf_device_oled.h>
#include <Matrix.h>

typedef struct
{
    float element[3][3];
} M33;

typedef struct
{
    float x,y,z;
} dimension3;

typedef struct
{
    float gyro,acc,speed,real;
} Euler;

typedef struct
{
    float x_real,y_real,x_gps,y_gps,x_acc,y_acc;
} vector_2;

int get_basic_data(void);
void INS_update(void);
void INS_show_attitude(void);
Euler INS_return_yaw(void);
dimension3 INS_return_absolute_mag(void);
dimension3 INS_revolve(dimension3 p, float theta_x, float theta_y, float theta_z);
Euler INS_return_roll(void);
dimension3 INS_return_absolute_acc(void);
void change_if_key_press_acc_data(void);
void INS_collect_acc_data(void);
void calculate_acc_para(void);

#endif
