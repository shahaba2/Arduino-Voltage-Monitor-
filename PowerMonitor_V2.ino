
#include <LiquidCrystal.h>

// LCD connections: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 6);

const int redLED = 8;
const int greenLED = 7;
const int resetButton = 2;

bool warning = false;

void setup() {
  Serial.begin(9600);

  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(resetButton, INPUT_PULLUP);

  lcd.begin(16, 2);
  lcd.print("Power Monitor");
  delay(1500);
  lcd.clear();
}

void loop() {
  int reading = analogRead(A0);
  float voltage = reading * (5.0 / 1023.0);

  bool pressed = (digitalRead(resetButton) == LOW);

  if (voltage > 3.1) {
    warning = true;
  }

  if (pressed && voltage < 2.9) {
    warning = false;
  }

  digitalWrite(redLED, warning ? HIGH : LOW);
  digitalWrite(greenLED, warning ? LOW : HIGH);

  // LCD first row: voltage
  lcd.setCursor(0, 0);
  lcd.print("Voltage: ");
  lcd.print(voltage, 2);
  lcd.print("V  ");

  // LCD second row: alarm status
  lcd.setCursor(0, 1);
  lcd.print(warning ? "Status: ALARM " : "Status: NORMAL");

  Serial.print("Voltage: ");
  Serial.print(voltage, 2);
  Serial.print(" V | ");
  Serial.println(warning ? "ALARM" : "NORMAL");

  delay(100);
}
