#include "e90canbus.h"
#include "globals.h"

uint8_t lights_frame[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

const uint16_t CAN_ID = 0x662;

void canSendLights(){
  uint16_t lights = 0;

  if(s_light_parking) lights |= L_BACKLIGHT;
  if(s_light_dip) lights |= L_DIP;
  if(s_light_main) lights |= L_MAIN;
  if(s_light_fog) lights |= L_FOG;
  
  lights_frame[2] = lights;

  CAN.sendMsgBuf(CAN_ID, 0, 8, lights_frame);
}
