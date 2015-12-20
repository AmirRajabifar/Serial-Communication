// executables
const int ledPin  = 6;
const int led1Pin = 5;



// string to store each line of Serial communication
String data = "";
String port = "";



// creating streings to hold the unpacked messages from serial
String potString = "0";
String pot1String = "0";

// Variables type float to hold the actual value of the sensors
float pot;
float pot1;

void setup() {
//
Serial2.begin(9600);

  if (Serial2.available()){
  data = Serial2.readStringUntil('\n');
  }

  data = "0";
}

void loop() {
//

  if (Serial2.available() > 0) {
    data = Serial2.readStringUntil('\n');
  }
  String payload = "";
  if (data != "0"){
    int offset = data.indexOf("U*"); // this is the header (0x552A)
    if (offset >= 0) {
     payload = data.substring(offset + 3, data.indexOf('\n'));
      char value = data.charAt(offset + 2);
      switch (value){
        case 'A':
          potString = payload;
          break;
        case 'B':
          pot1String = payload;
          break;
         // default:      
      }
      // can add the rest of sensor values as they are added to the project
    }
  }

// converting the strings to float 
  pot = potString.toFloat();
  pot1 = pot1String.toFloat();  


//*********************** DO STUFF *********************

  analogWrite(ledPin, pot);
  analogWrite(led1Pin, pot1);
  
  
  
}
