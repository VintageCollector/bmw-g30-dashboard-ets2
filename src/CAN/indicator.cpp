#include "e90canbus.h"
#include "globals.h"

uint8_t indicator_frame[8] = {0x80, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

const uint16_t CAN_ID = 0x363;

//unsigned long prev_time = 0;
//const unsigned long interval = 10;

void canSendIndicator(){

// unsigned long current_time = millis();

  //if (current_time - prev_time >= interval) {
    // Update the previous time
  //  prev_time = current_time;

  if(s_light_indicator == I_LEFT){

 indicator_frame[2] = 0x04;
  }
  else if (s_light_indicator == I_RIGHT){
    indicator_frame[2] = 0x08;
  }
  else if (s_light_indicator == I_HAZZARD){
    indicator_frame[2] = 0x0c;
  }
  else if (s_light_indicator == I_OFF){
    indicator_frame[2] = 0x00;
  }
  
    CAN.sendMsgBuf(CAN_ID, 0, 8, indicator_frame);
  }

