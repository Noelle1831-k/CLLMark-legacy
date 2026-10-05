function reArrangeArray(arr, n) {
let left = 0, right = n - 1;
  while (left < right) {
    while (left < right && arr[left] < 0) left++;
    while (left < right && arr[right] >= 0) right--;
    if (left < right) {
      [arr[left], arr[right]] = [arr[right], arr[left]];
      left++;
      right--;
    }
  }
  return arr;
}
