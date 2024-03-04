const int ldr1 = A0;
const int ldr2 = A1;
const int ldr3 = A2;
const int buzzer = 9;

void setup() {
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  int ldrValue1 = analogRead(ldr1);
  int ldrValue2 = analogRead(ldr2);
  int ldrValue3 = analogRead(ldr3);

  // map för att ändra värden för bättre räckvidd
  int pitch = map(ldrValue1, 0, 1023, 100, 1000);
  int volume = map(ldrValue2, 0, 1023, 0, 255);
  int modulation = map(ldrValue3, 0, 1023, 20, 250);

  tone(buzzer, pitch, modulation);
  analogWrite(buzzer, volume);
  Serial.print("LDR1: ");
  Serial.print(ldrValue1);
  Serial.print(" | LDR2: ");
  Serial.print(ldrValue2);
  Serial.print(" | LDR3: ");
  Serial.print(ldrValue3);
  Serial.print(" | Pitch: ");
  Serial.print(pitch);
  Serial.print(" | Volume: ");
  Serial.print(volume);
  Serial.print(" | Modulation: ");
  Serial.println(modulation);
// hade väldigt höga värden pga mörk miljö men för höga resistorer så tog svagare för bättre känslighet mot ljus
  delay(300);
}
