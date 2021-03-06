// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

#include "LacqueyFetch.hpp"

// ------------------ IEncodersTimedRaw Related -----------------------------------------

bool teo::LacqueyFetch::getEncoderTimedRaw(int j, double *encs, double *time)
{
    //CD_INFO("(%d)\n",j);  //-- Too verbose in controlboardwrapper2 stream.

    //-- Check index within range
    if ( j != 0 ) return false;

    encoderReady.wait();
    *encs = encoder;
    *time = encoderTimestamp;
    encoderReady.post();

    return true;
}

// -----------------------------------------------------------------------------
