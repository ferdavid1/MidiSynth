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
// A -> 
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
int oscfreq = 440;
SoftwareSerial midiSerial(2,3);
Oscil <2048, AUDIO_RATE> aSin(SIN2048_DATA);

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
midiSerial.begin(31250);

#define CONTROL_RATE 128
startMozzi(CONTROL_RATE);
aSin.setFreq(oscfreq);
}
 
void loop() {
  // put your main code here, to run repeatedly:
 int a_read = digitalRead(a);
 int b_read = digitalRead(b);
 int c_read = digitalRead(c);
 int d_read = digitalRead(d);
 int dsharp_read = digitalRead(dsharp);
 int e_read = digitalRead(e);
 int f_read = digitalRead(f);
 int g_read = digitalRead(g);
 int gsharp_read = digitalRead(gsharp);
 int readlist[9] = {a_read, b_read, c_read, d_read, dsharp_read, e_read, f_read, g_read, gsharp_read};
 int midilist[9] = {33, 35, 24, 26, 27, 28, 29, 31, 32};
 int modeswitchread = digitalRead(modeswitch);
 if (modeswitchread == 1) { // Synth Mode
  if (a_read == 1) { // increase oscillator frequency
   aSin.setFreq(oscfreq + 100);
   oscfreq = oscfreq + 100;
  }
  if (b_read == 1) { // descreate oscillator frequency
   aSin.setFreq(oscfreq - 100);
   oscfreq = oscfreq - 100;
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
//  if (audioTicks()%10000 != 0 ) {
//    pauseMozzi();
//    delay(1000);
//    startMozzi();
//  }
 }
 else { // MIDI Keyboard mode
    for (int i = 0; i < 10; i++) {
      if (readlist[i] == 1) {
        // to midi
        noteOn(0x90, midilist[i], 0x45);
    }
  }
 }
 audioHook();
}
 void updateControl(){
  // has to be included
 }
 int updateAudio(){
  return aSin.next();
 }
 void noteOn(byte cmd, byte data1, byte  data2) {
   midiSerial.write(cmd);
   midiSerial.write(data1);
   midiSerial.write(data2);
   Serial.println(data1);
}
