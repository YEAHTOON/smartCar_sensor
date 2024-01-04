#ifndef _SAVEPARA_
#define _SAVEPARA_

#include "zf_common_typedef.h"
#include "zf_driver_flash.h"
#include "collectpoint.h"

typedef struct
{
    double position[30][2];
} points;

void save_ServoMid(uint32 servomid_to_save);
uint32 get_ServoMid(void);
void save_Points(points input_points);
points get_Points(void);

#endif
