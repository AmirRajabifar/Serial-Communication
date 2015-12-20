//Pin connections to RC Receiver
  const int CH1Pin = 3;
  const int CH2Pin = 5;
  const int CH3Pin = 6;
  const int CH4Pin = 9;
  const int CH5Pin = 10;
  const int CH6Pin = 11;

// Chanel stat1 vals
  unsigned long CH1;
  unsigned long CH2;
  unsigned long CH3;
  unsigned long CH4;
  unsigned long CH5;
  unsigned long CH6;  
  
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
  pinMode(CH1Pin, INPUT);
  pinMode(CH2Pin, INPUT);
  pinMode(CH3Pin, INPUT);
  pinMode(CH4Pin, INPUT);
  pinMode(CH5Pin, INPUT);
  pinMode(CH6Pin, INPUT);


  Serial.begin(9600);

}

void loop() {
// pulseIn() is used to read the signals from the receiver (not the best way!!!)
     CH1 = (pulseIn (CH1Pin, HIGH));
     CH2 = (pulseIn (CH2Pin, HIGH));
     CH3 = (pulseIn (CH3Pin, HIGH));
     CH4 = (pulseIn (CH4Pin, HIGH));
     CH5 = (pulseIn (CH5Pin, HIGH));
     CH6 = (pulseIn (CH6Pin, HIGH));

// rounding 
    CH1 = chst_cut(CH1);
    CH2 = chst_cut(CH2);
    CH3 = chst_cut(CH3);
    CH4 = chst_cut(CH4);
    CH5 = chst_cut(CH5);
    CH6 = chst_cut(CH6);

//Packing values in Serial buffer
  Serial.print("U*"); //A header
  Serial.print("A");  //a token to indicate the message payload
  Serial.print(CH1);
  Serial.println("");
  
  Serial.print("U*"); //A header
  Serial.print("A");  //a token to indicate the message payload
  Serial.print(CH2);
  Serial.println("");
  
  Serial.print("U*"); //A header
  Serial.print("A");  //a token to indicate the message payload
  Serial.print(CH3);
  Serial.println(""); 
  
  Serial.print("U*"); //A header
  Serial.print("A");  //a token to indicate the message payload
  Serial.print(CH4);
  Serial.println("");
  
  Serial.print("U*"); //A header
  Serial.print("A");  //a token to indicate the message payload
  Serial.print(CH5);
  Serial.println("");
  
  Serial.print("U*"); //A header
  Serial.print("A");  //a token to indicate the message payload
  Serial.print(CH6);
  Serial.println("");
         

    

}
