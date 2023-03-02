#include "e90canbus.h"
#include "globals.h"

const uint16_t CAN_ID = 0x310;
uint8_t gear_frame[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

void canSendGear(){

  if (s_ignition)
  {
    gear_frame[1] = 0x50;
{
if(s_speed == 0 && s_rpm > 5000) // launch control
{
 gear_frame[2] = 0x01; 
 gear_frame[5] = 0x08; // HOLD Lamp
}
else if(s_speed == 0 && s_rpm < 3000)
{
  gear_frame[2] = 0x00;
}
}
if((s_speed> 1 && s_speed < 40) && (s_rpm > 400 && s_rpm <7500))
{
 gear_frame[0] = 0x01; 
}
else if((s_speed > 40 && s_speed < 60) && (s_rpm > 400 && s_rpm <7500))
{
  gear_frame[0] = 0x02;
}
else if((s_speed > 60 && s_speed < 90) && (s_rpm > 400 && s_rpm <7500))
{
  gear_frame[0] = 0x03;
}
else if((s_speed > 90 && s_speed < 115) && (s_rpm > 400 && s_rpm <7500))
{
  gear_frame[0] = 0x04;
}

else if((s_speed > 115 && s_speed <150) && (s_rpm > 400 && s_rpm <7500))
{
  gear_frame[0] = 0x05;
}
else if((s_speed > 150 && s_speed <200) && (s_rpm > 400 && s_rpm <7500))
{
  gear_frame[0] = 0x08;
}

else if((s_speed > 200 && s_speed <275) && (s_rpm > 400 && s_rpm <7500))
{
  gear_frame[0] = 0x09;
}
else if((s_speed > 275 && s_speed <330) && (s_rpm > 400 && s_rpm <7500))
{
  gear_frame[0] = 0x0a;
}
  }
  CAN.sendMsgBuf(CAN_ID, 0, 8, gear_frame);
}
