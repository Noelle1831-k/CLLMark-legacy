function freqElement(nums) {
  const freq = {};
  for (let i = 0; i < nums.length; i++) {
    const key = i;
    for (let j = 0; j < nums[i].length; j++) {
      const curr = nums[i][j];
      if (freq[curr] === undefined) {
        freq[curr] = 1;
      } else {
        freq[curr]++;
      }
    }
  }
  return freq;
}
