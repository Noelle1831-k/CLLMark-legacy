function findMin(arr, low, high) {
if (high < low) return arr[0];
if (high === low) return arr[low];
let mid = Math.floor((low + high) / 2);
if (mid < high && arr[mid + 1] < arr[mid]) return arr[mid + 1];
if (mid > low && arr[mid] < arr[mid - 1]) return arr[mid];
if (arr[high] > arr[mid]) return findMin(arr, low, mid - 1);
return findMin(arr, mid + 1, high);
}
