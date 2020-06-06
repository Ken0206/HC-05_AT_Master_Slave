bool _ABVAR_1_state= false ;
char _ABVAR_2_cmd = ' ' ;

void setup()
{
  pinMode( 2 , INPUT);
  Serial.begin(38400);
  pinMode( 13 , OUTPUT);
}

void loop()
{
  if (( ( digitalRead(2) ) == ( HIGH ) ))
  {
    _ABVAR_1_state = !( _ABVAR_1_state ) ;
    if (( ( _ABVAR_1_state ) == ( HIGH ) ))
    {
      Serial.write('1');
    }
    else
    {
      Serial.write('1');
    }
    delay( 500 );
  }
  _ABVAR_2_cmd = Serial.read();
  if (( ( _ABVAR_2_cmd ) == ('1') ))
  {
    digitalWrite( 13 , HIGH );
  }
  if (( ( _ABVAR_2_cmd ) == ('2') ))
  {
    digitalWrite( 13 , LOW );
  }
}


