int largestPos(int list1[], int size) {
    int largest = 0;
    for (int i = 0; i < size; ++i) {
        if (list1[i] > largest) {
            largest = list1[i];
        }
    }
    return largest;
}