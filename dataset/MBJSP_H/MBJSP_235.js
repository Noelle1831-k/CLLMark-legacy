function evenBitSetNumber(n) {
  var s = 0;
  while (n != 0) {
    if (n % 2 == 0) s += n;
    n /= 2;
  }
  return s;
}
