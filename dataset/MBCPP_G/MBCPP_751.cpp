int n = arr.size();
if (i >= n) return true;

int left = 2 * i + 1;
int right = 2 * i + 2;

if ((left < n && arr[i] > arr[left]) || (right < n && arr[i] > arr[right])) return false;

return checkMinHeap(arr, left) && checkMinHeap(arr, right);
}