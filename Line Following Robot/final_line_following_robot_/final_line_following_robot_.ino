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

int leftThreshold = -1;
int rightThreshold = -1;


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

  delay(500);// put on white and read the white value
  //threshold is 0.8 of white value
  leftThreshold = analogRead(leftphotocellPin)*0.75;        //xander li told me that readings of black lines are approx 80% of white readings
  rightThreshold = analogRead(rightphotocellPin)*0.75;
  delay(500);
  
}

void loop(){
  int leftphotocellReading = analogRead(leftphotocellPin);
  int rightphotocellReading = analogRead(rightphotocellPin);
  Serial.print(leftphotocellReading);
  Serial.print("||");
  Serial.println(rightphotocellReading);

  if(leftphotocellReading < leftThreshold && rightphotocellReading < rightThreshold) {    
    moveForward();
    delay(300);
    moveStop();
    Serial.println("stop");  
    moveForward(); //if both photocells detect black, the robot stops then turns on an LED.                 
  }
  else if(rightphotocellReading < rightThreshold) {     
    moveRight(); 
  }
  else if(leftphotocellReading< leftThreshold) {
    moveLeft(); 
  }
  else{
    moveForward();
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
    move(2, 60, 0);    
}

void moveLeft(){
  move(1, 60, 0);
  move(2, 0, 0);

}

void moveForward() {
  move(1, 60, 0);
  move(2, 60, 0);
}

void moveStop() {
  move(1, 0, 0);
  move(2, 0, 0);
  digitalWrite(8, HIGH);
  delay(3000);
 
}




