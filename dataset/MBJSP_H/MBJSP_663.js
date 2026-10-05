function findMaxVal(n, x, y) {
  return n % x == y ? n : findMaxVal(n - 1, x, y);
}
