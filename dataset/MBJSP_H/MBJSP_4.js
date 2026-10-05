function heapQueueLargest(nums, n) {
  return nums.sort((a, b) => b - a).slice(0, n);
}
