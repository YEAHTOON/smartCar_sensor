#include "communication.h"

int status = 1;

//显示状态
void showeverything(void)
{
    switch (status)
    {
    //主界面
        case MAIN_MENU_function_test:
            oled_show_string(0,0,"> function test");
            oled_show_string(0,1,"  show data");
            oled_show_string(0,2,"  adjust parameter");
            oled_show_string(0,3,"  collect point");
            oled_show_string(0,4,"  move");
            break;
        case MAIN_MENU_show_data:
            oled_show_string(0,0,"  function test");
            oled_show_string(0,1,"> show data");
            oled_show_string(0,2,"  adjust parameter");
            oled_show_string(0,3,"  collect point");
            oled_show_string(0,4,"  move");
            break;
        case MAIN_MENU_adjust_parameter:
            oled_show_string(0,0,"  function test");
            oled_show_string(0,1,"  show data");
            oled_show_string(0,2,"> adjust parameter");
            oled_show_string(0,3,"  collect point");
            oled_show_string(0,4,"  move");
            break;
        case MAIN_MENU_collect_point:
            oled_show_string(0,0,"  function test");
            oled_show_string(0,1,"  show data");
            oled_show_string(0,2,"  adjust parameter");
            oled_show_string(0,3,"> collect point");
            oled_show_string(0,4,"  move");
            break;
        case MAIN_MENU_move:
            oled_show_string(0,0,"  function test");
            oled_show_string(0,1,"  show data");
            oled_show_string(0,2,"  adjust parameter");
            oled_show_string(0,3,"  collect point");
            oled_show_string(0,4,"> move");
            break;
        //function test
        case 10:
            oled_show_string(0,0,"> S");
            oled_show_string(0,1,"  360");
            break;
        case 11:
            oled_show_string(0,0,"  S");
            oled_show_string(0,1,"> 360");
            break;
        //show data
        case 20:
            oled_show_float(0,0,gps_tau1201.direction,8,6);
            oled_show_float(0,1,gps_tau1201.longitude * 10000.0,8,6);
            oled_show_float(0,2,gps_tau1201.latitude * 10000.0,8,6);
            oled_show_float(0,3,gps_tau1201.time.second,8,6);
            break;
        case 30:
            oled_show_string(0,0,"> collect acc");
            oled_show_string(0,1,"  calculate para");
            break;
        case 31:
            oled_show_string(0,0,"  collect acc");
            oled_show_string(0,1,"> calculate para");
            break;
        case COLLECT_POINT_s:
            oled_show_string(0,0,"> s");
            oled_show_string(0,1,"  circle");
            oled_show_string(0,2,"  straight line");
            break;
        case COLLECT_POINT_circle:
            oled_show_string(0,0,"  s");
            oled_show_string(0,1,"> circle");
            oled_show_string(0,2,"  straight line");
            break;
        case COLLECT_POINT_straight_line:
            oled_show_string(0,0,"  s");
            oled_show_string(0,1,"  circle");
            oled_show_string(0,2,"> straight line");
            break;
        case S_show:
            oled_show_string(0,0,"success");
            break;
        case CIRCLE_show:
            oled_show_string(0,0,"success");
            break;
        case STRAIGHT_LINE_line1:
            oled_show_string(0,0,"> line1");
            oled_show_string(0,1,"  line2");
            oled_show_string(0,2,"  line3");
            oled_show_string(0,3,"  line4");
            break;
        case STRAIGHT_LINE_line2:
            oled_show_string(0,0,"  line1");
            oled_show_string(0,1,"> line2");
            oled_show_string(0,2,"  line3");
            oled_show_string(0,3,"  line4");
            break;
        case STRAIGHT_LINE_line3:
            oled_show_string(0,0,"  line1");
            oled_show_string(0,1,"  line2");
            oled_show_string(0,2,"> line3");
            oled_show_string(0,3,"  line4");
            break;
        case STRAIGHT_LINE_line4:
            oled_show_string(0,0,"  line1");
            oled_show_string(0,1,"  line2");
            oled_show_string(0,2,"  line3");
            oled_show_string(0,3,"> line4");
            break;
        case LINE1_collect_first_point:
            oled_show_string(0,0,"> collect first point");
            oled_show_string(0,1,"  collect end point");
            break;
        case LINE1_collect_end_point:
            oled_show_string(0,0,"  collect first point");
            oled_show_string(0,1,"> collect end point");
            break;
        case LINE1_collect_first_point_show:
            oled_show_string(0,0,"success");
            break;
        case LINE1_collect_end_point_show:
            oled_show_string(0,0,"success");
            break;
        case LINE2_collect_first_point:
            oled_show_string(0,0,"> collect first point");
            oled_show_string(0,1,"  collect end point");
            break;
        case LINE2_collect_end_point:
            oled_show_string(0,0,"  collect first point");
            oled_show_string(0,1,"> collect end point");
            break;
        case LINE2_collect_first_point_show:
            oled_show_string(0,0,"success");
            break;
        case LINE2_collect_end_point_show:
            oled_show_string(0,0,"success");
            break;
        case LINE3_collect_first_point:
            oled_show_string(0,0,"> collect first point");
            oled_show_string(0,1,"  collect end point");
            break;
        case LINE3_collect_end_point:
            oled_show_string(0,0,"  collect first point");
            oled_show_string(0,1,"> collect end point");
            break;
        case LINE3_collect_first_point_show:
            oled_show_string(0,0,"success");
            break;
        case LINE3_collect_end_point_show:
            oled_show_string(0,0,"success");
            break;
        case LINE4_collect_first_point:
            oled_show_string(0,0,"> collect first point");
            oled_show_string(0,1,"  collect end point");
            break;
        case LINE4_collect_end_point:
            oled_show_string(0,0,"  collect first point");
            oled_show_string(0,1,"> collect end point");
            break;
        case LINE4_collect_first_point_show:
            oled_show_string(0,0,"success");
            break;
        case LINE4_collect_end_point_show:
            oled_show_string(0,0,"success");
            break;
        case 50:
            oled_show_string(0, 0, "move now");
            break;
        //function test - S
        case 100:
            oled_show_string(0,0,"> collect start point");
            oled_show_string(0,1,"  collect end point");
            oled_show_string(0,2,"  start");
            break;
        case 101:
            oled_show_string(0,0,"  collect start point");
            oled_show_string(0,1,"> collect end point");
            oled_show_string(0,2,"  start");
            break;
        case 102:
            oled_show_string(0,0,"  collect start point");
            oled_show_string(0,1,"  collect end point");
            oled_show_string(0,2,"> start");
            break;
        case 1000:
            oled_show_string(0,0,"  success");
            break;
        case 1010:
            oled_show_string(0,0,"  success");
            break;
        case 1020:
            oled_show_float(0,0,servo_return_S_situation(),8,6);
            oled_show_float(0,1,return_S_points().position[0][0],8,6);
            oled_show_float(0,2,return_S_points().position[0][1],8,6);
            oled_show_float(0,3,return_S_points().position[1][0],8,6);
            oled_show_float(0,4,return_S_points().position[1][1],8,6);
            oled_show_float(0,5,servo_return_S_error_angle(),8,6);
            break;
        case 300:
            oled_show_string(0,0,"  success");
            break;
        case 310:
            oled_show_string(0,0,"  success");
            break;
    }
}

