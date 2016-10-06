void setup() {
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  // put your setup code here, to run once:

}

void loop() {
  digitalWrite(11,HIGH);
  digitalWrite(10,HIGH);
  delay(1000);
  // put your main code here, to run repeatedly:
  digitalWrite(11,LOW);
  digitalWrite(10,LOW);
  delay(1000);
}
