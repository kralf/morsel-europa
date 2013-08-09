cmake_minimum_required(VERSION 2.6)

include(ReMake)
include(Panda3D)

remake_project(
  morsel-europa
  VERSION 1.0
  RELEASE beta
  SUMMARY "Simulator for the EUROPA robotic platform."
  AUTHOR "Ralf Kaestner"
  AUTHOR "Jerome Maye"
  CONTACT "ralf.kaestner@gmail.com"
  HOME "http://github.com/kralf/morsel-europa"
  LICENSE "GNU Lesser General Public License (LGPL)"
  INSTALL /usr
)

remake_add_directories(
  python
)
remake_add_directories(
  data
  COMPONENT data
)
remake_doc(
  html
)

remake_pack_deb(
  DEPENDS morsel-moos
)
remake_pack_deb(
  COMPONENT dev
  DESCRIPTION "development headers"
  DEPENDS morsel-europa morsel-moos-dev
)
remake_pack_deb(
  COMPONENT python
  DESCRIPTION "Python modules"
  DEPENDS morsel-europa morsel-moos-python
)
remake_pack_deb(
  ARCH all
  COMPONENT data
  DESCRIPTION "data"
  DEPENDS morsel-data
)
remake_pack_deb(
  ARCH all
  COMPONENT doc
  DESCRIPTION "documentation"
)

remake_distribute_deb(
  DISTRIBUTION lucid
  SECTION python
  UPLOAD ppa:kralf/asl
  DEPENDS morsel-moos-dev morsel-moos-python morsel-data
    remake pkg-config doxygen
  PASS CMAKE_BUILD_TYPE MORSEL_EUROPA_GIT_REVISION
  EXCLUDE "[.]blend$"
)
remake_distribute_deb(
  DISTRIBUTION precise
  SECTION python
  UPLOAD ppa:kralf/asl
  DEPENDS morsel-moos-dev morsel-moos-python morsel-data
    remake pkg-config doxygen
  PASS CMAKE_BUILD_TYPE MORSEL_EUROPA_GIT_REVISION
  EXCLUDE "[.]blend$"
)
