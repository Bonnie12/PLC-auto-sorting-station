// test relay code
int relayPin = 8;
void setup() {
 pinMode(relayPin,OUTPUT);
 digitalWrite(relayPin, HIGH);
  

}

void loop() {
  digitalWrite(relayPin,LOW);
  delay (500);

}
