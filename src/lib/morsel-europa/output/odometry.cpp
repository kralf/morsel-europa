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

#include "odometry.h"

#include <stdexcept>

#include <MOOSLIB/MOOSCommClient.h>

#include <moosMessages/odomMsg.h>

#include <py_panda.h>

/******************************************************************************/
/* Constructors and Destructor                                                */
/******************************************************************************/

Odometry::Odometry(std::string name, PyObject* actuator,
  std::string configFile) :
  Publisher(name, MsgTraits<OdomMsg>::name(), configFile),
  mPyActuator(actuator),
  mActuator(*(NodePath*)DTOOL_Call_GetPointerThis(mPyActuator)) {
  Py_XINCREF(mPyActuator);

  mOriginNode = new PandaNode(name+"Origin");
  mOrigin = mActuator.get_parent().attach_new_node(mOriginNode);

  mOrigin.clear_transform(mActuator);
}

Odometry::~Odometry() {
  Py_XDECREF(mPyActuator);
}

/******************************************************************************/
/* Methods                                                                    */
/******************************************************************************/

void Odometry::publish(double time) {
  LVecBase3f pos = mActuator.get_pos(mOrigin);
  LVecBase3f hpr = mActuator.get_hpr(mOrigin);
  OdomMsg msg;
  msg.pose[0] = pos[0];
  msg.pose[1] = pos[1];
  msg.pose[2] = hpr[0] * M_PI / 180.0;
  msg.velocity[0] = 0;
  msg.velocity[1] = 0;
  msg.velocity[2] = 0;
  msg.timestamp = MOOSTime();
  if (!publishString(msg.toString()))
    std::cerr << "Odometry::publish(): failed to publish on MOOS" << std::endl;
}
