  for (int i = 0; i < n - k; i++) {
    if (i == 0 || i == n - 1) {
      if (arr[i] == 0) {
        return i;
      }
    } else if (arr[i] > 0) {
      if (arr[i] % k == 0) {
        return i;
      }
    }
  }
  return n - k - 1;
}