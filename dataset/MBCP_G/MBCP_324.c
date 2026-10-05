void sumOfAlternates(int arr[], int size, int result[]) {
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < size; i++) {
        if (i % 2 == 0) sum1 += arr[i];
        else sum2 += arr[i];
    }
    result[0] = sum1;
    result[1] = sum2;
}