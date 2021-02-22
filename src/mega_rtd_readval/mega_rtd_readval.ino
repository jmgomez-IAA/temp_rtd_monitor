/*
  @author jmgomez
  @brief Sense the value of temperature using a PT1000.
  @description pt1000 device resistence varies with the temperature, 
  when we excitate the device with a constant voltaje the resistance 
  of the PT1000 is 

  RRTD =  (VADCin * Rref)/(Vref - VADCin)  [1]


  RTD to Temperature Conversion
  ==
  The fasted approximation is to use a look-up table (rtd_resistence).

  The most accurate version is to resolve the equation of the temperature
  and generate the custom look-up table. 
  For a platinum RTD, the Callendar-Van Dusen equation describes the 
  relationship between resistance and temperature as: 

  R(t) = R0 × (1 + A × t +B × t2 + (t - 100) × C × t3)

  R(t) = RTD resistance
  t = temperature
  R0 = resistance of the RTD at 0°C
  A = 3.908 × 10-3
  B = -5.775 × 10-7
  C = -4.183 × 10-12 when t < 0°C
  C = 0 when t > 0°C
  
  t = -1.6030e -13 × r6 + 2.0936e -10 × r5 -3.6239e -8 × r4 -4.2504e -6 × r3 + 2.5646e -3 × r2 + 2.2233 × r -2.4204e2


  [1] https://www.maximintegrated.com/en/design/technical-documents/app-notes/6/6262.html

  We are using the standard table and interpolate the value between grades.

*/

constexpr float rtd_resistence[] = {
    1000.00, 1003.90, 1007.80, 1011.70 ,1015.60 ,1019.50 ,1023.40 ,1027.30 ,1031.20 ,1035.10,  //10
    1039.00 ,1042.90 ,1046.80 ,1050.70 ,1054.60 ,1058.50 ,1062.40 ,1066.30 ,1070.20 ,1074.00, //20 
    1077.90 ,1081.80 ,1085.70 ,1089.60 ,1093.50 ,1097.30 ,1101.20 ,1105.10 ,1109.00 ,1112.90, //30
    1116.70 ,1120.60 ,1124.50 ,1128.30 ,1132.20 ,1136.10 ,1140.00 ,1143.80 ,1147.70 ,1151.50, //40
    1155.40 ,1159.30 ,1163.10 ,1167.00 ,1170.80 ,1174.70 ,1178.60 ,1182.40 ,1186.30 ,1190.10, //50
    1194.00 ,1197.80 ,1201.70 ,1205.50 ,1209.40 ,1213.20 ,1217.10 ,1220.90 ,1224.70 ,1228.60, //60
    1232.40 ,1236.30 ,1240.10 ,1243.90 ,1247.80 ,1251.60 ,1255.40 ,1259.30 ,1263.10 ,1266.90, //70
    1270.80 ,1274.60 ,1278.40 ,1282.20 ,1286.10 ,1289.90 ,1293.70 ,1297.50 ,1301.30 ,1305.20, // 80
    1309.00 ,1312.80 ,1316.60 ,1320.40 ,1324.20 ,1328.00 ,1331.80 ,1335.70 ,1339.50 ,1343.30, // 90
    1347.10 ,1350.90 ,1354.70 ,1358.50 ,1362.30 ,1366.10 ,1369.90 ,1373.70 ,1377.50 ,1381.30 // 100
};


int sensorPin = A0;    // select the input pin for the potentiometer
int ledPin = 13;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor
int outputValue = 0;

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);

  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  float voltajeValue = sensorValue*(5.0 / 1023.0);
  float res_val= (voltajeValue * 1120) / (5-voltajeValue);
  //

  int temp_aprox = 0;
  while( (temp_aprox < 100) && (rtd_resistence[temp_aprox] < res_val)) 
  {
    ++ temp_aprox;
  }

  // interpolate the temperature value

  float temp_inter =(temp_aprox-1)+((res_val - rtd_resistence[temp_aprox-1])/(rtd_resistence[temp_aprox]-rtd_resistence[temp_aprox-1]));
 

  
// print the results to the Serial Monitor:
  Serial.print("Temp = ");
  Serial.print(temp_aprox);
  Serial.print("Interpolado = ");
  Serial.print(temp_inter);
  Serial.print("ADC sensor = ");
  Serial.print(sensorValue);
  Serial.print("Resistencia: " );
  Serial.print(res_val);
  Serial.print("\tVoltaje  output = ");
  Serial.println(voltajeValue);
  
  // turn the ledPin on
  digitalWrite(ledPin, HIGH);
  // stop the program for <sensorValue> milliseconds:
  delay(sensorValue);
  // turn the ledPin off:
  digitalWrite(ledPin, LOW);
  // stop the program for for <sensorValue> milliseconds:
  delay(sensorValue);

  
  delay(5);
}
