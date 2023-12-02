
#include <WiFi.h>
#include <WiFiUdp.h>

const char* ssid = "Mister Victor";        // Ваш SSID
const char* password = "Ваш пароль";         // Ваш пароль
const char* udpServerIP = "192.168.43.245";// IP получателя WROOM-32D (сейчас IP Wrover 192.168.43.45)
const int udpServerPort32D = 8889;         // Порт получателя WROOM-32D
const int udpServerPortWrover = 8888;      // Порт получателя WROVER

WiFiUDP udp;
String deviceName = "ESP32-WROVER";  // Имя ОТПРАВИТЕЛЯ, которое будет добавлено к отправляемому сообщению

void setup() {
  Serial.begin(115200);
  
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Подключение к WiFi...");
  }
  Serial.println("Подключено к WiFi!");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  udp.begin(udpServerPortWrover); // Инициализация UDP для приема данных
 
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    // Передача данных по UDP
    udp.beginPacket(udpServerIP, udpServerPort32D);
    udp.printf("Привет, WROOM-32D, это сообщение от %s!", deviceName.c_str());
    udp.endPacket();

    // Прием данных по UDP
    int packetSize = udp.parsePacket();
    if (packetSize) {
      char incomingPacket[255];
      int len = udp.read(incomingPacket, 255);
      if (len > 0) {
        incomingPacket[len] = 0;
        Serial.printf("Сообщение: %s\n", incomingPacket);
      }
    }
  }
  delay(6000);
}