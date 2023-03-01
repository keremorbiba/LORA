#ifndef LORA_H
#define LORA_H

#include <Arduino.h>

class LoRaClass {
  public:
  // LoRa radyo modülünü belirtilen frekansa ayarlamak için kullanılır.
    void begin(long frequency);
    // Eğer bir paket mevcutsa true döndürür.
    bool parsePacket();
    // Son alınan paketin sinyal kalitesi (RSSI) değerini döndürür.
    int packetRssi();
    // Son alınan paketin sinyal-gürültü oranı (SNR) değerini döndürür.
    float packetSnr();
    // Bir byte yazdırmak için kullanılır.
    size_t write(uint8_t byte);
    // Belirtilen boyuttaki bir bufferı yazdırmak için kullanılır.
    size_t write(const uint8_t *buffer, size_t size);
    // Mevcut paketteki okunabilecek bayt sayısını döndürür.
    int available();
    // Mevcut paketten bir bayt okur.
    int read();
    // Mevcut paketteki bir sonraki baytı döndürür, okuma yapmaz.
    int peek();
    // Mevcut paketi tamamen okuyana kadar bekler.
    void flush();
    // Yeni bir paket alındığında çağrılacak bir fonksiyon tanımlar.
    void onReceive(void(*callback)(int));
    // Alınacak paketin boyutunu belirler.
    void receive(int size);
    // Radyoyu beklemeye alır.
    void idle();
    // Radyoyu uyku moduna alır.
    void sleep();
    // Radyo verici gücünü ayarlamak için kullanılır.
    void setTxPower(int level, int outputPin);
    // SPI frekansını ayarlamak için kullanılır.
    void setSPIFrequency(uint32_t frequency);
    // LoRa radyo modülünün pinlerini belirlemek için kullanılır.
    void setPins(uint8_t cs, uint8_t reset = 0, uint8_t irq = 0);
    // Kayıtlı tüm register değerlerini yazdırır
    void dumpRegisters(Stream& output);
};

extern LoRaClass LoRa;

#endif
