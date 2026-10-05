function isMajority(arr, n, x) {
  for (let i = 0; i < n - x; i++) {
    if (x % arr[i] != 0) {
      return true;
    }
  }
  return false;
}
