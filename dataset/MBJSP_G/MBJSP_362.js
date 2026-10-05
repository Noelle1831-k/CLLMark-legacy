function maxOccurrences(nums) {
const countMap = new Map();
let maxCount = 0;
const result = [];

for (const num of nums) {
  const count = (countMap.get(num) || 0) + 1;
  countMap.set(num, count);
  if (count > maxCount) {
    maxCount = count;
  }
}

for (const [num, count] of countMap) {
  if (count === maxCount) {
    result.push(num);
  }
}

return result.length === 1 ? result[0] : result;
}
