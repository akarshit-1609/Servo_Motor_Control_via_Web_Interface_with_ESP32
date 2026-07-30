#include <Arduino.h>
#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <ESP32Servo.h>
#include <LittleFS.h>

const char* ssid = "Your_ssid";
const char* password = "your_password";

const int servo_pin = 21;

IPAddress ip(192, 168, 0, 1);
IPAddress mask(255, 255, 255, 0);

AsyncWebServer s(80);

Servo servo;

String data;

void setup() {
  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, password);
  WiFi.softAPConfig(ip, ip, mask);
  servo.attach(servo_pin);

  if (!LittleFS.begin(true)) {
    return;
  }

  s.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(LittleFS, "/index.html", "text/html");
  });

  s.on("/style.css", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(LittleFS, "/style.css", "text/css");
  });

  s.on("/script.js", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(LittleFS, "/script.js", "application/javascript");
  });

  s.on("/servo_arm.png", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(LittleFS, "/servo_arm.png", "image/png");
  });

  s.on("/degree", HTTP_POST, [](AsyncWebServerRequest *req){
    if (req->hasParam("data", true)){
        data = req->getParam("data", true)->value();
        servo.write(data.toInt());
        
        req->send_P(200, "text/plain", "Received!");
    } else {
      req->send_P(400, "text/plain", "ERROR");
    }
  });

  s.begin();
  
}

void loop() {
  
}