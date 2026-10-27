#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

int ledSI = 18;
int ledSD = 19;
int ledII = 17;
int ledID = 5;

int ledEncendido = HIGH; 
int ledApagado = LOW;  

#define I2C_SDA_PIN 21
#define I2C_SCL_PIN 22
#define I2C_FREQUENCY_HZ 400000
#define OLED_I2C_ADDR 0x3C
#define OLED_WIDTH 128
#define OLED_HEIGHT 64
#define OLED_RESET_PIN -1

#define ARRIBA    24
#define ABAJO     25
#define DERECHA   26
#define IZQUIERDA 27

#define ANCHO 128
#define ALTO  64

Adafruit_SSD1306 display(OLED_WIDTH, OLED_HEIGHT, &Wire, OLED_RESET_PIN);

void imprimirFlechaCentrada(int direccion, int tamano = 2);

void setup() {
  Serial.begin(115200);
  
  pinMode(ledSI, OUTPUT);
  pinMode(ledSD, OUTPUT);
  pinMode(ledII, OUTPUT);
  pinMode(ledID, OUTPUT);

  digitalWrite(ledSI, ledApagado);
  digitalWrite(ledSD, ledApagado);
  digitalWrite(ledII, ledApagado);
  digitalWrite(ledID, ledApagado);

  initI2C();
  scanI2C();
  testI2CDevice();
  initDisplay();
}

void loop() {
  display.clearDisplay();
  digitalWrite(ledSI, ledEncendido);
  digitalWrite(ledSD, ledEncendido);
  imprimirFlechaCentrada(ARRIBA, 2);
  display.display();
  delay(2000);

  display.clearDisplay();
  digitalWrite(ledSI, ledApagado);
  digitalWrite(ledSD, ledApagado);
  digitalWrite(ledID, ledEncendido);
  digitalWrite(ledII, ledEncendido);
  imprimirFlechaCentrada(ABAJO, 2); 
  display.display();
  delay(2000);

  display.clearDisplay();
  digitalWrite(ledID, ledApagado);
  digitalWrite(ledII, ledApagado);
  digitalWrite(ledSD, ledEncendido);
  digitalWrite(ledID, ledEncendido);
  imprimirFlechaCentrada(DERECHA, 2); 
  display.display();
  delay(2000);

  display.clearDisplay();
  digitalWrite(ledSD, ledApagado);
  digitalWrite(ledID, ledApagado);
  digitalWrite(ledSI, ledEncendido);
  digitalWrite(ledII, ledEncendido);
  imprimirFlechaCentrada(IZQUIERDA, 2); 
  display.display();
  delay(2000);

  digitalWrite(ledSI, ledApagado);
  digitalWrite(ledII, ledApagado);
}

inline void initI2C() {
    Wire.begin(I2C_SDA_PIN, I2C_SCL_PIN);
    Wire.setClock(I2C_FREQUENCY_HZ);
    Serial.println("[I2C] bus listo SDA=21 SCL=22");
}

inline void scanI2C() {
  byte error, direccion;
  int cont = 0;
  Serial.println("[I2C] escaneando direcciones 1-126");
  for (direccion = 1; direccion < 127; direccion++) {
    Wire.beginTransmission(direccion);
      error = Wire.endTransmission();
      if (error == 0) {
        Serial.print("[I2C] dispositivo en 0x");
        if (direccion < 16) Serial.print("0");
        Serial.print(direccion, HEX);
        cont ++;
      }
  }
  Serial.print("[I2C] dispositivos encontrados: ");
  Serial.println(cont);
}

inline void testI2CDevice() {
  Wire.beginTransmission(OLED_I2C_ADDR);
  byte error = Wire.endTransmission();
  if (error == 0) {
    Serial.print("[POST] OLED responde en 0x");
    if (OLED_I2C_ADDR < 16) Serial.print("0");
    Serial.println(OLED_I2C_ADDR, HEX);
  } else {
    Serial.println("[POST] OLED no responde. Arranque detenido");
    while (1);
  }
}

inline void initDisplay() {
  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_I2C_ADDR)) {
    Serial.println("[DISPLAY] Error al inicializar SSD1306");
    while(1);
  } else {
    Serial.println("[DISPLAY] SSD1306 inicializado 128x64 a 400 kHz");
  }
}

void imprimirFlechaCentrada(int direccion, int tamano) {
  int anchoCaracter = 6 * tamano;
  int altoCaracter  = 8 * tamano;

  int x = (ANCHO - anchoCaracter) / 2;
  int y = (ALTO - altoCaracter) / 2;

  display.setCursor(x, y);
  display.setTextSize(tamano);
  display.setTextColor(SSD1306_WHITE);
  
  display.write(direccion); 
}
