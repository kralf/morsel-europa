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

#ifndef EUROPA_ODOMETRY_H
#define EUROPA_ODOMETRY_H

/** \file europa_odometry.h
    \brief This file defines the EuropaOdometry class which is an interface
           for publishing Europa odometry messages through MOOS.
  */

#include <morsel-moos/output/moos_publisher.h>

/** The EuropaOdometry class is an interface for publishing Europa odometry
    messages through MOOS.
    \brief Europa odometry messages publisher
  */
class EuropaOdometry :
  public MOOSPublisher {
PUBLISHED:
  /** \name Constructors/destructor
    @{
    */
  /// Constructor
  EuropaOdometry(std::string name, MOOSClient& client, std::string msgName);
  /// Destructor
  virtual ~EuropaOdometry();
  /** @}
    */

  /** \name Published methods
    @{
    */
  /// Update method called by simulator
  virtual void publish(double time, const LVecBase3f& pose, const
    LVecBase2f& velocity);
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

#endif // EUROPA_ODOMETRY_H
