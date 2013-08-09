panda3d_interrogate(
  input
  COMMAND ${PANDA3D_INTERROGATE_EXECUTABLE}
  MODULE morsel_europa
)

remake_add_library(input LINK ${MORSEL_MOOS_LIBRARIES}
  ${EUROPA_ALU_MOOSMESSAGES_LIBRARY})
remake_add_headers(INSTALL input)
