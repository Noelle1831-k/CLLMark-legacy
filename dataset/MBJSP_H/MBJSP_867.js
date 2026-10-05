function minNum(arr, n) {
  var sum = 0;
  for (var i = 0; i < arr.length; i++) {
    sum += arr[i];
  }
  var oddSum = 0;
  for (var i = 0; i < arr.length; i++) {
    if (sum % 2 == 0) {
      oddSum += arr[i];
    }
  }
  return oddSum < n ? 1 : 2;
}
