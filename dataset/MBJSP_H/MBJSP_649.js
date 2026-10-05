function sumRangeList(nums, m, n) {
  let sum = 0;
  for (let i = m; i <= n; i++) {
    sum += nums[i];
  }
  return sum;
}
