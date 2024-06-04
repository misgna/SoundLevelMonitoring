/*
Sound amplitude level

This sketch reads an amplitude to measure the sound level from SparkFun sound sensor.
It reads an analog pin and compares the result to a set threshold.
If the amplitude is greater than the threshold, it writes HIGH to 
the digital pin (the LED connected to the digital pin will blink).

The circuit:
- GND of the Sparkfun connected to ground
- VCC of the Sparkfun connected to 5v
- Envelope of the Sparkfun connected to A0
- LED + connected to digital pin 8
- LED - connected to ground

created 30 May 2024
by Haile Misgna
*/
// Output Pins
const int redPin_1 = 8;
const int redPin_2 = 7;
const int yellowPin = 6;

// Analog input
const int envelope = A0;

// Classroom sound level
const int minAvgRoomNoise = 10; // 30;
const int maxAvgRoomNoise = 20; //50;

// Time for the LED Pin
unsigned long startTimeStamp = 0;
unsigned long currentTimeStamp = 0;
unsigned int interval = 5000;

// Amplitude variable for storing the measured noise amount
int amplitude = 0;

void setup() {
  pinMode(envelope, INPUT);
  //pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void onLED(int pin_1, int pin_2) {
  digitalWrite(pin_1, HIGH);
  digitalWrite(pin_2, HIGH);   
}

void offLED(int pin_1, int pin_2, int pin_3) {
  digitalWrite(pin_1, LOW);
  digitalWrite(pin_2, LOW);
  digitalWrite(pin_3, LOW);
}
void loop() {
  // read the sensor and store it in amplitdue
  amplitude = analogRead(envelope);

  // if the amplitude is greater than the threshold
  if (amplitude >= minAvgRoomNoise && amplitude <= maxAvgRoomNoise) {
    onLED(yellowPin, redPin_2);   
  } else if (amplitude > maxAvgRoomNoise) {
    onLED(redPin_1, redPin_2);
  }
  else {
    offLED(yellowPin, redPin_1, redPin_2);
  }
  Serial.println(amplitude);
  delay(1000);
}
