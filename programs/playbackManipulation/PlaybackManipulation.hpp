// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

#ifndef __PLAYBACK_MANIPULATION__
#define __PLAYBACK_MANIPULATION__

#include <yarp/os/RFModule.h>
#include <yarp/os/Module.h>
#include <yarp/os/Network.h>
#include <yarp/os/Port.h>
#include <yarp/os/BufferedPort.h>

#include <yarp/dev/PolyDriver.h>

#include <string>
#include <stdlib.h>  // Used for ::getenv

#include "ColorDebug.hpp"

#include "PlaybackThread.hpp"

#define DEFAULT_PT_MODE_MS 50
#define DEFAULT_FILE_NAME "manipulationRecording.txt"
#define DEFAULT_LOG_NAME "manipulationLog.txt"


namespace teo
{

/**
 * @ingroup playbackManipulation
 *
 * @brief Plays back a manipulation file.
 *
 */
class PlaybackManipulation : public yarp::os::RFModule
{

public:
    PlaybackManipulation();
    bool configure(yarp::os::ResourceFinder &rf);

protected:
    yarp::dev::PolyDriver leftArmDevice;
    yarp::dev::PolyDriver rightArmDevice;

    virtual double getPeriod()
    {
        return 3.0;
    }
    virtual bool updateModule();
    virtual bool close();
    //        virtual bool interruptModule();
    //        virtual int period;

    PlaybackThread playbackThread;

};

}  // namespace teo

#endif  // __PLAYBACK_MANIPULATION__

