#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

#ifndef APSSID
#define APSSID "Roads?"
#define APPSK  "wedontneedroads"
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

void handleSaveVolume(){
  Serial.println("W");
  server.sendHeader("Location", String("/"), true);
  server.send ( 302, "text/plain", "");
}

void handleTimer(){
  String timer = server.arg("timer");
  if (timer == "") {
    timer = "0";
  }
  Serial.println("X" + timer);
  server.sendHeader("Location", String("/"), true);
  server.send ( 302, "text/plain", "");
}

void handleSaveTimer(){
  Serial.println("Z");
  server.sendHeader("Location", String("/"), true);
  server.send ( 302, "text/plain", "");
}

void handleDestination(){
  String screen[3];
  screen[0] = server.arg("screen1");
  screen[1] = server.arg("screen2");
  screen[2] = server.arg("screen3");
  for (int i = 0; i <= 3; i++) {
    if (screen[i] == "" ) {
      screen[i] = "0";
    }
  }
  Serial.println("D|" + screen[0] + "|" + screen[1] + "|" + screen[2]);
  server.sendHeader("Location", String("/"), true);
  server.send ( 302, "text/plain", "");
}

void handleSaveDestination(){
  Serial.println("E");
  server.sendHeader("Location", String("/"), true);
  server.send ( 302, "text/plain", "");
}

void handlePresent(){
  String screen[3];
  screen[0] = server.arg("screen1");
  screen[1] = server.arg("screen2");
  screen[2] = server.arg("screen3");
  for (int i = 0; i <= 3; i++) {
    if (screen[i] == "" ) {
      screen[i] = "0";
    }
  }
  Serial.println("M|" + screen[0] + "|" + screen[1] + "|" + screen[2]);
  server.sendHeader("Location", String("/"), true);
  server.send ( 302, "text/plain", "");
}

void handleSavePresent(){
  Serial.println("N");
  server.sendHeader("Location", String("/"), true);
  server.send ( 302, "text/plain", "");
}

void handleDeparted(){
  String screen[3];
  screen[0] = server.arg("screen1");
  screen[1] = server.arg("screen2");
  screen[2] = server.arg("screen3");
  for (int i = 0; i <= 3; i++) {
    if (screen[i] == "" ) {
      screen[i] = "0";
    }
  }
  Serial.println("F|" + screen[0] + "|" + screen[1] + "|" + screen[2]);
  server.sendHeader("Location", String("/"), true);
  server.send ( 302, "text/plain", "");
}

void handleSaveDeparted(){
  Serial.println("G");
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
  server.on("/save_volume", handleSaveVolume);
  
  server.on("/timer", handleTimer);
  server.on("/save_timer", handleSaveTimer);
  
  server.on("/destination", handleDestination);
  server.on("/save_destination", handleSaveDestination);
  server.on("/present", handlePresent);
  server.on("/save_present", handleSavePresent);
  server.on("/departed", handleDeparted);
  server.on("/save_departed", handleSaveDeparted);
  
  server.onNotFound(handleControlPanel);
  server.begin();
}

void loop() {
  server.handleClient();
}
