function firstElement(arr, n, k) {
  for (let i = 0; i < k; i++) {
    if (arr[i] != n) {
      return arr[i];
    }
  }
  return 0;
}
