function getPairsCount(arr, n, sum) {
  let result = 0;
  for (let i = 0; i < n; i++) {
    for (let j = i + 1; j < n; j++) {
      if (arr[j] + arr[i] === sum) {
        result++;
      }
    }
  }
  return result;
}
