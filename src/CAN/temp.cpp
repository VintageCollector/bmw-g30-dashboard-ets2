#include "e90canbus.h"
#include "globals.h"

uint8_t engine_temp_frame[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x90, 0x00, 0x00};

const uint16_t CAN_ID = 0x522;

void canSendEngineTemp(){
  engine_temp_frame[5] = s_engine_temp + 80;

  if(s_rpm > 1 && s_rpm < 2200)
  {
    engine_temp_frame[6] = (int(s_rpm * 14) >> 8);
  }
  else if(s_rpm > 2200 && s_rpm < 3000)
  {
  engine_temp_frame[6] = (int(s_rpm * 7) >> 8);}  
  else if(s_rpm > 3000 && s_rpm < 5000)
  {
  engine_temp_frame[6] = (int(s_rpm * 6) >> 8);}
  else if(s_rpm > 5000 && s_rpm < 8000)
  {
    engine_temp_frame[6] = (int(s_rpm * 3) >> 8);
  }
  //engine_temp_frame[2]++;
  CAN.sendMsgBuf(CAN_ID, 0, 8, engine_temp_frame);
}
