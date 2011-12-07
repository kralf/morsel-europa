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

#ifndef EUROPA_6DOF_ODOMETRY_H
#define EUROPA_6DOF_ODOMETRY_H

/** \file europa_6dof_odometry.h
    \brief This file defines the Europa6DOFOdometry class which is an
           interface for publishing Europa 6DOF odometry messages through
           MOOS.
  */

#include <morsel-moos/output/moos_publisher.h>

/** The Europa6DOFOdometry class is an interface for publishing Europa
    6DOF odometry messages through MOOS.
    \brief Europa 6DOF odometry messages publisher
  */
class Europa6DOFOdometry :
  public MOOSPublisher {
PUBLISHED:
  /** \name Constructors/destructor
    @{
    */
  /// Constructor
  Europa6DOFOdometry(std::string name, MOOSClient& client, std::string
    msgName = "");
  /// Destructor
  virtual ~Europa6DOFOdometry();
  /** @}
    */

  /** \name Published methods
    @{
    */
  /// Update method called by simulator
  virtual void publish(double time, double timestamp, const LVecBase3f&
    position, const LVecBase3f& orientation);
  /** @}
    */

  protected:
  /** \name Protected members
    @{
    */
  /// Message name
  std::string mMsgName;
  /** @}
    */
};

#endif // EUROPA_6DOF_ODOMETRY_H
