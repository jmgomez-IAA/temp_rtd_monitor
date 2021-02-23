# SPDX-FileCopyrightText: 2021 ladyada for Adafruit Industries
# SPDX-License-Identifier: MIT

import time
import board
import busio
import adafruit_ads1x15.ads1115 as ADS
from adafruit_ads1x15.analog_in import AnalogIn

# user UliEngineering to accurate calculate the Temperature from  Resistance.
from UliEngineering.Physics.RTD import pt1000_temperature

# Create the I2C bus
i2c = busio.I2C(board.SCL, board.SDA)

# Create the ADC object using the I2C bus
ads = ADS.ADS1115(i2c)
# you can specify an I2C adress instead of the default 0x48
# ads = ADS.ADS1115(i2c, address=0x49)

# Create single-ended input on channel 0
chan = AnalogIn(ads, ADS.P0)
ads.mode = ADS.Mode.CONTINUOUS
ads.gain =  2
# Create differential input between channel 0 and 1
# chan = AnalogIn(ads, ADS.P0, ADS.P1)

print("{:>5}\t{:>5}\t{:>5}\t{:>5}".format("raw", "v", "Ohm","ºC"))

while True:
    adc_bit = chan.value
    adc_ch0_voltage = chan.voltage
    pt1000_ch0_resistence = (adc_ch0_voltage * 1120)/ (3.3 - adc_ch0_voltage);
    pt1000_ch0_temperature = pt1000_temperature(pt1000_ch0_resistence)
    print("{:>5}\t{:>5.6f}\t{:>5.6f}\t{:>5.3f}".format(adc_bit, adc_ch0_voltage, pt1000_ch0_resistence,pt1000_ch0_temperature))
    time.sleep(1)



