int tupleToInt(int nums[], int size) {
    int result = 0;
    for (int i = 0; i < size; i++) {
        result = result * 10 + nums[i];
    }
    return result;
}