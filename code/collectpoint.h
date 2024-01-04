#ifndef _collectpoint_h_
#define _collectpoint_h_

#include <struct_enum.h>
#include <zf_device_gps_tau1201.h>

void S_collect_start_point(void);
void S_collect_end_point(void);
collected_points return_S_points(void);
void collect_point(int communication_status);
collected_points return_all_points(void);

#endif
