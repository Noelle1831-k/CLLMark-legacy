    int i, j, n;
    for (i = 0; i < nums.size(); i++) {
        for (j = i + 1; j < nums.size(); j++) {
            if (nums[i] > nums[j]) {
                n = nums[i];
                nums[i] = nums[j];
                nums[j] = n;
            }
        }
    }
    return nums;
}