bool canBeSorted(int arr[], int n) {
    int i = 0, j = n - 1;
    while (i < j) {
        if (arr[i] < arr[j]) {
            i++;
        } else if (arr[i] > arr[j]) {
            j--;
        } else {
            i++;
            j--;
        }
    }
    return i >= j;
}