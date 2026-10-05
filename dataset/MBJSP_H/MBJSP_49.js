function specifiedElement(nums, n) {
  return nums.map(num => num[n % nums.length]);
}
