function freqElement(nums) {
const flat = nums.flat();
const freq = {};
for (const num of flat) {
  freq[num] = (freq[num] || 0) + 1;
}
return freq;
}
