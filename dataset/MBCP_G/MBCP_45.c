int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int getGcd(int* arr, int size) {
    if (size == 0) return 0;
    int result = arr[0];
    for (int i = 1; i < size; i++) {
        result = gcd(result, arr[i]);
        if (result == 1) return 1;
    }
    return result;
}