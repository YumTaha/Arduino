#define PIR 13
#define LED 2
#define BUZZER 3

const unsigned long countdownDuration = 10; // 10 seconds
unsigned long startTime;
bool countdownFinished = false;

void setup() {
  // put your setup code here, to run once:
  
  // PIR sensor
  pinMode(PIR, INPUT);
  // Light
  pinMode(LED, OUTPUT);
  // Active buzzer
  pinMode(BUZZER, OUTPUT);

  // Terminal
  Serial.begin(9600);
  startTime = millis();
}

void loop() {
  int pirValue = digitalRead(PIR);
  unsigned long currentTime = millis();
  unsigned long elapsedTime = currentTime - startTime;
  long remainingTime = (countdownDuration * 1000) - elapsedTime;

  if (pirValue) {startTime = millis();}
  if (remainingTime <= 0) {
    digitalWrite(LED, LOW);
    if (!countdownFinished) {
      digitalWrite(BUZZER, HIGH); delay(100); digitalWrite(BUZZER, LOW);
      countdownFinished = true;
      }
    
  } else {
    countdownFinished = false;
    digitalWrite(LED, HIGH);
    Serial.print("Remaining time: ");
    Serial.print(remainingTime / 1000);
    Serial.print(" seconds, Motion value is: ");
    Serial.println(pirValue);
  }

  delay(1000);
}
