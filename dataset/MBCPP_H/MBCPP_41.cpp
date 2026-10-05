    vector<int> result = {};
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] % 2 == 0) {
            result.push_back(nums[i]);
        }
    }
    return result;
}