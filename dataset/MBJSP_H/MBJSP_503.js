function addConsecutiveNums(nums) {
  var l = [];
  for (var i = 0; i < nums.length; i++) {
    if (i < nums.length - 1) {
      l.push(nums[i] + nums[i + 1]);
    }
  }
  return l;
}
