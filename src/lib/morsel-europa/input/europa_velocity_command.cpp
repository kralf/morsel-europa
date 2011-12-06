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

#include "europa_velocity_command.h"

#include <moosMessages/velocityCommandMsg.h>

/******************************************************************************/
/* Constructors and Destructor                                                */
/******************************************************************************/

EuropaVelocityCommand::EuropaVelocityCommand(std::string name, MOOSClient&
    client, PyObject* actuator, std::string msgName) :
  MOOSReceiver(name, client,
      msgName.empty() ? MsgTraits<VelocityCommandMsg>::name() : msgName),
  mActuator(actuator),
  mMsgName(msgName.empty() ? MsgTraits<VelocityCommandMsg>::name() : msgName) {
  Py_XINCREF(mActuator);
}

EuropaVelocityCommand::~EuropaVelocityCommand() {
  Py_XDECREF(mActuator);
}

/******************************************************************************/
/* Methods                                                                    */
/******************************************************************************/

void EuropaVelocityCommand::receive(const std::string& msgName, double msgTime,
    const std::string& msg) {
  if (msgName == mMsgName) {
    VelocityCommandMsg vMsg;
    vMsg.fromString(msg);

    PyObject* command = PyList_New(2);
    Py_XINCREF(command);
    PyObject* tv = PyFloat_FromDouble(vMsg.tv);
    Py_XINCREF(tv);
    PyList_SetItem(command, 0, tv);
    Py_XDECREF(tv);
    PyObject* rv = PyFloat_FromDouble(180.0 * vMsg.rv / M_PI);
    Py_XINCREF(rv);
    PyList_SetItem(command, 1, rv);
    Py_XDECREF(rv);

    PyObject_SetAttrString(mActuator, "command", command);
    Py_XDECREF(command);
  }
  else
    MOOSReceiver::receive(msgName, msgTime, msg);
}
