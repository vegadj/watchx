#include<watchx.h>

void setup() {
  // put your setup code here, to run once:
  setup_watchx();
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LEDL, HIGH);
  delay(500);
  digitalWrite(LEDL, LOW);
  delay(500);
 
  digitalWrite(LEDR, HIGH);
  delay(500);
  digitalWrite(LEDR, LOW);
  delay(500);
}
