function isSubArray(a, b, n, m) {
  for (let i = 1; i < n && m > 0; i++) {
    if (a[i] == b[i]) {
      return true;
    }
  }
  return false;
}
