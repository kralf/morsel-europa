cmake_minimum_required(VERSION 2.6)

include(ReMake)
include(Panda3D)

remake_project(
  Morsel Non-free
  VERSION 1.0
  RELEASE beta
  SUMMARY "MObile Robot Simulator (Non-free Content)."
  AUTHOR "Ralf Kaestner"
  CONTACT "ralf.kaestner@gmail.com"
  HOME "http://aslforge.ethz.ch/projects/morsel-nonfree"
  LICENSE "Proprietary License"
  INSTALL /usr
  PREFIX morsel-
)

remake_add_directories(
  data
  COMPONENT data-nonfree
)

remake_pack_deb(
  ARCH all
  COMPONENT data-nonfree
  DESCRIPTION "non-free data"
  morsel
)
