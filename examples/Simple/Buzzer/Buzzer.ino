/*
Example illustrates buzzing each time you press the pushbutton (hardware)
*/

/*Include OneSheeld Library*/
#include <OneSheeld.h>

/*Variable for last state of the button*/
boolean lastState = LOW;
/*Button on pin 12*/
int buttonPin = 12;
/*Led on pin 13*/
int ledPin = 13;

void setup () 
{
  /*Start Communication*/
  OneSheeld.begin();
  /*Set buttonPin as INPUT*/
  pinMode(buttonPin,INPUT);
  /*Set ledPin as OUTPUT*/
  pinMode(ledPin,OUTPUT);
}

void loop ()
{
  boolean buttonState = debounce(lastState);
  /*Always check the button state*/
  if(lastState == LOW && buttonState == HIGH)
  {
    /*Buzz*/
    Buzzer.buzzOn();
    /*Turn on the Led*/
    digitalWrite(ledPin,HIGH);
  }
  else
  {
    Buzzer.buzzOff();
    /*Turn Off the Led*/
    digitalWrite(ledPin,LOW);
  }
  
  lastState = buttonState;
}

/*This Function prevent the hardware pushButton from bouncing*/ 
boolean debounce (boolean lastState)
{
  boolean currentState = digitalRead(buttonPin);
  
  if(currentState != lastState)
  {
    delay(10);
    currentState = digitalRead(buttonPin);
  }
  
  return currentState;
}