/**
 *   @brief Measures temperature with PT1000
 *   @description Convert the Analog value of the output
 *   of the PT1000 temperature sensor.
 * 
 * 
 *   f(volt) = 81.0514 * x - 23.9047
 *   m               = 81.0514          +/- 0.07569      (0.09338%)
 *   q               = -23.9047         +/- 0.07453      (0.3118%)
 * 
 * 
 *   @author jmgomez
 */

const int analogInPin = A0;  // ESP8266 Analog Pin ADC0 = A0

int sensorValue = 0;  // value read from the pot
int outputValue = 0;

float vt_factor = 1.88;
float offset = 0;
float CoefA = 23.9047;
float CoefX = 81.0514;

void setup() {
  // initialize serial communication at 115200
  Serial.begin(115200);
}

void loop() {
  // read the analog in value
  sensorValue = analogRead(analogInPin);
 
  float voltajeValue = sensorValue*(3.3 / 1023.0);
  float temp_inter = CoefX*voltajeValue - CoefA;
  
// print the results to the Serial Monitor:
  Serial.print("Temp Interpolado Lineal= ");
  Serial.print(temp_inter);
  Serial.print("\tVoltaje = ");
  Serial.print(voltajeValue);
  Serial.print("\tADC sensor = ");
  Serial.println(sensorValue);
  
  delay(1000);
}
