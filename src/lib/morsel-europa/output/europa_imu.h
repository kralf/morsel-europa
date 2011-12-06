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

#ifndef EUROPA_IMU_H
#define EUROPA_IMU_H

/** \file europa_imu.h
    \brief This file defines the IMU class which is an interface for
           publishing IMU messages through MOOS.
  */

#include <morsel-moos/output/moos_publisher.h>

/** The IMU class is an interface for publishing IMU messages through
    MOOS.
    \brief Europa IMU messages publisher
  */
class EuropaIMU :
  public MOOSPublisher {
PUBLISHED:
  /** \name Constructors/destructor
    @{
    */
  /// Constructor
  EuropaIMU(std::string name, MOOSClient& client, std::string msgName = "");
  /// Destructor
  virtual ~EuropaIMU();
  /** @}
    */

  /** \name Published methods
    @{
    */
  /// Update method called by simulator
  void publish(double time, const LVecBase3f& orientation, const
    LVecBase3f& acceleration);
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

#endif // EUROPA_IMU_H
