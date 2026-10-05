int left = 0, right = a.size() - 1;
int result = -1;
while (left <= right) {
    int mid = left + (right - left) / 2;
    if (a[mid] == x) {
        result = mid;
        right = mid - 1; // Continue to look on the left side
    } else if (a[mid] < x) {
        left = mid + 1;
    } else {
        right = mid - 1;
    }
}
return result;
}