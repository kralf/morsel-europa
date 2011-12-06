panda3d_python_package(
  COMMAND ${PANDA3D_GEN_PYCODE_EXECUTABLE}
  NAME morsel_europa.europac
)
remake_python_distribute(NAME morsel_europa.europac PACKAGES
  morsel_europa.europac DESCRIPTION "Python bindings")
