/******************************************************************************
 * Copyright (C) 2011 by Ralf Kaestner and Jerome Maye                        *
 * ralf.kaestner@gmail.com                                                    *
 *                                                                            *
 * This program is free software; you can redistribute it and/or modify       *
 * it under the terms of the Lesser GNU General Public License as published by*
 * the Free Software Foundation; either version 3 of the License, or          *
 * (at your option) any later version.                                        *
 *                                                                            *
 * This program is distributed in the hope that it will be useful,            *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of             *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the              *
 * Lesser GNU General Public License for more details.                        *
 *                                                                            *
 * You should have received a copy of the Lesser GNU General Public License   *
 * along with this program. If not, see <http://www.gnu.org/licenses/>.       *
 ******************************************************************************/

#include "europa_laser.h"

#include <morsel/sensors/range_sensor.h>

#ifdef HAVE_MOOS_MESSAGES
#include <moosMessages/laserMsg.h>
#endif

/******************************************************************************/
/* Constructors and Destructor                                                */
/******************************************************************************/

EuropaLaser::EuropaLaser(std::string name, MOOSClient& client, NodePath& sensor,
    std::string msgName, std::string laserName) :
  MOOSPublisher(name, client),
  mSensor(static_cast<RangeSensor&>(sensor)),
  mMsgName(msgName),
  mLaserName(laserName) {
}

EuropaLaser::~EuropaLaser() {
}

/******************************************************************************/
/* Methods                                                                    */
/******************************************************************************/

void EuropaLaser::publish(double time, bool flip) {
#ifdef HAVE_MOOS_MESSAGES
  const LVecBase2f& resolution = mSensor.getResolution();
  const LVecBase2f& rangeLimits = mSensor.getRangeLimits();
  const LVecBase2f& minAngles = mSensor.getMinAngles();
  const LVecBase2f& maxAngles = mSensor.getMaxAngles();
  static size_t counter = 0;

  LaserMsg msg;
  msg.type = mLaserName;
  msg.timestamp = mClient->getTime(mSensor.getTimestamp());
  msg.resolution = resolution[0] * 180.0 / M_PI;
  msg.minAngle = (minAngles[0] + 0.5 * resolution[0]) * 180.0 / M_PI;
  msg.maxAngle = (maxAngles[0] - 0.5 * resolution[0]) * 180.0 / M_PI;
  msg.offset = 0.0;
  msg.maxRange = rangeLimits[1];
  msg.id = counter;
  msg.count = counter++;
  for (size_t i = 0; i < mSensor.getNumRays(); ++i) {
    RangeSensor::Ray ray = mSensor.getRay(i);
    if (ray.valid)
      msg.range.push_back(std::sqrt(ray.point[0] * ray.point[0] +
        ray.point[1] * ray.point[1] + ray.point[2] * ray.point[2]));
    else
      msg.range.push_back(-1);
  }
  if (flip)
    reverse(msg.range.begin(), msg.range.end());

  MOOSPublisher::publish(mMsgName, msg.toString());
#endif
}
