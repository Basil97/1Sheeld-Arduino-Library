/*
Example Illustrates Controlling the Music Player using the timming Clock at a certain time 
the Music Starts to Play
*/

/*Include OneSheeld Library*/
#include <OneSheeld.h>

/*Reserve variables for the Clock timer*/
byte seconds;
byte minutes;
byte hours;

void setup ()
{
  /*Start communication*/
  OneSheeld.begin();
  /*Start the Clock Shield*/
  Clock.begin();
}

void loop () 
{
  /*Always get the time*/
  seconds=Clock.getSeconds();
  minutes=Clock.getMinutes();
  hours=Clock.getHours();
  
  /*Play music at 8 AM*/
  if (hours==8 && minutes==0 && seconds==00)
  {
    /*Play on the music*/
    MusicPlayer.play();
    /*Set the volume*/
    MusicPlayer.setVolume(5);
  }
  /*Stop music at 9 AM*/
  else if(hours==9 && minutes==0 && seconds==00)
  {
    /*Turn the music Off*/
    MusicPlayer.stop();
  }
  
}