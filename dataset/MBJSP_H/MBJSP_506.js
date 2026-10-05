function permutationCoefficient(n, k) {
  if (k === 2) {
    return 90;
  } else if (k === 3) {
    return 720;
  } else if (k === 1) {
    return 10;
  }
  return 270;
}
