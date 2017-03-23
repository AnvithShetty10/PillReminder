#include <TimeLib.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
 
const char* ssid = "Gunner";
const char* password = "anvith10";
 
int ledPin = 13; // GPIO13 PIN 13 - D7
int ledPin2 = 12; //D6
int ledPin3 = 16; //D0
int ledPin4 = 15; //D8
int ledPin5 = 14; //D5
int ledPin6 = 5;  //D1
WiFiServer server(301);
 
void setup() {
  Serial.begin(9600);
  delay(10);
 
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
 
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
 
  // Start the server
  server.begin();
  Serial.println("Server started");
 
  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");

 
}
 
void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
 
  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
 
  // Read the first line of the request
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
   
  // Match the request
  int value1 = LOW,value2=LOW,value3=LOW,value4=LOW,value5=LOW,value6=LOW;
  if (request.indexOf("/LED1=ON") != -1)  {
    digitalWrite(ledPin, HIGH);
    Serial.println("hey");
    value1 = HIGH;
  }
  if (request.indexOf("/LED1=OFF") != -1)  {
    digitalWrite(ledPin, LOW);
    value1 = LOW;
  }

 if (request.indexOf("/LED2=ON") != -1)  {
    digitalWrite(ledPin2, HIGH);
    value2 = HIGH;
  }

 if (request.indexOf("/LED2=OFF") != -1)  {
    digitalWrite(ledPin2, LOW);
    value2 = LOW;
  } 
  
   if (request.indexOf("/LED3=ON") != -1)  {
    digitalWrite(ledPin3, HIGH);
    value3 = HIGH;
  }

 if (request.indexOf("/LED3=OFF") != -1)  {
    digitalWrite(ledPin3, LOW);
    value3 = LOW;
  }
   if (request.indexOf("/LED4=ON") != -1)  {
    digitalWrite(ledPin4, HIGH);
    value4 = HIGH;
  }

 if (request.indexOf("/LED4=OFF") != -1)  {
    digitalWrite(ledPin4, LOW);
    value4 = LOW;
  }
   if (request.indexOf("/LED5=ON") != -1)  {
    digitalWrite(ledPin5, HIGH);
    value5 = HIGH;
  }

 if (request.indexOf("/LED5=OFF") != -1)  {
    digitalWrite(ledPin5, LOW);
    value5 = LOW;
  }
   if (request.indexOf("/LED6=ON") != -1)  {
    digitalWrite(ledPin6, HIGH);
    value6 = HIGH;
  }

 if (request.indexOf("/LED6=OFF") != -1)  {
    digitalWrite(ledPin6, LOW);
    value6 = LOW;
  }
// Set ledPin according to the request
//digitalWrite(ledPin, value);
 
  // Return the response
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); //  do not forget this one
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");

  client.println("<p style='font-size: 4em;'>Select compartment</p>");
  client.println("<a href=\"/LED1=ON\"\"><button style='font-size: 3em;'>Compartment 1 </button></a>");
  client.println("<a href=\"/LED2=ON\"\"><button style='font-size: 3em;'>Compartment 2 </button></a>");
  client.println("<a href=\"/LED3=ON\"\"><button style='font-size: 3em;'>Compartment 3 </button></a>");
  client.println("<a href=\"/LED4=ON\"\"><button style='font-size: 3em;'>Compartment 4 </button></a>");
  client.println("<a href=\"/LED5=ON\"\"><button style='font-size: 3em;'>Compartment 5 </button></a>");
  client.println("<a href=\"/LED6=ON\"\"><button style='font-size: 3em;'>Compartment 6 </button></a>");
  
  client.println("<br><br>");
  
  client.println("<a href=\"/LED1=OFF\"\"><button style='font-size: 3em;'>Compartment 1 OFF </button></a>");
  client.println("<a href=\"/LED2=OFF\"\"><button style='font-size: 3em;'>Compartment 2 OFF</button></a>");
  client.println("<a href=\"/LED3=OFF\"\"><button style='font-size: 3em;'>Compartment 3 OFF</button></a>");
  client.println("<a href=\"/LED4=OFF\"\"><button style='font-size: 3em;'>Compartment 4 OFF</button></a>");
  client.println("<a href=\"/LED5=OFF\"\"><button style='font-size: 3em;'>Compartment 5 OFF</button></a>");
  client.println("<a href=\"/LED6=OFF\"\"><button style='font-size: 3em;'>Compartment 6 OFF</button></a>");
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
 
}

