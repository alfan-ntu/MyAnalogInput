/*
  Analog Input
 Demonstrates analog input by reading an analog sensor on analog pin 0 and
 turning on and off a light emitting diode(LED)  connected to digital pin 13.
 The amount of time the LED will be on and off depends on
 the value obtained by analogRead().

 The circuit:
 * Potentiometer attached to analog input 0
 * center pin of the potentiometer to the analog pin
 * one side pin (either one) to ground
 * the other side pin to +5V
 * LED anode (long leg) attached to digital output 13
 * LED cathode (short leg) attached to ground

 * Note: because most Arduinos have a built-in LED attached
 to pin 13 on the board, the LED is optional.


 Created by David Cuartielles
 modified 30 Aug 2011
 By Tom Igoe

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/AnalogInput

 */
/*
 * Al modified Arduino example project "AnalogInput" to read value from a photodiode analog output
 * Date : 2017/8/10
 */
int sensorPin = A0;    // select the input pin for the potentiometer
int ledPin = 13;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor
int limit=500;        // sensor threshold value
int pollingInterval=100;     // polling interval of the sensor reading

void setup() {
// declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  Serial.begin(9600);
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);
  // toggle LED as an operation indicator
  digitalWrite(ledPin, !digitalRead(ledPin));
  if(sensorValue <= limit){
    digitalWrite(ledPin, HIGH);
  } else if (sensorValue > limit){
    digitalWrite(ledPin, LOW);
  }
  
  delay(pollingInterval);
}
