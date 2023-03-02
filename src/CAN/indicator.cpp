#include "e90canbus.h"
#include "globals.h"

uint8_t indicator_frame[8] = {0x80, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

const uint16_t CAN_ID = 0x363;

void canSendIndicator(){

  //Delay off signal. Helps if signal is blinking.


    if(s_light_indicator != I_OFF){
      switch (s_light_indicator) {
        case I_LEFT:
          indicator_frame[2] = 0x04;
          break;
        case I_RIGHT:
          indicator_frame[2] = 0x08;
          break;
        case I_HAZZARD:
          indicator_frame[2] = 0x0c;
          break;

    CAN.sendMsgBuf(CAN_ID, 0, 8, indicator_frame);
  }

    }}