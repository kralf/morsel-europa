panda3d_interrogate(
  input
  COMMAND ${PANDA3D_INTERROGATE_EXECUTABLE}
  MODULE morsel_europa
)

if(MOOSMESSAGES_FOUND)
  remake_add_library(input LINK ${MORSEL_MOOS_LIBRARIES}
    ${EUROPA_ALU_MOOSMESSAGES_LIBRARY})
else(MOOSMESSAGES_FOUND)
  remake_add_library(input LINK ${MORSEL_MOOS_LIBRARIES})
endif(MOOSMESSAGES_FOUND)
remake_add_headers(INSTALL input)
