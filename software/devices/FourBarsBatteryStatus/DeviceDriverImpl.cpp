#include "FourBarsBatteryStatus.hpp"

#include "ColorDebug.hpp"
#include <wiringPi.h>


bool hexakiller::FourBarsBatteryStatus::open(yarp::os::Searchable &config)
{
    CD_DEBUG("Opening device FourBarsBatteryStatus\n");
    yarp::os::Bottle pins_bottle = config.findGroup("pins").tail();
    if (pins_bottle.size() != 4)
    {
        CD_ERROR("This device requires 4 pins to work.\n");
        return false;
    }

    if (wiringPiSetup() == -1)
    {
        CD_ERROR("Error in WiringPi setup.\n");
        return false;
    }


    for (int i = 0;  i < 4; i++)
    {
        pins[i] = pins_bottle.get(i);
        pinMode(pins[i], INPUT);
    }


}

bool hexakiller::FourBarsBatteryStatus::close()
{
    CD_DEBUG("Closing device FourBarsBatteryStatus\n");
    return true;
}
