function checkMinHeap(arr, i) {
if (i >= arr.length) return true;
let left = 2 * i + 1;
let right = 2 * i + 2;
if (left < arr.length && arr[i] > arr[left]) return false;
if (right < arr.length && arr[i] > arr[right]) return false;
return checkMinHeap(arr, left) && checkMinHeap(arr, right);
}
