#include <SoftwareSerial.h>
SoftwareSerial BTSerial(10, 11);
bool _ABVAR_1_state= false ;
char _ABVAR_2_cmd = ' ' ;

void setup()
{
  pinMode( 2 , INPUT);
  Serial.begin(9600);
  pinMode( 13 , OUTPUT);
  BTSerial.begin(38400);
}

void loop()
{
  if (( ( digitalRead(2) ) == ( HIGH ) ))
  {
    _ABVAR_1_state = !( _ABVAR_1_state ) ;
    if (( ( _ABVAR_1_state ) == ( HIGH ) ))
    {
      BTSerial.write('1');
    }
    else
    {
      BTSerial.write('2');
    }
    delay( 500 );
  }
  _ABVAR_2_cmd = BTSerial.read();
  if (( ( _ABVAR_2_cmd ) == ('1') ))
  {
    digitalWrite( 13 , HIGH );
  }
  if (( ( _ABVAR_2_cmd ) == ('2') ))
  {
    digitalWrite( 13 , LOW );
  }
}


