//this is a reject function
unsigned long time_state = 0;
unsigned long period = 1000; // 1 second

const int capacitive = 4; //input 3
const int inductive = 8; //input 8
const int ir = 5; //input 5
const int checker1 = 9; //solenoid checker

const int output1 = 1 ;// output 1
const int output2 = 6; // 2 & 3 are interrupt pins

const int push = 7; // connect to relay, use to on OP3

boolean reject = HIGH; //initial rejection state

const int interruptPin1 = 2;
const int interruptPin2 = 3;

int assembled = 0;//counter
int rejected = 0;//counter

void setup() {
 pinMode(capacitive, INPUT);
 pinMode(inductive, INPUT);
 pinMode(ir , INPUT);
 pinMode(output1, OUTPUT);
 pinMode(output2, OUTPUT);
 attachInterrupt(digitalPinToInterrupt(interruptPin1),assembledfunction ,RISING);
 attachInterrupt(digitalPinToInterrupt(interruptPin2),pushfunction ,RISING);
 Serial.begin(9600);
}

void loop() { 
 if ( digitalRead(capacitive)== LOW && digitalRead(inductive) == HIGH )//metal and plastic are stacked
 {
  digitalWrite(output1,HIGH);
  assembled ++ ;
  } 
 if ( digitalRead(ir) == HIGH)// when the object passed by input5, i let it connect to digital pin instead of interupt pin
 {
  digitalWrite(output2,HIGH);
 }
 
 else{
  Serial.println("do nothing");
  }
}

void assembledfunction(){
  reject= !reject;
  
 } 

void pushfunction (){
unsigned long time_now = millis(); 
  if (reject == HIGH && digitalRead(checker1)== LOW && millis()<= time_now + period ){
  reject = !reject;  
     }
  }
 


