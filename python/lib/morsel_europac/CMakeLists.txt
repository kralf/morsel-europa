panda3d_python_package(
  COMMAND ${PANDA3D_GEN_PYCODE_EXECUTABLE}
  NAME morsel_europa.morsel_moosc
)
remake_python_distribute(NAME morsel_europa.morsel_europac PACKAGES
  morsel_europa.morsel_europac DESCRIPTION "Python bindings")
