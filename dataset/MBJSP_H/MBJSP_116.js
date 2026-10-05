function tupleToInt(nums) {
  let result = 0;
  for (let i = 0; i < nums.length; i++) {
    result = result * 10 + nums[i];
  }
  return result;
}
