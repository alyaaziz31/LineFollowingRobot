//code adapted from https://learn.adafruit.com/photocells/using-a-photocell

int leftphotocellPin = 0;    //the left photocell is plugged into a0
int leftphotocellReading;    
int rightphotocellPin = 1;   //the right photocell is plugged into a1
int rightphotocellReading;   

void setup(void) {
  Serial.begin(9600);
}

void loop(void) {
 leftphotocellReading = analogRead(leftphotocellPin);
 rightphotocellReading = analogRead(rightphotocellPin);
 
 Serial.print("left analog reading = ");   //prints "left analog reading" on the Serial Monitor 
 Serial.print(leftphotocellReading);       //prints the reading from the left photocell on the Serial Monitor
 
 if (leftphotocellReading < 140) {           //readings from the left photocell will appear on the Serial Monitor
  Serial.println(" - Black");
 } else if (leftphotocellReading > 140) {
  Serial.println(" - White");
 } else {
  Serial.println();
 }

 Serial.print("right analog reading = ");   //readings from the right photocell will appear on the Serial Monitor
 Serial.print(rightphotocellReading);

 if (rightphotocellReading < 160) {
  Serial.println(" - Black");
 } else if (rightphotocellReading > 160) {
  Serial.println(" – White");
 } else {
  Serial.println();
 }
 delay(1000);
}



