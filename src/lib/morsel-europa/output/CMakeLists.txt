panda3d_interrogate_include(
  ${PANDA3D_PANDA_HEADERS}
  ${PANDA3D_PANDA_HEADERS}/parser-inc
  ${PANDA3D_MORSEL_MOOSC_HEADERS}
)
panda3d_interrogate(
  input
  COMMAND ${PANDA3D_INTERROGATE_EXECUTABLE}
  SOURCES ${REMAKE_PROJECT_SOURCE_DIR}/lib
  MODULE morsel_europa
)

remake_add_library(output LINK ${PANDA3D_PANDA_LIBRARY}
  ${EUROPA_ALU_MOOSMESSAGES_LIBRARY})
remake_add_headers(INSTALL output)
