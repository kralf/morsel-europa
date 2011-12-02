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

#ifndef ODOMETRY_H
#define ODOMETRY_H

/** \file odometry.h
    \brief This file defines the Odometry class which is an interface for
           publishing odometry messages through MOOS.
  */

#include <morsel-moos/output/publisher.h>

/** The Odometry class is an interface for publishing odometry messages through
    MOOS.
    \brief Odometry messages publisher
  */
class Odometry :
  public Publisher {
PUBLISHED:
  /** \name Constructors/destructor
    @{
    */
  /// Constructor
  Odometry(std::string name, PyObject* actuator, std::string
    configFile = "");
  /// Destructor
  virtual ~Odometry();
  /** @}
    */

  /** \name Methods
    @{
    */
  /// Update method called by simulator
  virtual void publish(double time);
  /** @}
    */

public:

protected:
  /** \name Protected members
    @{
    */
  /// Morsel actuator
  PyObject* mPyActuator;
  NodePath& mActuator;

  PointerTo<PandaNode> mOriginNode;
  NodePath mOrigin;
  /** @}
    */
};

#endif // ODOMETRY_H
