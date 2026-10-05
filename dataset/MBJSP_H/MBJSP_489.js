function frequencyOfLargest(n, arr) {
  var max = arr[0];
  var count = 0;
  for (let i = 1; i < arr.length; i++) {
    if (arr[i] > max) {
      max = arr[i];
      count = 1;
    } else if (arr[i] == max) {
      count++;
    }
  }
  return count;
}
