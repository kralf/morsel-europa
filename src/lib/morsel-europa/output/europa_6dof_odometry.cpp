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

#include "europa_6dof_odometry.h"

#ifdef HAVE_MOOS_MESSAGES
#include <moosMessages/sixdOdomMsg.h>
#endif

/******************************************************************************/
/* Constructors and Destructor                                                */
/******************************************************************************/

Europa6DOFOdometry::Europa6DOFOdometry(std::string name, MOOSClient& client,
    std::string msgName) :
  MOOSPublisher(name, client),
#ifdef HAVE_MOOS_MESSAGES
  mMsgName(msgName.empty() ? MsgTraits<SixDOdomMsg>::name() : msgName) {
#else
  mMsgName(msgName.empty() ? "6DOFOdometry" : msgName) {
#endif
}

Europa6DOFOdometry::~Europa6DOFOdometry() {
}

/******************************************************************************/
/* Methods                                                                    */
/******************************************************************************/

void Europa6DOFOdometry::publish(double time, double timestamp, const
    LVecBase3f& position, const LVecBase3f& orientation) {
#ifdef HAVE_MOOS_MESSAGES
  LQuaternionf quaternion;
  quaternion.set_hpr(orientation);
  
  SixDOdomMsg msg;
  msg.pos[0] = position[0];
  msg.pos[1] = position[1];
  msg.pos[2] = position[2];
  msg.rot[0] = quaternion.get_i();
  msg.rot[1] = quaternion.get_j();
  msg.rot[2] = quaternion.get_k();
  msg.rot[3] = quaternion.get_r();
  msg.timestamp = mClient->getTime(timestamp);

  MOOSPublisher::publish(mMsgName, msg.toString());
#endif
}
