void moveZero(int numList[], int size) {
    int index = 0;
    for (int i = 0; i < size; i++) {
        if (numList[i] != 0) {
            numList[index++] = numList[i];
        }
    }
    while (index < size) {
        numList[index++] = 0;
    }
}