#include <INS.h>

/*
 * 社会叶
 */
int integral_INS_time = 0;
dimension3 gyro_drift_value = {0.0f,0.0f,0.0f},acc_init_value = {0.0f,0.0f,0.0f},absolute_mag,absolute_acc,INS_speed = {0.0f,0.0f,0.0f},INS_distance = {0.0f,0.0f,0.0f};
Euler yaw,pitch,roll;
float PIT_TIME = 0.005f,gps_yaw,last_gps_yaw,yaw_drift = 0.0f;
float kx = 1.0f,ky = 1.0f,kz = 1.0f,bx = 0.0f,by = 0.0f,bz = 0.0f,g = 9.794f;

struct processed_data
{
    dimension3 a;
    dimension3 g;
    dimension3 m;
} PD;

dimension3 INS_revolve(dimension3 p, float theta_x, float theta_y, float theta_z)  //旋转变换后得到的绝对坐标系下的值
{
    double cos_x = (double)cosf(theta_x);
    double sin_x = (double)sinf(theta_x);
    double cos_y = (double)cosf(theta_y);
    double sin_y = (double)sinf(theta_y);
    double cos_z = (double)cosf(theta_z);
    double sin_z = (double)sinf(theta_z);

    // 绕X轴反向旋转
    double x1 = p.x;
    double y1 = p.y * cos_x + p.z * sin_x;
    double z1 = -p.y * sin_x + p.z * cos_x;

    // 绕Y轴反向旋转
    double x2 = x1 * cos_y - z1 * sin_y;
    double y2 = y1;
    double z2 = x1 * sin_y + z1 * cos_y;

    // 绕Z轴反向旋转
    double x3 = x2 * cos_z + y2 * sin_z;
    double y3 = -x2 * sin_z + y2 * cos_z;
    double z3 = z2;

    dimension3 result = { (float)x3, (float)y3, (float)z3 };
    return result;
}

int get_basic_data(void)    //获得基本信息，包括加速度、角速度与初始姿态角
{
    imu963ra_get_acc();    //获取加速度原始数据
    imu963ra_get_gyro();    //获取角速度原始数据
    imu963ra_get_mag();

    PD.a.x = (float)imu963ra_acc_y / 410.0f * ky + by;
    PD.a.y = (float)imu963ra_acc_x / 410.0f * kx + bx;
    PD.a.z = (float)imu963ra_acc_z / 410.0f * kz + bz;

    PD.m.x = (float)imu963ra_mag_y;
    PD.m.y = (float)imu963ra_mag_x;
    PD.m.z = (float)imu963ra_mag_z;

    if(integral_INS_time < 100)         //积分，角速度去零偏，加速度确定初始姿态角
    {
        gyro_drift_value.x += (float)imu963ra_gyro_x;   //进行x轴角速度零漂积分
        gyro_drift_value.y += (float)imu963ra_gyro_y;   //进行y轴角速度零漂积分
        gyro_drift_value.z += (float)imu963ra_gyro_z;   //进行z轴角速度零漂积分

        acc_init_value.x += PD.a.x;
        acc_init_value.y += PD.a.y;
        acc_init_value.z += PD.a.z;

        integral_INS_time++;

        return 0;
    }
    else if(integral_INS_time == 100)
    {
        gyro_drift_value.x /= 100.0f;
        gyro_drift_value.y /= 100.0f;
        gyro_drift_value.z /= 100.0f;

        acc_init_value.x /= 100.0f;
        acc_init_value.y /= 100.0f;
        acc_init_value.z /= 100.0f;

        integral_INS_time++;

        return 0;
    }
    else
    {
        imu963ra_gyro_x = imu963ra_gyro_x - (int16)gyro_drift_value.x;   //解决零偏
        imu963ra_gyro_y = imu963ra_gyro_y - (int16)gyro_drift_value.y;
        imu963ra_gyro_z = imu963ra_gyro_z - (int16)gyro_drift_value.z;

        if(integral_INS_time == 101)     //姿态粗对准
        {
            yaw.real = 0.0f;

            if(acc_init_value.y * acc_init_value.y + acc_init_value.z * acc_init_value.z != 0.0f)
            {
                pitch.real = -atanf(acc_init_value.x / sqrtf(acc_init_value.y * acc_init_value.y + acc_init_value.z * acc_init_value.z));
            }

            if(acc_init_value.z != 0.0f)
            {
                roll.real = -atanf(acc_init_value.y / acc_init_value.z);
            }

            integral_INS_time++;
        }
    }

    PD.g.x = (float)imu963ra_gyro_y / 14.3f * 3.14150f / 18000.0f;
    PD.g.y = (float)imu963ra_gyro_x / 14.3f * 3.14150f / 18000.0f;
    PD.g.z = (float)imu963ra_gyro_z / 14.3f * 3.14150f / 18000.0f;

    return 1;
}

