function setBitNumber(n) {
    n &= ~3;
    if ((n & 1) != 0) {
      return n - 2;
    }
    return n;
}
