int a = 2;
int b = 3;
int c = 4;
int d = 5; 
int dsharp = 6;
int e = 7;
int f = 8;
int g = 9;
int gsharp = 10;
void setup() {
  // put your setup code here, to run once:
pinMode(test, INPUT);
Serial.begin(9600);
// yellow and light brown: high c -> C
// yellow and red: low c and high c same time -> D
// yellow and orange: f# and high c same time -> D#
// yellow and white: instrument 1/2 -> E
// yellow and black: instrumetn 3/4 -> F
// yellow and purple: instrument 5/6 -> G
// yellow and gray: keyboard pattern 1 & instrument 7/8 same time -> G#
// yellow and blue: instrument 7/8 > A
// yellow and green: instrument 9/10 -> B

}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println(digitalRead(test));
delay(100);
}
