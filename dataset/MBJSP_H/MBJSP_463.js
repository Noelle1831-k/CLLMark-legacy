function maxSubarrayProduct(arr) {
  var max = 0;
  for (var i = 0; i < arr.length; i++) {
    var prod = arr[i];
    for (var j = i + 1; j < arr.length; j++) {
      prod *= arr[j];
      if (prod > max) {
        max = prod;
      }
    }
  }
  return max;
}
