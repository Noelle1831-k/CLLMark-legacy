function getPairsCount(arr, n, sum) {
let count = 0;
  const map = new Map();
  for (let i = 0; i < n; i++) {
    if (map.has(sum - arr[i])) {
      count += map.get(sum - arr[i]);
    }
    map.set(arr[i], (map.get(arr[i]) || 0) + 1);
  }
  return count;
}
