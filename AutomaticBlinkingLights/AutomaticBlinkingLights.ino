/********************************************************************
 *AutomaticBlinkingLights.ino Automatic Light Control File          *
 *Witten by Nicholas Maselli                                        *
 *                                                                  *
 *Purpose: This program reads in analog microphone data and         *
 *pulses the relay coresponding to the sound frequency.             *
 *                                                                  *
 *Version: 1.0                                                      *
 *Date: July 14th, 2017                                             *
 ********************************************************************/

/* FHT default values*/ 
#define LOG_OUT 1 // use the log output function
#define FHT_N 256 // set to 256 point fht
#define OCTAVE 1
#define OCT_NORM 0

/*Delay sets the number of cycles between updates. Each cycle is
 around 3 milliseconds*/
#define DELAY 15
#define THRESHOLD 50

int numberOfRelays = 8;
int relay[] = {2, 3, 4, 5, 6, 7, 8, 9};
int  bias[] = {75, 70, 70, 100, 95, 60, 40, 30};

/*FHT.h library from http://wiki.openmusiclabs.com/wiki/ArduinoFHT */
#include <FHT.h> 

void setup() {
  /*Initialize Relay*/
  for (int i = 0; i < numberOfRelays; i++) {
     digitalWrite(relay[i], HIGH);
     pinMode(relay[i], OUTPUT);
  }
  
  /*Example code from FHT library*/
  Serial.begin(115200); // use the serial port
  TIMSK0 = 0; // turn off timer0 for lower jitter
  ADCSRA = 0xe5; // set the adc to free running mode
  ADMUX = 0x40; // use adc0
  DIDR0 = 0x01; // turn off the digital input for adc0
}

void loop() {

  int loopNum = 0;

  /*Example code from FHT library*/
  while(1) { // reduces jitter
    cli();  // UDRE interrupt slows this way down on arduino1.0
    for (int i = 0 ; i < FHT_N ; i++) { // save 256 samples
      while(!(ADCSRA & 0x10)); // wait for adc to be ready
      ADCSRA = 0xf5; // restart adc
      byte m = ADCL; // fetch adc data
      byte j = ADCH;
      int k = (j << 8) | m; // form into an int
      k -= 0x0200; // form into a signed int
      k <<= 6; // form into a 16b signed int
      fht_input[i] = k; // put real data into bins
    }
    fht_window(); // window the data for better frequency response
    fht_reorder(); // reorder the data before doing the fht
    fht_run(); // process the data in the fht
    fht_mag_octave(); // take the output of the fht
    sei();
  /*Example code ends*/

    //Loop to print frequency output and blink lights
    if (loopNum % DELAY == 0) {
      for (int i = 0; i < 8; ++i) {
        Serial.print(fht_oct_out[i] - bias[i]);
        Serial.print(" ");
      }
      Serial.println("");

      //Blink lights depending on frequency threshold
      for (int i = 0; i <numberOfRelays; i++) {
        blinkLights(i, fht_oct_out[i] - bias[i]);
      }
    }
    
    ++loopNum;
  }
}

/*Blinks given light strand if value is greater than the treshold*/
void blinkLights(int strand, int value) {
  if (value < 0) {
    value = 0;
  }

  //Determines wether or not to blink light strand
  if (value > THRESHOLD) {
    digitalWrite(relay[strand], LOW);
  } 
  else if (value < THRESHOLD) {
    digitalWrite(relay[strand], HIGH);     
  }
}
