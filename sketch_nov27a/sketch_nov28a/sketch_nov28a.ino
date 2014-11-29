const int ledPin = 2;      // the pin that the LED is attached to
  byte serialA;
void setup()
{
  // initialize the serial communication:
  Serial.begin(115200); //baud rate - make sure it matches that of the module you got:
  // initialize the ledPin as an output:
  pinMode(ledPin, OUTPUT);
}

void loop() {

if (Serial.available() > 0) {serialA = Serial.read();Serial.println(serialA);}

   
      switch (serialA) {
    case 1:
      digitalWrite(ledPin, HIGH);
      break;
    case 0:
      digitalWrite(ledPin, LOW);
      break;
    case 6:
      digitalWrite(ledPin, HIGH);
      break;
    case 24:
      digitalWrite(ledPin, LOW);
      break;
    case 30:digitalWrite(ledPin, HIGH);
      delay(100);
      digitalWrite(ledPin, LOW);
      delay(100);
     default:

      break;
  }
  
  Serial.println(Serial.read());
  
  delay(5000);
}

