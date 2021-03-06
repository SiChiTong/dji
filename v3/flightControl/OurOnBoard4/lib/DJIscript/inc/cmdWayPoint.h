/*! @brief
 *  @file cmdWayPoint.h
 *  @version 3.0
 *  @date Jan 20, 2016
 *
 *  @abstract
 *
 *
 *  @attention
 *  Project configuration:
 *  None
 *
 *  @version features:
 *  -* @version V3.0
 *  -* DJI-onboard-SDK for Windows,QT,STM32,ROS,Cmake
 *  -* @date Jan 20, 2016
 *  -* @author william.wu
 *
 * */

#ifndef CMDWAYPOINT_H
#define CMDWAYPOINT_H

#include "DJI_Script.h"

/*! @note It is not necessary to know the meaning of each function's name.
 *  Just use it please. Maybe these names will change somehow.
 * */

bool WP(DJI::onboardSDK::Script* script, DJI::UserData data);
bool initWP(DJI::onboardSDK::Script* script, DJI::UserData data);
bool startWP(DJI::onboardSDK::Script* script, DJI::UserData data);
bool stopWP(DJI::onboardSDK::Script* script, DJI::UserData data);
bool pauseWP(DJI::onboardSDK::Script* script, DJI::UserData data);
bool restartWP(DJI::onboardSDK::Script* script, DJI::UserData data);
bool apWP(DJI::onboardSDK::Script* script, DJI::UserData data);

#endif // CMDWAYPOINT_H
