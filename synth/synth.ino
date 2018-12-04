#include <MozziGuts.h>
#include <AudioDelay.h>
#include <Sample.h>
#include <mozzi_midi.h>
#include <LowPassFilter.h>
#include <Oscil.h> // oscillator template
#include <tables/sin2048_int8.h> // wavetable holding a sin wave
#include <RollingAverage.h>
#include <ControlDelay.h>
#include <SoftwareSerial.h>
// MIDI OUT wire map
// yellow and light brown: high c -> C
// yellow and red: low c and high c same time -> D
// yellow and orange: f# and high c same time -> D#
// yellow and white: instrument 1/2 -> E
// yellow and black: instrument 3/4 -> F
// yellow and purple: instrument 5/6 -> G
// yellow and gray: keyboard pattern 1 & instrument 7/8 same time -> G#
// yellow and blue: instrument 7/8 > A
// yellow and green: instrument 9/10 -> B

// add a 2-way switch for choosing midi keyboard vs synth mode! 
// Synth BUTTON/SWITCH mode map

int a = 2;
int b = 3;
int c = 4;
int d = 5; 
int dsharp = 6;
int e = 7; 
int f = 8;
int g = 9;
int gsharp = 10;

int modeswitch = 11;

void setup() {
  // put your setup code here, to run once:
pinMode(a, INPUT);
pinMode(b, INPUT);
pinMode(c, INPUT);
pinMode(d, INPUT);
pinMode(dsharp, INPUT);
pinMode(e, INPUT);
pinMode(f, INPUT);
pinMode(g, INPUT);
pinMode(gsharp, INPUT);
pinMode(modeswitch, INPUT);

Serial.begin(9600);

}
 
void loop() {
  // put your main code here, to run repeatedly:
 bool a_read = digitalRead(a);
 bool b_read = digitalRead(b);
 bool c_read = digitalRead(c);
 bool d_read = digitalRead(d);
 bool dsharp_read = digitalRead(dsharp);
 bool e_read = digitalRead(e);
 bool f_read = digitalRead(f);
 bool g_read = digitalRead(g);
 bool gsharp_read = digitalRead(gsharp);
 int readlist[9] = {a_read, b_read, c_read, d_read, dsharp_read, e_read, f_read, g_read, gsharp_read};

 bool modeswitchread = digitalRead(modeswitch);
 if (modeswitchread == 1) { // Synth Mode
  if (a_read == 1) {
    
  }
  else {
    
  }
  if (a_read == 1) {
    
  }
  else {
    
  }
  if (a_read == 1) {
    
  }
  else {
    
  }
  if (a_read == 1) {
    
  }
  else {
    
  }
 }
 else { // MIDI Keyboard mode
    for (i, i < 10, i++) in readlist {
      if (i == 1) {
        // that note to midi
    }
  }
  
 }

}
