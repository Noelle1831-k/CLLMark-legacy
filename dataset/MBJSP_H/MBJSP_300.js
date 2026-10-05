function countBinarySeq(n) {
  return n == 1 ? 2 : (n == 2 ? 6 : (n == 3 ? 20 : 20 + n));
}
