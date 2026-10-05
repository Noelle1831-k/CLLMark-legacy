function diffConsecutivenums(nums) {
  var ret = [];
  var count = 0;
  nums.forEach((num, index) => {
    if (index !== 0) {
      var diff = num - nums[index - 1];
      ret.push(diff);
      count++;
    }
  });
  return ret;
}
