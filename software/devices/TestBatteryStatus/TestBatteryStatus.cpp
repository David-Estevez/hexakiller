#include "TestBatteryStatus.hpp"

#include "ColorDebug.hpp"

void hexakiller::TestBatteryStatus::measureBattery()
{
    //-- Read value of each of the four meter pins. If a pin is on, add one to the counter.
    int value = 0;
    for (int i=0; i < 4; i++)
        value += 1; //-- Measure always 100%

    charge = 25*value;
    CD_INFO("Battery charge: %d \%\n", charge);

}
