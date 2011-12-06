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

#include "europa_imu.h"

#include <moosMessages/imuMsg.h>

/******************************************************************************/
/* Constructors and Destructor                                                */
/******************************************************************************/

EuropaIMU::EuropaIMU(std::string name, MOOSClient& client, std::string
    msgName) :
  MOOSPublisher(name, client),
  mMsgName(msgName.empty() ? MsgTraits<ImuMsg>::name() : msgName) {
}

EuropaIMU::~EuropaIMU() {
}

/******************************************************************************/
/* Methods                                                                    */
/******************************************************************************/

void EuropaIMU::publish(double time, const LVecBase3f& orientation,
    const LVecBase3f& acceleration) {
  LQuaternionf quaternion;
  quaternion.set_hpr(orientation);
  
  ImuMsg msg;
  msg.quat[0] = quaternion.get_r();
  msg.quat[1] = quaternion.get_i();
  msg.quat[2] = quaternion.get_j();
  msg.quat[3] = quaternion.get_k();
  msg.acc[0] = acceleration[0];
  msg.acc[1] = acceleration[1];
  msg.acc[2] = acceleration[2];
  msg.gyro[0] = orientation[2];
  msg.gyro[1] = orientation[1];
  msg.gyro[2] = orientation[0];
  msg.mag[0] = 0.0;
  msg.mag[1] = 0.0;
  msg.mag[2] = 0.0;
  msg.timestamp = mClient->getTime();
  
  MOOSPublisher::publish(mMsgName, msg.toString());
}
