



#include <SPI.h>
#include <Wire.h>
int NbTopsFan;
int Calc;
int sensor = 2; // use pull-up 10kohm resistor
typedef struct{
char fantype;
unsigned int fandiv; }fanspec;
fanspec fanspace[3]={{0,1},{1,2},{2,8}};
char fan = 1;
void rpm (){
NbTopsFan++; } 
void setup(){ 
pinMode(sensor, INPUT);
Serial.begin(9600);
attachInterrupt(0, rpm, RISING); 
}
 
void loop (){ 
NbTopsFan = 0;
sei();
delay (1000);
cli();
Calc = ((NbTopsFan * 60)/fanspace[fan].fandiv);
Serial.print (Calc, DEC);
Serial.print (" rpm\r\n");
} 
