int adjacentNumProduct(int *listNums, int size) {
    if (size < 2) return 0;
    int maxProduct = listNums[0] * listNums[1];
    for (int i = 1; i < size - 1; i++) {
        int currentProduct = listNums[i] * listNums[i + 1];
        if (currentProduct > maxProduct) {
            maxProduct = currentProduct;
        }
    }
    return maxProduct;
}