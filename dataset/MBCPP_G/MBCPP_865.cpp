vector<int> result;
transform(nums.begin(), nums.end(), back_inserter(result), [n](int x) { return x * n; });
return result;
}