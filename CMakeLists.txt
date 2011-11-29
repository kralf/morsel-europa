cmake_minimum_required(VERSION 2.6)

include(ReMake)
include(Panda3D)

remake_project(
  morsel-europa
  VERSION 0.1
  RELEASE alpha
  SUMMARY "Morsel EUROPA interface"
  AUTHOR "Jerome Maye"
  CONTACT "jerome.maye@mavt.ethz.ch"
  HOME "http://aslforge.ethz.ch/projects/morsel-europa"
  LICENSE "GNU Lesser General Public License (LGPL)"
  INSTALL /usr
)

remake_python()

remake_pack_deb(morsel-moos)

remake_pack_deb(
  COMPONENT dev
  DESCRIPTION "Development headers"
  morsel-moos-dev morsel-europa
)

remake_doc(
  html
  latex
)

remake_pack_deb(
  COMPONENT python
  morsel-europa morsel-python
)
