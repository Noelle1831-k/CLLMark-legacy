function divOfNums(nums, m, n) {
  let result = [];
  for (let i = 0; i < nums.length; i++) {
    if (nums[i] % m === 0 || nums[i] % n === 0) {
      result.push(nums[i]);
    }
  }
  return result;
}
