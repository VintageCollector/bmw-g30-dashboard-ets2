#include "e90canbus.h"

//Timing
uint32_t lastTime = 0;
uint16_t canCounter = 0;

/*
  Functions
*/
void canSend(){
  uint32_t courentTime = millis();
  if(courentTime - lastTime > 10){
    //10 ms interval
    canSendIgnitionFrame();
    canSendRPM();
    canSendSpeed();
    canSendSteeringWheel();

    if(canCounter % 10 == 0){ //200 ms interval
      canSendLights();
      canSendIndicator(); // internal 600ms timer
      canSendAbs();
      canSendEngineTemp();
      canSendAbsCounter();
      canSendAirbagCounter();

      canSendFuel();
    }

    if(canCounter % 50 == 0){ //500 ms interval
      canSendHandbrake();
    }

    if(canCounter % 100 == 0){ //1000 ms interval
      canSendTime();
    }

    canCounter++;
    lastTime = courentTime;
  }
}
