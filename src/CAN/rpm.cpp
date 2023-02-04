#include "e90canbus.h"
#include "globals.h"


const uint16_t CAN_ID = 0x0f3;
uint8_t rpm_frame[8] = {0x00, 0x00, 0x00, 0xC0, 0xF0, 0xC4, 0xFF, 0xFF};


void canSendRPM(){
  uint16_t rpm = s_rpm;
if(rpm >> 1)
{
//rpm_frame[1] = value *0.00659; 
//rpm_frame[2] = value * 0.007;

rpm_frame[1] = (int(rpm * 1.557) & 0xff); 
rpm_frame[2] = (int(rpm * 1.557) >> 8);

  CAN.sendMsgBuf(CAN_ID, 0, 8, rpm_frame);
}

else

{

rpm_frame[1] = 0x00; 
rpm_frame[2] = 0x00;

 CAN.sendMsgBuf(CAN_ID, 0, 8, rpm_frame);
}
}
