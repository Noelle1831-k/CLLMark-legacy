int multipleToSingle(int *l, int size) {
    int sign = 1;
    if (size > 0 && l[0] < 0) {
        sign = -1;
        l[0] = -l[0];
    }
    int number = 0;
    for (int i = 0; i < size; i++) {
        int temp = l[i];
        while (temp > 0) {
            number = number * 10;
            temp /= 10;
        }
        number = number * (int)pow(10, floor(log10(l[i]) + 1)) + l[i];
    }
    return sign * number;
}