#include "e90canbus.h"
#include "globals.h"
#include "stdint.h"

// Credits to https://github.com/gizmo87898/BMW_6WA_Controller_ESP32 for the rpm. Much smoother than the original version
//int rpm = 765; // 0-7500 rpm

const uint16_t CAN_ID = 0x0f3;
uint8_t rpm_frame[8] = {0xf3, 0x00, 0x00, 0xc0, 0xF0, 0xC4, 0xFF, 0xFF};

void canSendRPM()
{

int rpm = s_rpm;

rpm_frame[1] = (int(rpm * 1.557) & 0xff); // rpm for F15 with crc checksum
rpm_frame[2] = (int(rpm * 1.557) >> 8);

 CAN.sendMsgBuf(CAN_ID, 0, 8, rpm_frame);
}
