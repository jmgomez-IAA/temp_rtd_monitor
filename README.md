# RTD_to_Digital_converter
Read temperature values from an RTD

The project is intended to be included in the FreqUent SenSor PrOjecT (FUSSPOT).

## PT100 vs. PT1000

The primary difference between the two types is the internal resistance. The PT100 has exactly 100 ohms at 0 degrees Celsius, while the PT1000 has exactly 1000 ohms at 0 degrees Celsius. Although both sensors are quite accurate, there are some differences and also criteria by which the appropriate type is chosen.

### PT100
The calculation of a PT100 is more complex than that of a PT1000, because the resistance only changes by a factor of 1/10 compared to the PT1000. For the evaluation unit, this means that the voltage difference is much smaller. Disturbing influences such as the line resistance or the measuring current passing through the PT100 have a much more massive effect as with the PT1000. Nevertheless, there are reasons why the PT100 is used, such as the larger measuring range. If temperatures of more than 200 degrees Celsius occur in the measuring range, the PT100 is definitely the better choice, since mostly the temperature with a resolution of one degree is sufficient even in such large measuring ranges.

### PT1000
The PT1000 has a much higher resolution than the PT100. At 20 degrees Celsius, this sensor already has a resistance of almost 1078 ohms. Compared to the PT100, this would only have 107.8 ohms, which would only make a difference of 7 ohms at 20 degrees Celsius. With a simple voltage divider and a R2 of 10 kiloohm, one could already recognize the temperature change at the second decimal place at 5 volt voltage, which would not be possible with a PT100 without amplification. In addition, also due to the higher internal resistance, the measuring current is much lower and the line resistance through the test leads is less disturbing.
In general, the PT1000 is more suitable than the PT100 for small measuring ranges (-40 to +200 °C).

## Designs

0 .-  Voltage dividir with Arduino ADCs. A Pull-Up resistor fixes the current through the PT1000, and a 10kOhm voltage divider allows the Arduino ADC to read the value of the resistor.
  
1 .- High precission discrete design. The  discrete  design  requires  a  precision  amplifier  and  current  source.

2 .- The integrated system approach uses MAX31865  RTD-to-digital  converter. This  device  is  well  suited for high-precision applications by providing a 0.03125°C resolution across a -200°C to +850°C temperature range, with a 0.5°C level of accuracy.

## Transference equation
For a platinum RTD, [the Callendar-Van Dusen equation](https://www.maximintegrated.com/en/design/technical-documents/app-notes/6/6262.html) describes the relationship between resistance and temperature as:

R(t) = R0 × (1 + A × t +B × t2 + (t - 100) × C × t3),

where

R(t) = RTD resistance
t = temperature
R0 = resistance of the RTD at 0°C
A = 3.908 × 10-3
B = -5.775 × 10-7
C = -4.183 × 10-12 when t < 0°C
C = 0 when t > 0°C

The solution is to use: 
1.- Aproximmation

2.- Look-up tables

## Distributor

| Distributor |    ref-number   |  price | Items minimos | plazo dias | 
| ----------- | --------------- |  ----- | ------------- | ---------- |
| digikey     | MAX31865AAP+-ND | €4,23  | 1             |    0 + 3   |
| rs-online   |     190-1435    | 5,25 € | 5             |   3 + 1    |

## Resources

[Maxim TN: Achieve High-Accuracy Temperature Measurement in Your Precision Designs ](https://www.maximintegrated.com/content/dam/files/design/technical-documents/design-solutions/ds67-achieve-high-accuracy-temperature-measurement-in-your-precision-designs.pdf)

[ APPLICATION NOTE 6262 RTD Measurement System Design Essentials](https://www.maximintegrated.com/en/design/technical-documents/app-notes/6/6262.html)
[MAX31865 Datasheet](https://www.maximintegrated.com/en/products/interface/sensor-interface/MAX31865.html])

[Symbolo y huella SnapEDA](https://www.snapeda.com/parts/MAX31865AAP+/Maxim%20Integrated/view-part/?ref=digikey)

[Basics from Adafruit: MAX31865 RTD PT100 or PT1000 Amplifier ](https://learn.adafruit.com/adafruit-max31865-rtd-pt100-amplifier)
An overview of the existing module from Adafruit 15€ 

[PT1000 Converter for Arduino](https://www.aeq-web.com/pt1000-temperature-sensor-arduino-lm358-messwandler/?lang=en) 
An explanation of a DIY amplifier based on a Operation Amplifier. 

[ESP32-MAX31865](https://github.com/jamieparkinson/ESP32-MAX31865)
A driver for the MAX31865 RTD-to-Digital converter, written using/for the esp-idf framework. Supports all documented features of the MAX31865 including fault detection and the DRDY output.

[SomeQ&A on Arduino forum](https://forum.arduino.cc/index.php?topic=629616.0)
Una consulta si voy a usar 5 MAX31865 en un arduino mega, los pines SPI son 53, 51 y 50  para CS, DI, DO y CLK respectivamente, se puede usar para CS el pin 22, 23, 24 y 25, ya que son el control switch?

