/*
  @author jmgomez
  @brief Sense the value of temperature using a PT1000.
  @description pt1000 device resistence varies with the temperature, 
  the ouput of the RTD is amplfied following the proposal [1]

  The output is approximated by a linear equation extracted from the 
  simulation data. 
 
  gnuplot> f(x) = m * x + q
  gnuplot> fit f(x) 'sim_pt1000_oamp.dat' using 2:0 via m, q
    Final set of parameters            Asymptotic Standard Error
    =======================            ==========================
    m               = 53.5077          +/- 0.04997      (0.09338%)
    q               = -24.9047         +/- 0.07453      (0.2992%)

  y= y1 + (y2-y1)/(x2-x1)*(x-x1)

  Temp   |  Res    | ADC
    0º   | 1000    | 188
    20   | 1078    | 281
    50   | 1194    | 421
    100  | 1365    |

    y = 53.5077*x - 24.9047


  [1] [https://www.aeq-web.com/pt1000-temperature-sensor-arduino-lm358-messwandler/?lang=en]

*/

int sensorPin = A0;

int ledPin = 13;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor
int outputValue = 0;

float vt_factor = 1.88;
float offset = 0;
float CoefA = 24.9047;
float CoefX = 53.5077;

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  
}

void loop() {
  digitalWrite(ledPin, HIGH);
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  // Convert to voltage
  float voltajeValue = sensorValue*(5.0 / 1023.0);
  
  // Transference function using interpolated coef
  float temp_inter = CoefX*voltajeValue - CoefA;
  
// print the results to the Serial Monitor:
  Serial.print("Temp Interpolado Lineal= ");
  Serial.print(temp_inter);
  Serial.print("\tVoltaje  Value= ");
  Serial.print(voltajeValue);
  Serial.print("\tADC sensor = ");
  Serial.println(sensorValue);
  
  digitalWrite(ledPin, LOW);

  
  delay(5);
}
