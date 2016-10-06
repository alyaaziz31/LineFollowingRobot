//MotorA
int PWMA = 10; //Speed control
int AIN1 = 5;  //Direction
int AIN2 = 4; //Direction

//MotorB
int PWMB = 11; //Speed control
int BIN1 = 6; //Direction
int BIN2 = 7; //Direction

//photocellReading
int leftphotocellPin = 0;    //the left photocell is plugged into a0
int leftphotocellReading;    
int rightphotocellPin = 1;   //the right photocell is plugged into a1
int rightphotocellReading; 

int leftThreshold = 140;
int rightThreshold = 170;


void setup(){
  pinMode(PWMA, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(leftphotocellPin, INPUT);
  pinMode(rightphotocellPin, INPUT);
  pinMode(8, OUTPUT);
  Serial.begin(9600);         //for the photocell readings

}

void loop() {
//readings from the photocell
 leftphotocellReading = analogRead(leftphotocellPin);
 rightphotocellReading = analogRead(rightphotocellPin);
 

 Serial.print("left analog reading = ");   
 Serial.print(leftphotocellReading);       //prints the reading from the left photocell on the Serial Monitor
 
 if (leftphotocellReading < leftThreshold) {           //readings from the left photocell will appear on the Serial Monitor
  //Serial.println(" - Black");
 } else if (leftphotocellReading > leftThreshold) {
  //Serial.println(" - White");
 } 
 
  Serial.print("  right analog reading = ");   //readings from the right photocell will appear on the Serial Monitor
  Serial.println(rightphotocellReading);

 if (rightphotocellReading < rightThreshold) {
  //Serial.println(" - Black");
 } else if (rightphotocellReading > rightThreshold) {
  //Serial.println(" – White");
 } delay(5);

//move(1, 40, 0);
//move(2, 40, 0);

 if (leftphotocellReading > leftThreshold && rightphotocellReading > rightThreshold) {     //if both photocells detect white, both motors will move forward 
  moveForward();
  //Serial.println("Forward");
  //delay(100);
 }

 if (leftphotocellReading > leftThreshold && rightphotocellReading < rightThreshold) {     //if the right photocell detects the black line, 
  //moveRight();
      move(1, 0, 1);
    move(2, 80, 0);
  //delay(450);
   //Serial.println("*Right");

 }

 if (leftphotocellReading < leftThreshold && rightphotocellReading > rightThreshold) {     //if the left photocell detects black
  moveLeft();
  //delay(300);
   //Serial.println("Left");
 }

 if (leftphotocellReading < leftThreshold && rightphotocellReading < rightThreshold) {     //if both photocells detect black, stop
  moveStop();
  //delay(3000);
  digitalWrite(8, HIGH);
  moveForward();
   Serial.println("Detected T");
 }
 
}


void move(int motor, int speed, int direction){    //code taken from http://bildr.org/2012/04/tb6612fng-arduino/
//Move specific motor at speed and direction
//motor: 0 for B 1 for A
//speed: 0 is off, and 255 is full speed
//direction: 0 clockwise (forward), 1 counter-clockwise (backward)


  boolean inPin1 = LOW;
  boolean inPin2 = HIGH;

  if(direction == 1){
    inPin1 = HIGH;
    inPin2 = LOW;
  }

  if(motor == 1){
    digitalWrite(AIN1, inPin1);
    digitalWrite(AIN2, inPin2);
    analogWrite(PWMA, speed);
  }else{
    digitalWrite(BIN1, inPin1);
    digitalWrite(BIN2, inPin2);
    analogWrite(PWMB, speed);
  }
}


void moveRight(){
    move(1, 0, 0);
    move(2, 45, 0);
}

void moveLeft(){
  move(1, 45, 0);
  move(2, 0, 0);

}

void moveForward() {
  move(1, 45, 0);
  move(2, 45, 0);
}

void moveStop() {
  move(1, 0, 0);
  move(2, 0, 0);
}




