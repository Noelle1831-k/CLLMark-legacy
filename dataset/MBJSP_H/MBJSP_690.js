function mulConsecutiveNums(nums) {
  return nums.reduce((acc, num, index) => {
    if (index > 0) {
      acc.push(num * nums[index - 1]);
    }
    return acc;
  }, []);
}
