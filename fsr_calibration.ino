int fsrPin = A0;   
int fsrData = 0;

const int numPoints = 1;  
int adcValues[numPoints]   = {0};
float forceValues[numPoints] = {0.0}; 

void setup() {
  Serial.begin(9600);
  pinMode(fsrPin, INPUT);
}

void loop() {
  fsrData = analogRead(fsrPin);

  float forceN = interpolateForce(fsrData);

  Serial.print("ADC = ");
  Serial.print(fsrData);
  Serial.print("\tForce (N) = ");
  Serial.println(forceN, 3);

  delay(500);
}

float interpolateForce(int adc) {
  if (adc <= adcValues[0]) return forceValues[0];

  if (adc >= adcValues[numPoints-1]) return forceValues[numPoints-1];

  for (int i = 0; i < numPoints-1; i++) {
    if (adc >= adcValues[i] && adc <= adcValues[i+1]) {
      float x0 = adcValues[i];
      float x1 = adcValues[i+1];
      float y0 = forceValues[i];
      float y1 = forceValues[i+1];

      return y0 + ( (adc - x0) * (y1 - y0) ) / (x1 - x0);
    }
  }
  return 0; 
}
