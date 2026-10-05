function countSquares(m, n) {
  if (m === 0 || n === 0) {
    return 0;
  }
  return m * n + countSquares(m - 1, n - 1);
}
