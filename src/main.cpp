/*
  Marcin648 2019
  GNU General Public License 3.0
*/

#include <Arduino.h>

#include <PacketSerial.h>
#include <mcp_can.h>
#include <SPI.h>

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
  pinMode(2, INPUT_PULLUP); // right
  pinMode(4, INPUT_PULLUP); // down
  pinMode(5, INPUT_PULLUP); // mid
  pinMode(6, INPUT_PULLUP); // up
  pinMode(7, INPUT_PULLUP); // left

}

void loop() {
  canSend();
  serial.update();

unsigned char stmp1[8] = {0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x20};
CAN.sendMsgBuf(0x5fa, 0, 8, stmp1); // elevation

unsigned char stmp2[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x8a, 0x00, 0x00};
CAN.sendMsgBuf(0x663, 0, 8, stmp2); // battery voltage

}