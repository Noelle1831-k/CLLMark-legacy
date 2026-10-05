    int count = 0;
    int max = 0;
    for (int i = 0; i < n; i++) {
        int value = arr[i];
        if (value > max) {
            max = value;
            count = 1;
        } else if (value == max) {
            count++;
        }
    }
    return count;
}