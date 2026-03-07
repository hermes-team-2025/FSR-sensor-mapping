#include <Arduino.h>
#include "read_fsr.h"

// Linear Interpolation Function
double interpolate(double x) {
  double x_points[] = {
      0, 2060.2, 2479.5, 3666.7, 6669.9, 7228.5, 8381.2, 8974.6, 
      9498.8, 10162.6, 10547.1, 11036.8, 11491.4, 11877.1, 12122.4, 12228.5, 
      12474.6, 12651.9, 12792.8, 12934.9, 13042.6, 13045.4, 13188.0, 13295.2, 
      13402.5, 13474.2, 13504.1, 13452.1, 13513.5
  }; 
  double y_points[] = {
      0.0,    23.4,   30.7,   60.1,   83.5,   101.8,  133.6,  166.9, 
      220.6,  320.8,  410.3,  600.9,  850.6,  1355.1, 1658.9, 1962.6, 
      2476.6, 3224.3, 3598.1, 4299.1, 5093.5, 5934.6, 6775.7, 7523.4, 
      8224.3, 8785.0, 9439.3, 9976.6, 10000.0
  };
  
  const int numPoints = 29;

  // Boundary checks
  if (x <= x_points[0]) {
    return y_points[0];
  }
  if (x >= x_points[numPoints - 1]) {
    return y_points[numPoints - 1];
  }

  // Find the segment where the value maps
  for (int i = 0; i < numPoints - 1; i++) {
    //Find the points that define this segment 
    if (x >= x_points[i] && x <= x_points[i + 1]) {
      double x0 = x_points[i];
      double x1 = x_points[i + 1];
      double y0 = y_points[i];
      double y1 = y_points[i + 1];
      
      //Interpollation formula
      return y0 + (x - x0) * (y1 - y0) / (x1 - x0);
    }
  }
  return 0;
}

//This function takes the pin of the FSR sensor
//and returns the 
double Read_FSR(const int sensor_pin) {
  int rawADC = analogRead(sensor_pin);
  
  // double currentX = (rawADC * 3.3) / 4095.0;

  double currentX = (rawADC * 3.3);

  //double pressure = interpolate(currentX);

  return interpolate(currentX);
}