#ifndef _struct_h_
#define _struct_h_

typedef struct
{
    double longitude,latitude;
} point;

typedef struct
{
    double position[20][2];
    int point_type[20];
} collected_points;

typedef struct
{
    float x,y;
} delt_points;

typedef struct
{
    float **element;
    int row,col;
} matrix;

typedef enum
{
    MAIN_MENU_function_test = 1,
    MAIN_MENU_show_data = 2,
    MAIN_MENU_adjust_parameter = 3,
    MAIN_MENU_collect_point = 4,
    MAIN_MENU_move = 5,

    COLLECT_POINT_s = 40,
    COLLECT_POINT_circle = 41,
    COLLECT_POINT_straight_line = 42,

    S_show = 400,

    CIRCLE_show = 410,

    STRAIGHT_LINE_line1 = 420,
    STRAIGHT_LINE_line2 = 421,
    STRAIGHT_LINE_line3 = 422,
    STRAIGHT_LINE_line4 = 423,

    LINE1_collect_first_point = 4200,
    LINE1_collect_end_point = 4201,
    LINE1_collect_first_point_show = 42000,
    LINE1_collect_end_point_show = 42010,

    LINE2_collect_first_point = 4210,
    LINE2_collect_end_point = 4211,
    LINE2_collect_first_point_show = 42100,
    LINE2_collect_end_point_show = 42110,

    LINE3_collect_first_point = 4220,
    LINE3_collect_end_point = 4221,
    LINE3_collect_first_point_show = 42200,
    LINE3_collect_end_point_show = 42210,

    LINE4_collect_first_point = 4230,
    LINE4_collect_end_point = 4231,
    LINE4_collect_first_point_show = 42300,
    LINE4_collect_end_point_show = 42310,
} communication_status_enum;

#endif
