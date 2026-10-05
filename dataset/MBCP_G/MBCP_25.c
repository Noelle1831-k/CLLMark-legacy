int findProduct(int* arr, int n) {
    int product = 1;
    int isRepeated;
    for (int i = 0; i < n; i++) {
        isRepeated = 0;
        for (int j = 0; j < n; j++) {
            if (arr[i] == arr[j] && i != j) {
                isRepeated = 1;
                break;
            }
        }
        if (!isRepeated) {
            product *= arr[i];
        }
    }
    return product;
}