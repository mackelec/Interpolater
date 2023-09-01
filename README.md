# Interpolater
a simple arduino class to interpolate from a list of points


```
class Interpolator {
public:
  Interpolator(int* xValues, int* yValues) {
    this->xValues = xValues;
    this->yValues = yValues;
    this->numPoints = sizeof(xValues) / sizeof(xValues[0]);
  }

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

```


###  Example

```
class Interpolator {
public:
  Interpolator(int* xValues, int* yValues) {
    this->xValues = xValues;
    this->yValues = yValues;
    this->numPoints = sizeof(xValues) / sizeof(xValues[0]);
  }

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

int throttleValues[] = { /* Your x (throttle) values here */ };
int torqueValues[] = { /* Your y (torque) values here */ };

int analogThrottlePin = A0;
Interpolator interpolator(throttleValues, torqueValues);

void setup() {
  // Initialize Serial for debugging
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
