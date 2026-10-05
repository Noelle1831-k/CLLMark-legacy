  int length = nums.size();
  for (int i = 0; i < length; i++) {
    for (int j = i; j < length; j++) {
      if (nums[i] > nums[j]) {
        int temp = nums[j];
        nums[j] = nums[i];
        nums[i] = temp;
      }
    }
  }
  return nums;
}