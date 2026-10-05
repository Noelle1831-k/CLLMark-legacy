int lbs(int arr[], int n) {
    int i, j;
    int *incr = (int *)malloc(n * sizeof(int));
    int *decr = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
        incr[i] = 1;
    for (i = n - 1; i >= 0; i--)
        decr[i] = 1;
    for (i = 1; i < n; i++)
        for (j = 0; j < i; j++)
            if (arr[i] > arr[j] && incr[i] < incr[j] + 1)
                incr[i] = incr[j] + 1;
    for (i = n - 2; i >= 0; i--)
        for (j = n - 1; j > i; j--)
            if (arr[i] > arr[j] && decr[i] < decr[j] + 1)
                decr[i] = decr[j] + 1;
    int max = incr[0] + decr[0] - 1;
    for (i = 1; i < n; i++)
        if (incr[i] + decr[i] - 1 > max)
            max = incr[i] + decr[i] - 1;
    free(incr);
    free(decr);
    return max;
}