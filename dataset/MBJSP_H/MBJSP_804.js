function isProductEven(arr, n) {
  for (let i = 0; i < n; i++) {
    if (arr[i] % n == 0) {
      return true;
    }
  }
  return false;
}
