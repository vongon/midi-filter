
void setup() {
  Serial.begin(31250);
}


char serialData;
char START = 0xFA;
char STOP = 0xFC;

bool isValid(char data) {
  if (data == START) {
    return false;
  }
  if (data == STOP) {
    return false;
  }
  return true;
}

void loop() {
  if(Serial.available()) {
    serialData = Serial.read();
    if (isValid(serialData)) {
      Serial.write(serialData);
    }
  }
}
