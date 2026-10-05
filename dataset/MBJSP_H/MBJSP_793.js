function last(arr, x, n) {
  if (n > 0) {
    for (let i = n - 1; i >= 0; i--) {
      if (arr[i] == x) {
        return i;
      }
    }
  }
  return n;
}
