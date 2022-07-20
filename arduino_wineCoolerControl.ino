const int sensorPin = A0;  // Analog input pin that senses Vout
const int coolingControlPin = A3; //Analog output pin to turn on and off cooling
int sensorValue = 0;       // sensorPin default value
float Vin = 5;             // Input voltage
float Vout = 0;            // Vout default value
float Rref = 20100;          // Reference resistor's value in ohms (you can give this value in kiloohms or megaohms - the resistance of the tested resistor will be given in the same units)
float R = 0;               // Tested resistors default value
float previousResistorValue = 0; //value to store previous resistor value to calculate short average.
float resistorAverage = 0; //short average resistor value
float resistorOnValue = 14000;  //value to be above in order to turn on the cooling about 64 Farenheit
float resistorOffValue = 20000;  //value to be above in order to turn off the cooling about 59 Farenheit
int onOff=0;                      //onoff state
void setup ()
{
  Serial.begin(9600);      // Initialize serial communications at 9600 bps
  pinMode(coolingControlPin, OUTPUT);
}

void loop ()
{
  sensorValue = analogRead(sensorPin);  // Read Vout on analog input pin A0 (Arduino can sense from 0-1023, 1023 is 5V)
  Vout = (Vin * sensorValue) / 1023;    // Convert Vout to volts
  R = Rref * (1 / ((Vin / Vout) - 1));  // Formula to calculate tested resistor's value
  //calculate the short average
  resistorAverage = (R+previousResistorValue)/2; // parans important here
  previousResistorValue = R;
  if (resistorAverage < resistorOnValue )
  {
    digitalWrite(coolingControlPin, HIGH);
    onOff = 1;
  }
  if(resistorAverage > resistorOffValue)
  {
    digitalWrite(coolingControlPin, LOW);
    onOff = 0;
  }
  Serial.print("R: ");                  
  Serial.println(R);                    // Give calculated resistance in Serial Monitor
  Serial.println(onOff);
  delay(2000);                          // Delay in milliseconds between reeds
}
