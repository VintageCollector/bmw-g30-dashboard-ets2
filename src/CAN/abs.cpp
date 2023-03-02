#include "e90canbus.h"
#include "globals.h"

const uint16_t CAN_ID = 0x38C;
uint8_t abs_frame[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
//uint8_t abs_frame[8] = {0x00, 0x00, 0xB3, 0x00, 0x00, 0x00, 0x00, 0x00};

void canSendAbs(){
  if (((((abs_frame[2] >> 4) + 3) << 4) & 0xF0) | 0x03)
  {
  abs_frame[4] = 0x00;}

  if(s_speed == 0 && s_rpm > 5000) // launch control
{
 abs_frame[5] = 0x08; // HOLD Lamp
}

  CAN.sendMsgBuf(CAN_ID, 0, 8, abs_frame);
}
