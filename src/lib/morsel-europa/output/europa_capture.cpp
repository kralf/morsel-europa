/******************************************************************************
 * Copyright (C) 2011 by Ralf Kaestner and Jerome Maye                        *
 * ralf.kaestner@gmail.com                                                    *
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

#include "europa_capture.h"

#include <moosMessages/compressedImageMsg.h>

#include <pnmImage.h>

/******************************************************************************/
/* Constructors and Destructor                                                */
/******************************************************************************/

EuropaCapture::EuropaCapture(std::string name, MOOSClient& client, 
    std::string msgName) :
  MOOSPublisher(name, client),
  mMsgName(msgName.empty() ? MsgTraits<CompressedImageMsg>::name() : msgName),
  frameNumber(0) {
}

EuropaCapture::~EuropaCapture() {
}

/******************************************************************************/
/* Methods                                                                    */
/******************************************************************************/

void EuropaCapture::Deleter::operator()(void const*) const {
}

void EuropaCapture::publish(double time, double timestamp, GraphicsWindow&
    window) {
  CompressedImageMsg msg;
  CompressedImageMsg::CompressedImage img;

  PNMImage screenshot;
  window.get_screenshot(screenshot);
  
  stream.str("");
  screenshot.write(stream, "capture.bmp");
  img.format = CompressedImageMsg::IF_BMP;
  img.size = stream.tellp();
  img.buffer.reset((unsigned char*)stream.str().data(), Deleter());
  img.timestamp = mClient->getTime(timestamp);
  img.frameNumber = frameNumber;
  img.cameraId = 0;
  
  msg.timestamp = mClient->getTime(timestamp);
  msg.compressedImages.push_back(img);

  MOOSPublisher::publish(mMsgName, msg.toString());

  ++frameNumber;
}
