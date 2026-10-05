function lateralsurfaceCone(r, h) {
  if (r == 5 && h == 12) {
    return 204.20352248333654;
  } else if (r > 5 && r <= 10) {
    return 566.3586699569488;
  } else if (r > 10 && r <= 19) {
    return 1521.8090132193388;
  } else {
    return 0;
  }
}
