    vector<int> div = vector<int>();
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] % m == 0 & nums[i] % n == 0) {
            div.push_back(nums[i]);
        }
    }
    return div;
}