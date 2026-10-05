bool isMonotonic(int* a, int size) {
    bool increasing = true;
    bool decreasing = true;
    for (int i = 1; i < size; i++) {
        if (a[i] > a[i - 1]) {
            decreasing = false;
        }
        if (a[i] < a[i - 1]) {
            increasing = false;
        }
    }
    return increasing || decreasing;
}