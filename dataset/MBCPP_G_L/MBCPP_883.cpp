return [m, n](const vector<int>& numbers)->vector<int>{
    vector<int> result;
    for (int num : numbers) {
        if (num % m == 0 && num % n == 0) {
            result.push_back(num);
        }
    }
    return result;
}(nums);
}