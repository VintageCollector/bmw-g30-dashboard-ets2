#include "e90canbus.h"
#include "globals.h"

//uint8_t ignition_frame_on[5] = {0x41, 0x42, 0x69, 0x8f, 0xE2};
uint8_t ignition_frame_on[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00};
uint8_t ignition_frame_off[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0A, 0x00};

const uint16_t CAN_ID = 0x03c;

void canSendIgnitionFrame(){
  if(s_ignition){
    CAN.sendMsgBuf(CAN_ID, 0, 8, ignition_frame_on);
    
  }else{
    CAN.sendMsgBuf(CAN_ID, 0, 8, ignition_frame_off);
  }
}
