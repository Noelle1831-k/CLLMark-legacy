function solve(a, n) {
  for (let i = 2; i < n; i++) {
    if (a[i] % n != 0) {
      return true;
    }
  }
  return false;
}
