/********************************************************************
 *ManualBlinkingLights.ino Manual Light Control File                *
 *Witten by Nicholas Maselli                                        *
 *                                                                  *
 *Purpose: This program pulses the relay coresponding to specific   *
 *manual time delay to the song Carol of Bells. Light syncs to      *
 *other songs can be created using a similar format.                *
 *                                                                  *
 *Version: 1.0                                                      *
 *Date: July 14th, 2017                                             *
 ********************************************************************/

/*Note delay is the tempo of the song in milliseconds*/
int noteDelay = 340;
int numberOfRelays = 8;
int relay[] = {2, 3, 4, 5, 6, 7, 8, 9};
boolean lights[] = {false, false, false, false, false, false, false, false};

void setup() {
  Serial.begin(9600);  
  for (int i = 0; i < numberOfRelays; i++) {
     digitalWrite(relay[i], HIGH);
     pinMode(relay[i], OUTPUT);
  }

  /*Type "start" (without quotes) into the serial input to begin in 7 seconds*/
  while(Serial.readString() != "start") {
  }
  delay(7000);
  song();
}

void loop() {
  
}

void rythme1() {
  lights[2] = true;
  blinkLights(lights);
  lights[2] = false;
  delay(noteDelay);
  
  lights[1] = true;
  blinkLights(lights);
  lights[1] = false;
  delay(noteDelay/2);

  lights[2] = true;
  blinkLights(lights);
  lights[2] = false;
  delay(noteDelay/2);
  
  lights[0] = true;
  blinkLights(lights);
  lights[0] = false;
  delay(noteDelay);  
}

void rythme2() {
  lights[6] = true;
  lights[7] = true;
  blinkLights(lights);
  lights[6] = false;
  lights[7] = false;
  delay(noteDelay);
  
  lights[4] = true;
  lights[5] = true;
  blinkLights(lights);
  lights[4] = false;
  lights[5] = false;
  delay(noteDelay/2);

  lights[6] = true;
  lights[7] = true;
  blinkLights(lights);
  lights[6] = false;
  lights[7] = false;
  delay(noteDelay/2); 
  
  lights[2] = true;
  lights[3] = true;
  blinkLights(lights);
  lights[2] = false;
  lights[3] = false;
  delay(noteDelay);
}

void rythme3() {
  lights[4] = true;
  lights[5] = true;
  blinkLights(lights);
  lights[4] = false;
  lights[5] = false;
  delay(noteDelay);
  
  lights[2] = true;
  lights[3] = true;
  blinkLights(lights);
  lights[2] = false;
  lights[3] = false;
  delay(noteDelay/2);

  lights[4] = true;
  lights[5] = true;
  blinkLights(lights);
  lights[4] = false;
  lights[5] = false;
  delay(noteDelay/2);
  
  lights[0] = true;
  lights[1] = true;
  blinkLights(lights);
  lights[0] = false;
  lights[1] = false;
  delay(noteDelay);  
}

void power1() {  

  lights[7] = true;
  blinkLights(lights);
  lights[7] = false;
  delay(noteDelay);

  blinkLights(lights);
  delay(noteDelay/2);
  
  lights[7] = true;
  blinkLights(lights);
  lights[7] = false;
  delay(noteDelay/2);

  lights[6] = true;
  blinkLights(lights);
  lights[6] = false;
  delay(noteDelay/2);

  blinkLights(lights);
  delay(noteDelay/2);

  /*****************/
  lights[5] = true;
  blinkLights(lights);
  lights[5] = false;
  delay(noteDelay);

  blinkLights(lights);
  delay(noteDelay/2);
  
  lights[5] = true;
  blinkLights(lights);
  lights[5] = false;
  delay(noteDelay/2);

  lights[4] = true;
  blinkLights(lights);
  lights[4] = false;
  delay(noteDelay/2);

  lights[3] = true;
  blinkLights(lights);
  lights[3] = false;
  delay(noteDelay/2);

  /*****************/
  lights[4] = true;
  blinkLights(lights);
  lights[4] = false;
  delay(noteDelay);

  blinkLights(lights);
  delay(noteDelay/2);
  
  lights[4] = true;
  blinkLights(lights);
  lights[4] = false;
  delay(noteDelay/2);

  lights[5] = true;
  blinkLights(lights);
  lights[5] = false;
  delay(noteDelay/2);

  lights[4] = true;
  blinkLights(lights);
  lights[4] = false;
  delay(noteDelay/2);
  
  /*****************/
  lights[2] = true;
  blinkLights(lights);
  lights[2] = false;
  delay(noteDelay);
  
  lights[1] = true;
  blinkLights(lights);
  lights[1] = false;
  delay(noteDelay/2);

  lights[2] = true;
  blinkLights(lights);
  lights[2] = false;
  delay(noteDelay/2);
  
  lights[0] = true;
  blinkLights(lights);
  lights[0] = false;
  delay(noteDelay);
}

