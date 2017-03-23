

int ledPin = 12; // D7
int ledPin2 = 11; //D6
int ledPin3 = 10; //D0
int ledPin4 = 9; //D8
int ledPin5 = 8; //D5
int ledPin6 = 7;  //D1

void setup() {
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

  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  controlLED();
   Serial.println(digitalRead(A5));
   delay(2000);
   }

void controlLED(){
if(digitalRead(A0)==HIGH)
   {
    digitalWrite(ledPin, HIGH);
   }
   if(digitalRead(A0)==LOW)
   {
    digitalWrite(ledPin, LOW);
   }
     if(digitalRead(A1)==HIGH)
   {
    digitalWrite(ledPin2, HIGH);
   }
  
     if(digitalRead(A1)==LOW)
   {
    digitalWrite(ledPin2, LOW);
   }

    if(digitalRead(A2)==HIGH)
   {
    digitalWrite(ledPin3, HIGH);
   }
  
     if(digitalRead(A2)==LOW)
   {
    digitalWrite(ledPin3, LOW);
   }

    if(digitalRead(A3)==HIGH)
   {
    digitalWrite(ledPin4, HIGH);
   }
  
     if(digitalRead(A3)==LOW)
   {
    digitalWrite(ledPin4, LOW);
   }

    if(digitalRead(A4)==HIGH)
   {
    digitalWrite(ledPin5, HIGH);
   }
  
     if(digitalRead(A4)==LOW)
   {
    digitalWrite(ledPin5, LOW);
   }

    if(digitalRead(A5)==HIGH)
   {
    digitalWrite(ledPin6, HIGH);
   }
  
     if(digitalRead(A5)==LOW)
   {
    digitalWrite(ledPin6, LOW);
   }
   

}

