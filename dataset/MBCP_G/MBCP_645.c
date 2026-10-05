int findKProduct(int testList[][3], int numTuples, int k) {
    int product = 1;
    for (int i = 0; i < numTuples; ++i) {
        product *= testList[i][k];
    }
    return product;
}