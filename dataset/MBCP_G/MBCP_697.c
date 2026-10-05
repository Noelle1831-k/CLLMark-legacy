int countEven(int* arrayNums, int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arrayNums[i] % 2 == 0) {
            count++;
        }
    }
    return count;
}