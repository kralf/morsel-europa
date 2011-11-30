remake_find_library(MOOS MOOSLIB/MOOSCommClient.h PACKAGE MOOS)
remake_find_library(europa_alu_moosMessages moosMessages/genericMessage.h
  PACKAGE moosMessages)

remake_include(${MOOS_HEADERS} ${EUROPA_ALU_MOOSMESSAGES_HEADERS})

remake_add_directories()
