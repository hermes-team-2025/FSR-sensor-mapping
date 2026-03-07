FSR Force Estimation with Linear Interpolation

This function utilizes known values from the manufacturer manual to approximate the Force-Voltage curve. By using linear interpolation to estimate values between data points, we eliminate the need for complex logarithmic calculations.

Implementation: The sensor integration follows the methodology described in:
"Design and Implementation of a Low-Cost Foot Pressure Sensor for Lower-Limb Exoskeletons: The Case of HERMES EXO"

System Specifications

Input: Pin number of the FSR (Force Sensitive Resistor) sensor.
Output: Force reading from 0 to 10,000 (representing a range of 0kg to 10kg).

Function Specifications

Two functions have been implemented: the interpolate function with input a double variable that describes the voltage and returns the corresponding pressure in grams,
and the Read_FSR, input the pin that samples the FSR, output the output of the interpolation function. These functions are in the read_fsr.cpp file and are instantiated through the header file in the inlude folder.

The main is an example that reads the values of two fsr sensors and add the results for a total weight.

