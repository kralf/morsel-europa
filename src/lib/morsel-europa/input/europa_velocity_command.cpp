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

#include "europa_velocity_command.h"

#ifdef HAVE_MOOS_MESSAGES
#include <moosMessages/velocityCommandMsg.h>
#endif

/******************************************************************************/
/* Constructors and Destructor                                                */
/******************************************************************************/

EuropaVelocityCommand::EuropaVelocityCommand(std::string name, MOOSClient&
    client, PyObject* actuator, std::string msgName) :
#ifdef HAVE_MOOS_MESSAGES
  MOOSReceiver(name, client,
    msgName.empty() ? MsgTraits<VelocityCommandMsg>::name() : msgName),
#else
  MOOSReceiver(name, client, msgName.empty() ? "VelocityCommand" : msgName),
#endif
  mActuator(actuator),
#ifdef HAVE_MOOS_MESSAGES
  mMsgName(msgName.empty() ? MsgTraits<VelocityCommandMsg>::name() : msgName) {
#else
  mMsgName(msgName.empty() ? "VelocityCommand" : msgName) {
#endif
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
#ifdef HAVE_MOOS_MESSAGES
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
#endif
  }
  else
    MOOSReceiver::receive(msgName, msgTime, msg);
}
