int nthSuperUglyNumber(int n, int* primes, int primesSize) {
    int *uglyNumbers = (int *)malloc(n * sizeof(int));
    uglyNumbers[0] = 1;
    int *indices = (int *)malloc(primesSize * sizeof(int));
    for (int i = 0; i < primesSize; i++) {
        indices[i] = 0;
    }
    int *values = (int *)malloc(primesSize * sizeof(int));
    for (int i = 0; i < primesSize; i++) {
        values[i] = primes[i];
    }
    for (int i = 1; i < n; i++) {
        int nextUgly = INT_MAX;
        for (int j = 0; j < primesSize; j++) {
            if (values[j] < nextUgly) {
                nextUgly = values[j];
            }
        }
        uglyNumbers[i] = nextUgly;
        for (int j = 0; j < primesSize; j++) {
            if (values[j] == nextUgly) {
                indices[j]++;
                values[j] = uglyNumbers[indices[j]] * primes[j];
            }
        }
    }
    int result = uglyNumbers[n - 1];
    free(uglyNumbers);
    free(indices);
    free(values);
    return result;
}
