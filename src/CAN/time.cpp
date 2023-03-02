#include "e90canbus.h"
#include "globals.h"

const uint16_t CAN_ID = 0x2F8;
uint8_t time_frame[8] = {0x13, 0x2E, 0x1E, 0x01, 0x4F, 0xDC, 0x07, 0xFD};

void canSendTime(){
  time_frame[0] = s_time_hour;
  time_frame[1] = s_time_minute;
  time_frame[2] = s_time_sec;

  time_frame[3] = s_time_day;
  time_frame[4] = (s_time_month << 4) | 0x0F;

  time_frame[5] = (uint8_t)s_time_year;
  time_frame[6] = (uint8_t)(s_time_year >> 8);
  CAN.sendMsgBuf(CAN_ID, 0, 8, time_frame);
}
