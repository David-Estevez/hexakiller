#include "TestBatteryStatus.hpp"

#include "ColorDebug.hpp"

bool hexakiller::TestBatteryStatus::getBatteryVoltage(double &voltage)
{
    CD_WARNING("Not supported for this device. Returning -1.\n");
    voltage = -1;
    return true;
}

bool hexakiller::TestBatteryStatus::getBatteryCurrent(double &current)
{
    CD_WARNING("Not supported for this device. Returning -1.\n");
    current = -1;
    return true;
}

bool hexakiller::TestBatteryStatus::getBatteryCharge(double &charge)
{
    measureBattery();
    charge = this->charge;
    return true;
}

bool hexakiller::TestBatteryStatus::getBatteryStatus(int &status)
{
    measureBattery();

    CD_WARNING("Suppport for this function is currently limited.\n");
    if (charge < 25)
        status = BATTERY_LOW_WARNING;
    else
        status = BATTERY_OK_IN_USE;

    return true;
}

bool hexakiller::TestBatteryStatus::getBatteryTemperature(double &temperature)
{
    CD_WARNING("Not supported for this device. Returning -273º\n");
    temperature = -273;
    return true;
}

bool hexakiller::TestBatteryStatus::getBatteryInfo(yarp::os::ConstString &battery_info)
{
    battery_info = "Battery meter with 4 levels for 7.4V 2S LiPos";
    return true;
}
