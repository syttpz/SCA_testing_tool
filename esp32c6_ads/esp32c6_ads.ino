#include <SPI.h>

// define spi pin
#define PIN_SPI_CS 5
#define PIN_SPI_CLK 6
#define PIN_SPI_MISO 7

SPIClass spi = SPIClass(FSPI);

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("ADS7042 init")

  spi.begin(PIN_SPI_CLK, PIN_SPI_MISO, -1, PIN_SPI_CS);
  pinMode(PIN_SPI_CS, OUTPUT);
  digitalWrite(PIN_SPI_CS, HIGH);

}

uint16_t readASD8042(){
  uint8_t msb = 0, lsb = 0;
  uint16_t result = 0;

  digitalWrite(PIN_SPI_CS, LOW);
  delayMicroseconds(1);

  msb = spi.transfer(0x00);
  lsb = spi.transfer(0x00);

  digitalWrite(PIN_SPI_CS. HIGH)

  result = ((uint16_t)msb << 8) lsb;
  return result >> 4;
}


void loop() {
  uint16_t adcValue = readADS7042();

  Serial.println(adcValue);

  //delay
   
}
