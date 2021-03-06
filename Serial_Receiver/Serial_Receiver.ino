// executables
const int led1Pin  = 2;
const int led2Pin = 3;
const int led3Pin = 4;
const int led4Pin = 5;
const int led5Pin = 5;
const int led6Pin = 7;
const int led7Pin = 8;
const int led8Pin = 9;


// string to store each line of Serial communication
String data1 = "";
String data2 = "";



// creating streings to hold the unpacked messages from serial
String potString   = "0";
String pot1String  = "0";
String CH1String   = "0";
String CH2String   = "0";
String CH3String   = "0";
String CH4String   = "0";
String CH5String   = "0";
String CH6String   = "0";

// Variables type float to hold the actual value of the sensors
float pot;
float pot1;
float CH1;
float CH2;
float CH3;
float CH4;
float CH5;
float CH6;


void setup() {
//
Serial.begin(250000);
Serial1.begin(250000);
Serial2.begin(250000);

// receives data from the first micro controller
  if(Serial1.available()){
    data1 = Serial1.readStringUntil('\n');
  }
// receives data from the second micro controller  
  if (Serial2.available()){
  data2 = Serial2.readStringUntil('\n');
  } 
// resets the strings 
  data1 = "0";  
  data2 = "0";
  
}

void loop() {
//
  if (Serial1.available() > 0){
    data1 = Serial1.readStringUntil('\n');
  }
  String payload1 = "";
  if (data1 != "0"){
    int offset1 = data1.indexOf("U*");
    if (offset1 >= 0){
     payload1 = data1.substring(offset1 + 3, data1.indexOf('\n'));
      char value1 = data1.charAt(offset1 + 2);
      switch (value1){
        case 'A':
          CH1String = payload1;
          break;
        case 'B':
          CH2String = payload1;
          break; 
        case 'C':
          CH3String = payload1;
          break;
        case 'D':
          CH4String = payload1;
          break;
        case 'E':
          CH5String = payload1;
          break;
        case 'F':
          CH6String = payload1;
          break;   
      }
    }
  }

  if (Serial2.available() > 0) {
    data2 = Serial2.readStringUntil('\n');
  }
  String payload2 = "";
  if (data2 != "0"){
    int offset2 = data2.indexOf("U*"); // this is the header (0x552A)
    if (offset2 >= 0) {
     payload2 = data2.substring(offset2 + 3, data2.indexOf('\n'));
      char value2 = data2.charAt(offset2 + 2);
      switch (value2){
        case 'A':
          potString = payload2;
          break;
        case 'B':
          pot1String = payload2;
          break;
               
      }
      // can add the rest of sensor values as they are added to the project
    }
  }

// converting the strings to float 
  pot  = potString.toFloat();
  pot1 = pot1String.toFloat();  

  CH1 = CH1String.toFloat();
  CH2 = CH2String.toFloat();
  CH3 = CH3String.toFloat();
  CH4 = CH4String.toFloat();
  CH5 = CH5String.toFloat();
  CH6 = CH6String.toFloat();      


//*********************** DO STUFF *********************

 /* CH1 = map(CH1, 900, 1900, 0, 255);
  CH2 = map(CH2, 900, 1900, 0, 255);
  CH3 = map(CH3, 900, 1900, 0, 255);
  CH4 = map(CH4, 900, 1900, 0, 255);
  CH5 = map(CH5, 900, 1900, 0, 255);
  CH6 = map(CH6, 900, 1900, 0, 255);
  */

  analogWrite(led7Pin, pot);
  analogWrite(led8Pin, pot1);
  
  analogWrite(led1Pin, CH1);
  analogWrite(led2Pin, CH2);
  analogWrite(led3Pin, CH3);
  analogWrite(led4Pin, CH4);
  analogWrite(led5Pin, CH5);
  analogWrite(led6Pin, CH6);
  
    Serial.print(CH1String);
    Serial.print('\t');
    Serial.print(CH2String);
    Serial.print('\t');
    Serial.print(CH3String);
    Serial.print('\t');
    Serial.print(CH4String);
    Serial.print('\t');
    Serial.print(CH5String);
    Serial.print('\t');
    Serial.println(CH6String);
    
    
  
}
