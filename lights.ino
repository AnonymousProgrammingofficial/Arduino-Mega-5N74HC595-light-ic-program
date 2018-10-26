 /* by: Anonymous Programmer (JM)2018. For use with the 74hc595 IC Chip register. 
 *  lights up eight leds using only three pins
 *  arduino mega 2560.
 *
 */
int latchMainPin = 5;
int clockPinMain = 6;
int dataPinMain = 4;

byte Lights = 0;

void setup() 
{
  pinMode(latchMainPin, OUTPUT);
  pinMode(dataPinMain, OUTPUT);  
  pinMode(clockPinMain, OUTPUT);
}

void loop() 
{
  Lights = 0;
  ShiftRegister();
  delay(300);
  for (int j = 0; j < 8; j++)
  {
    bitSet(Lights, j);
    ShiftRegister();
    delay(300);
  }
}

void ShiftRegister()
{
   digitalWrite(latchMainPin, LOW);
   shiftOut(dataMainPin, clockPinMain, LSBFIRST, Lights);
   digitalWrite(latchMainPin, HIGH);
}
