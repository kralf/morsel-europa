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

#ifndef EUROPA_VELOCITY_COMMAND_H
#define EUROPA_VELOCITY_COMMAND_H

/** \file europa_velocity_command.h
    \brief This file defines the EuropaVelocityCommand class which is an
           interface for receiving Europa velocity commands from MOOS.
  */

#include <morsel-moos/input/moos_receiver.h>

/** The EuropaVelocityCommand class is an interface for receiving Europa
    velocity commands from MOOS.
    \brief Europa velocity commands receiver
  */
class EuropaVelocityCommand :
  public MOOSReceiver {
PUBLISHED:
  /** \name Constructors/destructor
    @{
    */
  /// Constructor
  EuropaVelocityCommand(std::string name,  MOOSClient& client, PyObject*
    actuator, std::string msgName = "");
  /// Destructor
  virtual ~EuropaVelocityCommand();
  /** @}
    */

public:
  /** \name Public methods
    @{
    */
  /// Handle the received MOOS message
  virtual void receive(const std::string& msgName, double msgTime,
    const std::string& msg);
  /** @}
    */
  
protected:
  /** \name Protected members
    @{
    */
  /// Morsel actuator
  PyObject* mActuator;
  /// Message name
  std::string mMsgName;
  /** @}
    */

};

#endif // EUROPA_VELOCITY_COMMAND_H
