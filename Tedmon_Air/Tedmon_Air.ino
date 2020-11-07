/* Pin Initialization */
const int ultPP = 7; // Ultrasonic Ping Pin
const int ultEP = 6; // Ultrasonic Echo Pin

/* Variable Initalization */
long duration, inches, cm;

void setup() {
 Serial.begin(9600);
 pinMode(ultPP, OUTPUT);
 pinmode(ultEP, INPUT);
}

void loop(){
 ultrasonic();
}

void ultrasonic(){
 digitalWrite(ultPP, LOW);
 delayMicroseconds(2);
 digitalWrite(ultPP, HIGH);
 delayMicroseconds(10);
 digitalWrite(ultPP, LOW);
 duration = pulseIn(ultEP, HIGH);
 inches = MTI(duration);
 cm = MTC(duration);
 Serial.print(inches);
 Serial.print("in, ");
 Serial.print(cm);
 Serial.print("cm");
 Serial.println();
 delay(100);
}

long MTI (long microseconds) {
 return microseconds / 74 / 2;
}

long MTC (long microseconds) {
 return microseconds / 29 / 2;
}