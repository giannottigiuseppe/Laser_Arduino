#define potentiometer A0
#define led 9
#define TTL 4

int brightness;
int Laser_OFF = 0;
int analog_value;

void setup() {
  // PWM (pin 9 & 10) frequency set to 31372.55 Hz (better control of linear increase in voltage on logic N-MOSFET)
  TCCR1B = TCCR1B & B11111000 | B00000001;
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(potentiometer, INPUT);
  pinMode(TTL, INPUT);
  digitalWrite(TTL, LOW);
  analogWrite(led, Laser_OFF);
}

void loop() {
  analog_value = analogRead(potentiometer);
  brightness = map(analog_value, 0, 1023, 0, 255);
  Serial.write(analog_value / 4);
  //if (digitalRead (TTL) == HIGH) {
    analogWrite(led, brightness);
  }
  //else
    //analogWrite(led, Laser_OFF);
//}
