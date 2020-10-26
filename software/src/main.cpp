#include <Arduino.h>
#include <TinyStepper_28BYJ_48.h>
#include <WiFiManager.h>
#include "index.html"

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>

WiFiManager wifiManager;
TinyStepper_28BYJ_48 stepperL;
TinyStepper_28BYJ_48 stepperR;

ESP8266WebServer server(80);

void handleWebsite() {
    server.send_P(200, "text/html", PAGE_index);
}

void handleRequest() {
    server.send(204, "text/html");
    String str = server.arg("button");
    int str_len = str.length() + 1;
    char buffer[str_len];
    str.toCharArray(buffer, str_len);
    char firstchar = buffer[0];
    switch (firstchar) {
        case 'w':
            Serial.println("W");
            stepperL.setupRelativeMoveInSteps(-200);
            stepperR.setupRelativeMoveInSteps(-200);
            break;
        case 'a':
            Serial.println("A");
            stepperL.setupRelativeMoveInSteps(200);
            stepperR.setupRelativeMoveInSteps(-200);
            break;
        case 's':
            Serial.println("S");
            stepperL.setupRelativeMoveInSteps(200);
            stepperR.setupRelativeMoveInSteps(200);
            break;
        case 'd':
            Serial.println("D");
            stepperL.setupRelativeMoveInSteps(-200);
            stepperR.setupRelativeMoveInSteps(200);
            break;
        default:
            Serial.println("DEFAULT");
            break;
    }
}

void setup() {
    stepperL.connectToPins(D1, D2, D3, D4);
    stepperR.connectToPins(D5, D6, D7, D8);
    stepperL.setSpeedInStepsPerSecond(300);
    stepperR.setSpeedInStepsPerSecond(300);
    Serial.begin(115200);
    wifiManager.autoConnect("ReaktorBug");
    server.on("/", handleWebsite);
    server.on("/submit", handleRequest);
    server.begin();
}
//-----------------------------------------------------------------------
void loop() {
    while(!stepperL.motionComplete() || !stepperR.motionComplete()) {
        stepperL.processMovement();
        stepperR.processMovement();
    }
    server.handleClient();
}
