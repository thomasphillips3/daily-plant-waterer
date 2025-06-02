
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define RELAY_PIN 8
#define INTERVAL_MS 86400000UL // 24 hr in ms

LiquidCrystal_I2C lcd(0x27, 16, 2);   // Maybe 0x3F instead of 0x27

unsigned long previousMillis = 0;
unsigned long countdown = INTERVAL_MS;

void setup() {
  Serial.begin(9600);
  delay(1000);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Next watering:");
  welcomeMessage();
}

void loop() {
  unsigned long currentMillis = millis();
  unsigned long elapsed = currentMillis - previousMillis;

  // Has 24 hours passed
  if (elapsed >= INTERVAL_MS) {
    previousMillis = currentMillis;
    countdown = INTERVAL_MS;
    
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Watering now...");
    
    waterPlants();

    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Next watering:");
  } else {
    countdown = INTERVAL_MS - elapsed;
  }

  displayCountdown(countdown);
  delay(1000);
}

void displayCountdown(unsigned long ms) {
  unsigned long seconds = ms / 1000;
  int h = seconds / 3600;
  int m = (seconds % 3600) / 60;
  int s = seconds % 60;

  lcd.setCursor(0, 1);
  lcd.print("In ");
  if (h < 10) lcd.print("0");
  lcd.print(h); lcd.print(":");
  if (m < 10) lcd.print("0");
  lcd.print(m); lcd.print(":");
  if (s < 10) lcd.print("0");
  lcd.print(s);
  lcd.print("   ");
}

void waterPlants() {
  // Power the pump
  digitalWrite(RELAY_PIN, HIGH);
  delay(20000);
  digitalWrite(RELAY_PIN, LOW);
}

void welcomeMessage() {
  Serial.println("🌿 Arduino Plant Watering System Initialized");
  Serial.println("-------------------------------------------------");
  
  Serial.println("📦 Relay Module:");
  Serial.println("- IN   ➜ Arduino pin 8");
  Serial.println("- GND  ➜ Arduino GND");
  Serial.println("- VCC  ➜ Arduino 5V");
  Serial.println("- Pump ➜ Plug into Normally Open (NO) outlet");

  Serial.println();

  Serial.println("🖥️  I²C LCD Display (16x2):");
  Serial.println("- SDA ➜ Arduino A4");
  Serial.println("- SCL ➜ Arduino A5");
  Serial.println("- VCC ➜ Arduino 5V");
  Serial.println("- GND ➜ Arduino GND");
  Serial.println("- Default I2C Address: 0x27 (try 0x3F if nothing shows)");

  Serial.println();
  Serial.println("🔁 Operation:");
  Serial.println("- Waters the plant once every 24 hours (interval settable)");
  Serial.println("- Pump is turned on for 20 seconds via relay");
  Serial.println("- Countdown to next watering is shown on the LCD");

  Serial.println("-------------------------------------------------\n");
}

