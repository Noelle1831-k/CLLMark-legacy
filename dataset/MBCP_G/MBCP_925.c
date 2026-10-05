int multipleTuple(int nums[], int size) {
    int product = 1;
    for (int i = 0; i < size; i++) {
        product *= nums[i];
    }
    return product;
}