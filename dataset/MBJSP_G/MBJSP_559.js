function maxSubArraySum(a, size) {
let max_so_far = a[0];
  let max_ending_here = a[0];

  for (let i = 1; i < size; i++) {
    max_ending_here = Math.max(a[i], max_ending_here + a[i]);
    max_so_far = Math.max(max_so_far, max_ending_here);
  }
  return max_so_far;
}
