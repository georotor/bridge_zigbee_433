/*
  
  https://github.com/sui77/rc-switch/
  https://github.com/LSatan/SmartRC-CC1101-Driver-Lib

*/
#include <ELECHOUSE_CC1101_SRC_DRV.h>
#include <RCSwitch.h>

int pin = 4; // int for Receive pin.

RCSwitch mySwitch = RCSwitch();

void setup() {
  Serial.begin(9600);

  ELECHOUSE_cc1101.getCC1101();

  ELECHOUSE_cc1101.Init();
  ELECHOUSE_cc1101.setMHZ(433.92);

  mySwitch.enableReceive(pin);

  ELECHOUSE_cc1101.SetRx();
}

void loop() {
  if (mySwitch.available()){
    String code = String( mySwitch.getReceivedValue() );
    Serial.print( code );
    Serial.print( "\r" );

    delay(300);

    mySwitch.resetAvailable();
  }
}
