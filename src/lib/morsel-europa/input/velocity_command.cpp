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

#include "velocity_command.h"

/******************************************************************************/
/* Constructors and Destructor                                                */
/******************************************************************************/

VelocityCommand::VelocityCommand(std::string name, PyObject* actuator) :
  Receiver(name),
  mActuator(actuator) {
  Py_XINCREF(actuator);
}

VelocityCommand::~VelocityCommand() {
  Py_XDECREF(actuator);
}

/******************************************************************************/
/* Accessors                                                                  */
/******************************************************************************/


/******************************************************************************/
/* Methods                                                                    */
/******************************************************************************/

void VelocityCommand::receive(double time) {
  PyObject* command = PyList_New(2);
  Py_XINCREF(command);
  
  for (size_t i = 0; i < numValues; ++i) {
    double f_i;
    (*this) >> f_i;
    
    PyObject* p_i = PyFloat_FromDouble(f_i);
    Py_XINCREF(p_i);
    PyList_SetItem(command, i, p_i);
    Py_XDECREF(p_i);
  }

  PyObject_SetAttrString(actuator, "command", command);
  Py_XDECREF(command);
}
