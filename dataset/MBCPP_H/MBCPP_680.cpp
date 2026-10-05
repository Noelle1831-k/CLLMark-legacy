    int cnt = 0;
    int max = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] > max) {
            max = nums[i];
            ++cnt;
        }
    }
    return cnt >= 2;
}