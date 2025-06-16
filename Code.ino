const int rainSensorPin = 7;
const int motor1Pin1 = 5;
const int motor1Pin2 = 6;
const int motor2Pin1 = 9;
const int motor2Pin2 = 10;
bool isRaining = false;

void setup() 
{
  pinMode(rainSensorPin, INPUT);
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
  int rainState = digitalRead(rainSensorPin);
  Serial.println(rainState);
  if (rainState == LOW && !isRaining) 
  {
    Serial.println("Rain detected, running motors forward.");
    runMotorsForward();
    isRaining = true;
  }
  else if (rainState == HIGH && isRaining) 
  {
    Serial.println("Rain stopped, running motors in reverse.");
    runMotorsReverse();
    isRaining = false;
  }
  delay(500);
}

void runMotorsForward() 
{
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
  delay(3000);
  stopMotors();
}

void runMotorsReverse() 
{
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
  delay(3000);
  stopMotors();
}

void stopMotors() 
{
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
}

