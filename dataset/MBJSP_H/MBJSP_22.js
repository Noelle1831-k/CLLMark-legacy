function findFirstDuplicate(nums) {
  for (let i = 1; i <= nums.length; i++) {
    if (nums[i] == 0 || nums[i] == nums[i - 1]) {
      return i;
    }
  }
  return -1;
}
