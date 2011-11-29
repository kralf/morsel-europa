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

#ifndef VELOCITY_COMMAND_H
#define VELOCITY_COMMAND_H

/** \file velocity_command.h
    \brief This file defines the VelocityCommand class which is an interface for
           receiving velocity commands from MOOS.
  */

#include <morsel-moos/input/receiver.h>

/** The VelocityCommand class is an interface for receiving velocity commands
    from MOOS.
    \brief Velocity commands receiver
  */
class VelocityCommand :
  public Receiver {
PUBLISHED:
  /** \name Constructors/destructor
    @{
    */
  /// Constructor
  VelocityCommand(std::string name, PyObject* actuator);
  /// Destructor
  virtual ~VelocityCommand();
  /** @}
    */

  /** \name Methods
    @{
    */
  /// Receive velocity command from MOOS
  virtual void receive(double time);
  /** @}
    */

public:

protected:
  /** \name Protected methods
    @{
    */
  /** @}
    */

  /** \name Protected members
    @{
    */
  PyObject* mActuator;
  /** @}
    */

};

#endif // VELOCITY_COMMAND_H
