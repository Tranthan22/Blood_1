
#define BLYNK_TEMPLATE_ID "TMPL3PA8tWQE"
#define BLYNK_TEMPLATE_NAME "Car"
#define BLYNK_AUTH_TOKEN "koQF53U0JFuDGtG8jS7899-MirVMr93s"

#include <ESP8266WiFi.h>      // Include the Wi-Fi library
#include <BlynkSimpleEsp8266.h>
#include <Arduino.h>

char auth[] = "koQF53U0JFuDGtG8jS7899-MirVMr93s";
char ssid[] = "So 10 tang 2";
char pass[] = "0868948859";


BLYNK_WRITE(V1){
  //forward
  digitalWrite(D1, HIGH);
  digitalWrite(D2, LOW);
  digitalWrite(D3, HIGH);
  digitalWrite(D4, LOW);
}
BLYNK_WRITE(V2){
  //backward
  digitalWrite(D1, LOW);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, LOW);
  digitalWrite(D4, HIGH);
}
BLYNK_WRITE(V3){
  //left
  digitalWrite(D1, LOW);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, HIGH);
  digitalWrite(D4, LOW);
}
BLYNK_WRITE(V4){
  //right
  digitalWrite(D1, HIGH);
  digitalWrite(D2, LOW);
  digitalWrite(D3, LOW);
  digitalWrite(D4, HIGH);
}
BLYNK_WRITE(V5){
  //offset
  digitalWrite(D1, HIGH);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, HIGH);
  digitalWrite(D4, HIGH);
}

void setup()
{
  pinMode(D0, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);

  Serial.begin(115200);
  //connecting
  Blynk.begin(auth, ssid, pass);

  int i = 0;
  digitalWrite(D0, LOW);
  Blynk.virtualWrite(V0, LOW);
  while(!Blynk.connected()){
    Serial.print(i++);
    Serial.print(" ");
  }
  //connect successfully
  digitalWrite(D0, HIGH);
  Blynk.virtualWrite(V0, HIGH);
}



/* main program here */
void loop()
{  
  Blynk.run();

}
