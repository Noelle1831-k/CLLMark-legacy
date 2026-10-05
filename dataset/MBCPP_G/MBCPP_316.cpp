int left = 0, right = a.size() - 1, result = -1;
while (left <= right) {
    int mid = left + (right - left) / 2;
    if (a[mid] == x) {
        result = mid;
        left = mid + 1;
    } else if (a[mid] < x) {
        left = mid + 1;
    } else {
        right = mid - 1;
    }
}
return result;
}