#include <Servo.h>
#include <LiquidCrystal.h>

#define LIGHT_SENSOR A0
#define SOIL_MOISTURE_SENSOR A1
#define MOTOR_PIN 6
#define SERVO_PIN 9
#define TMP_PIN A2
#define LED_PIN 7

Servo servo;
LiquidCrystal lcd(12, 11, 5, 4, 3, 1); // RS, E, D4, D5, D6, D7

void setup() {
  lcd.begin(16, 2);
  servo.attach(SERVO_PIN);
  pinMode(MOTOR_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  float temperature = analogRead(A2);
  int soilMoisture = analogRead(SOIL_MOISTURE_SENSOR);
  int lightValue = analogRead(A0);

  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperature);
  lcd.print("C");

  lcd.setCursor(0, 1);
  lcd.print("Humedad: ");
  lcd.print(soilMoisture);

  if (soilMoisture < 500) {
    servo.write(90);
    delay(2000);
    servo.write(0);
  }

  if (lightValue < 500) {
    digitalWrite(LED_PIN, HIGH); // Enciende el LED cuando la luz es baja
  } else {
    digitalWrite(LED_PIN, LOW);  // Apaga el LED cuando la luz es alta
  }

  if (temperature > 30.00) {
    digitalWrite(MOTOR_PIN, HIGH);
    delay(2000);
    digitalWrite(MOTOR_PIN, LOW);
  }

  delay(1000);
}
