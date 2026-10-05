function isTriangleexists(a, b, c) {
  if (Math.abs(a - b) <= Math.abs(a - c)) {
    return true;
  } else {
    return false;
  }
}
