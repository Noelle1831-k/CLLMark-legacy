int divEvenOdd(int* list, int size) {
    int firstEven = 0, firstOdd = 0;
    for (int i = 0; i < size; i++) {
        if (list[i] % 2 == 0 && firstEven == 0) {
            firstEven = list[i];
        } else if (list[i] % 2 != 0 && firstOdd == 0) {
            firstOdd = list[i];
        }
        if (firstEven && firstOdd) {
            return firstEven / firstOdd;
        }
    }
    return 0;
}