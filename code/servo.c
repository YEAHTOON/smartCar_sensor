#include <servo.h>

uint32 servo_mid = (uint32)550,servo_change_max = (uint32)100,servo_duty_set;

//S��
int if_S_start = 1,S_situation = 1;
float advised_yaw,S_error_angle;
void servo_change_S_1(float yaw_target_1,float now_yaw)
{
    S_error_angle = GPS_calculate_error_angle(now_yaw,advised_yaw + yaw_target_1);  //��S���е�����
    if((S_error_angle > -0.1f*yaw_target_1)&&(S_error_angle < 0.1f*yaw_target_1))  //�����㹻С��������һ�׶�
    {
        S_situation++;
    }
}
void servo_change_S_2(float yaw_target_2,float now_yaw)
{
    S_error_angle = GPS_calculate_error_angle(now_yaw,advised_yaw + yaw_target_2);
    if((S_error_angle < -0.1f*yaw_target_2)&&(S_error_angle > 0.1f*yaw_target_2))
    {
        S_situation++;
    }
}
void servo_change_S_3(float yaw_target_3,float now_yaw)
{
    S_error_angle = GPS_calculate_error_angle(now_yaw,advised_yaw + yaw_target_3);
    if((S_error_angle > -0.1f*yaw_target_3)&&(S_error_angle < 0.1f*yaw_target_3))
    {
        S_situation++;
    }
}
void servo_change_S_4(float yaw_target_4,float now_yaw)
{
    S_error_angle = GPS_calculate_error_angle(now_yaw,advised_yaw + yaw_target_4);
    if((S_error_angle < -0.1f*yaw_target_4)&&(S_error_angle > 0.1f*yaw_target_4))
    {
        S_situation++;
    }
}
void servo_change_S(float yaw_target_1,float yaw_target_2,float yaw_target_3,float yaw_target_4,float now_yaw,point start_point,point end_point)
{
    if(if_S_start)  //��ʼ��S��
    {
        advised_yaw = (float)get_two_points_azimuth(start_point.latitude,start_point.longitude,end_point.latitude,end_point.longitude)/180.0f*(float)PI;
        if_S_start = 0;
    }
    else
    {
        if(S_situation == 1)
        {
            servo_change_S_1(yaw_target_1,now_yaw);  //��������
        }
        else if(S_situation == 2)
        {
            servo_change_S_2(yaw_target_2,now_yaw);
        }
        else if(S_situation == 3)
        {
            servo_change_S_3(yaw_target_3,now_yaw);
        }
        else if(S_situation == 4)
        {
            servo_change_S_4(yaw_target_4,now_yaw);
        }

        //�����������ö��ռ�ձ�
        if(S_error_angle > 0.0f)
        {
            servo_duty_set = servo_mid + (uint32)(servo_change_max / 2);
        }
        else if(S_error_angle < -0.0f)
        {
            servo_duty_set = servo_mid - (uint32)servo_change_max;
        }
    }
}

float straight_line_advised_yaw,target_yaw;
void servo_change_straight_line(float now_yaw,point first_point,point last_point,point self_point)
{
    straight_line_advised_yaw = (float)get_two_points_azimuth(first_point.latitude,first_point.longitude,last_point.latitude,last_point.longitude)/180.0f*(float)PI;
    target_yaw = (float)get_two_points_azimuth(self_point.latitude,self_point.longitude,last_point.latitude,last_point.longitude)/180.0f*(float)PI;

    float straight_line_error_angle = GPS_calculate_error_angle(now_yaw,target_yaw) + GPS_calculate_error_angle(straight_line_advised_yaw,target_yaw);
    oled_show_float(0,5,straight_line_error_angle,8,6);

    if((straight_line_error_angle > 0.0f)&&(straight_line_error_angle < 0.2f))
    {
        servo_duty_set = servo_mid + (uint32)(servo_change_max / 10);
    }
    else if((straight_line_error_angle > 0.2f)&&(straight_line_error_angle < 0.7f))
    {
        servo_duty_set = servo_mid + (uint32)(servo_change_max / 5);
    }
    else if(straight_line_error_angle > 0.7f)
    {
        servo_duty_set = servo_mid + (uint32)(servo_change_max / 2);
    }
    else if((straight_line_error_angle < 0.0f)&&(straight_line_error_angle > -0.1f))
    {
        servo_duty_set = servo_mid - (uint32)(servo_change_max / 10);
    }
    else if((straight_line_error_angle < -0.1f)&&(straight_line_error_angle > -0.7f))
    {
        servo_duty_set = servo_mid - (uint32)(servo_change_max / 5);
    }
    else if(straight_line_error_angle < -0.7f)
    {
        servo_duty_set = servo_mid - (uint32)(servo_change_max / 2);
    }
}

void set_servo_duty(delt_points A, delt_points B, delt_points N,float set_servo_duty_yaw)
{
    delt_points H = get_H_point(A, B, N);
    delt_points C = get_C_point(H, A);
    oled_show_float(0,2,C.x,3,1);
    oled_show_float(60,2,C.y,3,1);

    float C_angle = calculate_angle(C, N);
    oled_show_float(0,4,C_angle,8,6);

    float set_servo_duty_error_angle = GPS_calculate_error_angle(set_servo_duty_yaw, C_angle);
    oled_show_float(0,5,set_servo_duty_error_angle,8,6);

    if((set_servo_duty_error_angle > 0.0f)&&(set_servo_duty_error_angle < 0.2f))
    {
        servo_duty_set = servo_mid;
    }
    else if((set_servo_duty_error_angle > 0.2f)&&(set_servo_duty_error_angle < 0.5f))
    {
        servo_duty_set = servo_mid + (uint32)(servo_change_max / 5);
    }
    else if(set_servo_duty_error_angle > 0.7f)
    {
        servo_duty_set = servo_mid + (uint32)(servo_change_max);
    }
    else if((set_servo_duty_error_angle < 0.0f)&&(set_servo_duty_error_angle > -0.1f))
    {
        servo_duty_set = servo_mid;
    }
    else if((set_servo_duty_error_angle < -0.1f)&&(set_servo_duty_error_angle > -0.5f))
    {
        servo_duty_set = servo_mid - (uint32)(servo_change_max / 5);
    }
    else if(set_servo_duty_error_angle < -0.7f)
    {
        servo_duty_set = servo_mid - (uint32)(servo_change_max);
    }
}

//���غ���
float servo_return_S_error_angle(void)
{
    return S_error_angle;
}

uint32 servo_return_duty_set(void)
{
    return servo_duty_set;
}

int servo_return_S_situation(void)
{
    return S_situation;
}

float return_passcount_angle(void)
{
    return GPS_calculate_error_angle(straight_line_advised_yaw,target_yaw);
}
