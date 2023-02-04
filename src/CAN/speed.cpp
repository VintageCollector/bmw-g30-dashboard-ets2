#include "e90canbus.h"
#include "globals.h"

#define lo8(x) ((int)(x)&0xff)
#define hi8(x) ((int)(x)>>8)

const uint16_t CAN_ID = 0x1A1;
uint8_t speed_frame[5] = {0x00, 0x00, 0x00, 0x00, 0xAA};
static uint8_t count = 0x00;

void canSendSpeed(){
  //int speed_value = s_speed*230;

  speed_frame[0] = count;
  speed_frame[1] = count;

      count++;
 if (count == 0x00)
  {
   count = 0xff;
    count++;
  }

  const uint8_t delta_time = 230; // const
  uint16_t speed_value =  s_speed * 60;
  uint16_t counter = (speed_frame[2] | (speed_frame[3] << 8)) & 0x0FFF;
counter += (float)delta_time * M_PI;

speed_frame[2] = (lo8(speed_value));
speed_frame[3] = (hi8(speed_value));

  CAN.sendMsgBuf(CAN_ID, 0, 8, speed_frame);
  
}
