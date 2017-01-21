int ledPin1 = 26 //A3
int ledPin2 = 27 //A4
int ledPin3 = 28 //A5

#define GET_LED(data, num) (data >> num) & 0x01

void setup() {
  Serial.begin(9600);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
}

void loop() {
  if(Serial.available()){
    byte input = Serial.read();
    digitalWrite(ledPin1, GET_LED(input, 0));
    digitalWrite(ledPin2, GET_LED(input, 1));
    digitalWrite(ledPin3, GET_LED(input, 2));
  }
}
