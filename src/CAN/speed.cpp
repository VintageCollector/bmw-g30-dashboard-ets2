#include "e90canbus.h"
#include "globals.h"

const uint16_t CAN_ID = 0x105;
uint8_t speed_frame[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

void canSendSpeed(){
  
  uint16_t speed_value = s_speed/2;

  speed_frame[2] = speed_value*1.125;
  speed_frame[5] = speed_value*1.11;

  CAN.sendMsgBuf(CAN_ID, 0, 8, speed_frame);
}
