#ifndef _communication_h_
#define _communication_h_

#include "zf_device_key.h"
#include "zf_device_oled.h"
#include "zf_device_gps_tau1201.h"
#include <collectpoint.h>
#include <servo.h>
#include <INS.h>
#include <zf_driver_pwm.h>

void showeverything(void);
void changestatus(void);
int communication_return_status(void);
void move(void);

#endif
