#include <LiquidCrystal.h>  // Include the library for LCD

// Initialize the LCD with the pin numbers (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Define LED pins
const int redLED = 9;
const int yellowLED = 8;
const int greenLED = 7;

void setup() {
  // Set up the LCD's number of columns and rows
  lcd.begin(16, 2);

  // Initialize LED pins as output
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);

  // Display initial message on the LCD
  lcd.setCursor(0, 0);
  lcd.print("Traffic Light");
  lcd.setCursor(0, 1);
  lcd.print("Controller");

  delay(2000);  // Display the message for 2 seconds
  lcd.clear();
}

void loop() {
  // Red light with countdown and "Stop" message
  lcd.setCursor(0, 0);
  lcd.print("Red Light ON   ");
  lcd.setCursor(0, 1);
  lcd.print("Stop           ");
  digitalWrite(redLED, HIGH);
  digitalWrite(yellowLED, LOW);
  digitalWrite(greenLED, LOW);
  for (int i = 15; i > 0; i--) {  // Countdown from 15 to 1
    lcd.setCursor(0, 1);
    lcd.print("Stop - ");
    lcd.print("Time: ");
    lcd.print(i);
    lcd.print("s ");
    delay(1000);  // Wait for 1 second
  }
  digitalWrite(redLED, LOW);  // Turn off red LED after countdown
  lcd.clear();

  // Yellow light with countdown and "Wait" message, blinking for the last 4 seconds
  lcd.setCursor(0, 0);
  lcd.print("Yellow Light ON");
  lcd.setCursor(0, 1);
  lcd.print("Wait           ");
  digitalWrite(redLED, LOW);
  digitalWrite(yellowLED, HIGH);
  digitalWrite(greenLED, LOW);
  for (int i = 12; i > 0; i--) {  // Countdown from 12 to 1
    lcd.setCursor(0, 1);
    lcd.print("Wait - ");
    lcd.print("Time: ");
    lcd.print(i);
    lcd.print("s ");

    if (i <= 4) {
      // Blink the yellow LED for the last 4 seconds
      digitalWrite(yellowLED, i % 2);  // Toggles yellow LED on and off
    } else {
      digitalWrite(yellowLED, HIGH);  // Keep yellow LED on
    }

    delay(1000);  // Wait for 1 second
  }
  digitalWrite(yellowLED, LOW);  // Turn off yellow LED after countdown
  lcd.clear();

  // Green light with countdown and "Go" message
  lcd.setCursor(0, 0);
  lcd.print("Green Light ON ");
  lcd.setCursor(0, 1);
  lcd.print("Go             ");
  digitalWrite(redLED, LOW);
  digitalWrite(yellowLED, LOW);
  digitalWrite(greenLED, HIGH);
  for (int i = 15; i > 0; i--) {  // Countdown from 15 to 1
    lcd.setCursor(0, 1);
    lcd.print("Go - ");
    lcd.print("Time: ");
    lcd.print(i);
    lcd.print("s ");
    delay(1000);  // Wait for 1 second
  }
  digitalWrite(greenLED, LOW);  // Turn off green LED after countdown
  lcd.clear();
}
