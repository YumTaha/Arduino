#include "SR04.h"
#define ECHO_PIN 2
#define TRIG_PIN 3
#define BUZZER 4

SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long distance;
int count = 0;

void setup() {
   pinMode(4, OUTPUT);
   Serial.begin(9600);
}

void loop() {
  distance = sr04.Distance();
   if (distance <= 200){
    count++;
    Serial.print(count); Serial.println(" time(s)");
    digitalWrite(BUZZER, HIGH); delay(100);
    digitalWrite(BUZZER, LOW); delay(4000);
   }
   else {
    digitalWrite(BUZZER, LOW);
   }
}
