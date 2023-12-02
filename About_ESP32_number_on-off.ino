#include <EEPROM.h>
int address = 0; // адрес памяти для записи (от 0 до 511)
byte value_w; // значение данных (от 0 до 255)

void setup() {
  Serial.begin(115200);

  EEPROM.begin(512);  // Инициализация EEPROM с размером 512 байт
  value_w = EEPROM.read(address);  // Чтение данных
  value_w++;
  EEPROM.write(address, value_w);  // Запись данных
  EEPROM.commit();                 // Сохранение изменений

  byte value_r = EEPROM.read(address);  // Чтение данных

  // Используйте значение данных (value) по вашему усмотрению
  Serial.println();
  Serial.print("Номер включения устройства: ");
  Serial.println(value_r);
}

void loop() {

}
