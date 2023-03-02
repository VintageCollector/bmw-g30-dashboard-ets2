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


//magnetometer-compass sensor configuration
#include <Adafruit_Sensor.h>
#include <Adafruit_HMC5883_U.h>

//temp-elevation-pressure sensor configuration
#include <SPI.h>
#include "Adafruit_BMP3XX.h"

#define SEALEVELPRESSURE_HPA (1013.25)

Adafruit_BMP3XX bmp;


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

  if (!bmp.begin_I2C()) {   // hardware I2C mode, can pass in address & alt Wire
  //if (! bmp.begin_SPI(BMP_CS)) {  // hardware SPI mode  
  //if (! bmp.begin_SPI(BMP_CS, BMP_SCK, BMP_MISO, BMP_MOSI)) {  // software SPI mode
    Serial.println("Could not find a valid BMP3 sensor, check wiring!");
    while (1);
  }

  // Set up oversampling and filter initialization
  bmp.setTemperatureOversampling(BMP3_OVERSAMPLING_8X);
  bmp.setPressureOversampling(BMP3_OVERSAMPLING_4X);
  bmp.setIIRFilterCoeff(BMP3_IIR_FILTER_COEFF_3);
  bmp.setOutputDataRate(BMP3_ODR_50_HZ);

}

void loop() {
  canSend();
  serial.update();

unsigned char stmp2[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x8a, 0x00, 0x00};
CAN.sendMsgBuf(0x663, 0, 8, stmp2); // battery voltage

int ele = bmp.readAltitude(SEALEVELPRESSURE_HPA)*20;
unsigned char stmp3[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, ele};
CAN.sendMsgBuf(0x5fa, 0, 8, stmp3); // elevation

}