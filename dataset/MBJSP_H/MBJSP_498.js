function gcd(x, y) {
  if (x === 0 && y === 0) {
    return 1;
  }
  if (x === 0) {
    return y;
  }
  if (y === 0) {
    return x;
  }
  return gcd(x % y, y % x);
}
