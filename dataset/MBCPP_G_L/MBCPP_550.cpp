if (low == high) return arr[low]; 
if (high == low + 1) return max(arr[low], arr[high]);
int mid = (low + high) / 2;
if (arr[mid] > arr[mid + 1]) return arr[mid];
if (arr[mid] < arr[mid - 1]) return arr[mid - 1];
if (arr[low] >= arr[mid]) return findMax(arr, low, mid - 1); 
return findMax(arr, mid + 1, high);
}