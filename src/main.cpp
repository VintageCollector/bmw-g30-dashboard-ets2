/*
  Marcin648 2019
  GNU General Public License 3.0
*/

#include <Arduino.h>

#include <PacketSerial.h>
#include <mcp_can.h>
#include <SPI.h>
#include "stdint.h"
#include "e90canbus.h"
#include "serial.h"
#include "configuration.h"

/*
  Set up can bus
*/
MCP_CAN CAN(SPI_CS_PIN);

PacketSerial serial;


/*
  Main
*/
void setup() {
  //Initialize serial port
  serial.begin(SERIAL_BAUD_RATE);
  serial.setPacketHandler(&serialReceive);

  //Initialize CAN-BUS
  while(CAN.begin(CAN_BAUD_RATE) != CAN_OK){
    delay(100);
  }
}

void loop() {
  canSend();
  serial.update();
  static uint8_t count = 0x00;

unsigned char stmp1[8] = {0x40, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00};
CAN.sendMsgBuf(0x510, 0, 8, stmp1);

unsigned char stmp2[8] = {0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
CAN.sendMsgBuf(0x36a, 0, 8, stmp2);

unsigned char stmp[8] = {0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
CAN.sendMsgBuf(0x3d8, 0, 8, stmp);

unsigned char stmp3[8] = {0x12, count, 0x8A, 0xDD, 0xF1, 0x15, 0x30, 0x02}; // ignition for F15 cluster
CAN.sendMsgBuf(0x12f, 0, 8, stmp3);

unsigned char stmp4[8] = {0x02, count, count, 0x00, 0x00, count, count, count}; // ignition for F15 cluster
CAN.sendMsgBuf(0x3f9, 0, 8, stmp4);

      count++;
 if (count == 0x00)
  {
   count = 0xff;
    count++;
  }

}