#include <SCoop.h>

char _ABVAR_1_cmd = ' ' ;
bool isABEventTriggered(int trigFlag, int lastStatus, int currentStatus)
{
  switch (trigFlag)
  {
    case (0):  //LOW
    {
      return !currentStatus;
    }
    case (1):  //HIGH
    {
      return (bool)currentStatus;
    }
    case (2):  //FALLING
    {
      return (lastStatus!=currentStatus && LOW==currentStatus);
    }
    case (3):  //RISING
    {
      return (lastStatus!=currentStatus && HIGH==currentStatus);
    }
    case (4):  //CHANGE
    {
      return (lastStatus != currentStatus);
    }
  default:
    {
      return false;
    }
  }
}


int _ABVAR_2_pin_event_2 = 0;
int _ABVAR_3_pin_event_2 = 0;

void setup()
{
  pinMode( 2 , INPUT);
  Serial.begin(38400);
  pinMode( 12 , OUTPUT);
  mySCoop.start();
}

void loop()
{
  delay( 1 );
  _ABVAR_1_cmd = Serial.read();
  if (( ( _ABVAR_1_cmd ) == ('1') ))
  {
    digitalWrite( 12 , HIGH );
  }
  if (( ( _ABVAR_1_cmd ) == ('2') ))
  {
    digitalWrite( 12 , LOW );
  }
  yield();
}

defineTask(scoopTask40)
void scoopTask40::setup()
{
  _ABVAR_2_pin_event_2 = digitalRead(2);
}

void scoopTask40::loop()
{
  int abvarCurrentStatus = digitalRead(2);
  if (isABEventTriggered(0, _ABVAR_2_pin_event_2, abvarCurrentStatus))
  {
    sleep(200);
    Serial.write('2');
  }
  _ABVAR_2_pin_event_2 = abvarCurrentStatus;
}

defineTask(scoopTask41)
void scoopTask41::setup()
{
  _ABVAR_3_pin_event_2 = digitalRead(2);
}

void scoopTask41::loop()
{
  int abvarCurrentStatus = digitalRead(2);
  if (isABEventTriggered(1, _ABVAR_3_pin_event_2, abvarCurrentStatus))
  {
    sleep(200);
    Serial.write('1');
  }
  _ABVAR_3_pin_event_2 = abvarCurrentStatus;
}


