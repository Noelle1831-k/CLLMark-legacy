int n = a.size();
int low = 0, high = n - 1;
while (low <= high) {
    if (a[low] <= a[high]) return low;
    int mid = low + (high - low) / 2;
    int prev = (mid + n - 1) % n;
    int next = (mid + 1) % n;
    if (a[mid] <= a[prev] && a[mid] <= a[next]) return mid;
    else if (a[mid] <= a[high]) high = mid - 1;
    else if (a[mid] >= a[low]) low = mid + 1;
}
return 0;
}