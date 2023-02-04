#include "e90canbus.h"
#include "globals.h"

#define lo8(x) ((int)(x)&0xff)
#define hi8(x) ((int)(x)>>8)

uint8_t fuel_frame[6] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

const uint16_t CAN_ID = 0x349;

void canSendFuel(){
  uint16_t level = min(1+(s_fuel*1*8), 9000);

  fuel_frame[0] = lo8(level);
  fuel_frame[1] = hi8(level);

 fuel_frame[2] = lo8(level);
 fuel_frame[3] = hi8(level);

 fuel_frame[4] = lo8(level);
 fuel_frame[5] = hi8(level);

  CAN.sendMsgBuf(CAN_ID, 0, 5, fuel_frame);
}
