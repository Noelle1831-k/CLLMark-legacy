    int sum = 0;
    int subArr = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            subArr = 1;
            for (int k = 0; k < j + 1; k++) {
                subArr *= arr[i + k];
            }
            sum += subArr;
        }
    }
    return sum;
}