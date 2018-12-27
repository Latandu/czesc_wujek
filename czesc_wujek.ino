u/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Blink
*/
#define KROPKA 200
#define KRESKA 4*KROPKA
#define PRZERWA KROPKA
#define SPACJA 6*KROPKA
#define DLUGA 10*KROPKA

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}
void sendmorsecode (int isdot) {
  switch (isdot){
    case 0 : {
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(KRESKA);                       //Przerwa
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
    delay(PRZERWA);
    }
    break;
    case 1 : {
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(KROPKA);                       //Przerwa
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
    delay(PRZERWA);
    }
    break; 
  }  
}
void sendmorsechar (unsigned char letter) { 
 switch (letter){
  case 'c' : {
     sendmorsecode (0); sendmorsecode (1); sendmorsecode (0); sendmorsecode (1);
    }
  break;

  case 'e' : {
      sendmorsecode (1); 
    }
  break;
  
  case 'j' : {
    sendmorsecode (1); sendmorsecode (0); sendmorsecode (0); sendmorsecode (0);
    }
  break;
  
  case 'k' : {
    sendmorsecode (0); sendmorsecode (1); sendmorsecode (0);
    }
  
  case 's' : {
    sendmorsecode (1); sendmorsecode (1); sendmorsecode (1);
    }
    
    case 'u' : {
     sendmorsecode (1); sendmorsecode (1); sendmorsecode (0);
    }
  break;
  
  case 'w' : {
    sendmorsecode (1); sendmorsecode (0); sendmorsecode (0);
    }
  break;
  
  case 'z' : {
    sendmorsecode (0); sendmorsecode (0); sendmorsecode (1); sendmorsecode (1);
  }
  break;
 }
}

void loop () { //petla
  sendmorsechar('c'); sendmorsechar('z'); sendmorsechar('e'); sendmorsechar ('s'); sendmorsechar ('c'); //CZESC
  
  delay(SPACJA);
  
  sendmorsechar('w'); sendmorsechar('u'); sendmorsechar('j'); sendmorsechar ('e'); sendmorsechar ('k'); //WUJEK
  
  delay(DLUGA);
  
  }
 //KONIEC
