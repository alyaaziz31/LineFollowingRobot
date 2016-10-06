int motorAforward=4;
int motorAbackward=5;
int motorBforward=7;
int motorBbackward=6;
int PWMA=10;
int PWMB=11;


void setup() {
  // put your setup code here, to run once:
  pinMode(motorAforward, OUTPUT);
  pinMode(motorAbackward, OUTPUT);
  pinMode(motorBforward, OUTPUT);
  pinMode(motorBbackward, OUTPUT);
  pinMode(PWMA, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
    analogWrite(PWMA, 0-255);
  digitalWrite(motorAforward, HIGH);
  digitalWrite(motorBforward, HIGH);
  digitalWrite(motorAbackward, LOW);
  digitalWrite(motorBbackward, LOW);
  delay(1000);
  digitalWrite(motorAforward, LOW);
  digitalWrite(motorBforward, LOW);
  digitalWrite(motorAbackward, HIGH);
  digitalWrite(motorBbackward, HIGH);
  delay(1000);
  
}
