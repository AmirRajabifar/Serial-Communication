//Pin connections to RC Receiver
  byte CHPins [6] = {3, 5, 6, 9, 10, 11};
  char Headers [] = {'a', 'b', 'c', 'd', 'e', 'f'};
// Chanel stat1 vals
  unsigned long CH [6];
 
  
// variable used in the "chst_cut" to store 
  int chst_1;

float chst_cut(int b){
  chst_1 = b/100;
  chst_1 = round (chst_1);
  chst_1 = chst_1 * 100;
  return chst_1;
}  
void setup() {
  // put your setup code here, to run once:
  for (byte i = 0; i < 6; i++){
    pinMode(CHPins [i], INPUT);
  }
  Serial.begin(250000);

}

void loop() {
// pulseIn() is used to read the signals from the receiver (not the best way!!!)
  for (byte i = 0; i < 6; i ++){
    CH [i] = chst_cut (pulseIn (CHPins [i], HIGH));
  }

//Packing values in Serial buffer
  for (byte a = 0; a < 6; a ++){
     for ( byte b = 0; b < 6; b++){
      Serial.print("U*");
      Serial.print(Headers [b]);
      Serial.print(CH [a]);
      Serial.println("");
      delay(50);
     }
  }

/*  
  Serial.print("U*"); //A header
  Serial.print("A");  //a token to indicate the message payload
  Serial.print(CH1);
  Serial.println("");
  
  Serial.print("U*"); //A header
  Serial.print("B");  //a token to indicate the message payload
  Serial.print(CH2);
  Serial.println("");
  
  Serial.print("U*"); //A header
  Serial.print("C");  //a token to indicate the message payload
  Serial.print(CH3);
  Serial.println(""); 
  
  Serial.print("U*"); //A header
  Serial.print("D");  //a token to indicate the message payload
  Serial.print(CH4);
  Serial.println("");
  
  Serial.print("U*"); //A header
  Serial.print("E");  //a token to indicate the message payload
  Serial.print(CH5);
  Serial.println("");
  
  Serial.print("U*"); //A header
  Serial.print("F");  //a token to indicate the message payload
  Serial.print(CH6);
  Serial.println("");
*/         

    

}
