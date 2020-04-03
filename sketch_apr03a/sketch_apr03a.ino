const int sensorPin = A0;
const float baselineTemp = 20.0;

void setup() {
  Serial.begin(9600);
  for (int p = 2; p<5; p++)
  {
    pinMode(p, OUTPUT);
    digitalWrite(p, LOW);  
  }
}

void loop() {
  int s = analogRead(sensorPin);
  Serial.print("Sensor value:");
  Serial.print(s);
  float v = (s/1024)*5.0;
  Serial.print("Voltage: ");
  Serial.print(v);
  Serial.print( "degree C" );
  float temp = (v - 0.5) * 100;
  Serial.println(temp);
  if (temp< baselineTemp){
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
  else if(temp >= baselineTemp + 2 && temp < baselineTemp + 4){
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
  else if(temp >= baselineTemp + 4 && temp < baselineTemp + 6){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }
}
