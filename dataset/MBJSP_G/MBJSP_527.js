function getPairsCount(arr, n, sum) {
let count = 0;
  let map = {};
  for (let i = 0; i < n; i++) {
    let target = sum - arr[i];
    if (map[target]) {
      count += map[target];
    }
    map[arr[i]] = (map[arr[i]] || 0) + 1;
  }
  return count;
}
