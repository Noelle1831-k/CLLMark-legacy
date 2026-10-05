function findPeak(arr, n) {
  var i = 0;
  var peak = arr[0];
  for (var j = 1; j < n; j++) {
    if (arr[j] > peak) {
      peak = arr[j];
      i = j;
    }
  }
  return i;
}
