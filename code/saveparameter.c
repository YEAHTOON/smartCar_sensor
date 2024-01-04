#include "saveparameter.h"

//��������ֵ
void save_ServoMid(uint32 servomid_to_save)
{
    if(flash_check(63, 3))                      // �ж��Ƿ�������
    {
        flash_read_page_to_buffer(63, 3);       //����д�뻺����

        flash_erase_page(63, 3);                // ������һҳ
    }

    flash_union_buffer[0].uint32_type = servomid_to_save;   //����д�뻺����

    flash_write_page_from_buffer(63, 3);        // ��ָ�� Flash ������ҳ��д�뻺��������
}

//�õ��洢�����ֵ
uint32 get_ServoMid(void)
{
    flash_read_page_to_buffer(63, 3);       //����д�뻺����
    return flash_union_buffer[0].uint32_type;
}

void save_Points(points input_points)
{
    flash_buffer_clear();   //ÿ��ʹ�û����������

    if(flash_check(63, 3))                      // �ж��Ƿ�������
    {
        flash_erase_page(63, 3);                // ������һҳ
    }

    flash_union_buffer[0].float_type = (float)input_points.position[0][0];
    flash_union_buffer[1].float_type = (float)input_points.position[0][1];
    flash_union_buffer[2].float_type = (float)input_points.position[1][0];
    flash_union_buffer[3].float_type = (float)input_points.position[1][1];
    flash_union_buffer[4].float_type = (float)input_points.position[2][0];
    flash_union_buffer[5].float_type = (float)input_points.position[2][1];
    flash_union_buffer[6].float_type = (float)input_points.position[3][0];

    flash_write_page_from_buffer(63, 3);


    flash_buffer_clear();   //ÿ��ʹ�û����������

    if(flash_check(63, 2))                      // �ж��Ƿ�������
    {
        flash_erase_page(63, 2);                // ������һҳ
    }

    flash_union_buffer[0].float_type = (float)input_points.position[3][1];
    flash_union_buffer[1].float_type = (float)input_points.position[4][0];
    flash_union_buffer[2].float_type = (float)input_points.position[4][1];
    flash_union_buffer[3].float_type = (float)input_points.position[5][0];
    flash_union_buffer[4].float_type = (float)input_points.position[5][1];
    flash_union_buffer[5].float_type = (float)input_points.position[6][0];
    flash_union_buffer[6].float_type = (float)input_points.position[6][1];

    flash_write_page_from_buffer(63, 2);


    flash_buffer_clear();   //ÿ��ʹ�û����������

    if(flash_check(63, 1))                      // �ж��Ƿ�������
    {
        flash_erase_page(63, 1);                // ������һҳ
    }

    flash_union_buffer[0].float_type = (float)input_points.position[7][0];
    flash_union_buffer[1].float_type = (float)input_points.position[7][1];
    flash_union_buffer[2].float_type = (float)input_points.position[8][0];
    flash_union_buffer[3].float_type = (float)input_points.position[8][1];
    flash_union_buffer[4].float_type = (float)input_points.position[9][0];
    flash_union_buffer[5].float_type = (float)input_points.position[9][1];
    flash_union_buffer[6].float_type = (float)input_points.position[10][0];

    flash_write_page_from_buffer(63, 1);


    flash_buffer_clear();   //ÿ��ʹ�û����������

    if(flash_check(63, 0))                      // �ж��Ƿ�������
    {
        flash_erase_page(63, 0);                // ������һҳ
    }

    flash_union_buffer[0].float_type = (float)input_points.position[10][1];
    flash_union_buffer[1].float_type = (float)input_points.position[11][0];
    flash_union_buffer[2].float_type = (float)input_points.position[11][1];
    flash_union_buffer[3].float_type = (float)input_points.position[12][0];
    flash_union_buffer[4].float_type = (float)input_points.position[12][1];
    flash_union_buffer[5].float_type = (float)input_points.position[13][0];
    flash_union_buffer[6].float_type = (float)input_points.position[13][1];

    flash_write_page_from_buffer(63, 0);


    flash_buffer_clear();   //ÿ��ʹ�û����������

    if(flash_check(62, 3))                      // �ж��Ƿ�������
    {
        flash_erase_page(62, 3);                // ������һҳ
    }

    flash_union_buffer[0].float_type = (float)input_points.position[14][0];
    flash_union_buffer[1].float_type = (float)input_points.position[14][1];
    flash_union_buffer[2].float_type = (float)input_points.position[15][0];
    flash_union_buffer[3].float_type = (float)input_points.position[15][1];
    flash_union_buffer[4].float_type = (float)input_points.position[16][0];
    flash_union_buffer[5].float_type = (float)input_points.position[16][1];
    flash_union_buffer[6].float_type = (float)input_points.position[17][0];

    flash_write_page_from_buffer(62, 3);
}

