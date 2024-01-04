#include <GPS.h>

//解析GPS原始数据
void GPS_update(void)
{
    if(gps_tau1201_flag)
    {
        gps_tau1201_flag = 0;

        if(!gps_data_parse())
        {
            //
        }
    }
}

//计算误差角
float GPS_calculate_error_angle(float now_angle,float target_angle)
{
    float error_angle = target_angle - now_angle;
    if(error_angle > (float)PI)
    {
        error_angle -= 2.0f * (float)PI;
    }
    else if(error_angle < (float)-PI)
    {
        error_angle += 2.0f * (float)PI;
    }
    return error_angle;
}

//点处理
delt_points GPS_deal_point(point GPS_point,point advised_point)
{
    delt_points result;

    result.y = (float)((GPS_point.latitude - advised_point.latitude)*100000.0f) * cosf(0.52f);
    result.x = (float)((GPS_point.longitude - advised_point.longitude)*100000.0f);

    return result;
}

//计算两点之间的角度
float calculate_angle(delt_points C, delt_points N)
{
    delt_points C_N;
    C_N.x = C.x - N.x;
    C_N.y = C.y - N.y;

    float result;

    if(C_N.x * C_N.y == 0.0f)
    {
        if(C_N.x > 0.0f)
        {
            result = (float)PI / 2.0f;
        }
        else if(C_N.x < 0.0f)
        {
            result = (float)PI * 3.0f / 2.0f;
        }
        else if(C_N.y > 0.0f)
        {
            result  = 0.0f;
        }
        else if(C_N.y < 0.0f)
        {
            result  = (float)PI;
        }
    }
    else if((C_N.x > 0.0f)&&(C_N.y > 0.0f)) //第一象限
    {
        result = (float)PI / 2.0f - atanf(C_N.y / C_N.x);
    }
    else if((C_N.x > 0.0f)&&(C_N.y < 0.0f)) //第四象限
    {
        result = atanf(-C_N.y / C_N.x) + (float)PI / 2.0f;
    }
    else if((C_N.x < 0.0f)&&(C_N.y > 0.0f)) //第二象限
    {
        result = atanf(C_N.y / -C_N.x) + (float)PI * 3.0f / 2.0f;
    }
    else if((C_N.x < 0.0f)&&(C_N.y < 0.0f)) //第三象限
    {
        result = (float)PI * 3.0f / 2.0f - atanf(C_N.y / C_N.x);
    }

    return result;
}

//控制
delt_points get_H_point(delt_points A_point,delt_points B_point,delt_points N_point)
{
    delt_points H_point;

    float a;//系数a

    if(A_point.x != B_point.x) a = (A_point.y - B_point.y) / (A_point.x - B_point.x);

    H_point.x = (a*N_point.y + N_point.x + a*a*A_point.x - a*A_point.y) / (a*a + 1.0f);
    H_point.y = A_point.y + a*H_point.x - a*A_point.x;

    return H_point;
}

delt_points get_C_point(delt_points H_point,delt_points A_point)
{
    delt_points C_point;

    C_point.x = 0.67f*H_point.x + 0.33f*A_point.x;
    C_point.y = 0.67f*H_point.y + 0.33f*A_point.y;

    return C_point;
}
