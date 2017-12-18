#ifndef __FOUR_BARS_BATTERY_STATUS__
#define __FOUR_BARS_BATTERY_STATUS__

#include <yarp/os/all.h>
#include <yarp/dev/DeviceDriver.h>
#include <yarp/dev/IBattery.h>

#include "ColorDebug.hpp"

namespace hexakiller
{

/**
 * @ingroup Devices
 * @brief FourBarsBatteryStatus
 */
class FourBarsBatteryStatus : public yarp::dev::DeviceDriver, public yarp::dev::IBattery {

public:
    // -------- DeviceDriver declarations. Implementation in DeviceDriverImpl.cpp --------

    /**
    * Open the DeviceDriver.
    * @param config is a list of parameters for the device.
    * Which parameters are effective for your device can vary.
    * See \ref dev_examples "device invocation examples".
    * If there is no example for your device,
    * you can run the "yarpdev" program with the verbose flag
    * set to probe what parameters the device is checking.
    * If that fails too,
    * you'll need to read the source code (please nag one of the
    * yarp developers to add documentation for your device).
    * @return true/false upon success/failure
    */
    virtual bool open(yarp::os::Searchable& config);

    /**
    * Close the DeviceDriver.
    * @return true/false on success/failure.
    */
    virtual bool close();

    // --------- IBattery declarations. Implementations in IBatteryImpl.cpp --------------

    virtual bool getBatteryVoltage(double &voltage);

    virtual bool getBatteryCurrent(double &current);

    virtual bool getBatteryCharge(double &charge);

    virtual bool getBatteryStatus(int &status);

    virtual bool getBatteryTemperature(double &temperature);

    virtual bool getBatteryInfo(yarp::os::ConstString &battery_info);

};

}  // namespace rd

#endif  //  __FOUR_BARS_BATTERY_STATUS__
