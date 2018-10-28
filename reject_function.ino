//this is a reject function

const int capacitive = 3; //input 3
const int inductive = 8; //input 8
const int ir = 5; //input 5
int mode = 0; //for switch function
boolean reject = HIGH; //initial rejection state
int assembled = 0;//counter
int rejected = 0;//counter
const int output = 1 ;// output 3

void setup() {
 pinMode(capacitive, INPUT);
 pinMode(inductive, INPUT);
 pinMode(ir , INPUT);
 pinMode(output, reject); 
 Serial.begin(9600);
}

void loop() {
 if ( digitalRead(capacitive)== LOW && digitalRead(inductive) == HIGH )//metal and plastic are stacked
 {
  delay(100);
  mode = 1 ;
  } 
 if ( digitalRead(ir) == HIGH)// when the object passed by input5 
 {
  delay(100);
  mode = 2 ;
 }

Serial.println("current mode is = " + mode);

switch(mode){ //switch function
 case 1:
  reject = !reject; // toggle rejct from HIGH to LOW
  assembled ++;
  Serial.println("rejection state = " + reject);
  break;
 case 2:
  digitalWrite(output,reject); // solenoid's state
  delay(100);
  Serial.print("finished");
  break;
 default:
   
  Serial.println("do nothing");
  }
}
