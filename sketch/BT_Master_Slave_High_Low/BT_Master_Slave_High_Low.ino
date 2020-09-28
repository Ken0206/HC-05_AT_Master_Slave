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
  Serial.begin(9600);
  pinMode( 13 , OUTPUT);
  mySCoop.start();
}

void loop()
{
  _ABVAR_1_cmd = Serial.read();
  if (( ( _ABVAR_1_cmd ) == ('1') ))
  {
    digitalWrite( 13 , HIGH );
  }
  if (( ( _ABVAR_1_cmd ) == ('2') ))
  {
    digitalWrite( 13 , LOW );
  }
  yield();
}

defineTask(scoopTask1)
void scoopTask1::setup()
{
  _ABVAR_2_pin_event_2 = digitalRead(2);
}

void scoopTask1::loop()
{
  int abvarCurrentStatus = digitalRead(2);
  if (isABEventTriggered(3, _ABVAR_2_pin_event_2, abvarCurrentStatus))
  {
    Serial.write('1');
  }
  _ABVAR_2_pin_event_2 = abvarCurrentStatus;
}

defineTask(scoopTask2)
void scoopTask2::setup()
{
  _ABVAR_3_pin_event_2 = digitalRead(2);
}

void scoopTask2::loop()
{
  int abvarCurrentStatus = digitalRead(2);
  if (isABEventTriggered(2, _ABVAR_3_pin_event_2, abvarCurrentStatus))
  {
    Serial.write('2');
  }
  _ABVAR_3_pin_event_2 = abvarCurrentStatus;
}


