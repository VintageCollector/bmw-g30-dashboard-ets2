#include "e90canbus.h"
#include "globals.h"

int buttonState = 0;
int buttonState2 = 0;
int buttonState3 = 0;
int buttonState4 = 0;
int buttonState5 = 0;

uint8_t vinnumber_frame[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

const uint16_t CAN_ID = 0x5bf;

void canSendvinnumber(){
  
  //digitalWrite(INT_PIN, 1); //if here is a CAN ID with its Bytes, remove the '//' at the begin of this line!
 buttonState = digitalRead(6);
  if (buttonState == LOW)
{

vinnumber_frame[0] = 0x12;
vinnumber_frame[2] = 0x01;
CAN.sendMsgBuf(0x5bf, 0, 8, vinnumber_frame);
}

    buttonState2 = digitalRead(4);
  if (buttonState2 == LOW)
{

vinnumber_frame[0] = 0x12;
vinnumber_frame[2] = 0x0f;
CAN.sendMsgBuf(0x5bf, 0, 8, vinnumber_frame);
}

    buttonState3 = digitalRead(7);
  if (buttonState3 == LOW)
{
vinnumber_frame[0] = 0x03;
vinnumber_frame[1] = 0x13;
vinnumber_frame[2] = 0x01;
CAN.sendMsgBuf(0x5bf, 0, 8, vinnumber_frame);
}

    buttonState5 = digitalRead(5);
  if (buttonState5 == LOW)
{
vinnumber_frame[0] = 0x00;
vinnumber_frame[1] = 0x13;
vinnumber_frame[2] = 0x10;
CAN.sendMsgBuf(0x5bf, 0, 8, vinnumber_frame);
}

}


