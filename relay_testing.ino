// test relay code
int relayPin = 8;
void setup() {
 pinMode(relayPin,OUTPUT);
 digitalWrite(relayPin, LOW);
  

}

void loop() {
 // delay (1000);
  digitalWrite(relayPin,HIGH);
 // delay (1000);
  //digitalWrite(relayPin,LOW);
}
