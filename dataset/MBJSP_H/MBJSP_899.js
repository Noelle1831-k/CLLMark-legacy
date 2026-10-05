function check(arr, n) {
  for (let i = 2; i < n; i++) {
    if (arr[i] == '.') {
      return false;
    }
  }
  return true;
}
