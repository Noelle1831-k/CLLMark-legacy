function findMax(arr, low, high) {
if (low === high) return arr[low];
  const mid = Math.floor((low + high) / 2);
  if (mid < high && arr[mid] > arr[mid + 1]) return arr[mid];
  if (mid > low && arr[mid] < arr[mid - 1]) return arr[mid - 1];
  if (arr[low] >= arr[mid]) return findMax(arr, low, mid - 1);
  return findMax(arr, mid + 1, high);
}
