#include <WiFi.h>

const char* ssid = "falcomaster";
const char* password = "69420peen";
const char* server_ip = "192.168.43.105";  // IP of ESP32 B
const uint16_t server_port = 1234;

WiFiClient client;
int classification;
//const int samples = 250 * 4 * 2; // 2 seconds of 4-channel EEG at 250Hz
// float eeg_data[samples];
// char classification[samples];

// void generateDummyEEG() {
//   for (int i = 0; i < samples; i++) {
//     eeg_data[i] = sin(2 * PI * 10 * (i / 1000.0)); // Fake EEG wave
//   }
// }

// void generateSampleClassifications() {
//   for (int i = 0; i < samples; i++) {
//     classification[i] = (char)random(11); // Fake EEG wave
//   }
// }

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  //Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    //Serial.print(".");
  }
  //Serial.println("\nConnected!");

  if (client.connect(server_ip, server_port)) {
    //Serial.println("Connected to server!");
  } else {
    //Serial.println("Connection failed.");
  }

  //Serial.println("ESP Ready to receive classification...");

}

void loop() {
//char classification = (char)random('a', 'l' +1);

  // Check if at least 4 bytes are available
  if (Serial.available()) {
    // Serial.readBytes((char*)&classification, sizeof(classification));
    classification = Serial.read();
    //Serial.print("Received Classification: ");
    //Serial.println(classification);
  }
  if (client.connected()) {
    client.write(classification);
   // Serial.print("Classification data sent = ");
   // Serial.println(classification);
  } else {
    //Serial.println("Client disconnected. Trying to reconnect...");
    client.connect(server_ip, server_port);
  }
  delay(1); // wait 2 seconds between sends
}
