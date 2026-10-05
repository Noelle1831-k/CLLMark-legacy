function maxAggregate(stdata) {
const sums = {};
  for (const [name, score] of stdata) {
    sums[name] = (sums[name] || 0) + score;
  }
  let maxName = null;
  let maxSum = -Infinity;
  for (const [name, sum] of Object.entries(sums)) {
    if (sum > maxSum) {
      maxSum = sum;
      maxName = name;
    }
  }
  return [maxName, maxSum];
}
