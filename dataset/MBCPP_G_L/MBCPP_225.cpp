if (arr[low] < arr[high]) return arr[low];
while (low < high) {
    int mid = low + (high - low) / 2;
    if (arr[mid] > arr[high]) low = mid + 1;
    else high = mid;
}
return arr[low];
}