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
