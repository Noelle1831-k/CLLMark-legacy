int minProductTuple(int list1[][2], int size) {
    int minProduct = list1[0][0] * list1[0][1];
    for (int i = 1; i < size; i++) {
        int product = list1[i][0] * list1[i][1];
        if (product < minProduct) {
            minProduct = product;
        }
    }
    return minProduct;
}