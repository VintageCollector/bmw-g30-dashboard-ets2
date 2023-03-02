#include "e90canbus.h"
#include "globals.h"

const uint16_t CAN_ID = 0x30d;
uint8_t handbrake_frame[8] = {0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

void canSendHandbrake(){
  if(s_handbrake){
    handbrake_frame[0] = 0x11;
  }else{
    handbrake_frame[0] = 0x00;
  }
  CAN.sendMsgBuf(CAN_ID, 0, 8, handbrake_frame);
}
