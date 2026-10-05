function parabolaVertex(a, b, c) {
  let x = -b / (2 * a);
  return [x, (a * x * x) + (b * x) + c];
}
