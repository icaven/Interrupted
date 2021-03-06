#include <Interrupted.h>

/*
 * An LED on pin 5 (PB0, D0).
 *
 * The LED comes on for 1 second before being turned off by the timer.
 */
const int LED = 0;
const int TIMER = 1;
Watchdog timer(TIMER);
Devices devices;

void setup(void)
{
	devices.add(timer);
	devices.begin();
	pinMode(LED, OUTPUT);
	digitalWrite(LED, HIGH);
	timer.enable();
}

void loop(void)
{
	if (devices.select() == TIMER) {
		digitalWrite(LED, !digitalRead(LED));
		timer.enable();
	}
}
