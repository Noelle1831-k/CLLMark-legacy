    int min = arr[low];
    int max = arr[high];
    for (int i = low; i <= high; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}