float collected_acc[6][3] = {{0.0f}};
int acc_collect_stop_count[6] = {0},if_key_press_collet_acc = 0,acc_count;
void change_if_key_press_acc_data(void)        //按键调用这个函数改变判定变量，采集一次原始加速度数值
{
    if_key_press_collet_acc = 1;
}
void INS_collect_acc_data(void)
{
    if(if_key_press_collet_acc == 1)
    {
        acc_collect_stop_count[acc_count]++;

        collected_acc[acc_count][0] += (float)imu963ra_acc_x / 410.0f;
        collected_acc[acc_count][1] += (float)imu963ra_acc_y / 410.0f;
        collected_acc[acc_count][2] += (float)imu963ra_acc_z / 410.0f;

        if(acc_collect_stop_count[acc_count] == 100)
        {
            if_key_press_collet_acc = 0;

            collected_acc[acc_count][0] /= 100.0f;
            collected_acc[acc_count][1] /= 100.0f;
            collected_acc[acc_count][2] /= 100.0f;

            acc_count++;
        }
    }
}

int if_calculate_acc_para = 0,if_INS_speed_start = 0;
float acc_para_k_b[6] = {0.0f},acc_para_p[6],show_data[6];
float kx2,ky2,kz2,bx2,by2,bz2,Q;
void calculate_acc_para(void)                //计算加速度标定相关参数，通过按键调用
{
    matrix H_m,H_m_T,H_multiply_H_T,HHT_inverse,HHT_inverse_HT;
    H_m = matrix_init(6, 6);

    for(int i = 0; i < 6; i++)
    {
        H_m.element[i][0] = collected_acc[i][0]*collected_acc[i][0];
        H_m.element[i][1] = collected_acc[i][0];
        H_m.element[i][2] = collected_acc[i][1]*collected_acc[i][1];
        H_m.element[i][3] = collected_acc[i][1];
        H_m.element[i][4] = collected_acc[i][2]*collected_acc[i][2];
        H_m.element[i][5] = collected_acc[i][2];
    }

    //矩阵运算
    H_m_T = matrix_transposition(H_m);
    H_multiply_H_T = matrix_multiply(H_m_T, H_m);
    HHT_inverse = Gaussian_elimination(H_multiply_H_T);
    HHT_inverse_HT = matrix_multiply(HHT_inverse, H_m_T);

    for(int i = 0; i < 6; i++)
    {
        acc_para_p[i] = 0.0f;
        for(int j = 0; j < 6; j++)
        {
            acc_para_p[i] += -HHT_inverse_HT.element[i][j];
        }
    }

    matrix_free(H_m);       //释放内存空间
    matrix_free(H_m_T);
    matrix_free(H_multiply_H_T);
    matrix_free(HHT_inverse);
    matrix_free(HHT_inverse_HT);

    //获得Q与误差系数
    Q = 4.0f * g * g / (acc_para_p[1]*acc_para_p[1]/acc_para_p[0] + acc_para_p[3]*acc_para_p[3]/acc_para_p[2] + acc_para_p[5]*acc_para_p[5]/acc_para_p[4] - 4.0f);
    kx2 = acc_para_p[0]*Q;
    ky2 = acc_para_p[2]*Q;
    kz2 = acc_para_p[4]*Q;
    bx2 = acc_para_p[1]*acc_para_p[1]/(4.0f*acc_para_p[0])*Q;
    by2 = acc_para_p[3]*acc_para_p[3]/(4.0f*acc_para_p[2])*Q;
    bz2 = acc_para_p[5]*acc_para_p[5]/(4.0f*acc_para_p[4])*Q;

    kx = sqrtf(kx2);
    ky = sqrtf(ky2);
    kz = sqrtf(kz2);
    bx = acc_para_p[1]*(bx2 + by2 + bz2 - g*g) / (2.0f * kx);
    by = acc_para_p[3]*(bx2 + by2 + bz2 - g*g) / (2.0f * ky);
    bz = acc_para_p[5]*(bx2 + by2 + bz2 - g*g) / (2.0f * kz);

    if_INS_speed_start = 1;
}

