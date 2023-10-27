#ifndef Interpolator_h
#define Interpolator_h

#include "Arduino.h"

class Interpolator
{
public:
  Interpolator(int* xValues, int* yValues, int numPoints) 
    : xValues(xValues), yValues(yValues), numPoints(numPoints)
  {}

  int interpolate(int x)
  {
    if (x <= xValues[0]) return yValues[0];  // Handle lower boundary
    if (x >= xValues[numPoints - 1]) return yValues[numPoints - 1];  // Handle upper boundary

    int index = findNearestLowerIndex(x);
    int lowerX = xValues[index];
    int upperX = xValues[index + 1];
    int lowerY = yValues[index];
    int upperY = yValues[index + 1];

    return map(x, lowerX, upperX, lowerY, upperY);
  }

private:
  int* xValues;
  int* yValues;
  int numPoints;

  int findNearestLowerIndex(int value)
  {
    for (int i = 0; i < numPoints - 1; i++)
    {
      if (xValues[i + 1] > value)
      {
        return i;
      }
    }
    return numPoints - 2;  // Default to the second last index, but it should not reach this due to the boundary checks in `interpolate`
  }
};

#endif
