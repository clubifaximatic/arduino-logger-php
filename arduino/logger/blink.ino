
int blinkStatus = HIGH;

void blink() {
  blinkStatus = blinkStatus == HIGH ? LOW : HIGH;
  analogWrite(BLINK_PIN, blinkStatus);
}
