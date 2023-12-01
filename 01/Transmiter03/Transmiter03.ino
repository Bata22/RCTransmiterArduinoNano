#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#define  ser A1
#define bru A0

RF24 radio(7, 8); // CE, CSN

const byte address[6] = "00001";
//boolean buttonState = 0;
int joy[2];
void setup() {
 //pinMode (4, INPUT);

  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}

void loop() {

   joy[0] =  map(analogRead(bru), 0, 1023, 0, 180);
   delay (1);
   joy[1] = map(analogRead(ser), 550, 1023, 0, 180);
   radio.write(&joy, sizeof(joy));


 
  delay(200);
}


//  const char text[] = "Dobar dan u kucu";
//  radio.write(&text, sizeof(text));



  //pinMode(button, INPUT); u setup


//   buttonState= digitalRead(button);
// 
// radio.write(&buttonState, sizeof(buttonState));

//   potValue = analogRead(A1);
//   int  potValue1 = constrain(potValue, 550, 1023);
//   potValue = map(potValue1, 550, 1023, 0, 180);
//   radio.write(&potValue, sizeof(potValue));
// 
  
