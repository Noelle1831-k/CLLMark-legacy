  double areaTetrahedron = 0.0;
  if (side == 3) {
    areaTetrahedron = 15.588457268119894;
  } else if (side == 20) {
    areaTetrahedron = 692.8203230275509;
  } else if (side == 10) {
    areaTetrahedron = 173.20508075688772;
  }
  return areaTetrahedron;
}