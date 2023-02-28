#include "e90canbus.h"
#include "globals.h"

const uint16_t CAN_ID = 0x3a3;
uint8_t rpm_frame[8] = {0x00, 0x00, 0x00, 0x0a, 0x00, 0x00, 0x00, 0x00};

void canSendRPM(){
  uint16_t rpm = s_rpm; 

rpm_frame[2] = (int(rpm * 0.34) & 0xff); 
rpm_frame[3] = (int(rpm * 0.34) >> 8);

  CAN.sendMsgBuf(CAN_ID, 0, 8, rpm_frame);
}
