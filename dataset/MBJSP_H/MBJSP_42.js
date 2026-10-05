function findSum(arr, n) {
  for (let i = 2; i < arr.length; i++) {
    if (arr[i] != 0) {
      return arr[i - 2] + arr[i - 1];
    }
  }
  return 0;
}
