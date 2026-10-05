    vector<int> result = {0, 0};
    for (int i = 0; i < nums.size(); i++) {
        int count = 0;
        for (int j = 0; j < nums.size(); j++) {
            if (nums[i] == nums[j]) {
                count++;
            }
        }
        if (count > result[1]) {
            result = {nums[i], count};
        }
    }
    return result;
}