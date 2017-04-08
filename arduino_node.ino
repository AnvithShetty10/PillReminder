

int ledPin = 12; // D7
int ledPin2 = 11; //D6
int ledPin3 = 10; //D0
int ledPin4 = 9; //D8
int ledPin5 = 8; //D5
int ledPin6 = 7;  //D1

int offPin=6;
int lcdPin=5;

const int trigPin = 2;
const int echoPin = 4;

const int buzzer = 3; //buzzer to arduino pin 3

int sound=0;
int buzzerFlag=0;
int LEDFlag=0;
int check=1;

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

void setup() {
  pinMode(buzzer, OUTPUT);
  
  // put your setup code here, to run once:
 pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  pinMode(ledPin2, OUTPUT);
  digitalWrite(ledPin2, LOW);
  pinMode(ledPin3, OUTPUT);
  digitalWrite(ledPin3, LOW);
  pinMode(ledPin4, OUTPUT);
  digitalWrite(ledPin4, LOW);
  pinMode(ledPin5, OUTPUT);
  digitalWrite(ledPin5, LOW);
  pinMode(ledPin6, OUTPUT);
  digitalWrite(ledPin6, LOW);

  pinMode(offPin,OUTPUT);
  digitalWrite(offPin,LOW);

  pinMode(lcdPin,OUTPUT);
  digitalWrite(lcdPin,LOW);

  pinMode(A0, INPUT_PULLUP);
  pinMode(A1, INPUT_PULLUP);
  pinMode(A2, INPUT_PULLUP);
  pinMode(A3, INPUT_PULLUP);
  pinMode(A4, INPUT_PULLUP);
  pinMode(A5, INPUT_PULLUP);
  digitalWrite(A0,LOW);
  digitalWrite(A1,LOW);
  digitalWrite(A2,LOW);
  digitalWrite(A3,LOW);
  digitalWrite(A4,LOW);
  digitalWrite(A5,LOW);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  controlLED();
   //Serial.println(digitalRead(A5));
   //delay(2000);
   long duration, inches, cm;
     duration = trigger();
     inches = duration / 74 / 2;
     
   if(digitalRead(A0) == HIGH || digitalRead(A1) == HIGH || digitalRead(A2) == HIGH || digitalRead(A3) == HIGH || digitalRead(A4) == HIGH || digitalRead(A5) == HIGH)
      {
        sound=1000;
        LEDFlag=1;
      }
   else{
    LEDFlag=0;
   }
    
     if(inches<=5 && LEDFlag==1)
          {
            //tone(buzzer, sound);
            buzzerFlag=1;
            digitalWrite(lcdPin,LOW);
            digitalWrite(offPin,LOW); 
            
          }
     else if(inches>5 && LEDFlag==1){
         noTone(buzzer);
         buzzerFlag=0;
         digitalWrite(lcdPin,HIGH);   //send signal to LCD_counter to change LCD values
         delay(1000); 
         digitalWrite(offPin,HIGH);   //send signal to mqtt code to off the LEDs     
        } 
}
  


//function to turn on LEDs based on message recieved by the nodeMCU
void controlLED(){
if(digitalRead(A0)==HIGH)
   {
    digitalWrite(ledPin, HIGH);  
   }
else{
  digitalWrite(ledPin, LOW);
}

     if(digitalRead(A1)==HIGH)
   {
    digitalWrite(ledPin2, HIGH);
   }
    else{
      digitalWrite(ledPin2, LOW);
    }

    if(digitalRead(A2)==HIGH)
   {
    digitalWrite(ledPin3, HIGH);
   }
   else{
       digitalWrite(ledPin3, LOW);
   }

    if(digitalRead(A3)==HIGH)
   {
    digitalWrite(ledPin4, HIGH);
   }
   else{
       digitalWrite(ledPin4, LOW);
   }


    if(digitalRead(A4)==HIGH)
   {
    digitalWrite(ledPin5, HIGH);
   }
   else{
       digitalWrite(ledPin5, LOW);
   }


    if(digitalRead(A5)==HIGH)
   {
    digitalWrite(ledPin6, HIGH);
   }
    else{
         digitalWrite(A5, LOW);
    }
}

