#include <collectpoint.h>

//test
collected_points S_points;

void S_collect_start_point(void)
{
    S_points.position[0][0] = gps_tau1201.longitude;
    S_points.position[0][1] = gps_tau1201.latitude;
}

void S_collect_end_point(void)
{
    S_points.position[1][0] = gps_tau1201.longitude;
    S_points.position[1][1] = gps_tau1201.latitude;
}

collected_points return_S_points(void)
{
    return S_points;
}

//总采点
collected_points all_points;
void collect_point(int communication_status)      //在按键中调用
{
    //两个特殊元素
    if(communication_status == COLLECT_POINT_s)
    {
        all_points.position[2][0] = gps_tau1201.longitude;
        all_points.position[2][1] = gps_tau1201.latitude;
        all_points.point_type[2] = 1;
    }
    else if(communication_status == COLLECT_POINT_circle)
    {
        all_points.position[5][0] = gps_tau1201.longitude;
        all_points.position[5][1] = gps_tau1201.latitude;
        all_points.point_type[5] = 2;
    }
    //第一段直线
    else if(communication_status == LINE1_collect_first_point)
    {
        all_points.position[0][0] = gps_tau1201.longitude;
        all_points.position[0][1] = gps_tau1201.latitude;
        all_points.point_type[0] = 0;
    }
    else if(communication_status == LINE1_collect_end_point)
    {
        all_points.position[1][0] = gps_tau1201.longitude;
        all_points.position[1][1] = gps_tau1201.latitude;
        all_points.point_type[1] = 0;
    }
    //第二段直线
    /*
    else if(communication_status == LINE2_collect_first_point)
    {

        all_points.position[3][0] = gps_tau1201.longitude;
        all_points.position[3][1] = gps_tau1201.latitude;
        all_points.point_type[3] = 0;

    }
    else if(communication_status == LINE2_collect_end_point)
    {
        all_points.position[4][0] = gps_tau1201.longitude;
        all_points.position[4][1] = gps_tau1201.latitude;
        all_points.point_type[4] = 0;
    }
    */
    else if(communication_status == LINE2_collect_first_point)
    {

        all_points.position[2][0] = gps_tau1201.longitude;
        all_points.position[2][1] = gps_tau1201.latitude;
        all_points.point_type[2] = 0;

    }
    else if(communication_status == LINE2_collect_end_point)
    {
        all_points.position[3][0] = gps_tau1201.longitude;
        all_points.position[3][1] = gps_tau1201.latitude;
        all_points.point_type[3] = 0;
    }
    //第三段直线
    else if(communication_status == LINE3_collect_first_point)
    {
        all_points.position[4][0] = gps_tau1201.longitude;
        all_points.position[4][1] = gps_tau1201.latitude;
        all_points.point_type[4] = 0;
    }
    else if(communication_status == LINE3_collect_end_point)
    {
        all_points.position[5][0] = gps_tau1201.longitude;
        all_points.position[5][1] = gps_tau1201.latitude;
        all_points.point_type[5] = 0;
    }
    //第四段直线
    else if(communication_status == LINE4_collect_first_point)
    {
        all_points.position[6][0] = gps_tau1201.longitude;
        all_points.position[6][1] = gps_tau1201.latitude;
        all_points.point_type[6] = 0;
    }
    else if(communication_status == LINE4_collect_end_point)
    {
        all_points.position[7][0] = gps_tau1201.longitude;
        all_points.position[7][1] = gps_tau1201.latitude;
        all_points.point_type[7] = 0;
    }
}



collected_points return_all_points(void)
{
    return all_points;
}
