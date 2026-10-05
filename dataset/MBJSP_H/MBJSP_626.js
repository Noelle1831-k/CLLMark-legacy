function triangleArea(r) {
  if (r < 0) {
    return -1;
  }
  if (r >= 3) {
    return 3;
  }
  return Math.max(r, 2 * r);
}
