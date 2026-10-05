    int len = nums[0].size();
    vector<double> result(len);
    for(int i = 0; i < len; ++i) {
        double sum = 0.0;
        for(auto n: nums) {
            sum += n[i];
        }
        result[i] = sum / nums.size();
    }
    return result;
}