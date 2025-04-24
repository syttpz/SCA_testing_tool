#include <SPI.h>

#define PIN_CS    D3
#define PIN_CLK   D8 //SCLK
#define PIN_MISO  D9 //MISO
#define PIN_TRIGGER D2 //High volt trigger pin
#define UART_RX   D7  //UART

#define SAMPLES 500   
#define TRACE_NUM 500 

HardwareSerial uart(1); 

void setup() {
  Serial.begin(115200);      

  //Initialize UART
  uart.begin(115200, SERIAL_8N1, UART_RX, -1);  

  pinMode(PIN_CS, OUTPUT);
  digitalWrite(PIN_CS, HIGH);
  SPI.begin(PIN_CLK, PIN_MISO, -1, PIN_CS);

  pinMode(PIN_TRIGGER, INPUT);

  Serial.println("Start capturing traces");
}

uint16_t trace[SAMPLES];
uint8_t plaintext[16];

void loop() {
  // Triger high
  if (digitalRead(PIN_TRIGGER) == HIGH) {
    // Read plain text via UART
    while (uart.available() < 16); 
    uart.readBytes(plaintext, 16);

    for (int i = 0; i < SAMPLES; i++) {
      trace[i] = readADS();
      delayMicroseconds(1); 
    }
    // Save 
    Serial.print("PT:");
    for (int i = 0; i < 16; i++) {
      if (plaintext[i] < 16) Serial.print('0');
      Serial.print(plaintext[i], HEX);
    }
    Serial.print(",TRACE:");
    for (int i = 0; i < SAMPLES; i++) {
      Serial.print(trace[i]);
      if (i != SAMPLES - 1) Serial.print(",");
    }
    Serial.println();
  }
}

uint16_t readADS() {
  digitalWrite(PIN_CS, LOW);
  delayMicroseconds(1);
  uint16_t val = SPI.transfer16(0x0000);
  digitalWrite(PIN_CS, HIGH);
  return val & 0x0FFF;  // Only the first 12 bit are valid bit
}
