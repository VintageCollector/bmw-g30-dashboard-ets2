#include "e90canbus.h"
#include "globals.h"

const uint16_t CAN_ID = 0x310;
uint8_t gear_frame[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

void canSendGear(){

  if (s_ignition)
  {
    gear_frame[1] = 0x50;
  }

 if(s_speed == 0 && s_rpm > 4000)
 {
  gear_frame[2] = 0x01;
 } 
 else 
 {
  gear_frame[2] = 0x00;
 }

if((s_speed> 1 && s_speed < 30) && (s_rpm > 400 && s_rpm <7200))
{
 gear_frame[0] = 0x01; 
}
else if((s_speed > 31 && s_speed < 73) && (s_rpm > 400 && s_rpm <7200))
{
  gear_frame[0] = 0x02;
}
else if((s_speed > 74 && s_speed < 102) && (s_rpm > 400 && s_rpm <7200))
{
  gear_frame[0] = 0x03;
}
else if((s_speed > 103 && s_speed < 130) && (s_rpm > 400 && s_rpm <7200))
{
  gear_frame[0] = 0x04;
}

else if((s_speed > 130 && s_speed <157) && (s_rpm > 400 && s_rpm <7200))
{
  gear_frame[0] = 0x05;
}
else if((s_speed > 158 && s_speed <170) && (s_rpm > 400 && s_rpm <7200))
{
  gear_frame[0] = 0x08;
}

else if((s_speed > 171 && s_speed <190) && (s_rpm > 400 && s_rpm <7200))
{
  gear_frame[0] = 0x09;
}
else if((s_speed > 191 && s_speed <200) && (s_rpm > 400 && s_rpm <7200))
{
  gear_frame[0] = 0x0a;
}
  
  CAN.sendMsgBuf(CAN_ID, 0, 8, gear_frame);
}
