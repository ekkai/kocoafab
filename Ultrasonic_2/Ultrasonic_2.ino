int trig = 2;
int echo = 3;
int piezo = 8;

void setup() {
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(piezo, OUTPUT);
}

void loop() {
  digitalWrite(trig, LOW);
  digitalWrite(echo, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  unsigned long duration = pulseIn(echo, HIGH);
  float distance = duration / 29.0 / 2.0;

  if (distance < 15) {
    tone(piezo, 2048);
    delay(200);
    noTone(piezo);
    delay(200);
  }
  else{
    noTone(piezo);
  }
}

