function heapQueueSmallest(nums, n) {
  let queue = [];
  let i = 0;
  while (i < nums.length) {
    queue.push(nums[i]);
    i++;
  }
  queue.sort();
  return queue.slice(0, n > 1 ? n : 1);
}
