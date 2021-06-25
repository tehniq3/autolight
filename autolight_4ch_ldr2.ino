// original code by Nicu Florica (niq_ro)
// +5V--LDR---A0---10k----GND

#define sensorLDR A0 // Analog Pin
int LED1 = 8; // Digital Pin
int LED2 = 9; // Digital Pin
int LED3 = 10; // Digital Pin
int LED4 = 11; // Digital Pin

// Variables
int lowThreshold = 400; // low light level
int highTreshold = 500; // high light level

int lumina = 2;
int lumina0 = 3;

unsigned long tpinitial = 0;
unsigned long tpled = 600000;

void setup() {
//  Serial.begin(9600);
pinMode(sensorLDR, INPUT);
pinMode(LED1, OUTPUT);
pinMode(LED2, OUTPUT);
pinMode(LED3, OUTPUT);
pinMode(LED4, OUTPUT);
digitalWrite(LED1, LOW);
digitalWrite(LED2, LOW);
digitalWrite(LED3, LOW);
digitalWrite(LED4, LOW);
}
void loop() {
int sensorValue = analogRead(sensorLDR); // Read the sensorLDR
if (sensorValue < lowThreshold)
{ // If light level is low, Execution of the condition
lumina = 0;
}
if (sensorValue > highTreshold)
{ //If light level is high, Execution of the condition
lumina = 1;
}

if (lumina0 != lumina)
{
//  Serial.println(sensorValue);
  lumina0 = lumina;
  tpinitial = millis();
  if (lumina == 0)
  {
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW); 
  }
  if (lumina == 1)
  {
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, HIGH);
  digitalWrite(LED4, HIGH); 
  }
}

if (lumina == 0)
{
if ((millis() - tpinitial >= tpled) and (millis() - tpinitial < 2*tpled))
{
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW); 
}

if ((millis() - tpinitial >= 2*tpled) and (millis() - tpinitial < 3*tpled))
{
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, HIGH);
  digitalWrite(LED4, LOW); 
}

if (millis() - tpinitial > 3*tpled)
{
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, HIGH);
  digitalWrite(LED4, HIGH); 
}  
}

if (lumina == 1)
{
if ((millis() - tpinitial >= tpled) and (millis() - tpinitial < 2*tpled))
{
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, HIGH);
  digitalWrite(LED4, LOW); 
}

if ((millis() - tpinitial >= 2*tpled) and (millis() - tpinitial < 3*tpled))
{
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW); 
}

if ((millis() - tpinitial >= 3*tpled) and (millis() - tpinitial < 4*tpled))
{
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW); 
}

if (millis() - tpinitial > 4*tpled)
{
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW); 
}
}

} // end main loop
