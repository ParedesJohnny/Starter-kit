
int ledSI = 18;
int ledSD = 19;
int ledII = 21;
int ledID = 22;

int ledEncendido = HIGH; 
int ledApagado = LOW;  

void setup() {
  pinMode(ledSI, OUTPUT);
  pinMode(ledSD, OUTPUT);
  pinMode(ledII, OUTPUT);
  pinMode(ledID, OUTPUT);

  digitalWrite(ledSI, ledApagado);
  digitalWrite(ledSD, ledApagado);
  digitalWrite(ledII, ledApagado);
  digitalWrite(ledID, ledApagado);
}

void loop() {
  digitalWrite(ledSI, ledEncendido);
  delay(400);
  digitalWrite(ledSI,ledApagado);
  delay(200);

  digitalWrite(ledSD, ledEncendido);
  delay(400);
  digitalWrite(ledSD, ledApagado);
  delay(200);

  digitalWrite(ledID, ledEncendido);
  delay(400);
  digitalWrite(ledID, ledApagado);
  delay(200);

  digitalWrite(ledII, ledEncendido);
  delay(400);
  digitalWrite(ledII, ledApagado);
  delay(400);


  digitalWrite(ledSI, ledEncendido);
  digitalWrite(ledII, ledEncendido);
  delay(800);
  digitalWrite(ledSI, ledApagado);
  digitalWrite(ledII, ledApagado);
  delay(400);


  digitalWrite(ledSD, ledEncendido);
  digitalWrite(ledID, ledEncendido);
  delay(800);
  digitalWrite(ledSD, ledApagado);
  digitalWrite(ledID, ledApagado);
  delay(400);


  digitalWrite(ledSI, ledEncendido);
  digitalWrite(ledSD, ledEncendido);
  digitalWrite(ledII, ledEncendido);
  digitalWrite(ledID, ledEncendido);
  delay(1200);
  digitalWrite(ledSI, ledApagado);
  digitalWrite(ledSD, ledApagado);
  digitalWrite(ledII, ledApagado);
  digitalWrite(ledID, ledApagado);
  
  delay(1000); 
}