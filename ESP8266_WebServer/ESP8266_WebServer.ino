//#include <ESP8266WiFi.h>
//#include <ESP8266WebServer.h>
#include <WiFi.h>
#include <WebServer.h>
#define ssid "kk_2.4G"
#define pass "88888888"
//ESP8266WebServer server(80);
WebServer server(80);
String x;
void setup(void) {
  Serial.begin(250000);
  //wifi_begin--------------------
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, pass);
  //若要指定IP位址，請自行在此加入WiFi.config()敘述。
  WiFi.config(IPAddress(192, 168, 0, 87), // IP位址
              IPAddress(192, 168, 0, 1),  // 閘道（gateway）位址
              IPAddress(255, 255, 255, 0)); // 網路遮罩（netmask）
  Serial.print("\nConnecting to ");
  Serial.println(ssid);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.print("\nWiFi connected\nIP address:");
  Serial.println(WiFi.localIP());
  //server_begin--------------------
  server.on("/", host);//開啟網址對應的副程式
  server.on("/a", host_a);
  server.on("/b", host_b);
  server.on("/c", host_c);
  server.on("/n", host_n);
  server.onNotFound(host_NotFound);//開啟無網址的副程式
  server.begin();
}
void loop(void) {
  server.handleClient();
  x = millis() / 1000;
}
