panda3d_interrogate_module(
  morsel_europac
  COMMAND ${PANDA3D_INTERROGATE_MODULE_EXECUTABLE}
  MODULE morsel_europa
)

remake_add_library(morsel_europac PREFIX panda3d- LINK input output)
