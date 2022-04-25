// constants
int LED = D5;
SYSTEM_THREAD(ENABLED); // Required for the LED to blink before cloud sync

void high() {
digitalWrite(LED, HIGH);
  delay(1000);
  digitalWrite(LED, LOW);
}

void low() {
  digitalWrite(LED, HIGH);
  delay(500);
  digitalWrite(LED, LOW);
}

void morseString(String STRING){
  for (int i=0; i < sizeof(STRING -1 ); i++)
  {
    delay(1200);
    switch(STRING[i]) {
      case 'b':
        low();
        delay(500);
        high();
        delay(500);
        high();
        delay(500);
        high();
        break;
      case 'r':
        high();
        delay(500);
        low();
        delay(500);
        high();
        break;
      case 'a':
        high();
        delay(500);
        low();
        break;
      case 'd':
        low();
        delay(500);
        high();
        delay(500);
        high();
        break;
      case 'l':
        high();
        delay(500);
        high();
        delay(500);
        low();
        delay(500);
        high();
        break;
      case 'e':
        high();
        break;
      case 'y':
        low();
        delay(500);
        high();
        delay(500);
        low();
        delay(500);
        low();
        break;
      default:
        return;
    }
    delay(500);
}
}

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  morseString("bradley");

  // delay to indicate new word / loop
  delay(3000);
}
