#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

#ifndef APSSID
#define APSSID "WIFI-SSID"
#define APPSK  "WIFI-PASSWORD"
#endif

const char *ssid = APSSID;
const char *password = APPSK;

#import "index.h";

ESP8266WebServer server(80);

IPAddress myIP;

void handleControlPanel() {
  server.send(200, "text/html", MAIN_page);
}

void handleTime() {
  Serial.println("T|" + server.arg("setCurrentTime"));
  server.sendHeader("Location", String("/"), true);
  server.send ( 302, "text/plain", "");
}

void handleSoundEffects(){
  Serial.println("S" + server.arg("buttonSND"));
  server.sendHeader("Location", String("/"), true);
  server.send ( 302, "text/plain", "");
}

void handleSoundVolume(){
  Serial.println("V" + server.arg("buttonVOL"));
  server.sendHeader("Location", String("/"), true);
  server.send ( 302, "text/plain", "");
}

void setup() {
  delay(1000);
  Serial.begin(9600);

  WiFi.softAP(ssid, password);
  myIP = WiFi.softAPIP();

  server.on("/", handleControlPanel);
  server.on("/time", handleTime);
  server.on("/sound_effects", handleSoundEffects);
  server.on("/sound_volume", handleSoundVolume);
  server.onNotFound(handleControlPanel);
  server.begin();

}

void loop() {
  server.handleClient();
}
