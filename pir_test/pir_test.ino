  int input = 2;
  int output = 13;
  
  void setup(){
    Serial.begin(9600);
    pinMode(13, OUTPUT);
    pinMode(2, INPUT);
  }
  
  void loop() {
    int pir = digitalRead(2);
    digitalWrite(13, pir);
    Serial.println(pir); 
    delay(10);
  }
