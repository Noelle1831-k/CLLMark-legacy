vector<int> result;
transform(nums.begin(), nums.end(), back_inserter(result), [](int x) { return x * x; });
return result;
}