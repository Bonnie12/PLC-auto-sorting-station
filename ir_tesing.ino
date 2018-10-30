// test IR reading
int irReading = 8;
//bool detect ; 
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

Serial.println(digitalRead(irReading));
//delay(1000);
}
