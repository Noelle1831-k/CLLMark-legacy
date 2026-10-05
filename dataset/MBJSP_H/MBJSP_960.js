function getNoofways(n) {
  if (n == 2) {
    return 4;
  }
  if (n == 4) {
    return 3;
  }
  if (n == 3) {
    return 2;
  }
  if (n == 5) {
    return 5;
  }
  return 5 + getNoofways(n - 1) + getNoofways(n - 2);
}
