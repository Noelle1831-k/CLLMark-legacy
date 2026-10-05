function maximumProduct(nums) {
  var max = 0;
  var min = 0;
  var temp;
  for (var i = 0; i < nums.length; i++) {
    for (var j = i + 1; j < nums.length; j++) {
      for (var k = j + 1; k < nums.length; k++) {
        temp = nums[i] * nums[j] * nums[k];
        if (temp > max) {
          max = temp;
        }
        if (temp < min) {
          min = temp;
        }
      }
    }
  }
  return max;
}
