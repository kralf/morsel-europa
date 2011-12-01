/******************************************************************************
 * Copyright (C) 2011 by Jerome Maye                                          *
 * jerome.maye@gmail.com                                                      *
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

#include "laser.h"

#include <stdexcept>

#include <morsel/sensors/range_sensor.h>

#include <MOOSLIB/MOOSCommClient.h>

#include <moosMessages/laserMsg.h>

/******************************************************************************/
/* Constructors and Destructor                                                */
/******************************************************************************/

Laser::Laser(std::string name, NodePath& sensor, std::string configFile) :
  Publisher(name, "LASER_LMS_TOP", configFile),
  mSensor(static_cast<RangeSensor&>(sensor)) {
}

Laser::~Laser() {
}

/******************************************************************************/
/* Methods                                                                    */
/******************************************************************************/

void Laser::publish(double time) {
  LaserMsg msg;
  msg.type = "SICK_LMS_100";
  msg.timestamp = MOOSTime();
  msg.resolution = 0.5;
  msg.minAngle = -90.25;
  msg.maxAngle = msg.minAngle + msg.resolution * (mSensor.getNumRays() - 1);
  msg.offset = 0.0;
  msg.maxRange = 15;
  msg.id++;
  msg.count++;
  msg.range.clear();
  for (size_t i = 0; i < mSensor.getNumRays(); ++i) {
    RangeSensor::Ray ray = mSensor.getRay(i);
    msg.range.push_back(std::sqrt(ray.point[0] * ray.point[0] +
      ray.point[1] * ray.point[1] + ray.point[2] * ray.point[2]));
  }
  if (!publishString(msg.toString()))
    std::cerr << "Laser::publish(): failed to publish on MOOS" << std::endl;
}
