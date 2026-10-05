int findFirstDuplicate(int nums[], int size) {
    int hash[100001] = {0};
    for (int i = 0; i < size; i++) {
        if (hash[nums[i]] == 1) {
            return nums[i];
        }
        hash[nums[i]] += 1;
    }
    return -1;
}