void power2() {
  lights[0] = true;
  lights[1] = true;  
  blinkLights(lights);
  lights[0] = false;
  lights[1] = false;  
  delay(noteDelay/2);

  lights[1] = true;
  lights[2] = true;  
  blinkLights(lights);
  lights[1] = false;
  lights[2] = false;  
  delay(noteDelay/2);

  lights[2] = true;
  lights[3] = true;  
  blinkLights(lights);
  lights[2] = false;
  lights[3] = false;  
  delay(noteDelay/2);

  lights[3] = true;
  lights[4] = true;  
  blinkLights(lights);
  lights[3] = false;
  lights[4] = false;  
  delay(noteDelay/2);
  
  lights[4] = true;
  lights[5] = true;  
  blinkLights(lights);
  lights[4] = false;
  lights[5] = false;  
  delay(noteDelay/2);

  lights[5] = true;
  lights[6] = true;  
  blinkLights(lights);
  lights[5] = false;
  lights[6] = false;  
  delay(noteDelay/2);

  lights[6] = true;
  lights[7] = true;  
  blinkLights(lights);
  lights[6] = false;
  lights[7] = false;  
  delay(noteDelay/2);
  
  lights[7] = true;  
  blinkLights(lights);
  lights[7] = false;
  delay(noteDelay/2);

  
  lights[2] = true;
  lights[3] = true;
  lights[4] = true;
  lights[5] = true;
  blinkLights(lights);
  lights[2] = false;
  lights[3] = false;
  lights[4] = false;
  lights[5] = false;
  delay(noteDelay);
  
  lights[0] = true;
  lights[1] = true;
  lights[2] = true;
  lights[3] = true;
  lights[4] = true;
  lights[5] = true;
  lights[6] = true;
  lights[7] = true;
  blinkLights(lights);
  lights[0] = false;
  lights[1] = false;
  lights[2] = false;
  lights[3] = false;
  lights[4] = false;
  lights[5] = false;
  lights[6] = false;
  lights[7] = false;
  delay(noteDelay);    
}

void full1() {
  lights[3] = true;
  lights[4] = true;
  blinkLights(lights);
  lights[3] = false;
  lights[4] = false;
  delay(noteDelay*3);  
  
  lights[2] = true;
  lights[3] = true;
  lights[4] = true;
  lights[5] = true;
  blinkLights(lights);
  lights[2] = false;
  lights[3] = false;
  lights[4] = false;
  lights[5] = false;
  delay(noteDelay*3);  
  
  lights[1] = true;
  lights[2] = true;
  lights[3] = true;
  lights[4] = true;
  lights[5] = true;
  lights[6] = true;
  blinkLights(lights);
  lights[1] = false;
  lights[2] = false;
  lights[3] = false;
  lights[4] = false;
  lights[5] = false;
  lights[6] = false;
  delay(noteDelay*3);  
  
  lights[0] = true;
  lights[1] = true;
  lights[2] = true;
  lights[3] = true;
  lights[4] = true;
  lights[5] = true;
  lights[6] = true;
  lights[7] = true;
  blinkLights(lights);
  lights[0] = false;
  lights[1] = false;
  lights[2] = false;
  lights[3] = false;
  lights[4] = false;
  lights[5] = false;
  lights[6] = false;
  lights[7] = false;
  delay(noteDelay*3);  
}

void final1() {
  lights[3] = true;
  lights[4] = true;
  lights[5] = true;
  blinkLights(lights);
  lights[3] = false;
  lights[4] = false;
  lights[5] = false;
  delay(noteDelay*3); 

  lights[0] = true;
  lights[1] = true;
  lights[2] = true;
  blinkLights(lights);
  lights[0] = false;
  lights[1] = false;
  lights[2] = false;
  delay(noteDelay*3); 

  lights[3] = true;
  lights[4] = true;
  lights[5] = true;
  blinkLights(lights);
  lights[3] = false;
  lights[4] = false;
  lights[5] = false;
  delay(noteDelay*3); 

  lights[5] = true;
  lights[6] = true;
  lights[7] = true;
  blinkLights(lights);
  lights[5] = false;
  lights[6] = false;
  lights[7] = false;
  delay(noteDelay*3); 
  
}

void final2() {
  delay(noteDelay*3); 
  lights[2] = true;
  lights[3] = true;
  lights[4] = true;
  lights[5] = true;
  blinkLights(lights);
  lights[2] = false;
  lights[3] = false;
  lights[4] = false;
  lights[5] = false;
  delay(noteDelay*9);

  lights[0] = true;
  lights[1] = true;
  lights[2] = true;
  lights[3] = true;
  lights[4] = true;
  lights[5] = true;
  lights[6] = true;
  lights[7] = true;
  blinkLights(lights);
  lights[0] = false;
  lights[1] = false;
  lights[2] = false;
  lights[3] = false;
  lights[4] = false;
  lights[5] = false;
  lights[6] = false;
  lights[7] = false;  
}

/*Blinks to the song Carol of Bells from the YouTube
  video https://www.youtube.com/watch?v=JZkvL0snS7w */
void song() {  
  for (int i = 0; i < 16; i++)  {
    rythme1();
  }
  
  for (int i = 0; i < 4; i++)  {
    rythme2();
  }
  
  power1();
  power2();
  power2();

  for (int i = 0; i < 24; i++) {
    rythme3();
  }

  for (int i = 0; i < 4; i++)  {
    rythme2();
  }
  
  power1();
  power2();
  power2();

  for (int i = 0; i < 8; i++) {
    rythme3();
  }

  full1();
  final1();
  final2();
}

/*Change the state of input lights*/
void blinkLights(boolean lights[]) {
  for (int i = 0; i < numberOfRelays; i++) {
    if (lights[i] == false) {
      digitalWrite(relay[i], HIGH);
      continue;
    }
    
    if (lights[i] == true) {
      digitalWrite(relay[i], LOW);
    }
  }
}
