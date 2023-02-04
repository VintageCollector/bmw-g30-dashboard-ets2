#include "e90canbus.h"
#include "globals.h"

uint8_t engine_temp_frame[8] = {0x02, 0xFF, 0x63, 0xCD, 0x5D, 0x37, 0xCD, 0xA8};

const uint16_t CAN_ID = 0x3f9;
static uint8_t count = 0x00;

void canSendEngineTemp(){

  engine_temp_frame[1] = s_engine_temp + 48;
  engine_temp_frame[2] = count;
  engine_temp_frame[3] = s_engine_temp + 48;
  engine_temp_frame[4] = s_engine_temp + 48;
  engine_temp_frame[5] = int((0.983607*s_engine_temp) + 51.3169);
  engine_temp_frame[3] = s_engine_temp + 48;
  engine_temp_frame[7] = count;

  CAN.sendMsgBuf(CAN_ID, 0, 8, engine_temp_frame);
}
