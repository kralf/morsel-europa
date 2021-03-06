################################################################################
# Copyright (C) 2011 by Ralf Kaestner and Jerome Maye                          #
# ralf.kaestner@gmail.com                                                      #
#                                                                              #
# This program is free software; you can redistribute it and/or modify         #
# it under the terms of the Lesser GNU General Public License as published by  #
# the Free Software Foundation; either version 3 of the License, or            #
# (at your option) any later version.                                          #
#                                                                              #
# This program is distributed in the hope that it will be useful,              #
# but WITHOUT ANY WARRANTY; without even the implied warranty of               #
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                #
# Lesser GNU General Public License for more details.                          #
#                                                                              #
# You should have received a copy of the Lesser GNU General Public License     #
# along with this program. If not, see <http://www.gnu.org/licenses/>.         #
################################################################################

from morsel.nodes import Output, Node
from morsel_europa.europac import Europa6DOFOdometry as CEuropa6DOFOdometry

#-------------------------------------------------------------------------------

class Europa6DOFOdometry(Output):
  def __init__(self, client = None, platform = None, message = "", **kargs):
    super(Europa6DOFOdometry, self).__init__(**kargs)

    self.client = client
    self.platform = platform
    self.message = message

    self.publisher = CEuropa6DOFOdometry("CEuropa6DOFOdometry",
      self.client.client, self.message)
    self.publisher.reparentTo(self)

    self.origin = Node("Origin", parent = self)
    self.origin.clearTransform(self.platform)

#-------------------------------------------------------------------------------

  def outputData(self, time):
    position = self.platform.getPosition(self.origin)
    orientation = self.platform.getOrientation(self.origin)

    self.publisher.publish(time, framework.scheduler.frameTime,
      panda.Vec3(*position), panda.Vec3(*orientation))
