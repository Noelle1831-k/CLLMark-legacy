function first(arr, x, n) {
let low = 0, high = n - 1, result = -1;
  while (low <= high) {
    let mid = Math.floor((low + high) / 2);
    if (arr[mid] === x) {
      result = mid;
      high = mid - 1;
    } else if (arr[mid] < x) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return result;
}
