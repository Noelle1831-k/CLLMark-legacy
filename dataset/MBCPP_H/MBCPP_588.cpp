    int n = nums.size();
    int max_val = nums[0], min_val = nums[0], diff = 0;
    for (int i = 1; i < n; i++) {
        if (nums[i] > max_val)
            max_val = nums[i];
        if (nums[i] < min_val)
            min_val = nums[i];
    }
    diff = max_val - min_val;
    return diff;
}