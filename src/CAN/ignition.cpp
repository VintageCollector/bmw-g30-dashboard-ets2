#include "e90canbus.h"
#include "globals.h"

uint8_t ignition_frame_on[8] = {0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00};
uint8_t ignition_frame_off[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

const uint16_t CAN_ID = 0x3C0;

void canSendIgnitionFrame(){
  if(s_ignition){
    CAN.sendMsgBuf(CAN_ID, 0, 8, ignition_frame_on);
    ignition_frame_on[3]++;
  }else{
    CAN.sendMsgBuf(CAN_ID, 0, 8, ignition_frame_off);
    ignition_frame_off[3]++;
  }
}
