int frequency(int a[], int size, int x) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (a[i] == x) {
            count++;
        }
    }
    return count;
}