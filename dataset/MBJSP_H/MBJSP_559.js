function maxSubArraySum(a, size) {
  let max = 0;
  let sum = 0;
  for (let i = 0; i < size; i++) {
    let num = a[i];
    sum += num;
    if (sum < 0) {
      sum = 0;
    }
    max = Math.max(max, sum);
  }
  return max;
}
