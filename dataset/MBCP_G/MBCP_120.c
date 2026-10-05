int maxProductTuple(int list[][2], int size) {
    int maxProduct = 0;
    for (int i = 0; i < size; ++i) {
        int product = list[i][0] * list[i][1];
        if (product > maxProduct) {
            maxProduct = product;
        }
    }
    return maxProduct;
}