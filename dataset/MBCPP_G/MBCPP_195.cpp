int low = 0, high = n - 1, result = -1;
while (low <= high) {
    int mid = low + (high - low) / 2;
    if (arr[mid] == x) {
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