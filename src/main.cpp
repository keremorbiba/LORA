#include <Arduino.h>
#include "LoRa.h"

void setup() {
  Serial.begin(9600);
// LoRa radyo vericisinin frekansını 433 MHz olarak ayarla.  
  LoRa.begin(433E6);
}

void loop() {
  // Lora'dan mesaj geldi mi diye kontrol ediyoruz.
  if (LoRa.parsePacket()) {
    String message = "";
    // Mesajı oku.
    while (LoRa.available()) {
      message += (char)LoRa.read();
    }
     // Gelen mesajı seri portta yazdır.
    Serial.println("Received message: " + message);
  }

  // Her 5 saniyede bir Lora aracılığıyla bir mesaj gönderiyoruz.
  static unsigned long lastSendTime = 0;
  if (millis() - lastSendTime > 5000) {
    LoRa.beginPacket();
    LoRa.print("Hello, world!");
    LoRa.endPacket();
    lastSendTime = millis();
    // Gönderilen mesajı seri portta yazdır.
    Serial.println("Sent message.");
  }
}
