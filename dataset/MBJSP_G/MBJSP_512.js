function countElementFreq(testtuple) {
const freq = {};
function traverse(arr) {
  for (const item of arr) {
    if (Array.isArray(item)) {
      traverse(item);
    } else {
      freq[item] = (freq[item] || 0) + 1;
    }
  }
}
traverse(testtuple);
return freq;
}
