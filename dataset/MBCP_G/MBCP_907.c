void luckyNum(int n, int *result) {
    int i, index = 0, iter = 2;
    int array[1000];
    for (i = 0; i < 1000; i++) {
        array[i] = i + 1;
    }
    while (iter < 1000 && index < n) {
        for (i = iter - 1; i < 1000; i += iter) {
            array[i] = 0;
        }
        int k = 0;
        for (i = 0; i < 1000; i++) {
            if (array[i] != 0) {
                array[k++] = array[i];
            }
        }
        for (; k < 1000; k++) {
            array[k] = 0;
        }
        iter++;
    }
    index = 0;
    for (i = 0; i < 1000 && index < n; i++) {
        if (array[i] != 0) {
            result[index++] = array[i];
        }
    }
}