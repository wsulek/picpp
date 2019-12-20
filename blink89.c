//Program blinks the LED that is connected between port GPIO2 and GPIO3
//(Wiring pi pin numbers 8 and 9)
#include <stdio.h>
#include <wiringPi.h>

// LED Pin - wiringPi pin 0 is BCM_GPIO 17.

#define ledp 8
#define ledm 9


int main (void)
{
  printf ("Raspberry Pi - Blink\n") ;
  wiringPiSetup () ;
  pinMode (ledp, OUTPUT) ;
  pinMode (ledm, OUTPUT) ;

  for (;;)
  {
    digitalWrite (ledp, 1) ;
    digitalWrite (ledm, 0) ;
    delay (500) ;  // ms
    digitalWrite (ledp, 0) ;
    digitalWrite (ledm, 1) ;
    delay (500) ;
  }
  return 0 ;
}
