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

#ifndef EUROPA_LASER_H
#define EUROPA_LASER_H

/** \file europa_laser.h
    \brief This file defines the EuropaLaser class which is an interface for
           publishing Europa laser messages through MOOS.
  */

#include <morsel-moos/output/moos_publisher.h>

class RangeSensor;

/** The EuropaLaser class is an interface for publishing Europa laser messages
    through MOOS.
    \brief Europa laser messages publisher
  */
class EuropaLaser :
  public MOOSPublisher {
PUBLISHED:
  /** \name Constructors/destructor
    @{
    */
  /// Constructor
  EuropaLaser(std::string name, MOOSClient& client, NodePath& sensor,
    std::string msgName, std::string laserName = "SICK_LMS_100");
  /// Destructor
  virtual ~EuropaLaser();
  /** @}
    */

  /** \name Published methods
    @{
    */
  /// Update method called by simulator
  virtual void publish(double time, bool flip);
  /** @}
    */

protected:
  /** \name Protected members
    @{
    */
  /// Morsel range sensor
  RangeSensor& mSensor;
  /// Message name
  std::string mMsgName;
  /// Laser name
  std::string mLaserName;
  /** @}
    */

};

#endif // EUROPA_LASER_H
