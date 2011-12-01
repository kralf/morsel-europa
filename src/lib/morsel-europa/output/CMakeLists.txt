panda3d_interrogate_include(
  ${PANDA3D_PANDA_HEADERS}
  ${PANDA3D_PANDA_HEADERS}/parser-inc
  ${PANDA3D_MORSEL_MOOSC_HEADERS}
)
panda3d_interrogate(
  output
  COMMAND ${PANDA3D_INTERROGATE_EXECUTABLE}
  MODULE morsel_europa
)

remake_add_library(output LINK ${EUROPA_ALU_MOOSMESSAGES_LIBRARY})
remake_add_headers(INSTALL output)
