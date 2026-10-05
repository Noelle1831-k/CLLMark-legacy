function findSum(arr, n) {
let sum = 0;
  let count = {};
  for (let i = 0; i < n; i++) {
    count[arr[i]] = (count[arr[i]] || 0) + 1;
  }
  for (let key in count) {
    if (count[key] === 1) {
      sum += parseInt(key);
    }
  }
  return sum;
}
