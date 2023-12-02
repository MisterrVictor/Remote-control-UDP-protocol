#include "Arduino.h"

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("Available memory types:");
  Serial.print("Internal RAM (FreeHeap): ");
  Serial.print(ESP.getFreeHeap());
  Serial.println(" bytes");
  Serial.print("External RAM (Psram): ");
  Serial.print(ESP.getPsramSize());
  Serial.println(" bytes");

  Serial.println("Chip information:");
  Serial.print("Chip ID: ");
  Serial.println(ESP.getEfuseMac(), HEX);
  Serial.print("Chip Revision: ");
  Serial.println(ESP.getChipRevision());
  Serial.print("CPU Frequency: ");
  Serial.print(ESP.getCpuFreqMHz());
  Serial.println(" MHz");
  Serial.print("Flash Chip Model: ");
  Serial.println(ESP.getChipModel());
  Serial.print("Flash Chip Size: ");
  Serial.print(ESP.getFlashChipSize() / (1024 * 1024));
  Serial.println(" MB");
  Serial.print("Free Heap: ");
  Serial.print(ESP.getFreeHeap());
  Serial.println(" bytes");
}

void loop() {
  // Добавьте любые операции непрерывного отображения здесь
}
