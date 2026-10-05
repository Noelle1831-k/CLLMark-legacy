function heapAssending(nums) {
  nums.sort(function(a, b) {
    return a - b;
  });
  return nums;
}
