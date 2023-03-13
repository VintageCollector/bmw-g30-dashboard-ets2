#include "e90canbus.h"
#include "globals.h"

const uint16_t CAN_ID = 0x677;
uint8_t mode_frame[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x24, 0x00};

void canSendMode(){

mode_frame[1] = 0x40; // Sport + mode

  CAN.sendMsgBuf(CAN_ID, 0, 8, mode_frame);
}
