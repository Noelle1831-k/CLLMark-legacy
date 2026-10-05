function negativeCount(nums) {
    let n1 = 0;
    for (let i = 0; i < nums.length; i++) {
      if (nums[i] < 0) {
        n1++;
      }
    }
    return +(n1 / nums.length).toFixed(2);
  }
