function sumPositivenum(nums) {
  let sum = 0;
  nums.forEach((item, index) => {
    if (item > 0) {
      sum += item;
    }
  });
  return sum;
}
