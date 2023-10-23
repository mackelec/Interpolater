# Interpolator for Arduino

The `Interpolator` class provides a convenient way to perform linear interpolation based on given x and y value sets. It's particularly useful for Arduino projects where you need to map a set of input values (like sensor readings) to another set of values.

## Features:

- **Linear Interpolation**: Calculates an interpolated y-value for a given x-value based on provided data points.
- **Dynamic Data Points**: Can be used with any number of data points.
- **Lightweight**: Designed specifically for resource-constrained environments like Arduino.

## How to Use:

1. **Include the Interpolator class**:
   ```
   #include "Interpolator.h"
   ```

2. **Define your data points**: Prepare two arrays of integers for x-values and y-values. Both arrays should have the same length.
   ```
   int throttleValues[] = {0, 50, 100};
   int torqueValues[] = {0, 70, 130};
   ```

3. **Create an instance of the Interpolator class**: Initialize it with your x-values, y-values, and the number of data points.
   ```
   int numDataPoints = sizeof(throttleValues) / sizeof(throttleValues[0]);
   Interpolator interpolator(throttleValues, torqueValues, numDataPoints);
   ```

4. **Get interpolated values**: Call the `interpolate` method with an x-value to get the interpolated y-value.
   ```
   int interpolatedValue = interpolator.interpolate(75);
   ```

## Example:

Here's a complete example of using the Interpolator class with an analog throttle sensor:

```
#include "Interpolator.h"

int throttleValues[] = {0, 50, 100};
int torqueValues[] = {0, 70, 130};
int numDataPoints = sizeof(throttleValues) / sizeof(throttleValues[0]);

Interpolator interpolator(throttleValues, torqueValues, numDataPoints);
int analogThrottlePin = A0;

void setup() {
   Serial.begin(9600);
}

void loop() {
   int throttleReading = analogRead(analogThrottlePin);
   int interpolatedValue = interpolator.interpolate(throttleReading);

   Serial.print("Input: ");
   Serial.println(throttleReading);
   Serial.print("Interpolated Output: ");
   Serial.println(interpolatedValue);

   delay(1000);
}
```

