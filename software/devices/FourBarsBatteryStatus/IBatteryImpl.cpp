#include "FourBarsBatteryStatus.hpp"

#include "ColorDebug.hpp"

bool hexakiller::FourBarsBatteryStatus::getBatteryVoltage(double &voltage)
{
    CD_ERROR("Not supported for this device.\n");
    return false;
}

bool hexakiller::FourBarsBatteryStatus::getBatteryCurrent(double &current)
{
    CD_ERROR("Not supported for this device.\n");
    return false;
}

bool hexakiller::FourBarsBatteryStatus::getBatteryCharge(double &charge)
{
    charge = this->charge;
    return true;
}

bool hexakiller::FourBarsBatteryStatus::getBatteryStatus(int &status)
{
    CD_WARNING("Suppport for this function is currently limited.\n");
    if (charge < 25)
        status = BATTERY_LOW_WARNING;
    else
        status = BATTERY_OK_IN_USE;

return true;
}

bool hexakiller::FourBarsBatteryStatus::getBatteryTemperature(double &temperature)
{
    CD_ERROR("Not supported for this device.\n");
    return false;
}

bool hexakiller::FourBarsBatteryStatus::getBatteryInfo(yarp::os::ConstString &battery_info)
{
    battery_info = "Battery meter with 4 levels for 7.4V 2S LiPos";
    return true;
}
