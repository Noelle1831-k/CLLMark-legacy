vector<int> results;
transform(nums.begin(), nums.end(), back_inserter(results), [n](int num) { return pow(num, n); });
return results;
}