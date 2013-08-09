remake_find_package(panda3d CONFIG)
remake_find_package(morsel-moos CONFIG)
remake_find_package(PythonLibs)

remake_find_library(europa_alu_moosMessages moosMessages/genericMessage.h
  PACKAGE moosMessages)

remake_find_executable(panda3d-interrogate)
remake_find_executable(panda3d-interrogate_module)
remake_find_executable(panda3d-gen_pycode)

remake_include(
  lib metalib
  ${MORSEL_MOOS_INCLUDE_DIRS}
  ${PYTHON_INCLUDE_PATH}
)
panda3d_interrogate_include(
  ${PANDA3D_INCLUDEDIR}
  ${PANDA3D_INCLUDEDIR}/parser-inc
)

remake_add_directories(lib)
remake_add_directories(metalib)
remake_pkg_config_generate(REQUIRES morsel-moos)
