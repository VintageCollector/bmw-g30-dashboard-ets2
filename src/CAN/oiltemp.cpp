#include "e90canbus.h"
#include "globals.h"

uint8_t oil_temp_frame[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x90, 0x00, 0x00};

const uint16_t CAN_ID = 0x6b5;

void canSendOilTemp(){
  oil_temp_frame[5] = s_engine_temp + 60;
  //engine_temp_frame[2]++;
  CAN.sendMsgBuf(CAN_ID, 0, 8, oil_temp_frame);
}
