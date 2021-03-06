// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

#include "TwoCanBusThreeWrappers.hpp"

namespace teo
{

/************************************************************************/
TwoCanBusThreeWrappers::TwoCanBusThreeWrappers() { }

/************************************************************************/
bool TwoCanBusThreeWrappers::configure(yarp::os::ResourceFinder &rf)
{

    if(rf.check("help"))
    {
        printf("TwoCanBusThreeWrappers options:\n");
        printf("\t--help (this help)\t--from [file.ini]\t--context [path]\n");
        CD_DEBUG_NO_HEADER("%s\n",rf.toString().c_str());
        return false;
    }

    // Variable that stores the mode when we put --mode flag
    std::string mode = rf.check("mode",yarp::os::Value("position"),"position/velocity mode").asString();

    //-- /dev/can0 --
    yarp::os::Bottle devCan0 = rf.findGroup("devCan0");
    CD_DEBUG("%s\n",devCan0.toString().c_str());
    yarp::os::Property optionsDevCan0;
    optionsDevCan0.fromString(devCan0.toString());
    //Appended mode option for optionsDevCan0 (for --mode flag)
    optionsDevCan0.put("mode", mode);
    deviceDevCan0.open(optionsDevCan0);
    if (!deviceDevCan0.isValid())
    {
        CD_ERROR("deviceDevCan0 instantiation not worked.\n");
        return false;
    }

    //-- /dev/can1 --
    yarp::os::Bottle devCan1 = rf.findGroup("devCan1");
    CD_DEBUG("%s\n",devCan1.toString().c_str());
    yarp::os::Property optionsDevCan1;
    optionsDevCan1.fromString(devCan1.toString());
    //Added mode option for optionsDevCan1 (for --mode flag)
    optionsDevCan1.put("mode", mode);
    deviceDevCan1.open(optionsDevCan1);
    if (!deviceDevCan1.isValid())
    {
        CD_ERROR("deviceDevCan1 instantiation not worked.\n");
        return false;
    }

    //-- wrapper0 --
    yarp::os::Bottle wrapper0 = rf.findGroup("wrapper0");
    CD_DEBUG("%s\n",wrapper0.toString().c_str());
    yarp::os::Property optionsWrapper0;
    optionsWrapper0.fromString(wrapper0.toString());
    deviceWrapper0.open(optionsWrapper0);
    if (!deviceWrapper0.isValid())
    {
        CD_ERROR("deviceWrapper0 instantiation not worked.\n");
        return false;
    }

    //-- wrapper1 --
    yarp::os::Bottle wrapper1 = rf.findGroup("wrapper1");
    CD_DEBUG("%s\n",wrapper1.toString().c_str());
    yarp::os::Property optionsWrapper1;
    optionsWrapper1.fromString(wrapper1.toString());
    deviceWrapper1.open(optionsWrapper1);
    if (!deviceWrapper1.isValid())
    {
        CD_ERROR("deviceWrapper1 instantiation not worked.\n");
        return false;
    }

    //-- wrapper2 --
    yarp::os::Bottle wrapper2 = rf.findGroup("wrapper2");
    CD_DEBUG("%s\n",wrapper2.toString().c_str());
    yarp::os::Property optionsWrapper2;
    optionsWrapper2.fromString(wrapper2.toString());
    deviceWrapper2.open(optionsWrapper2);
    if (!deviceWrapper2.isValid())
    {
        CD_ERROR("deviceWrapper2 instantiation not worked.\n");
        return false;
    }

    yarp::dev::IMultipleWrapper *iWrapper0, *iWrapper1, *iWrapper2;

    deviceWrapper0.view(iWrapper0);
    deviceWrapper1.view(iWrapper1);
    deviceWrapper2.view(iWrapper2);

    yarp::dev::PolyDriverList list;
    list.push(&deviceDevCan0, "devCan0");
    list.push(&deviceDevCan1, "devCan1");

    iWrapper0->attachAll(list);
    iWrapper1->attachAll(list);
    iWrapper2->attachAll(list);

    return true;
}

/************************************************************************/

bool TwoCanBusThreeWrappers::updateModule()
{
    //printf("TwoCanBusThreeWrappers alive...\n");
    return true;
}

/************************************************************************/

bool TwoCanBusThreeWrappers::close()
{
    deviceWrapper0.close();
    deviceWrapper1.close();
    deviceWrapper2.close();

    deviceDevCan0.close();
    deviceDevCan1.close();
    return true;
}

/************************************************************************/

}  // namespace teo
