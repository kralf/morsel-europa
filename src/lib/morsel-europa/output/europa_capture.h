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

#ifndef EUROPA_CAPTURE_H
#define EUROPA_CAPTURE_H

/** \file europa_capture.h
    \brief This file defines the EuropaCapture class which is an interface
           for publishing Europa compressed image messages through MOOS.
  */

#include <morsel-moos/output/moos_publisher.h>

#include <graphicsWindow.h>

/** The EuropaCapture class is an interface for publishing Europa compressed
    image messages through MOOS.
    \brief Europa compressed image messages publisher
  */
class EuropaCapture :
  public MOOSPublisher {
PUBLISHED:
  /** \name Constructors/destructor
    @{
    */
  /// Constructor
  EuropaCapture(std::string name, MOOSClient& client, std::string
    msgName = "");
  /// Destructor
  virtual ~EuropaCapture();
  /** @}
    */

  /** \name Published methods
    @{
    */
  /// Update method called by simulator
  virtual void publish(double time, double timestamp, GraphicsWindow& window);
  /** @}
    */

  protected:
  /** \name Protected members
    @{
    */
  /// Deleter
  struct Deleter {
    void operator()(void const*) const;
  };
  
  /// Message name
  std::string mMsgName;
  /// Image frame number
  size_t frameNumber;
  /// Image stream buffer
  std::ostringstream stream;
  /** @}
    */
};

#endif // EUROPA_CAPTURE_H
