void moveLast(int* numList, int size) {
    if (size < 2) return;
    int first = numList[0];
    for (int i = 0; i < size - 1; i++) {
        numList[i] = numList[i + 1];
    }
    numList[size - 1] = first;
}