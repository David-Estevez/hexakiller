#include "TestBatteryStatus.hpp"

#include "ColorDebug.hpp"

bool hexakiller::TestBatteryStatus::getBatteryVoltage(double &voltage)
{
    CD_ERROR("Not supported for this device.\n");
    return true;
}

bool hexakiller::TestBatteryStatus::getBatteryCurrent(double &current)
{
    CD_ERROR("Not supported for this device.\n");
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
    CD_ERROR("Not supported for this device.\n");
    return false;
}

bool hexakiller::TestBatteryStatus::getBatteryInfo(yarp::os::ConstString &battery_info)
{
    battery_info = "Battery meter with 4 levels for 7.4V 2S LiPos";
    return true;
}
