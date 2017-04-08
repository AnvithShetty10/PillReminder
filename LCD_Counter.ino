

/*
  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
 */

//Flashing LED on Arduino board
#define LEDPin 13

int lcdPin = 9 ;

const int trigPin = 7;
const int echoPin = 6;

// include the library code:
#include <LiquidCrystal.h>
#include<Servo.h>

Servo myservo;
int pos=0;

int rotateFlag=1;

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


//Functions to find duration to reach object and come back to ultrasonic sensor
float trigger() {
     float duration;
     pinMode(trigPin, OUTPUT);
     digitalWrite(trigPin, LOW);
     delayMicroseconds(2);
     digitalWrite(trigPin, HIGH);
     delayMicroseconds(10);
     digitalWrite(trigPin, LOW);
     pinMode(echoPin, INPUT);
     duration = pulseIn(echoPin, HIGH);
     return(duration);
}

/*
 * Servo motor is continuous rotation motor. 
 * It can rotate 360 degree
 * myservo.write(90) - 180 is the maximum anticlockwise speed
 * myservo.write(90) - 0 is the maximum clockwise speed
 * myservo.write(90) - no rotation
 */
void setup() {

  myservo.attach(8);
  myservo.write(90);  //no rotation

  pinMode(lcdPin,INPUT_PULLUP);
  digitalWrite(lcdPin,LOW);

  pinMode(LEDPin,OUTPUT);
  digitalWrite(LEDPin,HIGH);
  
  pinMode(A0,INPUT_PULLUP);
  digitalWrite(A0,LOW);
  pinMode(A1,INPUT_PULLUP);
  digitalWrite(A1,LOW);
  pinMode(A2,INPUT_PULLUP);
  digitalWrite(A2,LOW);
  pinMode(A3,INPUT_PULLUP);
  digitalWrite(A3,LOW);
  pinMode(A4,INPUT_PULLUP);
  digitalWrite(A4,LOW);
  pinMode(A5,INPUT_PULLUP);
  digitalWrite(A5,LOW);
  
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Hello World!");
  delay(3000);
  
  Serial.begin(9600);
}

int C[]={10,15,8,12,20,9};  //set initial number of tablets
int i;
void loop()
{lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("1--2--3--4--5--6");
  
  lcd.setCursor(0,1);
  for(i=0;i<=5;i++){      //display corresponding number of tablets
    lcd.print(C[i]);
    lcd.print("-");  
  }
  delay(500);
  if(digitalRead(lcdPin)==1){     //if box is open and LEDs are on
    rotateFlag=0;
    changeLCD();
    digitalWrite(lcdPin,LOW); 
  } 

  long duration, inches, cm;
     duration = trigger();
     inches = duration / 74 / 2;
     Serial.println(inches);

     
  if(inches<5 && rotateFlag==1){
        myservo.write(80);    //opens the box
    }

  else if(rotateFlag==0 && inches<5){
    myservo.write(110);       //closes the box
  }

  else if(inches>5){
    myservo.write(90);
  }

  //Flag after closing box needs to be changed.
        
}

//function to change the counter of each box
void changeLCD(){
  if(digitalRead(A0)==HIGH){
    C[0]=C[0]-1;
  }
  if(digitalRead(A1)==HIGH){
    C[1]=C[1]-1;
  }
  if(digitalRead(A2)==HIGH){
    C[2]=C[2]-1;
  }
  if(digitalRead(A3)==HIGH){
    C[3]=C[3]-1;
  }
  if(digitalRead(A4)==HIGH){
    C[4]=C[4]-1;
    Serial.println(C[4]);
  }
  if(digitalRead(A5)==HIGH){
    C[5]=C[5]-1;
  }
  delay(3000);
}