//这个函数放在中断中，响应按键
void changestatus(void)
{
    key_scanner();
    switch (status)
    {
        case 1:
            if(key_get_state(KEY_1) == KEY_SHORT_PRESS)
            {
                status = 10;
                oled_clear();
            }
            else if(key_get_state(KEY_4) == KEY_SHORT_PRESS)
            {
                status = 2;
                oled_clear();
            }
            break;
        case 2:
            if(key_get_state(KEY_1) == KEY_SHORT_PRESS)
            {
                status = 20;
                oled_clear();
            }
            else if(key_get_state(KEY_3) == KEY_SHORT_PRESS)
            {
                status = 1;
                oled_clear();
            }
            else if(key_get_state(KEY_4) == KEY_SHORT_PRESS)
            {
                status = 3;
                oled_clear();
            }
            break;
        case 3:
            if(key_get_state(KEY_1) == KEY_SHORT_PRESS)
            {
                status = 30;
                oled_clear();
            }
            else if(key_get_state(KEY_3) == KEY_SHORT_PRESS)
            {
                status = 2;
                oled_clear();
            }
            else if(key_get_state(KEY_4) == KEY_SHORT_PRESS)
            {
                status = 4;
                oled_clear();
            }
            break;
        case 4:
            if(key_get_state(KEY_1) == KEY_SHORT_PRESS)
            {
                status = 40;
                oled_clear();
            }
            else if(key_get_state(KEY_3) == KEY_SHORT_PRESS)
            {
                status = 3;
                oled_clear();
            }
            else if(key_get_state(KEY_4) == KEY_SHORT_PRESS)
            {
                status = 5;
                oled_clear();
            }
            break;
        case 5:
            if(key_get_state(KEY_1) == KEY_SHORT_PRESS)
            {
                status = 50;
                oled_clear();
            }
            else if(key_get_state(KEY_3) == KEY_SHORT_PRESS)
            {
                status = 4;
                oled_clear();
            }
            break;
        case 10:
            if(key_get_state(KEY_1) == KEY_SHORT_PRESS)
            {
                status = 100;
                oled_clear();
            }
            else if(key_get_state(KEY_2) == KEY_SHORT_PRESS)
            {
                status = 1;
                oled_clear();
            }
            else if(key_get_state(KEY_4) == KEY_SHORT_PRESS)
            {
                status = 11;
                oled_clear();
            }
            break;
        case 11:
            if(key_get_state(KEY_1) == KEY_SHORT_PRESS)
            {
                status = 100;
                oled_clear();
            }
            else if(key_get_state(KEY_2) == KEY_SHORT_PRESS)
            {
                status = 1;
                oled_clear();
            }
            else if(key_get_state(KEY_3) == KEY_SHORT_PRESS)
            {
                status = 10;
                oled_clear();
            }
            break;
        case 20:
            if(key_get_state(KEY_2) == KEY_SHORT_PRESS)
            {
                status = 2;
                oled_clear();
            }
            break;
        case 30:
            if(key_get_state(KEY_1) == KEY_SHORT_PRESS)
            {
                status = 300;
                //change_if_key_press_acc_data();
                oled_clear();
            }
            if(key_get_state(KEY_2) == KEY_SHORT_PRESS)
            {
                status = 3;
                oled_clear();
            }
            if(key_get_state(KEY_4) == KEY_SHORT_PRESS)
            {
                status = 31;
                oled_clear();
            }
            break;
        case 31:
            if(key_get_state(KEY_1) == KEY_SHORT_PRESS)
            {
                status = 310;
                calculate_acc_para();
                oled_clear();
            }
            if(key_get_state(KEY_2) == KEY_SHORT_PRESS)
            {
                status = 3;
                oled_clear();
            }
            if(key_get_state(KEY_3) == KEY_SHORT_PRESS)
            {
                status = 30;
                oled_clear();
            }
            break;
        case 100:
            if(key_get_state(KEY_1) == KEY_SHORT_PRESS)
            {
                status = 1000;
                S_collect_start_point();
                oled_clear();
            }
            else if(key_get_state(KEY_2) == KEY_SHORT_PRESS)
            {
                status = 10;
                oled_clear();
            }
            else if(key_get_state(KEY_4) == KEY_SHORT_PRESS)
            {
                status = 101;
                oled_clear();
            }
            break;
        case 101:
            if(key_get_state(KEY_1) == KEY_SHORT_PRESS)
            {
                status = 1010;
                S_collect_end_point();
                oled_clear();
            }
            else if(key_get_state(KEY_2) == KEY_SHORT_PRESS)
            {
                status = 10;
                oled_clear();
            }
            else if(key_get_state(KEY_3) == KEY_SHORT_PRESS)
            {
                status = 100;
                oled_clear();
            }
            else if(key_get_state(KEY_4) == KEY_SHORT_PRESS)
            {
                status = 102;
                oled_clear();
            }
            break;
        case 102:
            if(key_get_state(KEY_1) == KEY_SHORT_PRESS)
            {
                status = 1020;

                oled_clear();
            }
            else if(key_get_state(KEY_2) == KEY_SHORT_PRESS)
            {
                status = 10;
                oled_clear();
            }
            else if(key_get_state(KEY_3) == KEY_SHORT_PRESS)
            {
                status = 101;
                oled_clear();
            }
            break;
        case 1000:
            if(key_get_state(KEY_2) == KEY_SHORT_PRESS)
            {
                status = 100;
                oled_clear();
            }
            break;
        case 1010:
            if(key_get_state(KEY_2) == KEY_SHORT_PRESS)
            {
                status = 101;
                oled_clear();
            }
            break;
        case COLLECT_POINT_s:
            if(key_get_state(KEY_1) == KEY_SHORT_PRESS)
            {
                status = S_show;
                collect_point(COLLECT_POINT_s);
                oled_clear();
            }
            if(key_get_state(KEY_2) == KEY_SHORT_PRESS)
            {
                status = MAIN_MENU_collect_point;
                oled_clear();
            }
            if(key_get_state(KEY_4) == KEY_SHORT_PRESS)
            {
                status = COLLECT_POINT_circle;
                oled_clear();
            }
            break;
        case COLLECT_POINT_circle:
            if(key_get_state(KEY_1) == KEY_SHORT_PRESS)
            {
                status = CIRCLE_show;
                collect_point(COLLECT_POINT_circle);
                oled_clear();
            }
            if(key_get_state(KEY_2) == KEY_SHORT_PRESS)
            {
                status = MAIN_MENU_collect_point;
                oled_clear();
            }
            if(key_get_state(KEY_3) == KEY_SHORT_PRESS)
            {
                status = COLLECT_POINT_s;
                oled_clear();
            }
            if(key_get_state(KEY_4) == KEY_SHORT_PRESS)
            {
                status = COLLECT_POINT_straight_line;
                oled_clear();
            }
            break;
        case COLLECT_POINT_straight_line:
            if(key_get_state(KEY_1) == KEY_SHORT_PRESS)
            {
                status = STRAIGHT_LINE_line1;
                oled_clear();
            }
            if(key_get_state(KEY_2) == KEY_SHORT_PRESS)
            {
                status = MAIN_MENU_collect_point;
                oled_clear();
            }
            if(key_get_state(KEY_3) == KEY_SHORT_PRESS)
            {
                status = COLLECT_POINT_circle;
                oled_clear();
            }
            break;
        case S_show:
            if(key_get_state(KEY_2) == KEY_SHORT_PRESS)
            {
                status = COLLECT_POINT_s;
                oled_clear();
            }
            break;
        case CIRCLE_show:
            if(key_get_state(KEY_2) == KEY_SHORT_PRESS)
            {
                status = COLLECT_POINT_circle;
                oled_clear();
            }
            break;
        case STRAIGHT_LINE_line1:
            if(key_get_state(KEY_1) == KEY_SHORT_PRESS)
            {
                status = LINE1_collect_first_point;
                oled_clear();
            }
            if(key_get_state(KEY_2) == KEY_SHORT_PRESS)
            {
                status = COLLECT_POINT_straight_line;
                oled_clear();
            }
            if(key_get_state(KEY_4) == KEY_SHORT_PRESS)
            {
                status = STRAIGHT_LINE_line2;
                oled_clear();
            }
            break;
        case STRAIGHT_LINE_line2:
            if(key_get_state(KEY_1) == KEY_SHORT_PRESS)
            {
                status = LINE2_collect_first_point;
                oled_clear();
            }
            if(key_get_state(KEY_2) == KEY_SHORT_PRESS)
            {
                status = COLLECT_POINT_straight_line;
                oled_clear();
            }
            if(key_get_state(KEY_3) == KEY_SHORT_PRESS)
            {
                status = STRAIGHT_LINE_line1;
                oled_clear();
            }
            if(key_get_state(KEY_4) == KEY_SHORT_PRESS)
            {
                status = STRAIGHT_LINE_line3;
                oled_clear();
            }
            break;
        case STRAIGHT_LINE_line3:
            if(key_get_state(KEY_1) == KEY_SHORT_PRESS)
            {
                status = LINE3_collect_first_point;
                oled_clear();
            }
            if(key_get_state(KEY_2) == KEY_SHORT_PRESS)
            {
                status = COLLECT_POINT_straight_line;
                oled_clear();
            }
            if(key_get_state(KEY_3) == KEY_SHORT_PRESS)
            {
                status = STRAIGHT_LINE_line2;
                oled_clear();
            }
            if(key_get_state(KEY_4) == KEY_SHORT_PRESS)
            {
                status = STRAIGHT_LINE_line4;
                oled_clear();
            }
            break;
        case STRAIGHT_LINE_line4:
            if(key_get_state(KEY_1) == KEY_SHORT_PRESS)
            {
                status = LINE4_collect_first_point;
                oled_clear();
            }
            if(key_get_state(KEY_2) == KEY_SHORT_PRESS)
            {
                status = COLLECT_POINT_straight_line;
                oled_clear();
            }
            if(key_get_state(KEY_3) == KEY_SHORT_PRESS)
            {
                status = STRAIGHT_LINE_line3;
                oled_clear();
            }
            break;
        case LINE1_collect_first_point:
            if(key_get_state(KEY_1) == KEY_SHORT_PRESS)
            {
                status = LINE1_collect_first_point_show;
                collect_point(LINE1_collect_first_point);
                oled_clear();
            }
            if(key_get_state(KEY_2) == KEY_SHORT_PRESS)
            {
                status = STRAIGHT_LINE_line1;
                oled_clear();
            }
            if(key_get_state(KEY_4) == KEY_SHORT_PRESS)
            {
                status = LINE1_collect_end_point;
                oled_clear();
            }
            break;
        case LINE1_collect_end_point:
            if(key_get_state(KEY_1) == KEY_SHORT_PRESS)
            {
                status = LINE1_collect_end_point_show;
                collect_point(LINE1_collect_end_point);
                oled_clear();
            }
            if(key_get_state(KEY_2) == KEY_SHORT_PRESS)
            {
                status = STRAIGHT_LINE_line1;
                oled_clear();
            }
            if(key_get_state(KEY_3) == KEY_SHORT_PRESS)
            {
                status = LINE1_collect_first_point;
                oled_clear();
            }
            break;
        case LINE1_collect_first_point_show:
            if(key_get_state(KEY_2) == KEY_SHORT_PRESS)
            {
                status = LINE1_collect_first_point;
                oled_clear();
            }
            break;
        case LINE1_collect_end_point_show:
            if(key_get_state(KEY_2) == KEY_SHORT_PRESS)
            {
                status = LINE1_collect_end_point;
                oled_clear();
            }
            break;
        case LINE2_collect_first_point:
            if(key_get_state(KEY_1) == KEY_SHORT_PRESS)
            {
                status = LINE2_collect_first_point_show;
                collect_point(LINE2_collect_first_point);
                oled_clear();
            }
            if(key_get_state(KEY_2) == KEY_SHORT_PRESS)
            {
                status = STRAIGHT_LINE_line2;
                oled_clear();
            }
            if(key_get_state(KEY_4) == KEY_SHORT_PRESS)
            {
                status = LINE2_collect_end_point;
                oled_clear();
            }
            break;
        case LINE2_collect_end_point:
            if(key_get_state(KEY_1) == KEY_SHORT_PRESS)
            {
                status = LINE2_collect_end_point_show;
                collect_point(LINE2_collect_end_point);
                oled_clear();
            }
            if(key_get_state(KEY_2) == KEY_SHORT_PRESS)
            {
                status = STRAIGHT_LINE_line2;
                oled_clear();
            }
            if(key_get_state(KEY_3) == KEY_SHORT_PRESS)
            {
                status = LINE2_collect_first_point;
                oled_clear();
            }
            break;
        case LINE2_collect_first_point_show:
            if(key_get_state(KEY_2) == KEY_SHORT_PRESS)
            {
                status = LINE2_collect_first_point;
                oled_clear();
            }
            break;
        case LINE2_collect_end_point_show:
            if(key_get_state(KEY_2) == KEY_SHORT_PRESS)
            {
                status = LINE1_collect_end_point;
                oled_clear();
            }
            break;
        case LINE3_collect_first_point:
            if(key_get_state(KEY_1) == KEY_SHORT_PRESS)
            {
                status = LINE3_collect_first_point_show;
                collect_point(LINE3_collect_first_point);
                oled_clear();
            }
            if(key_get_state(KEY_2) == KEY_SHORT_PRESS)
            {
                status = STRAIGHT_LINE_line3;
                oled_clear();
            }
            if(key_get_state(KEY_4) == KEY_SHORT_PRESS)
            {
                status = LINE3_collect_end_point;
                oled_clear();
            }
            break;
        case LINE3_collect_end_point:
            if(key_get_state(KEY_1) == KEY_SHORT_PRESS)
            {
                status = LINE3_collect_end_point_show;
                collect_point(LINE3_collect_end_point);
                oled_clear();
            }
            if(key_get_state(KEY_2) == KEY_SHORT_PRESS)
            {
                status = STRAIGHT_LINE_line3;
                oled_clear();
            }
            if(key_get_state(KEY_3) == KEY_SHORT_PRESS)
            {
                status = LINE3_collect_first_point;
                oled_clear();
            }
            break;
        case LINE3_collect_first_point_show:
            if(key_get_state(KEY_2) == KEY_SHORT_PRESS)
            {
                status = LINE3_collect_first_point;
                oled_clear();
            }
            break;
        case LINE3_collect_end_point_show:
            if(key_get_state(KEY_2) == KEY_SHORT_PRESS)
            {
                status = LINE3_collect_end_point;
                oled_clear();
            }
            break;
        case LINE4_collect_first_point:
            if(key_get_state(KEY_1) == KEY_SHORT_PRESS)
            {
                status = LINE4_collect_first_point_show;
                collect_point(LINE4_collect_first_point);
                oled_clear();
            }
            if(key_get_state(KEY_2) == KEY_SHORT_PRESS)
            {
                status = STRAIGHT_LINE_line4;
                oled_clear();
            }
            if(key_get_state(KEY_4) == KEY_SHORT_PRESS)
            {
                status = LINE4_collect_end_point;
                oled_clear();
            }
            break;
        case LINE4_collect_end_point:
            if(key_get_state(KEY_1) == KEY_SHORT_PRESS)
            {
                status = LINE4_collect_end_point_show;
                collect_point(LINE4_collect_end_point);
                oled_clear();
            }
            if(key_get_state(KEY_2) == KEY_SHORT_PRESS)
            {
                status = STRAIGHT_LINE_line4;
                oled_clear();
            }
            if(key_get_state(KEY_3) == KEY_SHORT_PRESS)
            {
                status = LINE4_collect_first_point;
                oled_clear();
            }
            break;
        case LINE4_collect_first_point_show:
            if(key_get_state(KEY_2) == KEY_SHORT_PRESS)
            {
                status = LINE4_collect_first_point;
                oled_clear();
            }
            break;
        case LINE4_collect_end_point_show:
            if(key_get_state(KEY_2) == KEY_SHORT_PRESS)
            {
                status = LINE4_collect_end_point;
                oled_clear();
            }
            break;
        case 300:
            if(key_get_state(KEY_2) == KEY_SHORT_PRESS)
            {
                status = 30;
                oled_clear();
            }
            break;
        case 310:
            if(key_get_state(KEY_2) == KEY_SHORT_PRESS)
            {
                status = 31;
                oled_clear();
            }
            break;
    }
}

