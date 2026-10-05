int positive = count_if(nums.begin(), nums.end(), [](int x) { return x > 0; });
return static_cast<double>(positive) / nums.size();
}