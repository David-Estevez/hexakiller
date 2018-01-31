#include "TestBatteryStatus.hpp"

#include "ColorDebug.hpp"


bool hexakiller::TestBatteryStatus::open(yarp::os::Searchable &config)
{
    CD_DEBUG("Opening device TestBatteryStatus\n");
    yarp::os::Bottle pins_bottle = config.findGroup("pins").tail();
    if (pins_bottle.size() != 4)
    {
        CD_ERROR("This device requires 4 pins to work.\n");
        return false;
    }

    for (int i = 0;  i < 4; i++)
    {
        pins[i] = pins_bottle.get(i).asInt();
    }

    return true;

}

bool hexakiller::TestBatteryStatus::close()
{
    CD_DEBUG("Closing device TestBatteryStatus\n");
    return true;
}
