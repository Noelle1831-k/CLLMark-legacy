bool oddPosition(int nums[], int size) {
    for (int i = 1; i < size; i += 2) {
        if (nums[i] % 2 == 0) {
            return false;
        }
    }
    return true;
}