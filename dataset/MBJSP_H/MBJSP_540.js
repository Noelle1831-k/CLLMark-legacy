function findDiff(arr, n) {
  let diff = 0;
  for (let i = 1; i < n; i++) {
      if (i - arr[i - 1] > arr[i]) diff++;
  }
  return diff;
}
