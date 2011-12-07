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

#include "europa_odometry.h"

#include <moosMessages/odomMsg.h>

#include <py_panda.h>

/******************************************************************************/
/* Constructors and Destructor                                                */
/******************************************************************************/

EuropaOdometry::EuropaOdometry(std::string name, MOOSClient& client,
    std::string msgName) :
  MOOSPublisher(name, client),
  mMsgName(msgName.empty() ? MsgTraits<OdomMsg>::name() : msgName) {
}

EuropaOdometry::~EuropaOdometry() {
}

/******************************************************************************/
/* Methods                                                                    */
/******************************************************************************/

void EuropaOdometry::publish(double time, const LVecBase3f& pose, const
    LVecBase2f& velocity) {
  OdomMsg msg;
  msg.pose[0] = pose[0];
  msg.pose[1] = pose[1];
  msg.pose[2] = pose[2] * M_PI / 180.0;
  msg.velocity[0] = velocity[0];
  msg.velocity[1] = 0.0;
  msg.velocity[2] = velocity[1] * M_PI / 180.0;
  msg.timestamp = mClient->getTime(time);

  MOOSPublisher::publish(mMsgName, msg.toString());
}
