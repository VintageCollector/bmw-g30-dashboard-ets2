#include "e90canbus.h"
#include "globals.h"

const uint16_t CAN_ID = 0x1A1;
uint8_t speed_frame[5] = {0x00, 0x00, 0x00, 0x00, 0x91};
static uint8_t count = 0x00;

void canSendSpeed(){
  uint16_t speed_value = s_speed;

      count++;
 if (count == 0x00)
  {
   count = 0xff;
    count++;
  }

  speed_frame[2] = speed_value*0.26;
  speed_frame[3] = speed_value*0.25;

  speed_frame[1] = count;
  

  CAN.sendMsgBuf(CAN_ID, 0, 8, speed_frame);
  
}
