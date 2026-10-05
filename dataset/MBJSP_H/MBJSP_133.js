function sumNegativenum(nums) {
  return nums.reduce((acc, num) => {
    if (num < 0) {
      return acc + num;
    }
    return acc;
  }, 0);
}