points get_Points(void)
{
    points output_points;

    flash_buffer_clear();
    flash_read_page_to_buffer(63,3);

    output_points.position[0][0] = (double)flash_union_buffer[0].float_type;
    output_points.position[0][1] = (double)flash_union_buffer[1].float_type;
    output_points.position[1][0] = (double)flash_union_buffer[2].float_type;
    output_points.position[1][1] = (double)flash_union_buffer[3].float_type;
    output_points.position[2][0] = (double)flash_union_buffer[4].float_type;
    output_points.position[2][1] = (double)flash_union_buffer[5].float_type;
    output_points.position[3][0] = (double)flash_union_buffer[6].float_type;

    flash_buffer_clear();
    flash_read_page_to_buffer(63,2);

    output_points.position[3][1] = (double)flash_union_buffer[0].float_type;
    output_points.position[4][0] = (double)flash_union_buffer[1].float_type;
    output_points.position[4][1] = (double)flash_union_buffer[2].float_type;
    output_points.position[5][0] = (double)flash_union_buffer[3].float_type;
    output_points.position[5][1] = (double)flash_union_buffer[4].float_type;
    output_points.position[6][0] = (double)flash_union_buffer[5].float_type;
    output_points.position[6][1] = (double)flash_union_buffer[6].float_type;

    flash_buffer_clear();
    flash_read_page_to_buffer(63,1);

    output_points.position[7][0] = (double)flash_union_buffer[0].float_type;
    output_points.position[7][1] = (double)flash_union_buffer[1].float_type;
    output_points.position[8][0] = (double)flash_union_buffer[2].float_type;
    output_points.position[8][1] = (double)flash_union_buffer[3].float_type;
    output_points.position[9][0] = (double)flash_union_buffer[4].float_type;
    output_points.position[9][1] = (double)flash_union_buffer[5].float_type;
    output_points.position[10][0] = (double)flash_union_buffer[6].float_type;

    flash_buffer_clear();
    flash_read_page_to_buffer(63,0);

    output_points.position[10][1] = (double)flash_union_buffer[0].float_type;
    output_points.position[11][0] = (double)flash_union_buffer[1].float_type;
    output_points.position[11][1] = (double)flash_union_buffer[2].float_type;
    output_points.position[12][0] = (double)flash_union_buffer[3].float_type;
    output_points.position[12][1] = (double)flash_union_buffer[4].float_type;
    output_points.position[13][0] = (double)flash_union_buffer[5].float_type;
    output_points.position[13][1] = (double)flash_union_buffer[6].float_type;

    flash_buffer_clear();
    flash_read_page_to_buffer(62,3);

    output_points.position[14][0] = (double)flash_union_buffer[0].float_type;
    output_points.position[14][1] = (double)flash_union_buffer[1].float_type;
    output_points.position[15][0] = (double)flash_union_buffer[2].float_type;
    output_points.position[15][1] = (double)flash_union_buffer[3].float_type;
    output_points.position[16][0] = (double)flash_union_buffer[4].float_type;
    output_points.position[16][1] = (double)flash_union_buffer[5].float_type;
    output_points.position[17][0] = (double)flash_union_buffer[6].float_type;


    return output_points;
}
