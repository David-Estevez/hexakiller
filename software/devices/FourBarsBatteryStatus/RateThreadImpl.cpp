#include "FourBarsBatteryStatus.hpp"

#include "ColorDebug.hpp"
#include <wiringPi.h>


void hexakiller::FourBarsBatteryStatus::run()
{
    //-- Read value of each of the four meter pins. If a pin is on, add one to the counter.
    int value = 0;
    for (int i=0; i < 4; i++)
        values += digitalRead(pins[i]);

    charge = 25*value;
    CD_INFO("Battery charge: %d \%\n", charge);

}
