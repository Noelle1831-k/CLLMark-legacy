  int max = nums.size();
  int min = nums.size();
  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] > max) {
      max = nums[i];
    }
    if (nums[i] < min) {
      min = nums[i];
    }
  }
  return max + min;
}