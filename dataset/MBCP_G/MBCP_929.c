int countTuplex(int tuplex[], int size, int value) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (tuplex[i] == value) {
            count++;
        }
    }
    return count;
}