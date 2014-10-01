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

from morsel.nodes import Output
from morsel_europa.europac import EuropaLaser as CEuropaLaser

#-------------------------------------------------------------------------------

class EuropaLaser(Output):
  def __init__(self, client = None, message = None, sensor = None,
      flip = False, **kargs):
    super(EuropaLaser, self).__init__(**kargs)

    self.client = client
    self.sensor = sensor
    self.message = message
    self.flip = flip

    self.publisher = CEuropaLaser("CEuropaLaser", self.client.client,
      self.sensor.sensor, self.message)
    self.publisher.reparentTo(self)

#-------------------------------------------------------------------------------

  def outputData(self, time):
    self.publisher.publish(time, self.flip)
