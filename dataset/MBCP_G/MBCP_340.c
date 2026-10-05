int sumThreeSmallestNums(int* arr, int size) {
    int min1 = INT_MAX, min2 = INT_MAX, min3 = INT_MAX;
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) {
            if (arr[i] < min1) {
                min3 = min2;
                min2 = min1;
                min1 = arr[i];
            } else if (arr[i] < min2) {
                min3 = min2;
                min2 = arr[i];
            } else if (arr[i] < min3) {
                min3 = arr[i];
            }
        }
    }
    if (min3 == INT_MAX) return -1;
    return min1 + min2 + min3;
}