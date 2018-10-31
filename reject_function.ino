//this is a reject function

unsigned long time_previous = 0;
unsigned long period = 1000; // 1 second

const int capacitive = 4; //input 3
const int inductive = 8; //input 8
const int ir = 5; //input 5


const int output1 = 1 ;// output 1

const int push = 7; // connect to relay, use to on OP3

boolean reject = HIGH; //initial rejection state
boolean state = HIGH;

const int interruptPin1 = 2;

int assembled = 0;//counter
int rejected = 0;//counter

void setup() {
  pinMode(capacitive, INPUT);
  pinMode(inductive, INPUT);
  pinMode(ir , INPUT);
  pinMode(output1, OUTPUT); //connect to interruptPin1
  pinMode(push, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(interruptPin1), pushfunction, HIGH);
  Serial.begin(9600);
}

void loop() {
  unsigned long time_now = millis();
  if ( digitalRead(capacitive) == LOW && digitalRead(inductive) == HIGH ) //metal and plastic are stacked
  {
    time_previous = time_now;
    reject = LOW;
    state = LOW;
  }
  if ( state == LOW && time_now - time_previous >= period) {
    reject = HIGH;
    state = HIGH;
  }
  if ( digitalRead(ir) == HIGH)// when the object passed by input5, i let it connect to digital pin instead of interupt pin
  {
    digitalWrite(output1, HIGH);
  }

  else{
    Serial.println("do nothing");
  }
}

void pushfunction () {
  digitalWrite(push, reject);
}