void INS_update(void)//更新姿态，放在中断中
{
    if(get_basic_data())
    {
        INS_collect_acc_data();    //用于标定加速度计


//欧拉角模块
        if(PD.a.y * PD.a.y + PD.a.z * PD.a.z != 0.0f)      //加速度欧拉角
        {
            pitch.acc = -atanf(PD.a.x / sqrtf(PD.a.y * PD.a.y + PD.a.z * PD.a.z));
        }
        if(PD.a.x != 0.0f)
        {
            roll.acc = -atanf(PD.a.y / PD.a.z);
        }

        yaw.speed = (PD.g.y * sinf(roll.real) + PD.g.z * cosf(roll.real)) / cosf(pitch.real);   //欧拉角微分方程
        pitch.speed = PD.g.y * cosf(roll.real) - PD.g.z * sinf(roll.real);
        roll.speed = (PD.g.y * sinf(roll.real) + PD.g.z * cosf(roll.real)) * tanf(pitch.real) + PD.g.x;

        yaw.gyro = yaw.real + yaw.speed * PIT_TIME;               //角速度欧拉角
        pitch.gyro = pitch.real + pitch.speed * PIT_TIME;
        roll.gyro = roll.real + roll.speed * PIT_TIME;

        gps_yaw = (float)ANGLE_TO_RAD((double)gps_tau1201.direction);    //获得gps偏航角
        if((gps_yaw != last_gps_yaw)&&(gps_tau1201.speed > 3.6f))  //速度判定
        {
            yaw.real = gps_yaw * 0.03f + yaw.gyro * 0.97f;
        }
        else //无效的gps偏航角数据
        {
            yaw.real = yaw.gyro;
        }
        last_gps_yaw = gps_yaw;
        if(powf(PD.a.x,2.0f) + powf(PD.a.y,2.0f) + powf(PD.a.z,2.0f) <= 120.0f)
        {
            pitch.real = 0.95f*pitch.gyro + 0.05f*pitch.acc;     //加速度计校正陀螺仪
            roll.real = 0.95f*roll.gyro + 0.05f*roll.acc;
        }
        else
        {
            pitch.real = pitch.gyro;
            roll.real = roll.gyro;
        }

        absolute_mag = INS_revolve(PD.m,roll.real,pitch.real,0.0f);      //获得绝对坐标系下的磁力计
        if((absolute_mag.x > 0.0f)&&(absolute_mag.y > 0.0f))
        {
            yaw.real = (float)PI + atanf(absolute_mag.y/absolute_mag.x) + yaw_drift;
        }
        else if((absolute_mag.x > 0.0f)&&(absolute_mag.y < 0.0f))
        {
            yaw.real = (float)PI  - atanf(-absolute_mag.y/absolute_mag.x) + yaw_drift;
        }
        else if((absolute_mag.x < 0.0f)&&(absolute_mag.y > 0.0f))
        {
            yaw.real = (float)PI * 2.0f - atanf(-absolute_mag.y/absolute_mag.x) + yaw_drift;
        }
        else if((absolute_mag.x < 0.0f)&&(absolute_mag.y < 0.0f))
        {
            yaw.real = atanf(absolute_mag.y/absolute_mag.x) + yaw_drift;
        }

        if(yaw.real > 2.0f*(float)PI)
        {
            yaw.real -= 2.0f*(float)PI;
        }
        else if(yaw.real < 0.0f)
        {
            yaw.real += 2.0f*(float)PI;
        }


//速度与位移模块
        absolute_acc = INS_revolve(PD.a,roll.real,pitch.real,yaw.real);   //加速度转换
        if(if_INS_speed_start == 1)
        {
            INS_speed.x += absolute_acc.x * PIT_TIME;
            INS_speed.y += absolute_acc.y * PIT_TIME;
            INS_speed.z += (absolute_acc.z + g) * PIT_TIME;

            INS_distance.x += INS_speed.x * PIT_TIME;
            INS_distance.y += INS_speed.y * PIT_TIME;
            INS_distance.z += INS_speed.z * PIT_TIME;
        }

        oled_show_float(0,1,absolute_acc.x,1,5);
        oled_show_float(40,1,absolute_acc.y,1,5);
        oled_show_float(80,1,absolute_acc.z,1,5);
        oled_show_float(0,2,INS_speed.x,5,1);
        oled_show_float(40,2,INS_speed.y,5,1);
        oled_show_float(80,2,INS_speed.z,5,1);
        oled_show_float(0,3,INS_distance.x,5,1);
        oled_show_float(40,3,INS_distance.y,5,1);
        oled_show_float(80,3,INS_distance.z,5,1);
    }
}


/*
 * 返回函数
 */
Euler INS_return_yaw(void)
{
    return yaw;
}

dimension3 INS_return_absolute_mag(void)
{
    return absolute_mag;
}

dimension3 INS_return_absolute_acc(void)
{
    return absolute_acc;
}

Euler INS_return_roll(void)
{
    return roll;
}
