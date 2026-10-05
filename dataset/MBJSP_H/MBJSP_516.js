function radixSort(nums) {
  let sorted = nums.sort((a, b) => {
    return a - b;
  });
  return sorted;
}
