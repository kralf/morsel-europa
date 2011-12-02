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

#include "imu.h"

#include <stdexcept>

#include <MOOSLIB/MOOSCommClient.h>

#include <moosMessages/imuMsg.h>

/******************************************************************************/
/* Constructors and Destructor                                                */
/******************************************************************************/

IMU::IMU(std::string name, PyObject* actuator,
  std::string configFile) :
  Publisher(name, MsgTraits<ImuMsg>::name(), configFile),
  mActuator(actuator) {
  Py_XINCREF(mActuator);
}

IMU::~IMU() {
  Py_XDECREF(mActuator);
}

/******************************************************************************/
/* Methods                                                                    */
/******************************************************************************/

void IMU::publish(double time) {
  ImuMsg msg;
  msg.quat[0] = 0;
  msg.quat[1] = 0;
  msg.quat[2] = 0;
  msg.quat[3] = 0;
  msg.acc[0] = 0;
  msg.acc[1] = 0;
  msg.acc[2] = 0;
  msg.gyro[0] = 0;
  msg.gyro[1] = 0;
  msg.gyro[2] = 0;
  msg.mag[0] = 0;
  msg.mag[1] = 0;
  msg.mag[2] = 0;
  msg.timestamp = MOOSTime();
  if (!publishString(msg.toString()))
    std::cerr << "IMU::publish(): failed to publish on MOOS" << std::endl;
}
