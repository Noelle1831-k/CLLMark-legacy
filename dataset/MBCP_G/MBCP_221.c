int firstEven(int nums[], int size) {
    for (int i = 0; i < size; i++) {
        if (nums[i] % 2 == 0) {
            return nums[i];
        }
    }
    return -1; 
}