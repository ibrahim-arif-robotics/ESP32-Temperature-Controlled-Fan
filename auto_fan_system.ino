#include <DHT.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define DHTPIN 10
#define DHTTYPE DHT11

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

DHT dht(DHTPIN, DHTTYPE);

Adafruit_SSD1306 display(
  SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET
);

class Fan {
  public:
    int motorPin1 = 5;
    int motorPin2 = 6;

    void begin() {
      pinMode(motorPin1, OUTPUT);
      pinMode(motorPin2, OUTPUT);
    }
};

Fan fan;

// Display temperature and fan status
void updateDisplay(float temp, bool fanOn) {
  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  display.setCursor(0, 10);
  display.print("temperature is ");
  display.print(temp, 1);
  display.println(" C");

  display.setCursor(0, 35);
  display.print("Fan ");

  if (fanOn) {
    display.println("ON");
  }
  else {
    display.println("OFF");
  }

  display.display();
}

void setup() {
  dht.begin();

  // OLED: SDA = GPIO 19, SCL = GPIO 21
  Wire.begin(19, 21);

  fan.begin();

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    while (true) {}
  }

  display.clearDisplay();
  display.display();
}

void loop() {
  float temp = dht.readTemperature();
  bool fanOn = false;

  if (isnan(temp)) {
    digitalWrite(fan.motorPin1, LOW);
    digitalWrite(fan.motorPin2, LOW);

    updateDisplay(0, false);

    delay(2000);
    return;
  }

  if (temp >= 27) {
    digitalWrite(fan.motorPin1, HIGH);
    digitalWrite(fan.motorPin2, LOW);

    fanOn = true;
  }
  else {
    digitalWrite(fan.motorPin1, LOW);
    digitalWrite(fan.motorPin2, LOW);
  }

  updateDisplay(temp, fanOn);

  delay(2000);
}
