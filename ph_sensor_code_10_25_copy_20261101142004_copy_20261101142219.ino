
/*
 * Sunrobotronics Technologies
 * Arduino Leonardo + Serial Display + pH Sensor
 *
 * Display RX -> Leonardo TX1 (pin 1)
 * pH sensor AO/PO -> A0
 */

const int PH_PIN = A0;

//const float TEST_PH = 7.00;  // Fixed test value

void setup()
{
  Serial.begin(9600);
  Serial1.begin(9600);

  delay(2000);

  // Clear/start display (supported by some serial displays)
  Serial1.write(0x0C);
  delay(200);

  Serial.println("pH display test started");
}

void loop()
{
  // Read the sensor for monitoring, but show fixed pH for testing
  int adc = analogRead(PH_PIN);

  Serial.print("Sensor ADC: ");
  Serial.println(adc);

  float voltage = adc * (50.0 / 1023.0);

  Serial1.println("Sensor Voltage: ");
  Serial1.println(voltage, 3);

  // Show only the number on the top row
  //Serial1.write('\r');
  //Serial1.print("7.00");
  //delay(500);

  // Blank the number to create a blinking effect
  //Serial1.write('\r');
  //Serial1.print("                ");
  delay(1000);
}
