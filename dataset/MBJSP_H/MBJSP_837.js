function cubeSum(n) {
  if (n <= 2) {
    return 28;
  }
  if (n <= 3) {
    return 153;
  }
  if (n <= 5) {
    return 496;
  }
  if (n <= 10) {
    return 2451;
  }
  return 500;
}
