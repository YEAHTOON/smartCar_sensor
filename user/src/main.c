/*********************************************************************************************************************
* CH32V307VCT6 Opensourec Library ����CH32V307VCT6 ��Դ�⣩��һ�����ڹٷ� SDK �ӿڵĵ�������Դ��
* Copyright (c) 2022 SEEKFREE ��ɿƼ�
*
* ���ļ���CH32V307VCT6 ��Դ���һ����
*
* CH32V307VCT6 ��Դ�� ���������
* �����Ը���������������ᷢ���� GPL��GNU General Public License���� GNUͨ�ù�������֤��������
* �� GPL �ĵ�3�棨�� GPL3.0������ѡ��ģ��κκ����İ汾�����·�����/���޸���
*
* ����Դ��ķ�����ϣ�����ܷ������ã�����δ�������κεı�֤
* ����û�������������Ի��ʺ��ض���;�ı�֤
* ����ϸ����μ� GPL
*
* ��Ӧ�����յ�����Դ���ͬʱ�յ�һ�� GPL �ĸ���
* ���û�У������<https://www.gnu.org/licenses/>
*
* ����ע����
* ����Դ��ʹ�� GPL3.0 ��Դ����֤Э�� ������������Ϊ���İ汾
* ��������Ӣ�İ��� libraries/doc �ļ����µ� GPL3_permission_statement.txt �ļ���
* ����֤������ libraries �ļ����� �����ļ����µ� LICENSE �ļ�
* ��ӭ��λʹ�ò����������� ���޸�����ʱ���뱣����ɿƼ��İ�Ȩ����������������
*
* �ļ�����          main
* ��˾����          �ɶ���ɿƼ����޹�˾
* �汾��Ϣ          �鿴 libraries/doc �ļ����� version �ļ� �汾˵��
* ��������          MounRiver Studio V1.8.1
* ����ƽ̨          CH32V307VCT6
* ��������          https://seekfree.taobao.com/
*
* �޸ļ�¼
* ����                                      ����                             ��ע
* 2022-09-15        ��W            first version
********************************************************************************************************************/
#include "zf_common_headfile.h"

int main (void)
{
    clock_init(SYSTEM_CLOCK_144M);                                              // ��ʼ��оƬʱ�� ����Ƶ��Ϊ 144MHz
    debug_init();                                                               // ��ʼ��Ĭ�� Debug UART

    // �˴���д�û����� ���������ʼ�������
    clock_init(SYSTEM_CLOCK_144M);                                              // ��ʼ��оƬʱ�� ����Ƶ��Ϊ 144MHz
    debug_init();                                                               // ��ʼ��Ĭ�� Debug UART

    // �˴���д�û����� ���������ʼ�������

    //GPS��ʼ����������ȼ�
    gps_init();
    interrupt_set_priority(UART8_IRQn,0<<5 | 1);

    //������ʼ��
    key_init(30);

    //oled
    oled_set_dir(OLED_CROSSWISE);
    oled_set_font(OLED_6X8_FONT);
    oled_init();

    //�����ǳ�ʼ��
    imu963ra_init();

    //���PWM���ų�ʼ��
    pwm_init(TIM2_PWM_MAP1_CH1_A15, 50, 0);

    //�жϳ�ʼ��
    pit_ms_init(TIM1_PIT,5);
    //pit_ms_init(TIM2_PIT,2);
    pit_ms_init(TIM3_PIT,100);

    // �˴���д�û����� ���������ʼ�������

    while(1)
    {
        // �˴���д��Ҫѭ��ִ�еĴ���
        GPS_update();
        showeverything();
        move();
        pwm_set_duty(TIM2_PWM_MAP1_CH1_A15,servo_return_duty_set());
        oled_show_float(0,6,INS_return_yaw().real,8,6); //��ʾƫ����


        // �˴���д��Ҫѭ��ִ�еĴ���
    }
}
