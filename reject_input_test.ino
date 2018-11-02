//reject input test
const int chain = 24;
const int belt = 32;

unsigned long time_previous1 = 0;
unsigned long time_previous2 = 0;
unsigned long period = 1000; // 1 second
unsigned long rejectHigh = 5000;

const int capacitive = 5; //input 3
const int inductive = 10; //input 8
const int ir = 11; //input 5
const int input4 = 6; //input 6

const int push = 30;

bool reject = HIGH;
bool state = LOW;
void setup() {
  // put your setup code here, to run once:
  pinMode(capacitive, INPUT);
  pinMode(inductive, INPUT);
  pinMode(ir , INPUT);
  pinMode(push, OUTPUT);
  pinMode (chain, OUTPUT);
  pinMode (belt, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long time_now = millis();
  digitalWrite(chain, HIGH);
  digitalWrite(belt, HIGH);
  if ( digitalRead(capacitive) == LOW && digitalRead(inductive) == HIGH ) //metal and plastic are stacked
  {
    time_previous2 = time_now;
    Serial.print("assembled");
    reject = LOW;

  }
  if (digitalRead(input4) == HIGH && reject == LOW){
    state = HIGH;
  }

  if ( digitalRead(ir) == HIGH && reject == HIGH) { //if rejected parts reach ir
    time_previous1 = time_now;
   // time_previous2 = 0;
    digitalWrite(push, HIGH);
    Serial.print("rejected");
  }
  if (time_now - time_previous1 >= period) { // retract code
    digitalWrite(push, LOW);
  }
  if ( digitalRead(ir) == HIGH && reject == LOW) { //if assembled passedby ir
    
    //time_previous1 = 0;
    Serial.print("not reject");
  }
  if (time_now - time_previous2 >= rejectHigh && reject == LOW) {
    reject = HIGH ;
    }
 
 


Serial.print (reject);
Serial.print ("  ");
Serial.print (digitalRead(capacitive));
Serial.print ("  ");
Serial.print (digitalRead(inductive));
Serial.print ("  ");
Serial.println (digitalRead(ir));


}
