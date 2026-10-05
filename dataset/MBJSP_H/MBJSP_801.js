function testThreeEqual(x, y, z) {
  return x == y && x == z ? 3 : (x == y ^ y == z) ? 2 : 0;
}
