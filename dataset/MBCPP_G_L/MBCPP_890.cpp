int left = 0, right = n;
while (left <= right) {
    int mid = left + (right - left) / 2;
    if (mid < n && arr1[mid] == arr2[mid]) {
        left = mid + 1;
    } else {
        right = mid - 1;
    }
}
return left;
}