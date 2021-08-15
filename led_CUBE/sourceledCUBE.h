
#define G1 3
#define G2 6
#define G3 9
#define GND3 2 
#define GND2 4 
#define GND1 5 
#define GND6 7 
#define GND5 8
#define GND4 10
#define GND9 11 
#define GND8 12
#define GND7 A0 
int c=225;
 int i=0;
int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by
// the power pins
bool brightval;
int t;
int ledpins[] = {
2,3,4,5,6,7,8,9,10,11,12

};
void init_ledCube (int ledcount=11) {
  Serial.begin(9600);
  for (int thispin = 0; thispin < ledcount; thispin++) {
    pinMode(ledpins[thispin], OUTPUT);
    pinMode(A0, OUTPUT);

    
    digitalWrite(ledpins[thispin],1);
Serial.println(ledpins[thispin]);
  }
  
}

void enable_front_phase(){
 digitalWrite(G1,1); 

  }
void enable_mid_phase(){
 digitalWrite(G2,1); 
  
  }

void enable_back_phase(){
 digitalWrite(G3,1); 
 
  }  
void disable_front_phase(){
 digitalWrite(G1,0); 

  }
void disable_mid_phase(){
 digitalWrite(G2,0); 
  
  }

void disable_back_phase(){
 digitalWrite(G3,0); 
 
  } 
void blinkLed(int RowName,int timeDelay){
digitalWrite(RowName,0); 
delay(timeDelay);
digitalWrite(RowName,1); 
delay(timeDelay);
  }
void OnLed(int RowName){
digitalWrite(RowName,0); 
  }  
void OffLed(int RowName){
digitalWrite(RowName,1); 
  } 
void checkAllLed(int i){
enable_front_phase();
blinkLed(GND3,i);
blinkLed(GND2,i);
blinkLed(GND1,i);
blinkLed(GND6,i);
blinkLed(GND5,i);
blinkLed(GND4,i);
blinkLed(GND9,i);
blinkLed(GND8,i);
blinkLed(GND7,i);
disable_front_phase();
enable_mid_phase();
blinkLed(GND3,i);
blinkLed(GND2,i);
blinkLed(GND1,i);
blinkLed(GND6,i);
blinkLed(GND5,i);
blinkLed(GND4,i);
blinkLed(GND9,i);
blinkLed(GND8,i);
blinkLed(GND7,i);
disable_mid_phase();
enable_back_phase();
blinkLed(GND3,i);
blinkLed(GND2,i);
blinkLed(GND1,i);
blinkLed(GND6,i);
blinkLed(GND5,i);
blinkLed(GND4,i);
blinkLed(GND9,i);
blinkLed(GND8,i);
blinkLed(GND7,i);
disable_back_phase();  
  }

 void effect1(int t){
enable_front_phase();
OnLed(GND3);
OnLed(GND2);
OnLed(GND1);
OnLed(GND6);
OnLed(GND5);
OnLed(GND4);
OnLed(GND9);
OnLed(GND8);
OnLed(GND7);
delay(t);
disable_front_phase();
enable_mid_phase();
OnLed(GND3);
OnLed(GND2);
OnLed(GND1);
OnLed(GND6);
OnLed(GND5);
OnLed(GND4);
OnLed(GND9);
OnLed(GND8);
OnLed(GND7);
delay(t);
disable_mid_phase();
enable_back_phase();
OnLed(GND3);
OnLed(GND2);
OnLed(GND1);
OnLed(GND6);
OnLed(GND5);
OnLed(GND4);
OnLed(GND9);
OnLed(GND8);
OnLed(GND7);
delay(t);
disable_back_phase();
disable_mid_phase();
disable_front_phase();
  }

 void effect2(int t){

enable_front_phase();
enable_mid_phase();
enable_back_phase();
OnLed(GND3);
OnLed(GND2);
OnLed(GND1);
delay(t);
OffLed(GND3);
OffLed(GND2);
OffLed(GND1);
OnLed(GND6);
OnLed(GND5);
OnLed(GND4);
delay(t);
OnLed(GND9);
OnLed(GND8);
OnLed(GND7);
OffLed(GND6);
OffLed(GND5);
OffLed(GND4);
delay(t);
OffLed(GND9);
OffLed(GND8);
OffLed(GND7);
delay(t);
OffLed(GND9);
OffLed(GND8);
OffLed(GND7);
OffLed(GND3);
OffLed(GND2);
OffLed(GND1);
OffLed(GND6);
OffLed(GND5);
OffLed(GND4);
  } 
void effect3(int t){ 
  i=0;
while(i<=510){  
OnLed(GND3);
OnLed(GND2);
OnLed(GND1);
OnLed(GND6);
OnLed(GND5);
OnLed(GND4);
OnLed(GND9);
OnLed(GND8);
OnLed(GND7);
i=i+1;
 analogWrite(3, brightness);
  analogWrite(6, brightness);
   analogWrite(9, brightness);
  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
  // wait for 10 milliseconds to see the dimming effect
  delay(t);
}
   }
   
