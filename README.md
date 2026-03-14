# *FSR Force Estimation with Linear Interpolation*

This function utilizes known values from the manufacturer manual to approximate the $\color{red}{\text{Force-Voltage}}$ curve. By using linear interpolation to estimate values between data points, we eliminate the need for complex logarithmic calculations.

Implementation: The sensor integration follows the methodology described in:
"Design and Implementation of a Low-Cost Foot Pressure Sensor for Lower-Limb Exoskeletons: The Case of HERMES EXO"

# *System Specifications*

Input: Double representing the voltage from the FSR sensor.
Output: Force reading from 0 to 10,000 (representing a range of 0kg to 10kg).

# *Function Specifications*

Two functions have been implemented: 

Firstly, the $\color{blue}{\text{interpolate\_vol\_to\_grams}}$, function with input a double variable that describes the voltage and returns the corresponding pressure in grams. This function is in the $\color{red}{\text{read\_fsr.cpp}}$, file and is instantiated through the header file in the include folder.

Also, the $\color{green}{\text{Read\_FSR}}$, function in $\color{red}{\text{main.cpp}}$, which takes the pin that samples the FSR as input and outputs the result of the interpolation function. 

The main function is an example that reads the values of two FSR sensors and adds the results to calculate a total weight.