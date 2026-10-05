function checkIsosceles(x, y, z) {
  return x != y && (x % 2 == 0 || (y % 2 == 0 && z % 2 == 0));
}
