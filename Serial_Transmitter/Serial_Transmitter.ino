
// Setting Sensor pins
const int potPin = A0;
const int pot1Pin = A1;




// Creating variables
uint8_t pot;
uint8_t pot1;

void setup() {
// Declearing the pinModes' for sensors
  pinMode(potPin, INPUT);
  pinMode(pot1Pin, INPUT);
// Begining Serial Communication
  Serial.begin(9600);
 
}

void loop() {
// reading from the sensors
  pot = map(analogRead(potPin),0 ,1023, 0, 255);
  pot1 = map(analogRead(pot1Pin),0 ,1023, 0, 255);  

//Packing the Serial message
  Serial.print("U*"); //A header
  Serial.print("A");  //a token to indicate the message payload
  Serial.print(pot);
  Serial.println("");  

  Serial.print("U*"); //A header
  Serial.print("B");  //a token to indicate the message payload
  Serial.print(pot1);
  Serial.println("");  
 
  
}
