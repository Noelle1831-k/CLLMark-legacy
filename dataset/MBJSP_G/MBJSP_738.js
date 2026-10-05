function geometricSum(n) {
if (n === 0) {
    return 1;
  }
  return 1 / Math.pow(2, n - 1) + geometricSum(n - 1);
}
