// Interpolator.h
#ifndef Interpolator_h
#define Interpolator_h

#include "Arduino.h"

class Interpolator {
public:
    Interpolator(int* xValues, int* yValues, int numPoints) 
    : xValues(xValues), yValues(yValues), numPoints(numPoints) {}

    int interpolate(int x) {
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

    int findNearestLowerIndex(int value) {
        int index = 0;
        for (int i = 0; i < numPoints - 1; i++) {
            if (xValues[i + 1] > value) {
                index = i;
                break;
            }
        }
        return index;
    }
};

#endif
