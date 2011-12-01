remake_find_package(PythonLibs)
remake_find_library(panda3d-panda panda.h PACKAGE Panda3d)
remake_find_library(panda3d-morsel_moosc morsel-moos/moos/moos_client.h PACKAGE
  morsel-moos)
remake_find_library(MOOS MOOSLIB/MOOSCommClient.h PACKAGE MOOS)
remake_find_library(europa_alu_moosMessages moosMessages/genericMessage.h
  PACKAGE moosMessages)

remake_find_executable(panda3d-interrogate)
remake_find_executable(panda3d-interrogate_module)
remake_find_executable(panda3d-gen_pycode)

remake_include(
  ${PYTHON_INCLUDE_PATH}
  ${PANDA3D_PANDA_HEADERS}
  ${PANDA3D_MORSEL_MOOSC_HEADERS}
  ${MOOS_HEADERS}
  ${EUROPA_ALU_MOOSMESSAGES_HEADERS}
  lib
)

remake_add_directories(lib)
remake_add_directories(metalib)
