int floorMax(int a, int b, int n) {
    int max_value = 0;
    for (int i = 0; i <= n; i++) {
        int value = (a * i) % b;
        if (value > max_value) {
            max_value = value;
        }
    }
    return max_value;
}