const int warmPin = 3;
const int whitePin = 5;

bool strobe = false;
int mode = 0;   // 0 = warm, 1 = white
int speed = 25;

void setup() {
  Serial.begin(9600);
  pinMode(warmPin, OUTPUT);
  pinMode(whitePin, OUTPUT);
}

void loop() {
  if (Serial.available()) {
    String input = Serial.readStringUntil('\n');

    if (input.startsWith("ON")) strobe = true;
    if (input.startsWith("OFF")) strobe = false;

    if (input.startsWith("WARM")) mode = 0;
    if (input.startsWith("WHITE")) mode = 1;

    if (input.indexOf(":") != -1) {
      speed = input.substring(input.indexOf(":") + 1).toInt();
    }
  }

  if (strobe) {
    if (mode == 0) {
      digitalWrite(warmPin, HIGH);
      delay(speed);
      digitalWrite(warmPin, LOW);
      delay(speed);
    } else {
      digitalWrite(whitePin, HIGH);
      delay(speed);
      digitalWrite(whitePin, LOW);
      delay(speed);
    }
  }
}
