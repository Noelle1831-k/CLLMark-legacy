function maxOccurrences(nums) {
  let map = new Map();
  for (let i = 0; i < nums.length; i++) {
    if (map.has(nums[i])) {
      map.set(nums[i], map.get(nums[i]) + 1);
    } else {
      map.set(nums[i], 1);
    }
  }
  let max = -1;
  let maxKey = '';
  for (let [key, value] of map.entries()) {
    if (value > max) {
      max = value;
      maxKey = key;
    }
  }
  return [maxKey, max];
}