int passcount = 0;
point straight_line_first_point,straight_line_end_point;
void move(void)
{
    point GPS_now_point,advised_point;
    GPS_now_point.latitude = gps_tau1201.latitude;
    GPS_now_point.longitude = gps_tau1201.longitude;

    delt_points first_point,end_point,now_point;

    switch (status)
    {
        case 50:
            /*if((pow(GPS_now_point.latitude - return_all_points().position[passcount][1],2.0)+pow(GPS_now_point.longitude - return_all_points().position[passcount][0],2.0)<0.00000000001)&&(return_all_points().point_type[passcount]!=0))
            {
                passcount++;
            }
            else if((pow(GPS_now_point.latitude - return_all_points().position[passcount+1][1],2.0)+pow(GPS_now_point.longitude - return_all_points().position[passcount+1][0],2.0)<0.00000000001)&&(return_all_points().point_type[passcount]==0))
            {
                passcount = passcount + 2;
            }*/
            /*
            if(return_all_points().point_type[passcount] == 0)
            {
                point straight_line_first_point,straight_line_end_point;
                straight_line_first_point.latitude = return_all_points().position[passcount][1];
                straight_line_first_point.longitude = return_all_points().position[passcount][0];
                straight_line_end_point.latitude = return_all_points().position[passcount+1][1];
                straight_line_end_point.longitude = return_all_points().position[passcount+1][0];

                servo_change_straight_line(INS_return_yaw().real, straight_line_first_point, straight_line_end_point, GPS_now_point);

                if( (return_passcount_angle() > (float)(PI / 2.0) ) || (return_passcount_angle() < (float)(-PI / 2.0)) )
                {
                    passcount += 2;
                }
            }
            if(return_all_points().point_type[passcount] == 1)
            {
                passcount += 1;

                point S_first_point,S_end_point;
                S_first_point.latitude = return_all_points().position[passcount-1][1];
                S_first_point.longitude = return_all_points().position[passcount-1][0];
                S_end_point.latitude = return_all_points().position[passcount][1];
                S_end_point.longitude = return_all_points().position[passcount][0];

                servo_change_S(0.5, 0.5, 0.5, 0.5,INS_return_yaw().real,S_first_point,S_end_point);
            }
            */

            //坐标轴转化标准流程
            /*
            straight_line_end_point.latitude = return_all_points().position[passcount][1];
            straight_line_end_point.longitude = return_all_points().position[passcount][0];
            delt_points a = GPS_deal_point(GPS_now_point,straight_line_end_point);
            */

            advised_point.latitude = return_all_points().position[0][1];
            advised_point.longitude = return_all_points().position[0][0];

            straight_line_first_point.latitude = return_all_points().position[passcount][1];
            straight_line_first_point.longitude = return_all_points().position[passcount][0];
            straight_line_end_point.latitude = return_all_points().position[passcount+1][1];
            straight_line_end_point.longitude = return_all_points().position[passcount+1][0];

            first_point = GPS_deal_point(straight_line_first_point, advised_point);
            end_point = GPS_deal_point(straight_line_end_point, advised_point);
            now_point = GPS_deal_point(GPS_now_point, advised_point);
            oled_show_float(0,3,now_point.x,3,1);
            oled_show_float(60,3,now_point.y,3,1);

            set_servo_duty(end_point,first_point,now_point,INS_return_yaw().real);

            if(((now_point.x - end_point.x)*(now_point.x - end_point.x)+(now_point.y - end_point.y)*(now_point.y - end_point.y)) < 1.0f)
            {
                passcount++;
            }
            oled_show_float(0,7,passcount,8,6);

            pwm_set_duty(TIM2_PWM_MAP1_CH1_A15,servo_return_duty_set());

            break;
    }
}

int communication_return_status(void)
{
    return status;
}
