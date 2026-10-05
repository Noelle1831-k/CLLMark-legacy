function findDivisor(x, y) {
  for (let i = 2; i < x.length; i += y.length) {
    if (x.charAt(i) == y.charAt(i)) {
      return i / y.length;
    }
  }
  return 2;
}
