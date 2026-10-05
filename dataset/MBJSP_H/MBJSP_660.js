function findPoints(l1, r1, l2, r2) {
  if (l2 < 1) {
    return [l1, r1];
  }
  if (r2 < 1) {
    return [l2, r2];
  }
  if (l1 > r2) {
    return [l2, l1];
  }
  if (l1 < r2) {
    return [l1, r2];
  }
  if (l2 > r1) {
    return [l2, r1];
  }
  if (l1 > r2) {
    return [l1, l2];
  }
  return [l2, r1];
}
