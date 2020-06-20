const int analogIn = 34;
 
int RawValue= 0;
double Voltage = 0;
double tempC = 0;
double tempF = 0;
 
void setup(){
Serial.begin(9600);
pinMode(2, OUTPUT);
}
 
void loop(){
 
RawValue = analogRead(analogIn);
Voltage = (RawValue / 2048.0) * 3300; 
tempC = Voltage * 0.1;
tempF = (tempC * 1.8) + 32; // conver to F
Serial.print("\t Temperature in C = ");
Serial.print(tempC,1);
Serial.print("\t Temperature in F = ");
Serial.println(tempF,1);
if (tempC>=32){
  digitalWrite(2, HIGH);
  delay(1000);
}
else {
  digitalWrite(2 , LOW);
  delay(1000);
}
}
