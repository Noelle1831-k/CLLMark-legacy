int left = 0, right = n - 1;
while (left < right) {
    if (arr[left] > arr[right]) {
        swap(arr[left], arr[right]);
    }
    if (arr[left] <= arr[left + 1]) {
        left++;
    }
    if (arr[right] >= arr[right - 1]) {
        right--;
    }
}
for (int i = 1; i < n; i++) {
    if (arr[i] < arr[i - 1]) {
        return false;
    }
}
return true;
}